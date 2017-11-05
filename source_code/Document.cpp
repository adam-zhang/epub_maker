#include "Document.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QUrl>
#include <cassert>
#include <gumbo.h>

using namespace std;

Document::Document(const QString& url)
	: url_(url)
{
	assert(url_.size());
}

Document::~Document()
{
}

QString Document::getHtmlContent(const QString& url)
{
	QNetworkAccessManager* manager = new QNetworkAccessManager(this);
	QNetworkRequest request;
	request.setUrl(url);
	QNetworkReply *reply = manager->get(request);
	QEventLoop loop;
	connect(manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
	loop.exec();
	return reply->readAll();
}

static void find_links(map<QString, QString>& pairs, const GumboNode* node)
{
	if (node->type != GUMBO_NODE_ELEMENT) 
		return;
	if(node->v.element.tag == GUMBO_TAG_A)
	{
		GumboAttribute* href = gumbo_get_attribute(&node->v.element.attributes, "href");
		if (href)
		{
			QString link = href->value;
			QString text = node->v.text.text;
			qDebug() << "link:" << link << " " << "text:" << text;
			pairs.emplace(link, text);
		}
	}
	const GumboVector* children = &node->v.element.children;
	for(auto i = 0; i < children->length; ++i)
		find_links(pairs, static_cast<GumboNode*>(children->data[i]));
}

static bool find_links(map<QString, QString>& pairs, const QString& text)
{
	GumboOutput* node = gumbo_parse(text.toStdString().c_str());
	if (!node)
		return false;
	find_links(pairs, node->root);
	gumbo_destroy_output(&kGumboDefaultOptions, node);
	qDebug() << "pairs' size:" << pairs.size();
	return true;
}

static map<QString, QString> parseHtml(const QString& content)
{
	map<QString, QString> pairs;
	find_links(pairs, content);
	return pairs;
}

map<QString, QString> Document::contents()
{
	return parseHtml(getHtmlContent(url()));
}


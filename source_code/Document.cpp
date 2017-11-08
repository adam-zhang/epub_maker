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

QByteArray Document::getHtmlContent(const QString& url)
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

static void find_links(map<QByteArray, QByteArray>& pairs, const GumboNode* node)
{
	if (node->type != GUMBO_NODE_ELEMENT) 
		return;
	if(node->v.element.tag == GUMBO_TAG_A)
	{
		GumboAttribute* href = gumbo_get_attribute(&node->v.element.attributes, "href");
		if (href)
			pairs.emplace(href->value, node->v.text.text);
	}
	const GumboVector* children = &node->v.element.children;
	for(auto i = 0; i < children->length; ++i)
		find_links(pairs, static_cast<GumboNode*>(children->data[i]));
}

static QString getCode(const GumboNode* node)
{
	return QString();
}

static QString gbkToUTF8(const QByteArray& byteArray)
{
	QString str = QString::fromWCharArray((wchar_t*)byteArray.data());
	return str;
}

static bool find_links(map<QByteArray, QByteArray>& pairs, const QByteArray& text)
{
	QString utf8 = gbkToUTF8(text);
	GumboOutput* node = gumbo_parse(text.data());
	//QString code = getCode(node->root());
	if (!node)
		return false;
	find_links(pairs, node->root);
	gumbo_destroy_output(&kGumboDefaultOptions, node);
	return true;
}

static map<QByteArray, QByteArray> parseHtml(const QByteArray& content)
{
	map<QByteArray, QByteArray> pairs;
	find_links(pairs, content);
	return pairs;
}

map<QByteArray, QByteArray> Document::contents()
{
	return parseHtml(getHtmlContent(url()));
}


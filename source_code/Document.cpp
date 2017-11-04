#include "Document.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QUrl>
#include <cassert>

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

static map<QString, QString> parseHtml(const QString& content)
{
	map<QString, QString> pairs;
	qDebug() << content;
	return pairs;
}

map<QString, QString> Document::contents()
{
	return parseHtml(getHtmlContent(url()));
}


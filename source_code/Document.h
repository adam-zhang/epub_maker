#ifndef __DOCUMENT__H
#define __DOCUMENT__H

#include <QString>
#include <QObject>
#include <map>

class Document : public QObject
{
	Q_OBJECT

	public:
		Document(const QString&);
		~Document();
	private:
		QString url_;
	public:
		const QString& url()const
		{ return url_;}
	public:
		std::map<QByteArray, QByteArray> contents();
	private:
		QByteArray getHtmlContent(const QString& url);
};
#endif//__DOCUMENT__H

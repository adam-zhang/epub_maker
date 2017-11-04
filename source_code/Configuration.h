#ifndef __DECLARATION__H
#define __DECLARATION__H

#include <QString>
#include <QObject>

class Configuration
{
	private:
		Configuration() {}
		~Configuration() {}
	public:
		static QString applicationName()
		{ return QObject::tr("Epub Maker");}
};

#endif//__DECLARATION__H

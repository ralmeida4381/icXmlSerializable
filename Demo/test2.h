/***************************************************************************
 *   Copyright (C) 2007 by Roberto Almeida   *
 *   ralmeida@ingenieriacreativa.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef TEST2_H
#define TEST2_H

#include <icxmlserializable.h>
#include <QtCore>
#include <QString>
#include <test3_child.h>

/**
	@author Roberto Almeida <ralmeida@ingenieriacreativa.com>
*/
class test2 : public icXmlSerializable
{
Q_OBJECT
public:
    test2(QObject* parent=0);

    ~test2();

	void	populate(int offset);
	
protected:
    virtual bool 	deserialize();
    virtual bool 	serialize();

	int				m_v1;
	int				m_v2;
		
	QString			m_name;
	QString			m_app;
	QString			m_otroname;

	test3_child		m_t3c;
};

#endif

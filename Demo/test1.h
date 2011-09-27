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
#ifndef TEST1_H
#define TEST1_H

#include <icxmlserializable.h>
#include <QtCore>
#include <test2.h>
#include <test4.h>
#include <test5.h>
#include <test6.h>

/**
	@author Roberto Almeida <ralmeida@ingenieriacreativa.com>
*/
class test1 : public icXmlSerializable
{
Q_OBJECT
public:
    test1(QObject* parent=0);
    ~test1();

	void	populate();
	
protected:
    virtual bool deserialize();
    virtual bool serialize();

	test2	m_t2a;	
	test2	m_t2b;	
	test2	m_t2c;	
	test4	m_t4;
	test5	m_t5;
	test6	m_t6;
		
	QString	m_prop1;
	QString	m_prop2;
	
	int		m_x;
	int		m_y;
	
};

#endif

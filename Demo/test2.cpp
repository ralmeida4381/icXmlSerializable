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
#include "test2.h"

test2::test2(QObject* parent): icXmlSerializable(parent)
{
}


test2::~test2()
{
}


bool test2::deserialize()
{
	bool	res;	
	
	m_v1 = getSerialProperty("v1").toInt();
	m_v2 = getSerialProperty("v2").toInt();
        m_name = getSerialProperty("name").toString();
        m_app = getSerialProperty("lname").toString();
        m_otroname = getSerialProperty("other").toString();
	
	res = getSerialObject("t3c", &m_t3c);
	
	return res;
}

bool test2::serialize()
{
	setSerialProperty("v1", m_v1);
	setSerialProperty("v2", m_v2);
        setSerialProperty("name", m_name);
        setSerialProperty("lname", m_app);
        setSerialProperty("other", m_otroname);
	
	setSerialObject("t3c", &m_t3c);
	
	return true;
}

void test2::populate(int offset)
{
	m_v1 = offset + 928;
	m_v2 = offset + 234;
	
        m_name = "Alan " + QString::number(offset);
        m_app = "Wells "+ QString::number(offset);
	m_otroname = QDateTime::currentDateTime().toString(Qt::ISODate);
	
	m_t3c.populate(m_v2);
}


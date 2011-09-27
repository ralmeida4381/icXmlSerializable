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
#include "test1.h"

test1::test1(QObject* parent): icXmlSerializable(parent)
{
}


test1::~test1()
{
}


bool test1::deserialize()
{
	bool res;
	
	m_x = getSerialProperty("x").toInt();
	m_y = getSerialProperty("y").toInt();
	m_prop1 = getSerialProperty("prop1").toString();
	m_prop2 = getSerialProperty("prop2").toString();
	
	res = 	getSerialObject("t2a", &m_t2a) &&
			getSerialObject("t2b", &m_t2b) &&
			getSerialObject("t2c", &m_t2c) &&
			getSerialObject("t4", &m_t4) &&
			getSerialObject("t6", &m_t6) &&
			getSerialObject("t5", &m_t5);
	
	return res;
}

bool test1::serialize()
{
	setSerialProperty("x", m_x);
	setSerialProperty("y", m_y);
	setSerialProperty("prop1", m_prop1);
	setSerialProperty("prop2", m_prop2);
	
	setSerialObject("t2a", &m_t2a);
	setSerialObject("t2b", &m_t2b);
	setSerialObject("t2c", &m_t2c);
	setSerialObject("t4", &m_t4);
	setSerialObject("t5", &m_t5);
	setSerialObject("t6", &m_t6);
	
	return true;
}

void test1::populate()
{
	m_x=100;
	m_y=200;
	
        m_prop1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam consequat bibendum tincidunt. Nullam at lectus eget elit rutrum auctor at ac massa. Morbi et nisi ante. Vestibulum convallis dapibus nulla, vel egestas quam accumsan eget. Etiam accumsan, libero ut pretium aliquet, sapien urna pulvinar leo, at eleifend tortor justo a neque. Vivamus in est eu nunc varius placerat. Sed ut turpis sed felis vehicula pretium. Aliquam erat volutpat. Suspendisse adipiscing nibh vel eros volutpat quis aliquam dui pretium.";
        m_prop2 = "Mauris sit amet ipsum dui. Quisque bibendum, tellus et viverra aliquet, elit nunc luctus neque, ac malesuada justo nibh in magna. Vestibulum.";
		
	m_t2a.populate(10);
	m_t2b.populate(20);
	m_t2c.populate(30);
	m_t4.populate(m_y);
	m_t5.populate(4381);
	m_t6.populate(23);
}


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
#include "test3.h"

test3::test3(QObject* parent): icXmlSerializable(parent)
{
}


test3::~test3()
{
}


bool test3::deserialize()
{

	m_p1 = getSerialProperty("p1").toInt();
	m_p2 = (float)getSerialProperty("p2").toDouble();
	m_desc1 = getSerialProperty("desc1").toString();
	m_desc2 = getSerialProperty("desc2").toString();
	
	return true;
}

bool test3::serialize()
{
	setSerialProperty("p1", m_p1);
	setSerialProperty("p2", m_p2);
	setSerialProperty("desc1", m_desc1);
	setSerialProperty("desc2", m_desc2);

	return true;
}

void test3::populate(int offset)
{
	m_p1 = offset + 112;
	m_p2 = 	35674/offset;
	
        m_desc1 = "Lorem "  +  QString::number(m_p2) + " adfasdfdasfda";
        m_desc2 = "Ipsum "  +  QString::number(m_p1) + " adfasdfdasfda";
}


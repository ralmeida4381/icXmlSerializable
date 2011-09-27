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
#include "test3_child.h"

test3_child::test3_child(QObject* parent): test3(parent)
{
}


test3_child::~test3_child()
{
}


bool test3_child::deserialize()
{
	m_par1 = getSerialProperty("par1").toInt();
	m_par2 = getSerialProperty("par2").toInt();
        m_direccion = getSerialProperty("address").toString();
	
    return test3::deserialize();
}

bool test3_child::serialize()
{
	setSerialProperty("par1", m_par1);
	setSerialProperty("par2", m_par2);
        setSerialProperty("address", m_direccion);
	
    return test3::serialize();
}

void test3_child::populate(int offset)
{
    m_par1 = offset + 10;
    m_par2 = offset - 10;
    m_direccion = QString("Address %1 from %2").arg(m_par1).arg(m_par2);
    
    test3::populate(m_par1);
}


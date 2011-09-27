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
#include "test4.h"

test4::test4(QObject* parent): test2(parent)
{
}


test4::~test4()
{
}


bool test4::deserialize()
{

	m_attr1 = getSerialProperty("at1").toString();
	m_attr2 = getSerialProperty("at2").toString();
	int	index, total;
	bool	res;
		
	total = getSerialObjectCount("items");	
	for (index=0; index < total; index++ ) {
		test3_child *item = new test3_child(this);
		res = getSerialObject("items", item, index);
		m_items.append(item);
	}
	
	res = test2::deserialize();
    return res;
}

bool test4::serialize()
{
	setSerialProperty("at1", m_attr1);
	setSerialProperty("at2", m_attr2);
	setSerialObject("items", m_items);
	
    return test2::serialize();
}

void test4::populate(int offset)
{
    m_attr1 = "this (" + QString::number(offset) + ") is new";
    m_attr2 = "new too";
    
    for (int index=0; index < 3; index++) {
		test3_child	*item = new test3_child(this);
		item->populate(index + offset);
		m_items.append(item);    	
    }
    
    test2::populate(offset);
}


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
#include "test6.h"
#include <test3_child.h>

test6::test6(QObject* parent): test4(parent)
{
}


test6::~test6()
{
}


bool test6::deserialize()
{
	int index;
        int total = getSerialObjectCount("myitems");
	for (index=0; index < total; index++ ) {
		test3_child *item = new test3_child(this);
                getSerialObject("myitems", item, index);
		m_list.append(item);
	}
	
    return test4::deserialize();
}

bool test6::serialize()
{
        setSerialObject("myitems", m_list);
    return test4::serialize();
}

void test6::populate(int offset)
{
	int index;
	int total = offset % 37;
    for (index=0; index < total; index++ ){
    	test3_child *item = new test3_child(this);
    	item->populate(index);
    	m_list.append(item);
    }
    
    test4::populate(offset);
}


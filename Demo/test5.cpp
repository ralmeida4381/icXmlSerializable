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
#include "test5.h"

test5::test5(QObject* parent): test4(parent)
{
}


test5::~test5()
{
}


bool test5::deserialize()
{
	bool	res;
	
	m_you = getSerialProperty("you").toInt();
	m_tube = getSerialProperty("tube").toInt();
	m_youtube = getSerialProperty("yt").toString();
	
	res = test4::deserialize();
    return res;
}

bool test5::serialize()
{
	bool res;
	
	setSerialProperty("you", m_you);
	setSerialProperty("tube", m_tube);
	setSerialProperty("yt", m_youtube);
	
	res = test4::serialize();
    return res;
}

void test5::populate(int offset)
{
	m_you = offset * 2;
	m_tube = offset * 3;
	
	m_youtube = "http://www.ingenieriacreativa.com";
	
	test4::populate(offset*4);    
}


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
#ifndef TEST4_H
#define TEST4_H

#include <test2.h>
#include <test3_child.h>

/**
	@author Roberto Almeida <ralmeida@ingenieriacreativa.com>
*/
class test4 : public test2
{
Q_OBJECT
public:
    test4(QObject* parent=0);

    ~test4();

    void populate(int offset);

protected:
    virtual bool deserialize();
    virtual bool serialize();
    
	QString		m_attr1;
	QString		m_attr2;    
	
	QVector<icXmlSerializable *>	m_items;

};

#endif

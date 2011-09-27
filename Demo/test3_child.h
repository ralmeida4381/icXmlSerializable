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
#ifndef TEST3_CHILD_H
#define TEST3_CHILD_H

#include <test3.h>

/**
	@author Roberto Almeida <ralmeida@ingenieriacreativa.com>
*/
class test3_child : public test3
{
Q_OBJECT
public:
    test3_child(QObject* parent=0);

    ~test3_child();

    void populate(int offset);

protected:
    virtual bool deserialize();
    virtual bool serialize();

	int		m_par1;
	int		m_par2;
	QString	m_direccion;

};

#endif

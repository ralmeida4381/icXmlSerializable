/***************************************************************************
 *   Copyright (C) 2011 by Roberto Almeida   *
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
#include "objecta.h"

ObjectA::ObjectA(QObject *parent) :
    icXmlSerializable(parent)
{
    m_itemId = 0;
    m_itemName = "";
    m_itemComments = "";
    m_itemDate = QDateTime::currentDateTime();
    m_isActive = false;
    m_itemValue = 0;

}

bool ObjectA::serialize(){
    setSerialProperty("id", m_itemId);
    setSerialProperty("name", m_itemName);
    setSerialProperty("comments", m_itemComments);
    setSerialProperty("date", m_itemDate);
    setSerialProperty("active", m_isActive);
    setSerialProperty("value", m_itemValue);

    return true;
}


bool ObjectA::deserialize(){

    m_itemId = getSerialProperty("id").toInt();
    m_itemName = getSerialProperty("name").toString();
    m_itemComments = getSerialProperty("comments").toString();
    m_itemDate = getSerialProperty("date").toDateTime();
    m_isActive = getSerialProperty("active").toBool();
    m_itemValue = getSerialProperty("value").toFloat();

    return true;
}

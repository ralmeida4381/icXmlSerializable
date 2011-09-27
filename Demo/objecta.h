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
#ifndef OBJECTA_H
#define OBJECTA_H
#include "icxmlserializable.h"
#include <QString>
#include <QDateTime>

class ObjectA : public icXmlSerializable
{
    Q_OBJECT
public:
    explicit ObjectA(QObject *parent = 0);

signals:

public slots:

private:
    int     m_itemId;
    QString m_itemName;
    QString m_itemComments;
    QDateTime   m_itemDate;
    bool    m_isActive;
    float   m_itemValue;

protected:
    virtual bool    serialize();
    virtual bool    deserialize();

};

#endif // OBJECTA_H

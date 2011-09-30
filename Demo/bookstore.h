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

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <QtCore>
#include "icxmlserializable.h"

class Book;
class StoreSection;

//----------------------------------------------------
//STEP 1: inherits from icXmlSerializeble
//----------------------------------------------------
class BookStore : public icXmlSerializable
{
    Q_OBJECT
public:
    explicit BookStore(QObject *parent = 0);

    QString getTitle();
    void    setTitle(const QString& title);
    QDateTime getCreatedDate();

    QStringList   getSections();
    StoreSection* getSection(const QString& name);
    StoreSection* addSection(const QString& name);

    Book*    searchBookByTitle(const QString& title);
    Book*    searchBookByAuthor(const QString& author);

signals:

public slots:

private:
    QString     m_title;
    QDateTime   m_date;

    //------------
    //m_store contains pointers to icXmlSerializable objects
    //------------
    QHash<QString, icXmlSerializable *>   m_store;

    //----------------------------------------------------
    //STEP 2: declares serialize & deserialize methods
    //----------------------------------------------------
    virtual bool serialize();
    virtual bool deserialize();
};

#endif // BOOKSTORE_H

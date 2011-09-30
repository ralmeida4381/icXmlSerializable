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
#ifndef STORESECTION_H
#define STORESECTION_H

#include <QtCore>
#include "icxmlserializable.h"

class Book;

//----------------------------------------------------
//STEP 1: inherits from icXmlSerializeble
//----------------------------------------------------
class StoreSection : public icXmlSerializable
{
    Q_OBJECT
public:
    explicit StoreSection(QObject *parent = 0);

    QString getTitle();
    void    setTitle(const QString& title);

    QList<Book*> getBooks();
    Book*    addBook(const QString& title);
    Book*    searchBookByTitle(const QString& title);
    Book*    searchBookByAuthor(const QString& author);    

signals:

public slots:

private:
    QString         m_title;

    //------------
    //m_books contains icXmlSerializable objects
    //------------
    QHash<QString, icXmlSerializable *>  m_books;

    //----------------------------------------------------
    //STEP 2: declares serialize & deserialize methods
    //----------------------------------------------------
    virtual bool serialize();
    virtual bool deserialize();
};

#endif // STORESECTION_H

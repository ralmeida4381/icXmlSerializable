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
#include "storesection.h"
#include "book.h"

StoreSection::StoreSection(QObject *parent) :
    icXmlSerializable(parent)
{
    m_title = "";
}

QString StoreSection::getTitle(){
    return m_title;
}

void    StoreSection::setTitle(const QString &title){
    m_title = title;
}

Book*    StoreSection::addBook(const QString& newBookTitle){
    Book *book = 0;
    if (!m_books.contains(newBookTitle)) {
        Book *book = new Book(this);
        book->setTitle(newBookTitle);
        m_books.insert(book->getTitle(), book);
        return book;
    }

    return book;
}

Book*    StoreSection::searchBookByTitle(const QString& title){
    Book *book = 0;

    if (m_books.contains(title))
        book = (Book *)m_books.value(title);

    return book;
}

Book*    StoreSection::searchBookByAuthor(const QString& author){
    Book *book = 0;

    QHashIterator<QString, icXmlSerializable*> i(m_books);
    while (i.hasNext()) {
        i.next();
        book = (Book *)i.value();
        if (book->getAuthor() == author)
            return book;
    }

    return book;
}

QList<Book*> StoreSection::getBooks(){
    QList<Book*> list;
    Book *book;

    QHashIterator<QString, icXmlSerializable*> i(m_books);
    while (i.hasNext()) {
        i.next();
        book = (Book *)i.value();
        list.append(book);
    }

    return list;
}

//----------------------------------------------------
//STEP 3: implements serialize & deserialize methods
//----------------------------------------------------

bool    StoreSection::serialize(){

    //---------------
    //To serialize int, QString, float, bool, long, QDateTime
    //just call setSerialProperty
    //---------------
    setSerialProperty("title", m_title);

    //---------------
    //To serialize QObjects with icXmlSerializeble inheritance
    //just call setSerialObject
    //---------------
    setSerialObject("books", m_books);

    //---------------
    //Always return a boolean
    //beacause you may want to include this object in another inner serialization
    //---------------
    return true;
}

bool    StoreSection::deserialize(){

    //---------------
    //To deserialize int, QString, float, bool, long, QDateTime
    //just call getSerialProperty (returns a QVariant)
    //---------------
    m_title = getSerialProperty("title").toString();

    //-------------------
    //To deserialize QHash, QList, QVector:
    //  a) Obtain child count
    //  b) Instantiate each child
    //  c) Deserialize each child
    //  d) add to QHash, QList or QVector
    //-------------------
    m_books.clear();
    int index, total;

    //step (a)
    total = getSerialObjectCount("books");      //getSerialObjectCount return number of items inside "books" (xml tag)
    for (index = 0; index < total; index++ ) {

        //step (b)
        Book *book = new Book(this);

        //step (c)
        getSerialObject("books", book, index);
        if (book == 0) {
            book->deleteLater();
            return false;
        }

        //step (d)
        m_books.insert(book->getTitle(), book);
    }

    //---------------
    //Always return a boolean
    //beacause you may want to include this object in another inner serialization
    //---------------
    return true;
}

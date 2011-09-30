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
#include "bookstore.h"
#include "storesection.h"
#include "book.h"

BookStore::BookStore(QObject *parent) :
    icXmlSerializable(parent)
{
    m_title = "";
    m_date = QDateTime::currentDateTime();
}

QString BookStore::getTitle(){
    return m_title;
}

void    BookStore::setTitle(const QString& title){
    m_title = title;
}

QDateTime BookStore::getCreatedDate(){
    return m_date;
}

QStringList BookStore::getSections(){
    QStringList sections;

    QHashIterator<QString, icXmlSerializable*> i(m_store);
    while (i.hasNext()) {
        i.next();
        StoreSection* section= (StoreSection *)i.value();
        sections.append(section->getTitle());
    }

    return sections;
}

StoreSection* BookStore::getSection(const QString& name){
    StoreSection *section = 0;
    if (m_store.contains(name)) {
        section = (StoreSection *)m_store.value(name);
    }

    return section;
}

StoreSection* BookStore::addSection(const QString& name){
    StoreSection *section = 0;
    if (m_store.contains(name)) {
        section = (StoreSection *)m_store.value(name);
        return section;
    }

    section = new StoreSection(this);
    section->setTitle(name);
    m_store.insert(name, section);

    return section;
}

Book*    BookStore::searchBookByTitle(const QString& title){
    Book* book;

    QHashIterator<QString, icXmlSerializable*> i(m_store);
    while (i.hasNext()) {
        i.next();
        StoreSection* section = (StoreSection *)i.value();
        book = section->searchBookByTitle(title);
        if (book != 0)
            return book;
    }

    return book;
}

Book*    BookStore::searchBookByAuthor(const QString& author){
    Book* book;

    QHashIterator<QString, icXmlSerializable*> i(m_store);
    while (i.hasNext()) {
        i.next();
        StoreSection* section = (StoreSection *)i.value();
        book = section->searchBookByAuthor(author);
        if (book != 0)
            return book;
    }

    return book;
}


//----------------------------------------------------
//STEP 3: implements serialize & deserialize methods
//----------------------------------------------------

bool    BookStore::serialize(){

    //---------------
    //To serialize int, QString, float, bool, long, QDateTime
    //just call setSerialProperty
    //---------------
    setSerialProperty("title", m_title);
    setSerialProperty("date", m_date);

    //---------------
    //To serialize QObjects with icXmlSerializeble inheritance just call setSerialObject
    //You can use any from:
    //      icXmlSerializeble *
    //      QList<icXmlSerializeble *)
    //      QHash<QString, icXmlSerializeble *)
    //      QVector<icXmlSerializeble *)
    setSerialObject("sections", m_store);

    //---------------
    //Always return a boolean
    //beacause you may want to include this object in another inner serialization
    //---------------
    return true;
}

bool    BookStore::deserialize(){

    //---------------
    //To deserialize int, QString, float, bool, long, QDateTime
    //just call getSerialProperty (returns a QVariant)
    //---------------
    m_title = getSerialProperty("title").toString();
    m_date = getSerialProperty("date").toDateTime();

    //-------------------
    //To deserialize QHash, QList, QVector:
    //  a) Obtain child count
    //  b) Instantiate each child
    //  c) Deserialize each child
    //  d) add to QHash, QList or QVector
    //-------------------
    int index, total;
    //step (a)
    total = getSerialObjectCount("sections");
    for (index=0; index < total; index++){

        //step (b)
        StoreSection *section = new StoreSection(this);

        //step (c)
        if (!getSerialObject("sections", section, index)){
            section->deleteLater();
            return false;
        }

        //step (d)
        m_store.insert(section->getTitle(), section);
    }

    //---------------
    //Always return a boolean
    //beacause you may want to include this object in another inner serialization
    //---------------
    return true;
}

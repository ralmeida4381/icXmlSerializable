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
#include "book.h"

Book::Book(QObject *parent) :
    icXmlSerializable(parent)
{
    m_stock = 0;
    m_title = "";
    m_author = "";
    m_price = 0;
    m_date = QDateTime::currentDateTime();
}

bool   Book::shop(){
    if (m_stock > 0) {
        m_stock--;
        return true;
    }

    return false;
}

void    Book::setPrice(float price){
    m_price = price;
}

float   Book::getPrice(){
    return m_price;
}

void    Book::setTitle(const QString &title){
    m_title = title;
}

void    Book::addStock(int stock){
    m_stock += stock;
}

QString Book::getTitle(){
    return m_title;
}

void    Book::setAuthor(const QString &author){
    m_author = author;
}

QString Book::getAuthor(){
    return m_author;
}

int     Book::getStock(){
    return m_stock;
}

QDateTime Book::getCreatedDate() {
    return m_date;
}

//----------------------------------------------------
//STEP 3: implements serialize & deserialize methods
//----------------------------------------------------

bool    Book::serialize(){

    //---------------
    //To serialize int, QString, float, bool, long, QDateTime
    //just call setSerialProperty
    //---------------
    setSerialProperty("stock", m_stock);
    setSerialProperty("price", m_price);
    setSerialProperty("title", m_title);
    setSerialProperty("author", m_author);
    setSerialProperty("date", m_date);

    return true;
}

bool    Book::deserialize(){

    //---------------
    //To deserialize int, QString, float, bool, long, QDateTime
    //just call getSerialProperty (returns a QVariant)
    //---------------
    m_stock = getSerialProperty("stock").toInt();
    m_price = getSerialProperty("price").toFloat();
    m_title = getSerialProperty("title").toString();
    m_author = getSerialProperty("author").toString();
    m_date = getSerialProperty("date").toDateTime();

    return true;
}

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
#ifndef BOOK_H
#define BOOK_H
#include "icxmlserializable.h"

//----------------------------------------------------
//STEP 1: inherits from icXmlSerializeble
//----------------------------------------------------
class Book : public icXmlSerializable
{
    Q_OBJECT
public:
    explicit Book(QObject *parent = 0);

signals:

public slots:

    bool    shop();
    void    setTitle(const QString &title);
    void    setPrice(float price);
    void    setAuthor(const QString& author);
    void    addStock(int stock);

    QString getTitle();
    QString getAuthor();
    float   getPrice();
    int     getStock();
    QDateTime getCreatedDate();

private:
    float   m_price;
    QString m_title;
    int     m_stock;
    QString m_author;
    QDateTime m_date;

    //----------------------------------------------------
    //STEP 2: declares serialize & deserialize methods
    //----------------------------------------------------
    virtual bool    serialize();
    virtual bool    deserialize();
};

#endif // BOOK_H

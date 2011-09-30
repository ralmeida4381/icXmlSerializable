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
#include "bookview.h"
#include "ui_bookview.h"
#include "bookstore.h"
#include "storesection.h"
#include "book.h"

BookView::BookView(BookStore *bs, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookView)
{
    m_bookStore = bs;
    ui->setupUi(this);

    ui->comboSection->addItems(m_bookStore->getSections());
}

BookView::~BookView()
{
    delete ui;
}

void BookView::on_cmdSave_clicked()
{
    if (ui->txtAuthor->text().isEmpty()
            || ui->txtPrice->text().isEmpty()
            || ui->txtStock->text().isEmpty()
            || ui->txtTitle->text().isEmpty()) {
        QApplication::beep();
        return;
    }

    if (ui->comboSection->currentText().isEmpty()) {
        QApplication::beep();
        return;
    }

    StoreSection *section = m_bookStore->addSection(ui->comboSection->currentText());
    if (section == 0) {
        QApplication::beep();
        return;
    }

    Book* book = section->addBook(ui->txtTitle->text());
    if (book == 0) {
        QApplication::beep();
        return;
    }

    book->setAuthor(ui->txtAuthor->text());

    bool isOk;
    int stock = ui->txtStock->text().toInt(&isOk);
    if (isOk)
        book->addStock(stock);

    float price = ui->txtPrice->text().toFloat(&isOk);
    if (isOk)
        book->setPrice(price);

    qDebug() << "Book added: " << book->getTitle();
   this->accept();
}


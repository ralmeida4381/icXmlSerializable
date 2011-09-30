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

#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui>
#include "bookstore.h"

class StoreSection;
class Book;

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_cmdShop_clicked();
    void on_cmdNewBook_clicked();
    void on_cmdImport_clicked();
    void on_cmdExport_clicked();


    void on_treeBooks_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::Dialog *ui;

    BookStore   m_bookStore;
    Book*       m_currentBook;

    void        importBookStore();
    void        exportBookStore();
    void        searchBook();
    void        fillBooks();
    void        fillSection(StoreSection *section, QTreeWidgetItem *item);
    void        fillBook(const QString& title);
    void        displayBook(Book *);

};

#endif // DIALOG_H

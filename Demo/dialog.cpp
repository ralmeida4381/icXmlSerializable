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
#include "dialog.h"
#include "ui_dialog.h"
#include "bookview.h"
#include "storesection.h"
#include "book.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("BookStore Demo");
    m_currentBook = 0;

}

Dialog::~Dialog()
{
    delete ui;
}

void    Dialog::exportBookStore(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save BookStore File"),
                                                    "",
                                                    tr("BookStore (*.xml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Cant write file " << fileName;
        return;
    }

    //---------------------------------
    //NOTES on serializing to xml:
    // 1) m_bookStore inherits from icXmlSerializable
    // 2) m_bookStore contains icXmlSerializable members and this members will be serialized too
    // 3) I choose "bookstore" as the main node in xml string.
    //----
    QString xmlContent = m_bookStore.serializeMetaComponent("bookstore");
    if (xmlContent.isEmpty()) {
        QApplication::beep();
        return;

    }
    QTextStream out(&file);
    out << xmlContent;
    out.flush();
    file.close();

    this->setWindowTitle("BookStore Demo: " + fileName);
    qDebug() << "BookStore saved to " << fileName;
}

void    Dialog::importBookStore(){

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open BookStore File"),
                                                    "",
                                                    tr("BookStore (*.xml)"));

    if (fileName.isEmpty())
        return;

    QString xmlContent = "";
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        xmlContent += file.readLine();
    }

    m_bookStore.setMetaContent(xmlContent);
    if (!m_bookStore.deserializeMetaComponent("bookstore")) {
        QMessageBox::critical(this, tr("BookStore Demo"),
                                        tr("Cant load BookStore file"),
                                        QMessageBox::Ok);

        return;
    }

    this->setWindowTitle("BookStore Demo: " + fileName);
    fillBooks();

}


void    Dialog::searchBook(){

}

void Dialog::on_cmdShop_clicked()
{
    if (m_currentBook == 0)
        return;

    if (!m_currentBook->shop())
        QApplication::beep();

    displayBook(m_currentBook);
}

void Dialog::on_cmdNewBook_clicked()
{
    BookView* bookView = new BookView(&m_bookStore);
    bookView->exec();
    fillBooks();
}

void Dialog::on_cmdImport_clicked()
{
    importBookStore();
}

void Dialog::on_cmdExport_clicked()
{
    exportBookStore();
}

void    Dialog::fillBooks(){
    ui->treeBooks->clear();

    QStringList sections = m_bookStore.getSections();
    StoreSection *section;
    for (int index=0; index < sections.size(); index++) {
        section = m_bookStore.getSection(sections.at(index));

        QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeBooks);
        item->setText(0, section->getTitle());
        ui->treeBooks->addTopLevelItem(item);
        fillSection(section, item);
    }

}

void    Dialog::fillSection(StoreSection *section, QTreeWidgetItem *parentItem) {
    int index;
    Book *book;

    QList<Book*> list = section->getBooks();
    for (index=0; index < list.size(); index++) {
        book = list.at(index);

        QTreeWidgetItem *item = new QTreeWidgetItem(parentItem);
        item->setText(0, book->getTitle());
        item->setText(1, book->getAuthor());
        item->setText(2, QString::number(book->getPrice()));
        item->setText(3, QString::number(book->getStock()));
        parentItem->addChild(item);
    }
}

void Dialog::on_treeBooks_itemClicked(QTreeWidgetItem *item, int column)
{
    if (item->text(2).isEmpty()) {
        return;
    }

    fillBook(item->text(0));
}

void Dialog::fillBook(const QString &title){
    m_currentBook = m_bookStore.searchBookByTitle(title);
    if (m_currentBook == 0)
        return;

    displayBook(m_currentBook);
}

void Dialog::displayBook(Book *book){
    ui->txtAuthor->setText(book->getAuthor());
    ui->txtTitle->setText(book->getTitle());
    ui->txtPrice->setText(QString::number(book->getPrice()));
    ui->txtStock->setText(QString::number(book->getStock()));

}

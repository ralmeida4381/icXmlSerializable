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

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->comboSerialize->addItem("Object A");
    ui->comboSerialize->addItem("Test 1");
    ui->comboSerialize->addItem("Test 2");
    ui->comboSerialize->addItem("Test 3");

    m_test1.populate();
    m_test2.populate(10);
    m_test3.populate(20);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_cmdSerialize_clicked()
{

    if (ui->comboSerialize->currentText() == "Object A") {
        ui->txtSerialize->setPlainText(m_objectA.serializeMetaComponent("A"));
    }
    if (ui->comboSerialize->currentText() == "Test 1") {
        ui->txtSerialize->setPlainText(m_test1.serializeMetaComponent("T1"));
    }
    if (ui->comboSerialize->currentText() == "Test 2") {
        ui->txtSerialize->setPlainText(m_test2.serializeMetaComponent("T2"));
    }
    if (ui->comboSerialize->currentText() == "Test 3") {
        ui->txtSerialize->setPlainText(m_test3.serializeMetaComponent("T3"));
    }

}

void Dialog::on_cmdDeserialize_clicked()
{
    if (ui->comboSerialize->currentText() == "Object A") {
        m_objectA.setMetaContent(ui->txtSerialize->toPlainText());
        if (m_objectA.deserializeMetaComponent("A")) {
            ui->txtSerialize->setPlainText("Ok");
        }
        else {
            ui->txtSerialize->setPlainText("Error");
        }
    }

    if (ui->comboSerialize->currentText() == "Test 1") {
        m_test1.setMetaContent(ui->txtSerialize->toPlainText());
        if (m_test1.deserializeMetaComponent("T1")) {
            ui->txtSerialize->setPlainText("Ok");
        }
        else {
            ui->txtSerialize->setPlainText("Error");
        }
    }

    if (ui->comboSerialize->currentText() == "Test 2") {
        m_test2.setMetaContent(ui->txtSerialize->toPlainText());
        if (m_test2.deserializeMetaComponent("T2")) {
            ui->txtSerialize->setPlainText("Ok");
        }
        else {
            ui->txtSerialize->setPlainText("Error");
        }
    }

    if (ui->comboSerialize->currentText() == "Test 3") {
        m_test3.setMetaContent(ui->txtSerialize->toPlainText());
        if (m_test3.deserializeMetaComponent("T3")) {
            ui->txtSerialize->setPlainText("Ok");
        }
        else {
            ui->txtSerialize->setPlainText("Error");
        }
    }

}

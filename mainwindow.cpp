/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include "protocol.h"

#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>


//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//! [0]
    ui->setupUi(this);
   // console = new Console;
   // console->setEnabled(false);
    //setCentralWidget(console);
//! [1]
    serial = new QSerialPort(this);
    loop = new QEventLoop(this);
    proc = new QProcess(this);
    dialog_cam_sutup=new Cam_setup();
    dialog_settings_br_dist=new settings_brake_distance();
//! [1]
    settings = new SettingsDialog;
    tu_protocol =new Protocol(serial);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    status = new QLabel;
    ui->statusBar->addWidget(status);

    initActionsConnections();

    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);
    connect(serial,SIGNAL(readyRead()),tu_protocol,SLOT(dataHandler()));

    connect(dialog_cam_sutup,SIGNAL(set_cam_param(ushort,QByteArray)),SLOT(set_param(ushort,QByteArray)));
    connect(dialog_settings_br_dist,SIGNAL(set_brake_param(ushort,QByteArray)),SLOT(set_param(ushort,QByteArray)));
    connect(tu_protocol,SIGNAL(errorOccured(QString)),SLOT(status_message(QString)));
    connect(tu_protocol,SIGNAL(set_timeout(uint32_t*)),SLOT(set_timeout_dialog(uint32_t*)));
    connect(tu_protocol,SIGNAL(HW_redy()),loop,SLOT(quit()));
    connect(tu_protocol,SIGNAL(set_auto_brake_state(uint32_t)),dialog_settings_br_dist,SLOT(state_auto_brake(uint32_t)));
    connect(tu_protocol,SIGNAL(signal_auto_brake_done()),dialog_settings_br_dist,SLOT(deceleration_done_state()));
//! [2]
   // connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
//! [2]
    //connect(console, &Console::getData, this, &MainWindow::writeData);
//! [3]
}
//! [3]

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}

//! [4]
void MainWindow::openSerialPort()
{
    QByteArray data;

    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        //console->setEnabled(true);
        //console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
        tu_protocol->send_msg(GET_HW_STATE,data);
        tu_protocol->send_msg(GET_TIMEOUT,data);

    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}
//! [4]

//! [5]
void MainWindow::closeSerialPort()
{

    if (serial->isOpen())
        serial->close();
    //console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}
//! [5]

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

//! [6]
void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}
//! [6]

//! [7]
void MainWindow::readData()
{   QByteArray temp;
    QByteArray data = serial->readAll();
    temp=data.left(12);
    //console->putData(temp);
    //console->putData("\n");
    //console->putData(data);
    //console->putData("\n");
}
//! [7]

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
//! [8]

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionConfigure, &QAction::triggered, settings, &MainWindow::show);
    //connect(ui->actionClear, &QAction::triggered, console, &Console::clear);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(ui->actionConfigure_Cam,&QAction::triggered,dialog_cam_sutup,&MainWindow::show);
    connect(ui->actionConfigure_Brake,&QAction::triggered,dialog_settings_br_dist,&MainWindow::show);
}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}



void MainWindow::on_pushButton_clicked()
{

   send_data data={0,0,0};
   short operetion=DATA;

  if(get_HW_state(20000))
  {
   data.time_before_deceleration=ui->time_before_deceleration->value();
   data.time_deceleration=ui->deceleration_time->value();
   data.conditions.bit.deceleration_force=ui->deceleration_force->currentIndex()+1;
   if(ui->frontL->isChecked())
   {
       data.conditions.bit.front_left=1;
   }
   else
   {
       data.conditions.bit.front_left=0;
   }
   if(ui->frontR->isChecked())
   {
       data.conditions.bit.front_right=1;
   }
   else
   {
       data.conditions.bit.front_right=0;
   }
   if(ui->rearR->isChecked())
   {
       data.conditions.bit.rear_right=1;
   }
   else
   {
       data.conditions.bit.rear_right=0;
   }
   if(ui->rearL->isChecked())
   {
       data.conditions.bit.rear_left=1;
   }
   else
   {
       data.conditions.bit.rear_left=0;
   }

   QByteArray pkt_data((char *)&data,sizeof(send_data));
   tu_protocol->send_msg(operetion,pkt_data);
  }
  else
  {
    showStatusMessage(tr("Устройство не ответило на команду"));
  }
}

void MainWindow::on_actionConfigure_Radar_triggered()
{ QString temp;

    proc->start(QCoreApplication::applicationDirPath()+"/IWR1443ConfiguratorPortable/IWR1443Configurator.exe");
}

void MainWindow::set_param(ushort operetion, QByteArray data)
{
    tu_protocol->send_msg(operetion,data);
}

void MainWindow::status_message(QString data)
{
    showStatusMessage(data);
}

void MainWindow::set_timeout_dialog(uint32_t *data)
{
    ui->timeout->setValue(*data);
}

void MainWindow::on_pushButton_2_clicked()
{
    uint32_t time=0;
    short operetion=SET_TIMEOUT;

    time=ui->timeout->value();
    QByteArray pkt_data((char *)&time,sizeof(uint32_t));
    tu_protocol->send_msg(operetion,pkt_data);
}

void MainWindow::on_actionRun_module_test_triggered()
{
    QByteArray tx_data;

    tu_protocol->send_msg(RUN_TEST_HW,tx_data);
}
//------------------------------------------------------------------------------
//опросить сост железа и Дождаться ответа от устройства
//------------------------------------------------------------------------------
bool MainWindow::get_HW_state(int timeout)
{
    bool result;

    QTimer timer;

    timer.setSingleShot(true);
    connect(&timer,SIGNAL(timeout()),loop,SLOT(quit()));
    timer.start(timeout);
    tu_protocol->sendPacket(GET_HW_STATE,NULL);
    loop->exec();

    result=timer.isActive()?true:false;

    return result;
}

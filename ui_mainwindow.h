/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QAction *actionConnect_to_CAN;
    QAction *actionConfigure_Radar;
    QAction *actionConfigure_Cam;
    QAction *actionConfigure_Brake;
    QAction *actionRun_module_test;
    QWidget *centralWidget;
    QLabel *label;
    QCheckBox *frontL;
    QCheckBox *frontR;
    QCheckBox *rearL;
    QCheckBox *rearR;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *time_before_deceleration;
    QLabel *label_5;
    QLabel *label_3;
    QSpinBox *deceleration_time;
    QLabel *label_6;
    QLabel *label_4;
    QComboBox *deceleration_force;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QSpinBox *timeout;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(455, 495);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon1);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon2);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        actionConnect_to_CAN = new QAction(MainWindow);
        actionConnect_to_CAN->setObjectName(QStringLiteral("actionConnect_to_CAN"));
        actionConfigure_Radar = new QAction(MainWindow);
        actionConfigure_Radar->setObjectName(QStringLiteral("actionConfigure_Radar"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/set_radar_config.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure_Radar->setIcon(icon5);
        actionConfigure_Cam = new QAction(MainWindow);
        actionConfigure_Cam->setObjectName(QStringLiteral("actionConfigure_Cam"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/cam_sutup.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure_Cam->setIcon(icon6);
        actionConfigure_Brake = new QAction(MainWindow);
        actionConfigure_Brake->setObjectName(QStringLiteral("actionConfigure_Brake"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/brake_setings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure_Brake->setIcon(icon7);
        actionRun_module_test = new QAction(MainWindow);
        actionRun_module_test->setObjectName(QStringLiteral("actionRun_module_test"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/test_sustem.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun_module_test->setIcon(icon8);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, -10, 211, 431));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/vid_car2.png")));
        frontL = new QCheckBox(centralWidget);
        frontL->setObjectName(QStringLiteral("frontL"));
        frontL->setGeometry(QRect(270, 110, 21, 21));
        frontR = new QCheckBox(centralWidget);
        frontR->setObjectName(QStringLiteral("frontR"));
        frontR->setGeometry(QRect(430, 110, 21, 21));
        rearL = new QCheckBox(centralWidget);
        rearL->setObjectName(QStringLiteral("rearL"));
        rearL->setGeometry(QRect(270, 270, 70, 17));
        rearR = new QCheckBox(centralWidget);
        rearR->setObjectName(QStringLiteral("rearR"));
        rearR->setGeometry(QRect(430, 270, 70, 17));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 250, 75, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 150, 201, 74));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        time_before_deceleration = new QSpinBox(layoutWidget);
        time_before_deceleration->setObjectName(QStringLiteral("time_before_deceleration"));
        time_before_deceleration->setMaximum(20000);

        gridLayout->addWidget(time_before_deceleration, 0, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        deceleration_time = new QSpinBox(layoutWidget);
        deceleration_time->setObjectName(QStringLiteral("deceleration_time"));
        deceleration_time->setMaximum(20000);

        gridLayout->addWidget(deceleration_time, 1, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        deceleration_force = new QComboBox(layoutWidget);
        deceleration_force->setObjectName(QStringLiteral("deceleration_force"));

        gridLayout->addWidget(deceleration_force, 2, 1, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(51, 42, 158, 51));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        timeout = new QSpinBox(layoutWidget1);
        timeout->setObjectName(QStringLiteral("timeout"));
        timeout->setMaximum(20000000);

        gridLayout_2->addWidget(timeout, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 455, 21));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QStringLiteral("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addAction(actionConnect_to_CAN);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionConfigure_Radar);
        menuTools->addAction(actionConfigure_Cam);
        menuTools->addAction(actionConfigure_Brake);
        menuTools->addAction(actionClear);
        menuTools->addAction(actionRun_module_test);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionClear);
        mainToolBar->addAction(actionConfigure_Radar);
        mainToolBar->addAction(actionConfigure_Cam);
        mainToolBar->addAction(actionConfigure_Brake);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRun_module_test);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Deceleration Terminal", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", Q_NULLPTR));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("MainWindow", "C&onnect", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to serial port", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from serial port", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure serial port", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Alt+C", Q_NULLPTR));
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear data", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionClear->setShortcut(QApplication::translate("MainWindow", "Alt+L", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", Q_NULLPTR));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        actionConnect_to_CAN->setText(QApplication::translate("MainWindow", "Connect to CAN", Q_NULLPTR));
        actionConnect_to_CAN->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
        actionConfigure_Radar->setText(QApplication::translate("MainWindow", "Configure Radar", Q_NULLPTR));
        actionConfigure_Cam->setText(QApplication::translate("MainWindow", "Configure Cam", Q_NULLPTR));
        actionConfigure_Brake->setText(QApplication::translate("MainWindow", "Configure Auto deceleration", Q_NULLPTR));
        actionRun_module_test->setText(QApplication::translate("MainWindow", "Run module test", Q_NULLPTR));
        label->setText(QString());
        frontL->setText(QString());
        frontR->setText(QString());
        rearL->setText(QString());
        rearR->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Apply", Q_NULLPTR));
        pushButton->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Time before deceleration", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ms", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Deceleration time", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "ms", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Deceleration force", Q_NULLPTR));
        deceleration_force->clear();
        deceleration_force->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("MainWindow", "Timeout interval", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        menuCalls->setTitle(QApplication::translate("MainWindow", "Calls", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

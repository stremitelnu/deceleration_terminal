/********************************************************************************
** Form generated from reading UI file 'settings_brake_distance.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_BRAKE_DISTANCE_H
#define UI_SETTINGS_BRAKE_DISTANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings_brake_distance
{
public:
    QPushButton *apply;
    QLabel *label;
    QCheckBox *frontL;
    QCheckBox *frontR;
    QCheckBox *rearL;
    QCheckBox *rearR;
    QSpinBox *distance_for_brake;
    QLabel *label_9;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QCheckBox *on_off;
    QLabel *label_3;
    QSpinBox *time_before_deceleration;
    QLabel *label_7;
    QLabel *label_4;
    QSpinBox *deceleration_time;
    QLabel *label_8;
    QLabel *label_5;
    QComboBox *deceleration_force;
    QLabel *label_2;
    QCheckBox *auto_deceleration_state;
    QCheckBox *deceleration_done;

    void setupUi(QDialog *settings_brake_distance)
    {
        if (settings_brake_distance->objectName().isEmpty())
            settings_brake_distance->setObjectName(QStringLiteral("settings_brake_distance"));
        settings_brake_distance->resize(632, 297);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/brake_setings.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings_brake_distance->setWindowIcon(icon);
        apply = new QPushButton(settings_brake_distance);
        apply->setObjectName(QStringLiteral("apply"));
        apply->setGeometry(QRect(20, 270, 391, 23));
        label = new QLabel(settings_brake_distance);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, -10, 411, 281));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/brake_distance.png")));
        frontL = new QCheckBox(settings_brake_distance);
        frontL->setObjectName(QStringLiteral("frontL"));
        frontL->setGeometry(QRect(450, 190, 70, 17));
        frontR = new QCheckBox(settings_brake_distance);
        frontR->setObjectName(QStringLiteral("frontR"));
        frontR->setGeometry(QRect(530, 160, 70, 17));
        rearL = new QCheckBox(settings_brake_distance);
        rearL->setObjectName(QStringLiteral("rearL"));
        rearL->setGeometry(QRect(510, 230, 70, 17));
        rearR = new QCheckBox(settings_brake_distance);
        rearR->setObjectName(QStringLiteral("rearR"));
        rearR->setGeometry(QRect(580, 210, 70, 17));
        distance_for_brake = new QSpinBox(settings_brake_distance);
        distance_for_brake->setObjectName(QStringLiteral("distance_for_brake"));
        distance_for_brake->setGeometry(QRect(407, 150, 43, 20));
        distance_for_brake->setMaximum(200);
        label_9 = new QLabel(settings_brake_distance);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(456, 150, 16, 16));
        layoutWidget = new QWidget(settings_brake_distance);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 71, 201, 93));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        on_off = new QCheckBox(layoutWidget);
        on_off->setObjectName(QStringLiteral("on_off"));

        gridLayout->addWidget(on_off, 0, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        time_before_deceleration = new QSpinBox(layoutWidget);
        time_before_deceleration->setObjectName(QStringLiteral("time_before_deceleration"));
        time_before_deceleration->setMaximum(20000);

        gridLayout->addWidget(time_before_deceleration, 1, 1, 1, 2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 3, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        deceleration_time = new QSpinBox(layoutWidget);
        deceleration_time->setObjectName(QStringLiteral("deceleration_time"));
        deceleration_time->setMaximum(20000);

        gridLayout->addWidget(deceleration_time, 2, 1, 1, 2);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 3, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        deceleration_force = new QComboBox(layoutWidget);
        deceleration_force->setObjectName(QStringLiteral("deceleration_force"));

        gridLayout->addWidget(deceleration_force, 3, 2, 1, 1);

        label_2 = new QLabel(settings_brake_distance);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 150, 91, 16));
        QPalette palette;
        QBrush brush(QColor(255, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_2->setPalette(palette);
        auto_deceleration_state = new QCheckBox(settings_brake_distance);
        auto_deceleration_state->setObjectName(QStringLiteral("auto_deceleration_state"));
        auto_deceleration_state->setGeometry(QRect(10, 220, 131, 17));
        deceleration_done = new QCheckBox(settings_brake_distance);
        deceleration_done->setObjectName(QStringLiteral("deceleration_done"));
        deceleration_done->setGeometry(QRect(10, 240, 121, 17));
        layoutWidget->raise();
        apply->raise();
        label->raise();
        frontL->raise();
        frontR->raise();
        rearL->raise();
        rearR->raise();
        distance_for_brake->raise();
        label_9->raise();
        label_2->raise();
        auto_deceleration_state->raise();
        deceleration_done->raise();

        retranslateUi(settings_brake_distance);

        QMetaObject::connectSlotsByName(settings_brake_distance);
    } // setupUi

    void retranslateUi(QDialog *settings_brake_distance)
    {
        settings_brake_distance->setWindowTitle(QApplication::translate("settings_brake_distance", "Configure auto deceleration", Q_NULLPTR));
        apply->setText(QApplication::translate("settings_brake_distance", "Apply", Q_NULLPTR));
        label->setText(QString());
        frontL->setText(QString());
        frontR->setText(QString());
        rearL->setText(QString());
        rearR->setText(QString());
        label_9->setText(QApplication::translate("settings_brake_distance", "m", Q_NULLPTR));
        label_6->setText(QApplication::translate("settings_brake_distance", "Enable auto deceleration", Q_NULLPTR));
        on_off->setText(QString());
        label_3->setText(QApplication::translate("settings_brake_distance", "Time before deceleration", Q_NULLPTR));
        label_7->setText(QApplication::translate("settings_brake_distance", "ms", Q_NULLPTR));
        label_4->setText(QApplication::translate("settings_brake_distance", "Deceleration time", Q_NULLPTR));
        label_8->setText(QApplication::translate("settings_brake_distance", "ms", Q_NULLPTR));
        label_5->setText(QApplication::translate("settings_brake_distance", "Deceleration force", Q_NULLPTR));
        deceleration_force->clear();
        deceleration_force->insertItems(0, QStringList()
         << QApplication::translate("settings_brake_distance", "1", Q_NULLPTR)
         << QApplication::translate("settings_brake_distance", "2", Q_NULLPTR)
         << QApplication::translate("settings_brake_distance", "3", Q_NULLPTR)
         << QApplication::translate("settings_brake_distance", "4", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("settings_brake_distance", "distance to braking", Q_NULLPTR));
        auto_deceleration_state->setText(QApplication::translate("settings_brake_distance", "Auto deceleration on", Q_NULLPTR));
        deceleration_done->setText(QApplication::translate("settings_brake_distance", "Deceleration done", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settings_brake_distance: public Ui_settings_brake_distance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_BRAKE_DISTANCE_H

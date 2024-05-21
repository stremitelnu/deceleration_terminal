/********************************************************************************
** Form generated from reading UI file 'cam_setup.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAM_SETUP_H
#define UI_CAM_SETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Cam_setup
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *distance_to_cam;
    QLabel *label_2;
    QDoubleSpinBox *angle_x;
    QLabel *label_3;
    QDoubleSpinBox *angle_y;
    QLabel *label_4;
    QDoubleSpinBox *height;
    QLabel *label_5;
    QDoubleSpinBox *width;
    QPushButton *pushButton;

    void setupUi(QDialog *Cam_setup)
    {
        if (Cam_setup->objectName().isEmpty())
            Cam_setup->setObjectName(QStringLiteral("Cam_setup"));
        Cam_setup->resize(441, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/cam_sutup.png"), QSize(), QIcon::Normal, QIcon::Off);
        Cam_setup->setWindowIcon(icon);
        gridLayout = new QGridLayout(Cam_setup);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Cam_setup);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        distance_to_cam = new QDoubleSpinBox(Cam_setup);
        distance_to_cam->setObjectName(QStringLiteral("distance_to_cam"));
        distance_to_cam->setMaximum(5);
        distance_to_cam->setSingleStep(0.1);
        distance_to_cam->setValue(0.88);

        gridLayout->addWidget(distance_to_cam, 0, 2, 1, 1);

        label_2 = new QLabel(Cam_setup);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        angle_x = new QDoubleSpinBox(Cam_setup);
        angle_x->setObjectName(QStringLiteral("angle_x"));
        angle_x->setMaximum(180);
        angle_x->setSingleStep(0.01);
        angle_x->setValue(54.9);

        gridLayout->addWidget(angle_x, 1, 2, 1, 1);

        label_3 = new QLabel(Cam_setup);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        angle_y = new QDoubleSpinBox(Cam_setup);
        angle_y->setObjectName(QStringLiteral("angle_y"));
        angle_y->setMaximum(180);
        angle_y->setSingleStep(0.1);
        angle_y->setValue(31.7);

        gridLayout->addWidget(angle_y, 2, 2, 1, 1);

        label_4 = new QLabel(Cam_setup);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        height = new QDoubleSpinBox(Cam_setup);
        height->setObjectName(QStringLiteral("height"));
        height->setMaximum(5);
        height->setSingleStep(0.1);
        height->setValue(1.7);

        gridLayout->addWidget(height, 3, 2, 1, 1);

        label_5 = new QLabel(Cam_setup);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        width = new QDoubleSpinBox(Cam_setup);
        width->setObjectName(QStringLiteral("width"));
        width->setMaximum(2);
        width->setSingleStep(0.1);
        width->setValue(0.4);

        gridLayout->addWidget(width, 4, 2, 1, 1);

        pushButton = new QPushButton(Cam_setup);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 5, 1, 1, 2);


        retranslateUi(Cam_setup);

        QMetaObject::connectSlotsByName(Cam_setup);
    } // setupUi

    void retranslateUi(QDialog *Cam_setup)
    {
        Cam_setup->setWindowTitle(QApplication::translate("Cam_setup", "Configure Cam", Q_NULLPTR));
        label->setText(QApplication::translate("Cam_setup", "Distance from ground to camera", Q_NULLPTR));
        label_2->setText(QApplication::translate("Cam_setup", "Angle of camera capture vertically", Q_NULLPTR));
        label_3->setText(QApplication::translate("Cam_setup", "Angle of camera capture horizontally", Q_NULLPTR));
        label_4->setText(QApplication::translate("Cam_setup", "Height of the person", Q_NULLPTR));
        label_5->setText(QApplication::translate("Cam_setup", "Width of a person", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Cam_setup", "Apply", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Cam_setup: public Ui_Cam_setup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAM_SETUP_H

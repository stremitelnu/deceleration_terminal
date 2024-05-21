#ifndef CAM_SETUP_H
#define CAM_SETUP_H

#include <QDialog>
#include <QByteArray>
#include "protocol.h"

namespace Ui {
class Cam_setup;
}

class Cam_setup : public QDialog
{
    Q_OBJECT

public:
    explicit Cam_setup(QWidget *parent = 0);
    ~Cam_setup();
signals:
    void set_cam_param(ushort operetion,QByteArray data = QByteArray());
private slots:
    void on_pushButton_clicked();

private:
    Ui::Cam_setup *ui;

    struct cam_param
     {
      float cam_height;
      float cam_angle_x;
      float cam_angle_y;
      float human_h;
      float human_w;
     }cam_config;
};

#endif // CAM_SETUP_H

#include "cam_setup.h"
#include "ui_cam_setup.h"

Cam_setup::Cam_setup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cam_setup)
{
    ui->setupUi(this);
    cam_config={0,0,0,0,0};
}

Cam_setup::~Cam_setup()
{
    delete ui;
}

void Cam_setup::on_pushButton_clicked()
{
  ushort operetion=SETTINGS_CAM;


  cam_config.cam_height=ui->distance_to_cam->value();
  cam_config.cam_angle_x=ui->angle_x->value();
  cam_config.cam_angle_y=ui->angle_y->value();
  cam_config.human_h=ui->height->value();
  cam_config.human_w=ui->width->value();
  QByteArray send_data((char *)&cam_config,sizeof(cam_param));

  emit set_cam_param(operetion,send_data);
}

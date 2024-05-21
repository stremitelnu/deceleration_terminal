#include "settings_brake_distance.h"
#include "ui_settings_brake_distance.h"

settings_brake_distance::settings_brake_distance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings_brake_distance)
{
    ui->setupUi(this);

    time_get_auto_brake_state=new QTimer(this);
    connect(time_get_auto_brake_state,SIGNAL(timeout()),SLOT(send_auto_brake_state()));
    time_get_auto_brake_state->setInterval(10000);

}

settings_brake_distance::~settings_brake_distance()
{
    delete ui;
}

void settings_brake_distance::on_apply_clicked()
{
    ushort operetion=SETTINGS_AUTO_BRAKE;
    auto_brake_param tx_data={0,0,0,0,0};

    ui->deceleration_done->setChecked(false);
    if(ui->on_off->isChecked())
    {
     tx_data.auto_deceleration_on_off=1;
    }
    else
    {
        tx_data.auto_deceleration_on_off=0;
    }
    tx_data.distance_to_braking=ui->distance_for_brake->value();
    tx_data.time_deceleration=ui->deceleration_time->value();
    tx_data.time_before_deceleration=ui->time_before_deceleration->value();
    tx_data.conditions.bit.deceleration_force=ui->deceleration_force->currentIndex()+1;
    if(ui->frontL->isChecked())
    {
        tx_data.conditions.bit.front_left=1;
    }
    else
    {
        tx_data.conditions.bit.front_left=0;
    }
    if(ui->frontR->isChecked())
    {
        tx_data.conditions.bit.front_right=1;
    }
    else
    {
        tx_data.conditions.bit.front_right=0;
    }
    if(ui->rearR->isChecked())
    {
        tx_data.conditions.bit.rear_right=1;
    }
    else
    {
        tx_data.conditions.bit.rear_right=0;
    }
    if(ui->rearL->isChecked())
    {
        tx_data.conditions.bit.rear_left=1;
    }
    else
    {
        tx_data.conditions.bit.rear_left=0;
    }
    QByteArray data ((char *)&tx_data,sizeof(auto_brake_param));
    emit set_brake_param(operetion,data);
}

void settings_brake_distance::state_auto_brake(uint32_t data)
{
    switch (data)
    {
    case AUTO_BRAKE_ON:
         ui->auto_deceleration_state->setChecked(true);
        break;
    case AUTO_BRAKE_OFF:
        ui->auto_deceleration_state->setChecked(false);
        break;
    default:
        break;
    }
}

void settings_brake_distance::deceleration_done_state()
{
    ui->deceleration_done->setChecked(true);
}

void settings_brake_distance::send_auto_brake_state()
{
   emit set_brake_param(GET_AUTO_BRAKE_STATE,NULL);
}
void settings_brake_distance::showEvent(QShowEvent *event_show)
{
    QDialog::showEvent(event_show);
    time_get_auto_brake_state->start();
    emit set_brake_param(GET_AUTO_BRAKE_STATE,NULL);

}
void settings_brake_distance::closeEvent(QCloseEvent *event_close)
{
    QDialog::closeEvent(event_close);
    time_get_auto_brake_state->stop();
}

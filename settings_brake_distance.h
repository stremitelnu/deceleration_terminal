#ifndef SETTINGS_BRAKE_DISTANCE_H
#define SETTINGS_BRAKE_DISTANCE_H

#include <QDialog>
#include "protocol.h"

#define AUTO_BRAKE_ON               1
#define AUTO_BRAKE_OFF              0

namespace Ui {
class settings_brake_distance;
}

class settings_brake_distance : public QDialog
{
    Q_OBJECT
protected:
    virtual void closeEvent(QCloseEvent *event_close);
    void showEvent(QShowEvent * event_show);
public:
    explicit settings_brake_distance(QWidget *parent = 0);
    ~settings_brake_distance();
signals:void set_brake_param(quint16 operetion,QByteArray data);
private slots:
    void on_apply_clicked();
    void state_auto_brake(uint32_t data);
    void deceleration_done_state();

private:
    Ui::settings_brake_distance *ui;
    struct auto_brake_param
    {
        ushort time_deceleration;
        ushort time_before_deceleration;
        union
            {
              unsigned char word;
             struct
             {
              unsigned char deceleration_force:4;
              unsigned char rear_right:1;
              unsigned char rear_left:1;
              unsigned char front_right:1;
              unsigned char front_left:1;

             }bit;
            }conditions;
        uchar auto_deceleration_on_off;
        uchar distance_to_braking;

    };
    QTimer *time_get_auto_brake_state;
 public slots:
    void send_auto_brake_state();
};

#endif // SETTINGS_BRAKE_DISTANCE_H

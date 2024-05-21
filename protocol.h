#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QObject>
#include <QIODevice>
#include <QByteArray>
#include <QEventLoop>
#include <QTimer>
#include <QString>


//#include "qparameterswidget.h"

//********************* ПРОТОКОЛ ***********************************************
// |-----------------------------------------------------------------------------------------------------------------------------------------------------|
// | Начало пакета |  заголовок  |   код данных  |  данные  |     CRC код  |     CRC    | Конец пакета |
// |-----------------------------------------------------------------------------------------------------------------------------------------------------|
// | 2 байта       |  12 байт    |    2 байта    |  n байт  |    2 байта   |    2 байт  |   2 байт   |
// |-----------------------------------------------------------------------------------------------------------------------------------------------------|
// | A501          |  ...        |    A502       |   ...    |     A503     |      ...   |      A504   |
// |-----------------------------------------------------------------------------------------------------------------------------------------------------|
//
// * Если в пакете встречается байт данных A5, то он заменяется на два подряд идущих байта A5A5
// ** Поля могут отсутствовать в зависимости от типа операции, но порядок сохраняется
// *** Контрольная сумма считается от всего пакета целиком. При вычислении поле CRC зануляется
//метки в нутри пакета
#define PREAMBLE                    0xA5
#define START_OF_PACKET             0x01
#define START_OF_DATA               0x02
#define CHECKSUM_CODE               0x03
#define END_OF_PACKET               0x04
#define ATTRIBUTE                   0x05
//id пакета
#define DATA                        0x01
#define SETTINGS_CAM                0x02
#define STATUS_BRAKE                0x03
#define SETTINGS_AUTO_BRAKE         0x04
#define SET_TIMEOUT                 0x05
#define GET_TIMEOUT                 0x06
#define GET_HW_STATE                0x07
#define RUN_TEST_HW                 0x08
#define STATUS_TEST_HW              0x09
#define GET_AUTO_BRAKE_STATE        0x0A
//статусы ответа на сообщение
#define ERROR_OK                    0x00
#define ERROR_NOK                   0x01
#define ERROR_CRC                   0x02
#define ERROR_WRONG_PARAM           0x03
#define ERROR_WRONG_OPERATION       0x04
//статусы выполнения ФУ
#define SUCCESSFUL_EXECUTION_FU     0x00
#define BAD_STARTING_CONDITIONS     0x01
#define BRAKE_NOT_HIT_STARTING_POS  0x02
#define BRAKE_NOT_REQUIRED_POS      0x03
#define AUTO_BRAKE_DONE             0x04
//статусы педали
#define POS_PEDAL_0                 0x00
#define POS_PEDAL_1                 0x02
#define POS_PEDAL_2                 0x04
#define POS_PEDAL_3                 0x08
#define POS_PEDAL_4                 0x10
//статусы самотеста
#define TEST_STATUS_OK              0
#define PEDAL_NOT_POS_0             1
#define PEDAL_NOT_POS_1             2
#define PEDAL_NOT_POS_2             3
#define PEDAL_NOT_POS_3             4
#define PEDAL_NOT_POS_4             5
#define PEDAL_NOT_READY             6

class Protocol : public QObject
{
    Q_OBJECT

private:

    struct Header
    {
        char dst_id;
        char sou_id;
        short operation;
        int frame_num;
        short data_length;
        short error_code;
    }pkt_header;

private:
    QIODevice * device;
    QByteArray rxBuffer;

public:
    explicit Protocol(QIODevice * dev);
    ~Protocol();

    bool send_msg(short operation, QByteArray data = QByteArray());


    bool sendPacket(short operation,
                    QByteArray data = QByteArray());
private:
    bool parsePacket(QByteArray * rawPkt);
    bool waitResponse(int timeout = 1000);
signals:

    void responseReady();
    void errorOccured(QString e);
    void set_timeout(uint32_t * data);
    void HW_redy();
    void signal_auto_brake_done();
    void set_auto_brake_state(uint32_t data);
public slots:

private slots:
    void dataHandler();
    void slot_parsePacket();
};

#endif // PROTOCOL_H

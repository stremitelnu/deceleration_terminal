#include "protocol.h"

//------------------------------------------------------------------------------
// Конструктор
//------------------------------------------------------------------------------
Protocol::Protocol(QIODevice *dev) : QObject(),
    device(dev)
{
    pkt_header={0x00,0x00,0x00,0x00,0x00,0x00};
    //Прием данных
    connect(dev, SIGNAL(readyRead()), SLOT(dataHandler()));
    connect(dev,SIGNAL(readyRead()),SLOT(slot_parsePacket()));
}

//------------------------------------------------------------------------------
// Деструктор
//------------------------------------------------------------------------------
Protocol::~Protocol()
{
    if(device->isOpen())
    {
        device->close();
    }
}

//*****************************************************************************
// Вычисление контрольной суммы
//*****************************************************************************
static qint16 calc_sum(QByteArray data, qint16 count)
{

 qint16 sum1 = 0;
 qint16 sum2 = 0;
 qint16 index;

 for (index = 0; index < count; index++){
  sum1 = (sum1 + (quint8) data[index]) % 255;
  sum2 = (sum2 + sum1) % 255;
 }

 return (sum2 << 8) | sum1;
}

//------------------------------------------------------------------------------
// Посылка пакета
//------------------------------------------------------------------------------
bool Protocol::send_msg(short operation,QByteArray data)
{

    if(!sendPacket(operation,data))
    {
        return false;
    }

    if(!waitResponse())
    {
        emit errorOccured(tr("Устройство не ответило на запрос"));
        return false;
    }
    else if(!parsePacket(&rxBuffer))
         {
            return false;
         }


    return true;
}


//------------------------------------------------------------------------------
// Отправка пакета
//------------------------------------------------------------------------------
bool Protocol::sendPacket(short operation,
                          QByteArray data)
{
    if(!device->isOpen())
    {
        if(!device->open(QIODevice::ReadWrite))
        {
            emit errorOccured(tr("Нет доступа к устройству"));
            return false;
        }
    }

    ushort Crc=0;
    QByteArray pkt;
    QByteArray newData;

    //Начало пакета
    pkt.append(PREAMBLE);
    pkt.append(START_OF_PACKET);

    //заголовок
    pkt_header.operation=operation;
    pkt_header.data_length=data.length();
    pkt_header.frame_num++;

    QByteArray header((char *)&pkt_header,sizeof(Header));
    //Контрольная сумма
    Crc=calc_sum(header, header.length());
    Crc ^=calc_sum(data, data.length());
    for(int i =0;i<header.length();i++)
    {
        if((quint8)header.at(i)==PREAMBLE)
        {
            pkt.append(PREAMBLE);
            pkt.append(ATTRIBUTE);
        }
        else
        {
            pkt.append(header.at(i));
        }
    }

    //Начало данных
    pkt.append(PREAMBLE);
    pkt.append(START_OF_DATA);
    //Данные
    for(int i = 0; i < data.length(); i++)
    {
        quint8 ch = (quint8)data.at(i);

        if(ch == PREAMBLE)
        {
            newData.append(PREAMBLE);
            newData.append(ATTRIBUTE);
        }
        else
        {
            newData.append((char)ch);
        }
    }
    pkt.append(newData);
    //признак CRC
    pkt.append(PREAMBLE);
    pkt.append(CHECKSUM_CODE);

    QByteArray pkt_crc((char *)&Crc,sizeof(ushort));
    for(int i=0;i<pkt_crc.length();i++)
    {
      if((quint8)pkt_crc.at(i)==PREAMBLE)
      {
          pkt.append(PREAMBLE);
          pkt.append(ATTRIBUTE);
      }
      else
      {
        pkt.append(pkt_crc.at(i));
      }
    }

    //Конец пакета
    pkt.append(PREAMBLE);
    pkt.append(END_OF_PACKET);

    //Отправка
    qint64 i = device->write(pkt);

    if(i == -1 || i < pkt.length())
    {
        emit errorOccured(tr("Запрос не был отправлен"));
        return false;
    }

    return true;
}



//------------------------------------------------------------------------------
// Дождаться ответа от устройства
//------------------------------------------------------------------------------
bool Protocol::waitResponse(int timeout)
{
    bool result;
    QEventLoop loop;
    QTimer timer;

    timer.setSingleShot(true);
    connect(this, SIGNAL(responseReady()), &loop, SLOT(quit()));
    connect(&timer,SIGNAL(timeout()),&loop,SLOT(quit()));
    timer.start(timeout);

    loop.exec();

    result=timer.isActive()?true:false;
    //timer.stop();

    return result;
}
//------------------------------------------------------------------------------
// Разбор принятого пакета
//------------------------------------------------------------------------------
bool Protocol::parsePacket(QByteArray * rawPkt)
{
    QByteArray tx_header;
    QByteArray tx_data;
    QByteArray tx_Crc;
    Header * tx_pkt_header;
    quint64 sizeOfPacket = rawPkt->length();
    ushort crc_calc=0;
    ushort crc;

    //проверка на дополнение a505
    for(uint i=0;i<sizeOfPacket;i++)
    {
        if(((quint8)rawPkt->at(i)==PREAMBLE)&&(((quint8)rawPkt->at(i+1)==START_OF_PACKET)))
        {//заголовок
            i+=2;
            while(1)
            {
                if(((quint8)rawPkt->at(i)==PREAMBLE)&&(((quint8)rawPkt->at(i+1)==START_OF_DATA)))
                {
                   break;
                }
                if(((quint8)rawPkt->at(i)==PREAMBLE)&&(((quint8)rawPkt->at(i+1)==ATTRIBUTE)))
                {
                   tx_header.append(rawPkt->at(i));
                   i++;
                }
                else
                {
                    tx_header.append(rawPkt->at(i));
                }
                i++;
            }
        }
        if(((quint8)rawPkt->at(i)==PREAMBLE)&&(((quint8)rawPkt->at(i+1)==START_OF_DATA)))
        {//данные
            i+=2;
            while(1)
            {
                if(((quint8)rawPkt->at(i)==PREAMBLE)&&(((quint8)rawPkt->at(i+1)==CHECKSUM_CODE)))
                {
                    break;
                }
                if(((quint8)rawPkt->at(i)==PREAMBLE)&&(((quint8)rawPkt->at(i+1)==ATTRIBUTE)))
                {
                   tx_data.append(rawPkt->at(i));
                   i++;
                }
                else
                {
                    tx_data.append(rawPkt->at(i));
                }
                i++;
            }
        }
        if(((quint8)rawPkt->at(i)==PREAMBLE)&&(((quint8)rawPkt->at(i+1)==CHECKSUM_CODE)))
        {//crc
            i+=2;
            while(((quint8)rawPkt->at(i)!=PREAMBLE)&&(((quint8)rawPkt->at(i+1)!=END_OF_PACKET)))
            {
                if(((quint8)rawPkt->at(i)==PREAMBLE)&&(((quint8)rawPkt->at(i+1)==END_OF_PACKET)))
                {
                  break;
                }
                if(((quint8)rawPkt->at(i)==PREAMBLE)&&(((quint8)rawPkt->at(i+1)==ATTRIBUTE)))
                {
                   tx_Crc.append(rawPkt->at(i));
                   i++;
                }
                else
                {
                    tx_Crc.append(rawPkt->at(i));
                }
                i++;
            }
        }

    }

    tx_pkt_header=(Header *)tx_header.data();
    crc=((uchar)tx_Crc.at(1)<<8)|((uchar)tx_Crc.at(0));
    crc_calc=calc_sum(tx_header, tx_header.length());
    crc_calc ^=calc_sum(tx_data,tx_pkt_header->data_length);

    //Некорректный пакет
    if(crc != crc_calc)
    {
        emit errorOccured(tr("Некорректное CRC"));
        return false;
    }



    if(tx_pkt_header->frame_num!=pkt_header.frame_num)
    {
        emit errorOccured(tr("Пришел ответ с неверным номером"));
        return false;
    }

    switch (tx_pkt_header->operation) {
    case DATA:
    case SETTINGS_CAM:
    case SET_TIMEOUT:
    case RUN_TEST_HW:
        switch (tx_pkt_header->error_code) {
        case ERROR_OK:
                emit errorOccured(tr("Статус OK"));
                return false;
            break;
        case ERROR_NOK:
                //emit errorOccured(tr("Некорректное CRC при отправке"));
                //return false;
            break;
        case ERROR_CRC:
                emit errorOccured(tr("Некорректное CRC при отправке"));
                return false;
            break;
        case ERROR_WRONG_OPERATION:
                emit errorOccured(tr("Задан некорректный код операции"));
                return false;
            break;
        case ERROR_WRONG_PARAM:
                emit errorOccured(tr("Заданны некорректные параметры"));
                return false;
            break;
        default:
            break;
        }
        break;
    case STATUS_BRAKE:
        if(tx_data.at(0)==AUTO_BRAKE_DONE)
         {
             emit signal_auto_brake_done();
         }
        switch (tx_pkt_header->error_code)
        {
         case SUCCESSFUL_EXECUTION_FU:
                emit errorOccured(tr("Успешное исполнение команды ФУ"));
                return false;
            break;
         case BAD_STARTING_CONDITIONS:
                emit errorOccured(tr("Педаль не в стартовой позиции"));
                return false;
            break;
         case BRAKE_NOT_HIT_STARTING_POS:
                emit errorOccured(tr("Педаль не попала в стартовую позицию"));
                return false;
            break;
         case BRAKE_NOT_REQUIRED_POS:
                emit errorOccured(tr("Педаль не попала в заданную позицию"));
                return false;
            break;
        //case AUTO_BRAKE_DONE:
         //      emit errorOccured(tr("Выполненно автоматическое торможение"));
          //     emit signal_auto_brake_done();
           //    return false;
           //break;
         default:
            break;
        }
        break;
     case GET_TIMEOUT:{
                       uint32_t * timeout;
                       timeout=(uint32_t *)tx_data.data();
                        //emit errorOccured(tr("Полученно сообщение Timeout"));
                       emit set_timeout(timeout);
                       return false;
                       }

        break;
    case GET_HW_STATE:

            switch (tx_pkt_header->error_code)
            {
             case POS_PEDAL_0:
                emit HW_redy();
                emit errorOccured(tr("Сигналы с датчиков в норме,система готова к работе"));
                return false;
                break;
             case POS_PEDAL_1:
                emit errorOccured(tr("Система не готова к работе,педаль в 1 позиции"));
                return false;
                break;
            case POS_PEDAL_2:
                emit errorOccured(tr("Система не готова к работе,педаль во 2 позиции"));
                return false;
               break;
            case POS_PEDAL_3:
                emit errorOccured(tr("Система не готова к работе,педаль в 3 позиции"));
                return false;
               break;
            case POS_PEDAL_4:
                emit errorOccured(tr("Система не готова к работе,педаль в 4 позиции"));
                return false;
               break;
             default:
                emit errorOccured(tr("Система не готова к работе,неизвестная позиция датчиков"));
                return false;
                break;
            }

       break;
    case STATUS_TEST_HW:
        switch (tx_pkt_header->error_code)
        {
        case TEST_STATUS_OK:
            emit errorOccured(tr("Тест завершен успешно"));
            return false;
            break;
        case PEDAL_NOT_POS_0:
            emit errorOccured(tr("Педаль не находится в нулевом положени"));
            return false;
            break;
        case PEDAL_NOT_POS_1:
            emit errorOccured(tr("Педаль не попала в позицию 1"));
            return false;
            break;
        case PEDAL_NOT_POS_2:
            emit errorOccured(tr("Педаль не попала в позицию 2"));
            return false;
            break;
        case PEDAL_NOT_POS_3:
            emit errorOccured(tr("Педаль не попала в позицию 3"));
            return false;
            break;
        case PEDAL_NOT_POS_4:
            emit errorOccured(tr("Педаль не попала в позицию 4"));
            return false;
            break;
        case PEDAL_NOT_READY:
            emit errorOccured(tr("Педаль не вернулась в нулевую позицию"));
            return false;
            break;
        default:
            break;
        }

       break;
     case GET_AUTO_BRAKE_STATE:
        emit set_auto_brake_state(tx_pkt_header->error_code);
        break;
    default:
        break;
    }



    return true;
}

//------------------------------------------------------------------------------
// Обработчик принятых данных от устройства
//------------------------------------------------------------------------------
void Protocol::dataHandler()
{
    static bool fullPktReceived = false;
    int pktSize = 0;

    if(device->bytesAvailable() > 0)
    {
        if(fullPktReceived)
        {
            rxBuffer.clear();
            fullPktReceived = false;
        }

        //Добавляем принятых данные в буфер
        rxBuffer.append(device->readAll());
        pktSize = rxBuffer.length();


        //Проверка наличия начала и конца пакета
        if((quint8)rxBuffer.at(0) == PREAMBLE &&
           (quint8)rxBuffer.at(1) == START_OF_PACKET &&
           (quint8)rxBuffer.at(pktSize - 2) == PREAMBLE &&
           (quint8)rxBuffer.at(pktSize - 1) == END_OF_PACKET)
        {
            fullPktReceived = true;
            emit responseReady();
        }
    }
}

void Protocol::slot_parsePacket()
{
    parsePacket(&rxBuffer);
}


#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include "commondefine.h"
#include "writeregistermodel.h"

#include <QDialog>
#include <QModbusClient>
#include <QModbusReply>
#include <QSerialPort>
#include <QTimer>
#include <QModbusDataUnit>


struct RegisterData
{
    quint16  regAddr;  //寄存器地址
    quint16  regValue; //寄存器值
};

namespace Ui {
class MySerialPort;
}

class MySerialPort : public QDialog
{
    Q_OBJECT

public:
    explicit MySerialPort(QWidget *parent = nullptr);
    ~MySerialPort();

private:
    void initWin();

    QModbusDataUnit readRequest() const;
    QModbusDataUnit writeRequest() const;


signals:
    void sig_readRegister(QList<RegisterData> regValueList);

public slots:

    void on_btnConnect_clicked();
    void readReady();
    void onStateChanged(int state);
    void slot_writeRegister(SignalProtocolParam param, QList<quint16> regValueList);
    void slot_readRegister(quint16 startAddr, QList<quint16> regValueList);
    void slot_clearLabelInfo();
    void on_btnClear_clicked();
private:

    Ui::MySerialPort *ui;
    QModbusReply *m_lastRequest=nullptr;
    QModbusClient *m_modbusDevice=nullptr;
    WriteRegisterModel *writeModel;
    SignalProtocolParam   m_protocolParam;


};

#endif // MYSERIALPORT_H

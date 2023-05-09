#include "myserialport.h"
#include "ui_myserialport.h"

#include <QSerialPortInfo>
#include <QDebug>
#include <QModbusRtuSerialMaster>
#include <QLoggingCategory>
#include <QTimer>
MySerialPort::MySerialPort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MySerialPort)
{
    ui->setupUi(this);
    initWin();

}

MySerialPort::~MySerialPort()
{
    if (m_modbusDevice)
        m_modbusDevice->disconnectDevice();
    delete m_modbusDevice;
    delete ui;
}

void MySerialPort::initWin()
{
    //查找可用的串口
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comboBox_port->addItem(info.portName());
    }

    //波特率9600、19200、38400、43000、56000、57600、115200
     ui->comboBox_baud->addItem("9600");
     ui->comboBox_baud->addItem("19200");
     ui->comboBox_baud->addItem("38400");
     ui->comboBox_baud->addItem("57600");
     ui->comboBox_baud->addItem("115200");
     ui->comboBox_baud->setCurrentIndex(4);


     //数据位
     ui->comboBox_dataBit->addItem("5");
     ui->comboBox_dataBit->addItem("6");
     ui->comboBox_dataBit->addItem("7");
     ui->comboBox_dataBit->addItem("8");
     ui->comboBox_dataBit->setCurrentIndex(3);

     //停止位
     ui->comboBox_stopBit->addItem("1");
     ui->comboBox_stopBit->addItem("2");
     ui->comboBox_stopBit->setCurrentIndex(0);


     //校验位
     ui->comboBox_parityBit->addItem("None");
     ui->comboBox_parityBit->addItem("Odd");
     ui->comboBox_parityBit->addItem("Even");
     ui->comboBox_parityBit->addItem("Mark");
     ui->comboBox_parityBit->addItem("Space");
     ui->comboBox_parityBit->setCurrentIndex(0);

     //控制流
     ui->comboBox_flowControl->addItem("HardWare");
     ui->comboBox_flowControl->addItem("SoftWare");
     ui->comboBox_flowControl->addItem("None");
     ui->comboBox_flowControl->setCurrentIndex(2);

     if (m_modbusDevice)
     {
         m_modbusDevice->disconnectDevice();
         delete m_modbusDevice;
         m_modbusDevice = nullptr;
     }


     m_modbusDevice = new QModbusRtuSerialMaster(this);

     if (!m_modbusDevice)
     {
        ui->label_info->setText("创建Modbus失败");
        QTimer::singleShot(5000,this,&slot_clearLabelInfo);
     }
     else
     {
         connect(m_modbusDevice, &QModbusClient::stateChanged, this, &MySerialPort::onStateChanged);
     }

}

void MySerialPort::onStateChanged(int state)
{
    bool connected = (state != QModbusDevice::UnconnectedState);

    if (state == QModbusDevice::UnconnectedState)
        ui->btnConnect->setText(tr("连接"));
    else if (state == QModbusDevice::ConnectedState)
        ui->btnConnect->setText(tr("断开连接"));
}

void MySerialPort::slot_writeRegister(SignalProtocolParam param, QList<quint16> regValueList)
{
    if (!m_modbusDevice)
        return;
    ui->readValue->clear();
    m_protocolParam = param;

    QModbusDataUnit writeUnit = writeRequest();
    QModbusDataUnit::RegisterType table = writeUnit.registerType();
    for (uint i = 0; i < regValueList.size(); i++)
    {
        if (table == QModbusDataUnit::HoldingRegisters)
        {
            writeUnit.setValue(i, regValueList.at(i));
        }
    }

    if (auto *reply = m_modbusDevice->sendReadWriteRequest(readRequest(), writeUnit,
        m_protocolParam.uServerAddr)) {

        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, &MySerialPort::readReady);
        }
        else
        {
            delete reply; // broadcast replies return immediately
        }
    } else
    {
        ui->label_info->setText(tr("Read response error"));
        QTimer::singleShot(5000,this,&slot_clearLabelInfo);
    }
}

void MySerialPort::slot_readRegister(quint16 startAddr, QList<quint16> regValueList)
{
    if (!m_modbusDevice)
        return;
    ui->readValue->clear();


    if (auto *reply = m_modbusDevice->sendReadRequest(readRequest(), m_protocolParam.uServerAddr))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, &MySerialPort::readReady);
        }
        else
            delete reply; // broadcast replies return immediately
    } else
    {
          ui->label_info->setText(m_modbusDevice->errorString());
          QTimer::singleShot(5000,this,&slot_clearLabelInfo);
    }
}

void MySerialPort::slot_clearLabelInfo()
{
    ui->label_info->clear();
}

void MySerialPort::on_btnClear_clicked()
{
    ui->readValue->clear();
}

void MySerialPort::on_btnConnect_clicked()
{
    if (!m_modbusDevice)
        return;

    ui->label_info->clear();

    QString strPortName = ui->comboBox_port->currentText();	//端口
    QString strBaud = ui->comboBox_baud->currentText();	//波特率
    QString strDataBit = ui->comboBox_dataBit->currentText();	//数据位
    QString strStopBit = ui->comboBox_stopBit->currentText();	//停止位
    QString strParityBit = ui->comboBox_parityBit->currentText();	//校验位
    QString strFlowControl = ui->comboBox_flowControl->currentText();	//控制流


    int setBaud = strBaud.toInt();	//波特率
    QSerialPort::DataBits setDataBits;	//数据位
    QSerialPort::StopBits setStopBits;	//停止位
    QSerialPort::Parity setParityBits;	//校验位
    QSerialPort::FlowControl setFlowControl;//控制流

    if(strDataBit == "5")
    {
        setDataBits = QSerialPort::Data5;
    }else if(strDataBit == "6")
    {
        setDataBits = QSerialPort::Data6;
    }else if(strDataBit == "7")
    {
        setDataBits = QSerialPort::Data7;
    }else{
        setDataBits = QSerialPort::Data8;
    }

    if(strStopBit == "1")
    {
        setStopBits = QSerialPort::OneStop;
    }else if(strStopBit == "2"){
        setStopBits = QSerialPort::TwoStop;
    }else{
        setStopBits = QSerialPort::OneAndHalfStop;
    }

    if(strParityBit == "None")
    {
        setParityBits = QSerialPort::NoParity;
    }else if(strParityBit == "Odd"){
        setParityBits = QSerialPort::OddParity;
    }else if(strParityBit == "Even"){
        setParityBits = QSerialPort::EvenParity;
    }else if(strParityBit == "Mark"){
        setParityBits = QSerialPort::MarkParity;
    }else /*if(parityBits == "Space")*/{
        setParityBits = QSerialPort::SpaceParity;
    }

    if(strFlowControl == "HardWare"){
        setFlowControl = QSerialPort::HardwareControl;
    }else if(strFlowControl == "SoftWare"){
        setFlowControl = QSerialPort::SoftwareControl;
    }else /*if(flowControl == "None")*/{
        setFlowControl = QSerialPort::NoFlowControl;
    }

    if (m_modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        m_modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,strPortName);
        m_modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,setParityBits);
        m_modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,setBaud);
        m_modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,setDataBits);
        m_modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,setStopBits);

        m_modbusDevice->setTimeout(ui->lineEdit_timeout->text().toInt());
        m_modbusDevice->setNumberOfRetries(ui->lineEdit_retry->text().toInt());
        if (!m_modbusDevice->connectDevice())
        {
            ui->label_info->setText("连接失败");
            QTimer::singleShot(5000,this,&slot_clearLabelInfo);
        }
        else
        {
            ui->label_info->setText("连接成功");
            QTimer::singleShot(5000,this,&slot_clearLabelInfo);
        }
    } else
    {
        m_modbusDevice->disconnectDevice();
    }
}



void MySerialPort::readReady()
{
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;


    if (reply->error() == QModbusDevice::NoError) {

        const QModbusDataUnit unit = reply->result();
        QList<RegisterData>  mDataList;
        for (uint i = 0; i < unit.valueCount(); i++) {
            const QString entry = tr("Address: %1, Value: 0x%2").arg(unit.startAddress() + i)
                                     .arg(QString::number(unit.value(i),
                                          unit.registerType() <= QModbusDataUnit::Coils ? 10 : 16));
            ui->readValue->addItem(entry);

            RegisterData mData;
            mData.regAddr = unit.startAddress() +i;
            mData.regValue = unit.value(i);
            mDataList.append(mData);
        }
        emit sig_readRegister(mDataList);
    } else if (reply->error() == QModbusDevice::ProtocolError) {
        ui->label_info->setText(tr("Read response error: %1 (Mobus exception: 0x%2)").
                                    arg(reply->errorString()).
                                    arg(reply->rawResult().exceptionCode(), -1, 16));
        QTimer::singleShot(5000,this,&slot_clearLabelInfo);
    } else {
        ui->label_info->setText(tr("Read response error: %1 (code: 0x%2)").
                                    arg(reply->errorString()).
                                    arg(reply->error(), -1, 16));
        QTimer::singleShot(5000,this,&slot_clearLabelInfo);
    }

    reply->deleteLater();
}



QModbusDataUnit MySerialPort::readRequest() const
{

    int startAddress =m_protocolParam.uReadStartAddr;
    int numberOfEntries = m_protocolParam.iReadRegCounts;
    return QModbusDataUnit(QModbusDataUnit::HoldingRegisters, startAddress, numberOfEntries);
}

QModbusDataUnit MySerialPort::writeRequest() const
{
    int startAddress =m_protocolParam.uWriteStartAddr;
    int numberOfEntries = m_protocolParam.iWriteRegCounts;
    return QModbusDataUnit(QModbusDataUnit::HoldingRegisters, startAddress, numberOfEntries);
}

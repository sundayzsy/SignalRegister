#include "protocoljson.h"
#include <QFile>
#include <QApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QDebug>

ProtocolJson::ProtocolJson(QObject *parent) : QObject(parent)
{
    resetData();
}

void ProtocolJson::loadJson(const EnumJsonFile param)
{
    QString configPath = "";
    switch(param)
    {
        case Enum_Protocol_221: configPath = qApp->applicationDirPath() + "/../config/Protocol_221.json";break;
        case Enum_Protocol_222: configPath = qApp->applicationDirPath() + "/../config/Protocol_222.json";break;
        case Enum_Protocol_223: configPath = qApp->applicationDirPath() + "/../config/Protocol_223.json";break;
        case Enum_Protocol_224: configPath = qApp->applicationDirPath() + "/../config/Protocol_224.json";break;
        default: configPath = qApp->applicationDirPath() + "/../config/Protocol_221.json";break;
    }

    QFile file(configPath);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "File open error";
        return;
    }

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &parseError);
    if(parseError.error != QJsonParseError::NoError)
    {
        qDebug() << "Json parse error";
        return;
    }
    if(doc.isObject())
    {
        resetData();
        QJsonObject rootObj = doc.object();
        m_serverAddress = rootObj.value("ServerAddress").toString().toUInt();
        m_readStartAddress = rootObj.value("ReadStartAddress").toString().toUInt();
        m_writeStartAddress = rootObj.value("WriteStartAddress").toString().toUInt();
        m_functionCode = rootObj.value("FunctionCode").toString().toUInt();

        QJsonArray signalArray = rootObj.value("SignalArray").toArray();
        m_allSignalCounts = signalArray.size();
        for(int i = 0; i < signalArray.size(); i++)
        {
            QJsonObject obj = signalArray.at(i).toObject();
            QString paramName = obj.value("ParamName").toString();                  //参数名称
            QString type = obj.value("Type").toString();                            //参数类型
            QString decs = obj.value("Desc").toString();                            //参数描述
            quint8 serverAddr = obj.value("ServerAddr").toString().toUInt();        //从站地址
            quint16 registerAddr = obj.value("RegisterAddr").toString().toUInt();   //寄存器地址
            quint8 bitPos = obj.value("BitPos").toString().toUInt();                //BIT位
            quint8 length = obj.value("Length").toString().toUInt();                //数据BIT位长度

            SignalParameter signalParam;
            signalParam.strParamName = paramName;
            signalParam.strType = type;
            signalParam.strDesc = decs;
            signalParam.uServerAddr = serverAddr;
            signalParam.uRegisterAddr = registerAddr;
            signalParam.uBitPos = bitPos;
            signalParam.uLength = length;
            signalParam.uValue = 0;
            signalParam.uUIIndex = 0;

            if(m_dataMap.find(registerAddr) != m_dataMap.end())
            {
                m_dataMap[registerAddr].append(signalParam);
            }
            else
            {
                if(registerAddr >=0 && registerAddr < 500)
                {
                    m_readRegisterCounts += 1;
                }

                if(registerAddr >= 500)
                {
                    m_writeRegisterCounts += 1;
                }
                QList<SignalParameter> list;
                list.append(signalParam);
                m_dataMap.insert(registerAddr,list);
            }
        }
    }

    file.close();
}

QMap<quint16, QList<SignalParameter> > ProtocolJson::getDataMap()
{
    return m_dataMap;
}

int ProtocolJson::getReadRegisterCounts()
{
//    m_readRegisterCounts = 21;
    return m_readRegisterCounts;
}

int ProtocolJson::getWriteRegisterCounts()
{
    return m_writeRegisterCounts;
}

int ProtocolJson::getAllSignalCounts()
{
    return m_allSignalCounts;
}

quint16 ProtocolJson::getServerAddress()
{
    return m_serverAddress;
}

quint16 ProtocolJson::getReadStartAddress()
{
    return m_readStartAddress;
}

quint16 ProtocolJson::getWriteStartAddress()
{
    return m_writeStartAddress;
}

quint8 ProtocolJson::getFunctionCode()
{
    return m_functionCode;
}

void ProtocolJson::saveJson()
{
    QString configPath = qApp->applicationDirPath() + "/config/Protocol_221.json";
    QFile file(configPath);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "File open error";
        return;
    }
    file.resize(0);

    QJsonDocument doc;
    QJsonObject rootObj;
    QJsonArray signalArray;

    for(int row = 0; row < 80; row++)
    {
        QJsonObject signalObj;
        QString  strParamName = "";     //参数名称
        QString  strType = "";          //参数类型
        QString  strDesc = "";          //参数描述
        quint16  uServerAddr = 221;      //从站地址
        quint16  uRegisterAddr = 0;    //寄存器地址
        quint16  uBitPos = 0;          //BIT位
        quint16  uLength = 1;          //数据BIT位长度

        signalObj.insert("ParamName",strParamName);
        signalObj.insert("Type",strType);
        signalObj.insert("Desc",strDesc);
        signalObj.insert("ServerAddr",uServerAddr);
        signalObj.insert("RegisterAddr",uRegisterAddr);
        signalObj.insert("BitPos",uBitPos);
        signalObj.insert("Length",uLength);

        signalArray.insert(row,signalObj);
    }

    rootObj.insert("SignalArray",signalArray);
    rootObj.insert("ReadStartAddress","0");
    rootObj.insert("WriteStartAddress","500");
    rootObj.insert("ReadCounts","15");
    rootObj.insert("WriteCounts","2");
    rootObj.insert("FunctionCode","23");
    rootObj.insert("ServerAddress","221");

    doc.setObject(rootObj);
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
}

void ProtocolJson::resetData()
{
    m_dataMap.clear();
    m_readRegisterCounts = 0;
    m_writeRegisterCounts = 0;
    m_allSignalCounts = 0;
    m_serverAddress = 0;
    m_readStartAddress = 0;
    m_writeStartAddress = 0;
    m_functionCode = 0;
}

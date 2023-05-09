#ifndef COMMONDEFINE_H
#define COMMONDEFINE_H
#include <QString>


//通讯协议参数
struct  SignalProtocolParam
{
    int iReadRegCounts;                  //读寄存器个数
    int iWriteRegCounts;                 //写寄存器个数
    quint16 uServerAddr;                 //服务器地址
    quint16 uReadStartAddr;              //读寄存器开始地址
    quint16 uWriteStartAddr;              //写寄存器开始地址
    quint8  uFunctionCode;               //功能码 0x17
};

struct SignalParameter
{
    quint16  uUIIndex;                   //记录控件m_labelNameList,m_labeDescList,m_editParamList序号
    QString  strParamName;               //参数名称
    QString  strType;                    //参数类型
    QString  strDesc;                    //参数描述
    quint16  uServerAddr;                //从站地址
    quint16  uRegisterAddr;              //寄存器地址
    quint16  uBitPos;                    //BIT位
    quint16  uLength;                    //数据BIT位长度
    quint16  uValue;                     //参数数值
};

#endif // COMMONDEFINE_H

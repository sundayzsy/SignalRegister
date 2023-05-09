#ifndef SIGNALBOXDLG_H
#define SIGNALBOXDLG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMap>
#include <myserialport.h>
//信号参数结构
#include "commondefine.h"
#include "protocoljson.h"

namespace Ui {
class SignalBoxDlg;
}

class SignalBoxDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SignalBoxDlg(QWidget *parent = nullptr);
    ~SignalBoxDlg();
private:
    void initData();
    void setWidgetObjectName();
    void setSignalParamList(int iBoxNum);
    //从寄存器值中，获取指定位置，长度的值  regValue:寄存器读取的值   valuePos:需求获取值的起始位置， valueSize:获取值的长度,输出:参数值
    bool getParamValue(quint16 regValue, quint16 valuePos, quint16 valueSize, quint16 &parmValue);


    //设置寄存器某位置的数值  oldRegValue:寄存器读取的值   valuePos:需求获取值的起始位置， valueSize:获取值的长度  setValue:设置的值
    //输出newRegValue:新的寄存器值
    bool setParamValue(quint16 oldRegValue, quint16 valuePos, quint16 valueSize, quint16 setValue, quint16 &newRegValue);


    //输入写寄存器开始地址，根据参数设置，返回写到寄存器的值列表
    QList<quint16> getRegValues(quint16 qStartAddr, quint8 iRegCount);


    //根据寄存器值更新界面参数值 qRegAddr：寄存器地址  qRegValue：寄存器值
    void  updateParamValue(quint16 qRegAddr, quint16 qRegValue);

    //根据输入框的值，修改SignalParameter中的Value
    void  updateParamListValue();

    //输入参数编辑框在m_editParamList中的索引，在m_signalParamMap中查找，
    //找到后输出寄存器地址qRegAddr,   QList<SignalParameter>中对应的索引 qParamListIdx:
    bool querySignalParamByUIIndex(quint16 qIndex, quint16 &qRegAddr, quint16 &qParamListIdx);

    //根据配置文件，初始化信号窗口
    void initSignalWin();

    //按2进制打印数值
    void printValue2Bin(quint16 qValue);

public slots:
    void on_btnSingalBox1_clicked();
    void on_btnSingalBox2_clicked();
    void on_btnSingalBox3_clicked();
    void on_btnSingalBox4_clicked();
    void on_btnWrite_clicked();
    void on_btnCycle_clicked();
    void slot_signaleBox_readRegister(QList<RegisterData> regValueList);

signals:
    void sig_signaleBox_writeRegister(SignalProtocolParam param, QList<quint16> regValueList);
private:
    Ui::SignalBoxDlg *ui;

    QList<QLabel*> m_labelNameList;  //保存label_name
    QList<QLineEdit*> m_editParamList; //保存lineEdit_param
    //保存参数Map Key:寄存器地址 QList<SignalParameter>寄存器下对应的参数列表
    QMap<quint16, QList<SignalParameter>> m_signalParamMap;
    ProtocolJson m_jsonFile;
    SignalProtocolParam m_protocolParam;  //协议参数

    QTimer m_timer;
};

#endif // SIGNALBOXDLG_H

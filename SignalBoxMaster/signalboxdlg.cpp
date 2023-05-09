#include "signalboxdlg.h"
#include "ui_signalboxdlg.h"
#include <QDebug>
#include "math.h"
SignalBoxDlg::SignalBoxDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignalBoxDlg)
{
    ui->setupUi(this);

    setWidgetObjectName();
    on_btnSingalBox1_clicked();

    m_timer.setInterval(1000);
    connect(&m_timer,&QTimer::timeout,this,on_btnWrite_clicked);
}

SignalBoxDlg::~SignalBoxDlg()
{
    delete ui;
}

void SignalBoxDlg::initData()
{
    ui->label_name_85->setText("");
    ui->lineEdit_param_85->hide();
    for(int i=0; i<m_editParamList.size(); i++)
    {
        QLineEdit* pEdit = m_editParamList.at(i);
        if(pEdit)
        {
            pEdit->setText("0");
            pEdit->setMinimumWidth(60);
            pEdit->setMaximumWidth(60);
        }
    }
}

void SignalBoxDlg::setWidgetObjectName()
{
    ui->label_name_1->setObjectName("LABEL_NAME");
    ui->label_name_2->setObjectName("LABEL_NAME");
    ui->label_name_3->setObjectName("LABEL_NAME");
    ui->label_name_4->setObjectName("LABEL_NAME");
    ui->label_name_5->setObjectName("LABEL_NAME");
    ui->label_name_6->setObjectName("LABEL_NAME");
    ui->label_name_7->setObjectName("LABEL_NAME");
    ui->label_name_8->setObjectName("LABEL_NAME");
    ui->label_name_9->setObjectName("LABEL_NAME");
    ui->label_name_10->setObjectName("LABEL_NAME");


    ui->label_name_11->setObjectName("LABEL_NAME");
    ui->label_name_12->setObjectName("LABEL_NAME");
    ui->label_name_13->setObjectName("LABEL_NAME");
    ui->label_name_14->setObjectName("LABEL_NAME");
    ui->label_name_15->setObjectName("LABEL_NAME");
    ui->label_name_16->setObjectName("LABEL_NAME");
    ui->label_name_17->setObjectName("LABEL_NAME");
    ui->label_name_18->setObjectName("LABEL_NAME");
    ui->label_name_19->setObjectName("LABEL_NAME");
    ui->label_name_20->setObjectName("LABEL_NAME");


    ui->label_name_21->setObjectName("LABEL_NAME");
    ui->label_name_22->setObjectName("LABEL_NAME");
    ui->label_name_23->setObjectName("LABEL_NAME");
    ui->label_name_24->setObjectName("LABEL_NAME");
    ui->label_name_25->setObjectName("LABEL_NAME");
    ui->label_name_26->setObjectName("LABEL_NAME");
    ui->label_name_27->setObjectName("LABEL_NAME");
    ui->label_name_28->setObjectName("LABEL_NAME");
    ui->label_name_29->setObjectName("LABEL_NAME");
    ui->label_name_30->setObjectName("LABEL_NAME");


    ui->label_name_31->setObjectName("LABEL_NAME");
    ui->label_name_32->setObjectName("LABEL_NAME");
    ui->label_name_33->setObjectName("LABEL_NAME");
    ui->label_name_34->setObjectName("LABEL_NAME");
    ui->label_name_35->setObjectName("LABEL_NAME");
    ui->label_name_36->setObjectName("LABEL_NAME");
    ui->label_name_37->setObjectName("LABEL_NAME");
    ui->label_name_38->setObjectName("LABEL_NAME");
    ui->label_name_39->setObjectName("LABEL_NAME");
    ui->label_name_40->setObjectName("LABEL_NAME");

    ui->label_name_41->setObjectName("LABEL_NAME");
    ui->label_name_42->setObjectName("LABEL_NAME");
    ui->label_name_43->setObjectName("LABEL_NAME");
    ui->label_name_44->setObjectName("LABEL_NAME");
    ui->label_name_45->setObjectName("LABEL_NAME");
    ui->label_name_46->setObjectName("LABEL_NAME");
    ui->label_name_47->setObjectName("LABEL_NAME");
    ui->label_name_48->setObjectName("LABEL_NAME");
    ui->label_name_49->setObjectName("LABEL_NAME");
    ui->label_name_50->setObjectName("LABEL_NAME");

    ui->label_name_51->setObjectName("LABEL_NAME");
    ui->label_name_52->setObjectName("LABEL_NAME");
    ui->label_name_53->setObjectName("LABEL_NAME");
    ui->label_name_54->setObjectName("LABEL_NAME");
    ui->label_name_55->setObjectName("LABEL_NAME");
    ui->label_name_56->setObjectName("LABEL_NAME");
    ui->label_name_57->setObjectName("LABEL_NAME");
    ui->label_name_58->setObjectName("LABEL_NAME");
    ui->label_name_59->setObjectName("LABEL_NAME");
    ui->label_name_60->setObjectName("LABEL_NAME");

    ui->label_name_61->setObjectName("LABEL_NAME");
    ui->label_name_62->setObjectName("LABEL_NAME");
    ui->label_name_63->setObjectName("LABEL_NAME");
    ui->label_name_64->setObjectName("LABEL_NAME");
    ui->label_name_65->setObjectName("LABEL_NAME");
    ui->label_name_66->setObjectName("LABEL_NAME");
    ui->label_name_67->setObjectName("LABEL_NAME");
    ui->label_name_68->setObjectName("LABEL_NAME");
    ui->label_name_69->setObjectName("LABEL_NAME");
    ui->label_name_70->setObjectName("LABEL_NAME");

    ui->label_name_71->setObjectName("LABEL_NAME");
    ui->label_name_72->setObjectName("LABEL_NAME");
    ui->label_name_73->setObjectName("LABEL_NAME");
    ui->label_name_74->setObjectName("LABEL_NAME");
    ui->label_name_75->setObjectName("LABEL_NAME");
    ui->label_name_76->setObjectName("LABEL_NAME");
    ui->label_name_77->setObjectName("LABEL_NAME");
    ui->label_name_78->setObjectName("LABEL_NAME");
    ui->label_name_79->setObjectName("LABEL_NAME");
    ui->label_name_80->setObjectName("LABEL_NAME");

    ui->label_name_81->setObjectName("LABEL_NAME");
    ui->label_name_82->setObjectName("LABEL_NAME");
    ui->label_name_83->setObjectName("LABEL_NAME");
    ui->label_name_84->setObjectName("LABEL_NAME");
    ui->label_name_85->setObjectName("LABEL_NAME");


    ui->lineEdit_param_1->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_2->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_3->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_4->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_5->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_6->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_7->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_8->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_9->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_10->setObjectName("PARAM_EDIT");


    ui->lineEdit_param_11->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_12->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_13->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_14->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_15->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_16->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_17->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_18->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_19->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_20->setObjectName("PARAM_EDIT");


    ui->lineEdit_param_21->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_22->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_23->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_24->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_25->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_26->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_27->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_28->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_29->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_30->setObjectName("PARAM_EDIT");


    ui->lineEdit_param_31->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_32->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_33->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_34->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_35->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_36->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_37->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_38->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_39->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_40->setObjectName("PARAM_EDIT");

    ui->lineEdit_param_41->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_42->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_43->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_44->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_45->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_46->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_47->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_48->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_49->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_50->setObjectName("PARAM_EDIT");

    ui->lineEdit_param_51->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_52->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_53->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_54->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_55->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_56->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_57->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_58->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_59->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_60->setObjectName("PARAM_EDIT");

    ui->lineEdit_param_61->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_62->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_63->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_64->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_65->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_66->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_67->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_68->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_69->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_70->setObjectName("PARAM_EDIT");

    ui->lineEdit_param_71->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_72->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_73->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_74->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_75->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_76->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_77->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_78->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_79->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_80->setObjectName("PARAM_EDIT");

    ui->lineEdit_param_81->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_82->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_83->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_84->setObjectName("PARAM_EDIT");
    ui->lineEdit_param_85->setObjectName("PARAM_EDIT");

    m_labelNameList = this->findChildren<QLabel*>("LABEL_NAME");
    m_editParamList = this->findChildren<QLineEdit*>("PARAM_EDIT");
}

void SignalBoxDlg::setSignalParamList(int iBoxNum)
{
    switch (iBoxNum)
    {
        case 1:
            m_jsonFile.loadJson(Enum_Protocol_221);
            m_signalParamMap.clear();
            m_signalParamMap= m_jsonFile.getDataMap();
            m_protocolParam.iReadRegCounts = m_jsonFile.getReadRegisterCounts();
            m_protocolParam.iWriteRegCounts = m_jsonFile.getWriteRegisterCounts();
            m_protocolParam.uReadStartAddr = m_jsonFile.getReadStartAddress();
            m_protocolParam.uWriteStartAddr = m_jsonFile.getWriteStartAddress();
            m_protocolParam.uServerAddr = m_jsonFile.getServerAddress();
            m_protocolParam.uFunctionCode = m_jsonFile.getFunctionCode();
            break;
        case 2:
            m_jsonFile.loadJson(Enum_Protocol_222);
            m_signalParamMap.clear();
            m_signalParamMap= m_jsonFile.getDataMap();
            m_protocolParam.iReadRegCounts = m_jsonFile.getReadRegisterCounts();
            m_protocolParam.iWriteRegCounts = m_jsonFile.getWriteRegisterCounts();
            m_protocolParam.uReadStartAddr = m_jsonFile.getReadStartAddress();
            m_protocolParam.uWriteStartAddr = m_jsonFile.getWriteStartAddress();
            m_protocolParam.uServerAddr = m_jsonFile.getServerAddress();
            m_protocolParam.uFunctionCode = m_jsonFile.getFunctionCode();
            break;

        case 3:
            m_jsonFile.loadJson(Enum_Protocol_223);
            m_signalParamMap.clear();
            m_signalParamMap= m_jsonFile.getDataMap();
            m_protocolParam.iReadRegCounts = m_jsonFile.getReadRegisterCounts();
            m_protocolParam.iWriteRegCounts = m_jsonFile.getWriteRegisterCounts();
            m_protocolParam.uReadStartAddr = m_jsonFile.getReadStartAddress();
            m_protocolParam.uWriteStartAddr = m_jsonFile.getWriteStartAddress();
            m_protocolParam.uServerAddr = m_jsonFile.getServerAddress();
            m_protocolParam.uFunctionCode = m_jsonFile.getFunctionCode();
            break;

        case 4:
            m_jsonFile.loadJson( Enum_Protocol_224);
            m_signalParamMap.clear();
            m_signalParamMap= m_jsonFile.getDataMap();
            m_protocolParam.iReadRegCounts = m_jsonFile.getReadRegisterCounts();
            m_protocolParam.iWriteRegCounts = m_jsonFile.getWriteRegisterCounts();
            m_protocolParam.uReadStartAddr = m_jsonFile.getReadStartAddress();
            m_protocolParam.uWriteStartAddr = m_jsonFile.getWriteStartAddress();
            m_protocolParam.uServerAddr = m_jsonFile.getServerAddress();
            m_protocolParam.uFunctionCode = m_jsonFile.getFunctionCode();
            break;
        default:
            break;
    }

    initSignalWin();
}

bool SignalBoxDlg::getParamValue(quint16 regValue, quint16 valuePos, quint16 valueSize, quint16 &parmValue)
{
//    QString strRegValue = QString("%1").arg(regValue, 16, 2, QLatin1Char('0'));
//    QString strParam;

//    if((valuePos+valueSize)>16)
//    {
//        return false;
//    }

//    char chReg[17]={0};
//    strncpy(chReg,strRegValue.toStdString().c_str(), 16);

//    char chParam[17]={0};
//    QString strTmpParam = QString("%1").arg(0, 16, 2, QLatin1Char('0'));
//    strncpy(chParam, strTmpParam.toStdString().c_str(), 16);

//    int j=0;
//    int iStart = 15-valuePos;
//    for(int i=iStart; i<iStart+valueSize;i++)
//    {
//        chParam[15-j] = chReg[iStart-j];
//        j++;
//    }

//    strParam= QString(chParam);
//    bool bOk;
//    parmValue = strParam.toInt(&bOk, 2);
//    if(bOk) return true;
//    return false;

    if((valuePos+valueSize) > 16)
    {
        return false;
    }
    parmValue = (quint16)((regValue >> valuePos) & (0xFFFF >> (16-valueSize)));
    return true;
}

bool SignalBoxDlg::setParamValue(quint16 oldRegValue, quint16 valuePos, quint16 valueSize, quint16 setValue, quint16 &newRegValue)
{
//    //判断设置的值是否大于最大值，也就是2的valueSize次方
//    if(setValue >= pow(2, valueSize))
//    {
//        return false;
//    }

//    QString strRegValue = QString("%1").arg(oldRegValue, 16, 2, QLatin1Char('0'));
//    QString strParam =  QString("%1").arg(setValue, 16, 2, QLatin1Char('0'));

//    if((valuePos+valueSize)>16)
//    {
//        return false;
//    }

//    char chReg[17]={0};
//    strncpy(chReg,strRegValue.toStdString().c_str(), 16);

//    char chParam[17]={0};
//    strncpy(chParam,strParam.toStdString().c_str(), 16);

//    int j=0;
//    int iStart = 15-valuePos;
//    for(int i=iStart; i<iStart+valueSize;i++)
//    {
//        chReg[iStart-j] = chParam[15-j];
//        j++;
//    }

//    QString strNewReg = QString(chReg);
//    bool bOk;
//    newRegValue = strNewReg.toInt(&bOk, 2);
//    if(bOk) return true;
//    return false;


    //判断设置的值是否大于最大值，也就是2的valueSize次方
    if(setValue >= pow(2, valueSize))
    {
        return false;
    }
    if((valuePos+valueSize) > 16)
    {
        return false;
    }

    newRegValue = (quint16)((setValue << valuePos) | ( (0xFFFF<<(valuePos+valueSize) | 0xFFFF>>(16-valuePos)) & oldRegValue));
    return true;
}

QList<quint16> SignalBoxDlg::getRegValues(quint16 qStartAddr, quint8 iRegCount)
{
    int iOffsetAddr =qStartAddr; //偏移地址
    QList<quint16> regValuesList;
    for(int i=0; i<iRegCount; i++)
    {
        QMap<quint16, QList<SignalParameter>>::Iterator itr = m_signalParamMap.find(iOffsetAddr);
        if(itr != m_signalParamMap.end())
        {
            QList<SignalParameter> mList = itr.value();
            quint16 qRegValue=0x0;
            for(int j=0; j<mList.size();j++)
            {
                quint16 qPos = mList.at(j).uBitPos;
                quint16 qBitLen = mList.at(j).uLength;
                quint16 setValue=mList.at(j).uValue;
                quint16 qNewValue;
                setParamValue(qRegValue, qPos, qBitLen, setValue, qNewValue);
                qRegValue  = qNewValue;
//                printValue2Bin(qNewValue);
            }
            regValuesList.append(qRegValue);
        }
        iOffsetAddr++;
    }
    return regValuesList;

}

void SignalBoxDlg::updateParamValue(quint16 qRegAddr, quint16 qRegValue)
{
    QMap<quint16, QList<SignalParameter>>::Iterator itr = m_signalParamMap.find(qRegAddr);
    if(itr != m_signalParamMap.end())
    {
        QList<SignalParameter> mList = itr.value();
        for(int j=0; j<mList.size();j++)
        {
            quint16 qPos = mList.at(j).uBitPos;
            quint16 qBitLen = mList.at(j).uLength;
            quint16 parmValue;
            bool bRet = getParamValue(qRegValue, qPos, qBitLen, parmValue);
            if(bRet)
            {
                 m_signalParamMap[itr.key()][j].uValue = parmValue;
                 int uUIIdx =  mList.at(j).uUIIndex;
                 QLineEdit  *pLineEdit = m_editParamList.at(uUIIdx);
                 if(pLineEdit)
                 {
                     pLineEdit->setText(QString::number(m_signalParamMap[itr.key()][j].uValue));
                 }
//                 printValue2Bin(parmValue);
            }
        }
    }
}

void SignalBoxDlg::updateParamListValue()
{
    for(int i=0; i<m_editParamList.size(); i++)
    {
        quint16 qIndex =i;
        quint16 qRegAddr, qParamListIdx;
        bool bRet = querySignalParamByUIIndex(qIndex, qRegAddr, qParamListIdx);
        if(bRet)
        {
            QLineEdit  *pLineEdit = m_editParamList.at(qIndex);
            if(pLineEdit)
            {
                m_signalParamMap[qRegAddr][qParamListIdx].uValue = pLineEdit->text().toInt();
            }

        }
    }
}

bool SignalBoxDlg::querySignalParamByUIIndex(quint16 qIndex, quint16 &qRegAddr, quint16 &qParamListIdx)
{
    QMap<quint16, QList<SignalParameter>>::Iterator itr = m_signalParamMap.begin();
    while(itr != m_signalParamMap.end())
    {
        QList<SignalParameter> mList = itr.value();
        for(int i=0; i<mList.size();i++)
        {
            SignalParameter mData = mList.at(i);
            if(qIndex == mData.uUIIndex)
            {
                qRegAddr = itr.key();
                qParamListIdx = i;
                return true;
            }
        }
        itr++;
    }

    return false;
}

void SignalBoxDlg::initSignalWin()
{
     int iCnt = 0;
     QString strProtocol = "从机地址:"+QString::number(m_protocolParam.uServerAddr);
     strProtocol += "    读寄存器开始地址:"+QString::number(m_protocolParam.uReadStartAddr);
     strProtocol += "    读寄存器个数:"+QString::number(m_protocolParam.iReadRegCounts);
     strProtocol += "    写寄存器开始地址:"+QString::number(m_protocolParam.uWriteStartAddr);
     strProtocol += "    写寄存器个数:"+QString::number(m_protocolParam.iWriteRegCounts);
     strProtocol += "    功能码:"+QString::number(m_protocolParam.uFunctionCode);
     ui->label_protocol->setText(strProtocol);
     QMap<quint16, QList<SignalParameter>>::Iterator itr = m_signalParamMap.begin();
     while(itr != m_signalParamMap.end())
     {
         QList<SignalParameter> mList = itr.value();
         for(int i=0; i<mList.size();i++)
         {
             SignalParameter mData = mList.at(i);
             QLabel *pLabelName = m_labelNameList.at(iCnt);
             QLineEdit *pEditParam = m_editParamList.at(iCnt);
             pLabelName->setText(QString::number(iCnt+1)+":"+mData.strParamName);
             pEditParam->setText(QString::number(mData.uValue));
             pEditParam->setToolTip(mData.strDesc);
             mData.uUIIndex = iCnt;
             m_signalParamMap[itr.key()][i] =mData;

             if((mData.strType=="DI") ||(mData.strType=="AI"))
             {
                 pEditParam->setEnabled(false);
             }
             else if((mData.strType=="AO") ||(mData.strType=="DO"))
             {
                 pEditParam->setEnabled(true);
             }
             iCnt++;
         }
         itr++;
     }
}

void SignalBoxDlg::printValue2Bin(quint16 qValue)
{
    QString str = QString("%1").arg(qValue, 16, 2, QLatin1Char('0'));
    qDebug()<<QString::number(qValue)+":"<<str;
}

void SignalBoxDlg::on_btnSingalBox1_clicked()
{
    initData();
    setSignalParamList(1);
    ui->label_title->setText("信号箱1");
}

void SignalBoxDlg::on_btnSingalBox2_clicked()
{
    initData();
    setSignalParamList(2);
    ui->label_title->setText("信号箱2");
}

void SignalBoxDlg::on_btnSingalBox3_clicked()
{
    initData();
    setSignalParamList(3);
    ui->label_title->setText("信号箱3");
}

void SignalBoxDlg::on_btnSingalBox4_clicked()
{
    initData();
    setSignalParamList(4);
    ui->label_title->setText("信号箱4");
}

void SignalBoxDlg::on_btnWrite_clicked()
{
    //test
//    quint16 parmValue = 0xB311;
//    quint16 newParmValue, getParmValue;
//    quint16 setValue=0x3;
//    bool bRet = getParamValue(parmValue, 1, 4, getParmValue);
//    setParamValue(parmValue, 2, 3, setValue, newParmValue);

//    QString strConv1 = QString("%1").arg(parmValue, 16, 2, QLatin1Char('0'));
//    QString strConv2 = QString("%1").arg(getParmValue, 16, 2, QLatin1Char('0'));
//    QString strConv3 = QString("%1").arg(setValue, 16, 2, QLatin1Char('0'));
//    QString strConv4 = QString("%1").arg(newParmValue, 16, 2, QLatin1Char('0'));
//    qDebug()<<"get Pos Size 1 4";
//    qDebug()<<"set Pos Size 2 3";
//    qDebug()<<"parmValue:"<<strConv1;
//    qDebug()<<"getPValue:"<<strConv2;
//    qDebug()<<"set Value:"<<strConv3;
//    qDebug()<<"newParmae:"<<strConv4;

    updateParamListValue();
    quint16 qStartAddr = m_protocolParam.uWriteStartAddr;
    quint8 iRegCount = m_protocolParam.iWriteRegCounts;
    QList<quint16> mList = getRegValues(qStartAddr, iRegCount);
    if(mList.size() > 0)
    {
        emit sig_signaleBox_writeRegister(m_protocolParam, mList);
    }
}

void SignalBoxDlg::on_btnCycle_clicked()
{
    if(ui->btnCycle->text() == "循环发送")
    {
        ui->btnCycle->setText("停止循环");
        ui->btnWrite->setEnabled(false);
        m_timer.start();
    }
    else
    {
        ui->btnCycle->setText("循环发送");
        ui->btnWrite->setEnabled(true);
        m_timer.stop();
    }
}


void SignalBoxDlg::slot_signaleBox_readRegister(QList<RegisterData> regValueList)
{
    for(int i=0; i<regValueList.size(); i++)
    {
        RegisterData mData = regValueList.at(i);
        updateParamValue(mData.regAddr, mData.regValue);
    }

}

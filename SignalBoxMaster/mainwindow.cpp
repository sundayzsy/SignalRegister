#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("信号箱模拟器(主)");
    showMaximized();
    connect(ui->tab_signalBoxDlg, &SignalBoxDlg::sig_signaleBox_writeRegister, ui->tab_serial, &MySerialPort::slot_writeRegister);
    connect(ui->tab_serial, &MySerialPort::sig_readRegister, ui->tab_signalBoxDlg, &SignalBoxDlg::slot_signaleBox_readRegister);
}

MainWindow::~MainWindow()
{
    delete ui;
}


﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QInputDialog>
#include<QFileDialog>
#include<QTextStream>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QTimer>
#include<QByteArray>
#include<QChar>
#include<QtNetwork/QTcpServer>
#include<QtNetwork/QTcpSocket>
#include<QAbstractState>
#include<QHostInfo>
#include<QRegularExpression>
#include<QRegularExpressionMatch>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);//构造函数
    sendTimer=new QTimer(this);
    mySerialPort=new QSerialPort();
    tcpServer=new QTcpServer(this);
    tcpSocket=new QTcpSocket(this);

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(updateMyData()));
    QObject::connect(sendTimer,SIGNAL(timeout()),this,SLOT(on_pushButton_2_clicked()));
    QObject::connect(tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnections()));//服务器 端出现新的连接请求便出发acceptConnection()事件
    QObject::connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recData()));//客户端 收到服务器发送的数据后 执行recData()函数


    ui->label_9->setOpenExternalLinks(true);
    ui->label_9->setTextFormat(Qt::RichText);
    ui->comboBox_3->setCurrentIndex(3);

    QObject::connect(ui->action_2,SIGNAL(triggered(bool)),this,SLOT(MainWindow::on_action_2_triggered())); //添加串口事件
    QObject::connect(ui->action_5,SIGNAL(triggered(bool)),this,SLOT(MainWindow::on_action_5_triggered()));//添加波特率事件
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts()) {
       QSerialPort serial;
       serial.setPort(info);
       if(serial.open(QIODevice::ReadWrite)){
          // ui->plainTextEdit->appendPlainText(info.portName());
           ui->comboBox->addItem(info.portName());
           ui->comboBox->setCurrentText(info.portName());
           serial.close();
       }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete sendTimer;
    delete mySerialPort;
    delete tcpServer;
    delete tcpSocket;
}

//打开/关闭 串口
void MainWindow::on_pushButton_clicked()
{
    QString currentString=ui->pushButton->text();
    if(currentString.compare(u8"打开串口")==0){
         ui->pushButton->setText(u8"关闭串口");
         mySerialPort->setPortName(ui->comboBox->currentText());
         mySerialPort->open(QIODevice::ReadWrite);
         mySerialPort->setFlowControl(QSerialPort::NoFlowControl);//取默认值
         mySerialPort->setBaudRate(QSerialPort::BaudRate(ui->comboBox_2->currentText().toInt()),QSerialPort::AllDirections);//.................手动case转换
         //设置停止位
          switch (ui->comboBox_5->currentIndex()) {
          case 0:
               mySerialPort->setStopBits(QSerialPort::OneStop);
              break;
          case 1:
              mySerialPort->setStopBits(QSerialPort::OneAndHalfStop);
             break;
          case 2:
               mySerialPort->setStopBits(QSerialPort::TwoStop);
              break;
          default:
              break;
          }
          //设置校验位
          switch (ui->comboBox_4->currentIndex()) {
          case 0:
                mySerialPort->setParity(QSerialPort::NoParity);
              break;
          case 1:
              mySerialPort->setParity(QSerialPort::OddParity);
            break;
          case 2:
                mySerialPort->setParity(QSerialPort::EvenParity);
              break;

          default:
              break;
          }
          //设置数据位
          switch (ui->comboBox_3->currentIndex()) {
          case 0:
                mySerialPort->setDataBits(QSerialPort::Data5);
              break;
          case 1:
                mySerialPort->setDataBits(QSerialPort::Data6);
              break;
          case 2:
                mySerialPort->setDataBits(QSerialPort::Data7);
              break;
          case 3:
                mySerialPort->setDataBits(QSerialPort::Data8);
              break;

          default:
              break;
          }
         timer->start(1000);
    }
    else if(ui->pushButton->text().compare(u8"关闭串口")==0){
         ui->pushButton->setText(QStringLiteral("打开串口"));
         mySerialPort->close();
         timer->stop();


    }
    else if(ui->pushButton->text().compare(u8"打开网口")==0){
         ui->pushButton->setText(QStringLiteral("关闭网口"));
         ui->radioButton_3->setEnabled(false);
         ui->radioButton_4->setEnabled(false);
         if(createClient){
             addNewTcpConnect();//创建客户端的连接

         }
         else if(createServer){
             newListen(); //开始进行端口监听
             ui->statusBar->showMessage(u8"服务器创建成功");

         }



    }
    else if(ui->pushButton->text().compare(u8"关闭网口")==0){
         ui->pushButton->setText(QStringLiteral("打开网口"));
         ui->radioButton_3->setEnabled(true);
         ui->radioButton_4->setEnabled(true);
         if(createClient){
             tcpSocket->close();
             ui->statusBar->showMessage(u8"客户端已关闭");


         }
         else if(createServer){
             tcpServer->close();
             ui->statusBar->showMessage(u8"服务器已关闭");


         }
         //mySerialPort->close();
         //timer->stop();


    }

}

//清零 ok
void MainWindow::on_pushButton_5_clicked()
{
    ui->label_11->setText("0");
    ui->label_12->setText("0");
}

//发送 (简单实现)
void MainWindow::on_pushButton_2_clicked()
{
    QByteArray sendTxt=ui->plainTextEdit_2->toPlainText().toLocal8Bit();
    //设置发送字节
    if(currentMode==0){
    currentSend=ui->label_11->text().toInt();
    sendBytes=currentSend + sendTxt.size();
    ui->label_11->setText(QString::number(sendBytes,10));
    //发送十六进制数据
    if(ui->checkBox->isChecked()){
        mySerialPort->write(QByteArray::fromHex(sendTxt));
    }
    //发送字符
    else{

        mySerialPort->write(sendTxt);
    }

   //连续发送计时器
    if(ui->checkBox_2->isChecked()){
        bool ok=false;
        sendTimer->start(ui->spinBox->text().toInt(&ok,10));

    }
    else{
        sendTimer->stop();
    }
}
    else if(currentMode==1){
    //发送十六进制数据
    if(ui->checkBox->isChecked()){
        tcpSocket->write(QByteArray::fromHex(sendTxt));
    }
    //发送字符
    else{

       tcpSocket->write(sendTxt);
    }
    }
}


//接收数据(刷新)
void MainWindow::updateMyData()
{
currentReceive=ui->label_12->text().toInt();
requestData=mySerialPort->readAll();
receiveBytes=currentReceive + requestData.size();
ui->label_12->setText(QString::number(receiveBytes,10));
if(!requestData.isEmpty()){
    if(ui->radioButton_2->isChecked()){    // 十六进制显示 区分十六进制数据与字符型数据
        QString tempStr=requestData.toHex();
        ui->plainTextEdit->insertPlainText(tempStr);
    }
     //字符模式显示
    else{
        ui->plainTextEdit->insertPlainText(requestData);
    }
}

requestData.clear();
}


//清除 ok
void MainWindow::on_pushButton_3_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit_2->clear();
    ui->label_11->setText("0");
    ui->label_12->setText("0");

}

//保收发数据 ok
void  MainWindow::on_pushButton_4_clicked()
{
    QString saveText=QFileDialog::getSaveFileName(this,tr("保存收发信息"),"../dataStore.txt","Text files(*.txt)");
    ui->statusBar->showMessage(saveText); //statusBar的方式提示保存路径
    QString sendText=ui->plainTextEdit_2->toPlainText(); //转化为QString格式 toPlainText()
    QString receiveText=ui->plainTextEdit->toPlainText();
    // QMessageBox::warning(this,tr("保存提示"),sendText,QMessageBox::Ok);
    //创建保存文件
    QFile file(saveText);
    file.open(QIODevice::WriteOnly);
    file.close();
    //创建写入文件流
    if(!file.open(QIODevice::Text|QFile::WriteOnly|QIODevice::Truncate)){
        QMessageBox::information(this,tr("文件读取失败"),file.errorString());
    }
    QTextStream fileOut(&file);
    fileOut<<receiveText<<"\n";
    fileOut<<"\n";
    fileOut<<sendText<<"\n";
    file.flush();
    file.close();


}

//关于 ok
void MainWindow::on_action_triggered()
{
  aboutdialog.show();
}

//添加串口 ok
void MainWindow::on_action_2_triggered()
{
 bool ok=false;
QString portName=QInputDialog::getText(this,tr("串口添加"),tr("设备文件名称"),QLineEdit::Normal,0,&ok);
if(ok && !portName.isEmpty())
{
    ui->comboBox->addItem(portName);
    ui->statusBar->showMessage(tr("串口数据添加成功"));

}

}
//添加波特率
void MainWindow::on_action_5_triggered(){
    bool ok=false;
    QString baudRate=QInputDialog::getText(this,tr("addBaudRate"),tr("add BaudRate"),QLineEdit::Normal,0,&ok);
    if(ok && !baudRate.isEmpty()){
        ui->comboBox_2->addItem(baudRate);
        ui->statusBar->showMessage("success to add BaudRate");

    }
}
//十六进制转为整形ASCII码
int MainWindow::hex2int(char c)
{
    if(c>='0' && c<='9')
        return c-'0';
    else if(c>='A' && c<='F')
        return c-'A'+10;
    else if(c>='a' && c<='f')
        return c-'a'+10;
    else
        return -1;

}
//整型ASCII码转16进制
char int2hex(int i)
{
     return "123456789ABCDEF"[i];
}

//去除多余空格
void MainWindow::delBlank(QString &str)
{
   int length=str.length();
   for(int i=0;i<length;i++){
       if(str.at(i).isSpace()){
           str[i]='1';
       }
   }
}


void MainWindow::toWeb(QString myUrl)
{
QMessageBox::warning(this,tr("this is a test"),tr("this is a Label Event"),QMessageBox::Ok);

}

//跳转到指定网页
void MainWindow::on_label_9_linkActivated(const QString &link)
{
    QMessageBox::warning(this,tr("this is a test"),tr("this is a Label Event"),QMessageBox::Ok);

}
//串口网口切换函数
void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index==0){
        currentMode=0;
        if(mySerialPort->isOpen())
            ui->pushButton->setText(u8"关闭串口");
        else
            ui->pushButton->setText(u8"打开串口");
    }
    else if(index==1){
        currentMode=1;
        on_radioButton_3_clicked(true);
        //在次加入对网口的if判断 从而确定汉字的内容
        if(tcpServer->isListening() || tcpSocket->isOpen())
            ui->pushButton->setText(u8"关闭网口");
        else
            ui->pushButton->setText(u8"打开网口");
    }
}
//建立TCP监听事件（服务器端）
void MainWindow::newListen()
{
    //创建服务器端
    if(ui->radioButton_4->isChecked()){
        bool ok=false;
        if(!tcpServer->listen(QHostAddress::Any,ui->textEdit_2->toPlainText().toInt(&ok,10))){
            qDebug()<<tcpServer->errorString();
            tcpServer->close();
            return;
        }
          ui->statusBar->showMessage(u8"成功创建服务器");

    }



}
//服务器接受客户端的连接
void MainWindow::acceptConnections()
{
    tcpSocket=tcpServer->nextPendingConnection();

}
//创建服务器------
void MainWindow::on_radioButton_4_clicked(bool checked)
{
    createClient=false;
    createServer=true;
    ui->comboBox_6->clear();

    QHostInfo myInfo=QHostInfo::fromName(QHostInfo::localHostName());
    foreach (QHostAddress address, myInfo.addresses()) {
        if(address.protocol()==QAbstractSocket::IPv4Protocol){
            ui->comboBox_6->addItem(address.toString());
        }

    }


}
//创建客户端------
void MainWindow::on_radioButton_3_clicked(bool checked)
{
    createClient=true;
    createServer=false;
    ui->comboBox_6->clear();
    ui->comboBox_6->setEditable(true);
    QRegularExpression re("(\\d{1,3}\\.){3}");
    QRegularExpressionMatch ipMatch;
    QRegularExpressionMatchIterator ipIterator;
    QHostInfo myInfo=QHostInfo::fromName(QHostInfo::localHostName());
    foreach (QHostAddress address, myInfo.addresses()) {
        if(address.protocol()==QAbstractSocket::IPv4Protocol){
            ipIterator=re.globalMatch(address.toString());
            while(ipIterator.hasNext()){
                ipMatch=ipIterator.next();
                ui->comboBox_6->addItem(ipMatch.captured(0));
            }


        }
    }
}

//客户端接收服务器数据
void MainWindow::recData()
{

    QString recData=tcpSocket->readAll();
    ui->plainTextEdit->insertPlainText(recData);

}

//客户端新建连接
void MainWindow::addNewTcpConnect()
{
    bool ok=false;
    tcpSocket->abort();
    tcpSocket->connectToHost(ui->comboBox_6->currentText(),ui->textEdit_2->toPlainText().toInt(&ok,10));
    ui->statusBar->showMessage(u8"客户端创建成功");
}


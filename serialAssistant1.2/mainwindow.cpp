#include "mainwindow.h"
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
#include<QHostAddress>
#include<QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    timer=new QTimer(this);
    sendTimer=new QTimer(this);
    mySerialPort=new QSerialPort(this);
    tcpServer=new QTcpServer(this);
    tcpSocket=new QTcpSocket(this);
    QSettings mySettingsRead; //不加参数表明采用系统默认路径 windows下为注册表 linux下为==
    QPoint lastPoint=mySettingsRead.value("pos").toPoint();
    //设置记忆模式
    ui->serialCB->setCurrentText(mySettingsRead.value("serial").toString());
    ui->baudRateCB->setCurrentText(mySettingsRead.value("baudRate").toString());
    ui->dataBitCB->setCurrentText(mySettingsRead.value("dataBit").toString());
    ui->checkCB->setCurrentText(mySettingsRead.value("checkBit").toString());
    ui->stopBitCB->setCurrentText(mySettingsRead.value("stopBit").toString());
    this->move(lastPoint);



    connect(timer,SIGNAL(timeout()),this,SLOT(updateMyData()));
    connect(sendTimer,SIGNAL(timeout()),this,SLOT(on_sendData_clicked()));
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnections()));//服务器 端出现新的连接请求便出发acceptConnection()事件
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(updateMyData()));//客户端 收到服务器发送的数据后 执行recData()函数 服务器端无效
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(disconnectHost()));//主机下线提示
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectHost()));//主机上线提示

    lastState=QStringLiteral("打开网口");
    createClient=true;
    ui->label_9->setOpenExternalLinks(true);
    ui->label_9->setTextFormat(Qt::RichText);
    ui->dataBitCB->setCurrentIndex(3);

    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts()) {
       QSerialPort serial;
       serial.setPort(info);
       if(serial.open(QIODevice::ReadWrite)){
           ui->serialCB->addItem(info.portName());
           ui->serialCB->setCurrentText(info.portName());
           serial.close();
       }
    }
    ui->serialCB->setCurrentText(mySettingsRead.value("serial").toString());//执行两次 覆盖foreach结果

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
void MainWindow::on_openSerial_clicked()
{
    QString currentString=ui->openSerial->text();
    if(currentString==QStringLiteral("打开串口")){
         ui->openSerial->setText(QStringLiteral("关闭串口"));
         mySerialPort->setPortName(ui->serialCB->currentText());
         mySerialPort->open(QIODevice::ReadWrite);
         mySerialPort->setFlowControl(QSerialPort::NoFlowControl);//取默认值
         mySerialPort->setBaudRate(QSerialPort::BaudRate(ui->baudRateCB->currentText().toInt()),QSerialPort::AllDirections);
         //设置停止位
          switch (ui->stopBitCB->currentIndex()) {
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
          switch (ui->checkCB->currentIndex()) {
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
          switch (ui->dataBitCB->currentIndex()) {
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
    else if(ui->openSerial->text() == QStringLiteral("关闭串口")){
         ui->openSerial->setText(QStringLiteral("打开串口"));
         mySerialPort->close();
         timer->stop();
    }
    else if(ui->openSerial->text()==QStringLiteral("打开网口")){
         ui->openSerial->setText(QStringLiteral("关闭网口"));
         ui->clientCreate->setEnabled(false);
         ui->serverCreate->setEnabled(false);
         if(createClient){
             addNewTcpConnect();//创建客户端的连接
         }
         else if(createServer){
             newListen(); //开始进行端口监听
             ui->statusBar->showMessage(QStringLiteral("服务器创建成功"));
         }
    }
    else if(ui->openSerial->text()==QStringLiteral("关闭网口") ){
         ui->openSerial->setText(QStringLiteral("打开网口"));
         ui->clientCreate->setEnabled(true);
         ui->serverCreate->setEnabled(true);
         if(createClient){
             tcpSocket->close();
             ui->statusBar->showMessage(QStringLiteral("客户端已关闭"));
         }
         else if(createServer){
             tcpServer->close();
             tcpSocket->close();
             ui->statusBar->showMessage(QStringLiteral("服务器已关闭"));
         }
    }
}
//清零 ok
void MainWindow::on_clearCount_clicked()
{
    ui->label_11->setText("0");
    ui->label_12->setText("0");
}
//发送 (简单实现)
void MainWindow::on_sendData_clicked()
{if(mySerialPort->isOpen() || tcpSocket->isOpen())
    {
    QByteArray sendTxt=ui->sendContext->toPlainText().toLocal8Bit();
    //设置发送字节
    currentSend=ui->label_11->text().toInt();
    sendBytes=currentSend + sendTxt.size();
    ui->label_11->setText(QString::number(sendBytes,10));
    //发送十六进制数据
    if(ui->isHexSend->isChecked()){
        if(tcpSocket->isOpen()){
            tcpSocket->write(QByteArray::fromHex(sendTxt));
        }
        else{
            mySerialPort->write(QByteArray::fromHex(sendTxt));
        }
    }
    //发送字符
    else{
        if(tcpSocket->isOpen()){
            tcpSocket->write(sendTxt);
        }
    else{
        mySerialPort->write(sendTxt);
        }
    }
   //连续发送计时器
    if(ui->constantSend->isChecked()){
        bool ok=false;
        sendTimer->start(ui->constantTime->text().toInt(&ok,10));
    }
    else{
        sendTimer->stop();
    }
    }
}
//接收数据(刷新)
void MainWindow::updateMyData()
{
currentReceive=ui->label_12->text().toInt();
if(mySerialPort->isOpen()){
    requestData=mySerialPort->readAll();
}
else if(tcpSocket->isOpen()){
    requestData=tcpSocket->readAll();
}
receiveBytes=currentReceive + requestData.size();
ui->label_12->setText(QString::number(receiveBytes,10));
if(!requestData.isEmpty()){
    if(ui->showHex->isChecked()){    // 十六进制显示 区分十六进制数据与字符型数据
        QString tempStr=requestData.toHex();
        ui->receiveContext->insertPlainText(tempStr);
    }
     //字符模式显示
    else{
        ui->receiveContext->insertPlainText(requestData);
    }
}
requestData.clear();
}
//清除 ok
void MainWindow::on_clearData_clicked()
{
    ui->receiveContext->clear();
    ui->sendContext->clear();
    ui->label_11->setText("0");
    ui->label_12->setText("0");
}

//保收发数据 ok
void  MainWindow::on_saveData_clicked()
{
    QString saveText=QFileDialog::getSaveFileName(this,QStringLiteral("保存收发信息"),"../dataStore.txt","Text files(*.txt)");
    ui->statusBar->showMessage(saveText); //statusBar的方式提示保存路径
    QString sendText=ui->sendContext->toPlainText(); //转化为QString格式 toPlainText()
    QString receiveText=ui->receiveContext->toPlainText();
    // QMessageBox::warning(this,tr("保存提示"),sendText,QMessageBox::Ok);
    //创建保存文件
    QFile file(saveText);
    file.open(QIODevice::WriteOnly);
    file.close();
    //创建写入文件流
    if(!file.open(QIODevice::Text|QFile::WriteOnly|QIODevice::Truncate)){
        QMessageBox::information(this,QStringLiteral("文件读取失败"),file.errorString());
    }
    QTextStream fileOut(&file);
    fileOut<<receiveText<<"\n";
    fileOut<<"\n";
    fileOut<<sendText<<"\n";
    file.flush();
    file.close();
}

//关于 ok
void MainWindow::on_about_triggered()
{
  aboutdialog.show();
}

//添加串口 ok
void MainWindow::on_serialAdd_triggered()
{
 bool ok=false;
QString portName=QInputDialog::getText(this,QStringLiteral("串口添加"),QStringLiteral("设备文件名称"),QLineEdit::Normal,0,&ok);
if(ok && !portName.isEmpty())
{
    ui->serialCB->addItem(portName);
    ui->statusBar->showMessage(QStringLiteral("串口数据添加成功"));
}

}
//添加波特率
void MainWindow::on_addBaud_triggered(){
    bool ok=false;
    QString baudRate=QInputDialog::getText(this,tr("addBaudRate"),tr("add BaudRate"),QLineEdit::Normal,0,&ok);
    if(ok && !baudRate.isEmpty()){
        ui->baudRateCB->addItem(baudRate);
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
void MainWindow::on_changeMode_currentChanged(int index)
{
    if(index==0){
        currentMode=0;
        if(mySerialPort->isOpen())
            ui->openSerial->setText(QStringLiteral("关闭串口"));
        else
            ui->openSerial->setText(QStringLiteral("打开串口"));
    }
    else if(index==1){
        currentMode=1;
        on_clientCreate_clicked(true);
        //在次加入对网口的if判断 从而确定汉字的内容
        if(tcpServer->isListening() || tcpSocket->isOpen())
            ui->openSerial->setText(QStringLiteral("关闭网口"));
        else
            ui->openSerial->setText(QStringLiteral("打开网口"));
    }
}
//建立TCP监听事件（服务器端）
void MainWindow::newListen()
{
    if(isValidIP(ui->ipAddr->currentText())){
        //创建服务器端
        if(ui->serverCreate->isChecked()){
            bool ok=false;
            QHostAddress hostAddress;
            hostAddress.setAddress(ui->ipAddr->currentText());

            if(!tcpServer->listen(hostAddress,ui->hostPort->toPlainText().toInt(&ok,10))){
                qDebug()<<tcpServer->errorString();
                tcpServer->close();
                return;
            }
              ui->statusBar->showMessage(QStringLiteral("成功创建服务器"));
        }
    }
    else{
        QMessageBox::warning(this,"Qt","please input a valid ip address");
        ui->openSerial->setText(QStringLiteral("打开网口"));
        ui->statusBar->showMessage(QStringLiteral("failed to create server"));
    }

}
//服务器接受客户端的连接
void MainWindow::acceptConnections()
{

     if(!tcpSocket->isOpen()){
        tcpSocket=tcpServer->nextPendingConnection();
     }
    QObject::connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(updateMyData()));
    QObject::connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(disconnectHost()));//主机下线提示
    QObject::connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectHost()));//主机上线提示
    QMessageBox::warning(this,"Qt",QStringLiteral("客户端连接成功"));
    ui->statusBar->showMessage(QStringLiteral("客户端连接成功"));

}
//创建服务器radio------
void MainWindow::on_serverCreate_clicked(bool checked)
{
    createClient=false;
    createServer=true;
    ui->ipAddr->clear();
    QHostInfo myInfo=QHostInfo::fromName(QHostInfo::localHostName());
    foreach (QHostAddress address, myInfo.addresses()) {
        if(address.protocol()==QAbstractSocket::IPv4Protocol){
            ui->ipAddr->addItem(address.toString());
        }
    }
}
//创建客户端radio------
void MainWindow::on_clientCreate_clicked(bool checked)
{
    createClient=true;
    createServer=false;
    ui->ipAddr->clear();
    ui->ipAddr->setEditable(true);
    QRegularExpression re("(\\d{1,3}\\.){3}");
    QRegularExpressionMatch ipMatch;
    QRegularExpressionMatchIterator ipIterator;
    QHostInfo myInfo=QHostInfo::fromName(QHostInfo::localHostName());
    foreach (QHostAddress address, myInfo.addresses()) {
        if(address.protocol()==QAbstractSocket::IPv4Protocol){
            ipIterator=re.globalMatch(address.toString());
            while(ipIterator.hasNext()){
                ipMatch=ipIterator.next();
                ui->ipAddr->addItem(ipMatch.captured(0));
            }
        }
    }
}

//客户端 新建连接
void MainWindow::addNewTcpConnect()
{
    bool ok=false;
    tcpSocket->abort();
    QString ip=ui->ipAddr->currentText();
    if(isValidIP(ip)&& !tcpSocket->isOpen() ){
         tcpSocket->connectToHost(ip,ui->hostPort->toPlainText().toInt(&ok,10));
    }
    else{
        ui->openSerial->setText(QStringLiteral("打开网口"));
        QMessageBox::warning(this,"Qt","please enter a valid ip address");
    }

    /*
    if(tcpSocket->isOpen()){
        QMessageBox::warning(this,"Qt","connect to server successfully");
        ui->statusBar->showMessage(QStringLiteral("服务器连接成功");
    }
    else{
        QMessageBox::warning(this,"Qt","failed to connected server");
        ui->statusBar->showMessage(QStringLiteral("服务器连接失败");

    }
    */

}
//主机下线提示
void MainWindow::disconnectHost()
{
    ui->statusBar->showMessage(QStringLiteral("连接已断开"));
    ui->openSerial->setText(QStringLiteral("打开网口"));
    ui->clientCreate->setEnabled(true);
    ui->serverCreate->setEnabled(true);
    if(createClient){
        tcpSocket->close();
        ui->statusBar->showMessage(QStringLiteral("客户端已关闭"));
    }
    else if(createServer){
        tcpServer->close();
        tcpSocket->close();
        ui->statusBar->showMessage(QStringLiteral("服务器已关闭"));
    }
     QMessageBox::warning(this,QStringLiteral("Alert"),QStringLiteral("连接已断开"));


}
//主机上线提示
void MainWindow::connectHost()
{
    QMessageBox::warning(this,QStringLiteral("Alert"),QStringLiteral("服务器连接成功"));
    ui->statusBar->showMessage(QStringLiteral("服务器连接成功"));
}
//检测ip地址的合法性
bool MainWindow::isValidIP(QString ip)
{
    QRegularExpression re("(\\d{1,3}\\.){3}(\\d{1,3})");
    QRegularExpressionMatch ipMatch=re.match(ip);
    return ipMatch.hasMatch();

}
//窗口关闭事件
void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings mySettingsWrite;
    mySettingsWrite.setValue("pos",MainWindow::pos());
    mySettingsWrite.setValue("size",this->size());
    mySettingsWrite.setValue("serial",ui->serialCB->currentText());
    mySettingsWrite.setValue("baudRate",ui->baudRateCB->currentText());
    mySettingsWrite.setValue("dataBit",ui->dataBitCB->currentText());
    mySettingsWrite.setValue("checkBit",ui->checkCB->currentText());
    mySettingsWrite.setValue("stopBit",ui->stopBitCB->currentText());



    QMessageBox::StandardButton result;
    result=QMessageBox::warning(this,QStringLiteral("离开"),QStringLiteral("确定要离开吗?"),QMessageBox::Yes|QMessageBox::No);
    if(result==QMessageBox::Yes){
       event->accept();
    }
    else if(result==QMessageBox::No) {
     event->ignore();
    }

}


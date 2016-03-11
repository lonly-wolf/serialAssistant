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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);//构造函数
    sendTimer=new QTimer(this);
    mySerialPort=new QSerialPort();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(updateMyData()));
    QObject::connect(sendTimer,SIGNAL(timeout()),this,SLOT(on_pushButton_2_clicked()));
   // QObject::connect(ui->label_9,SIGNAL(clicked()),this,SLOT(toWeb(ui->label_9->text()));


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
    else{
         ui->pushButton->setText(QStringLiteral("打开串口"));
         mySerialPort->close();
         timer->stop();


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
    currentSend=ui->label_11->text().toInt();
    sendBytes=currentSend + sendTxt.size();
    ui->label_11->setText(QString::number(sendBytes,10));


   //QMessageBox::warning(this,tr("you will send this"),tr(sendTxt.toLatin1()),QMessageBox::Ok);
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

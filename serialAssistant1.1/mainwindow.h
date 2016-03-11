#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<aboutDialog.h>
class QSerialPort;
class QSerialPortInfo;
class QTimer;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int hex2int(char c);//十六进制转换为Ascii码
    char int2hex(int i);//Ascii码转换为十六进制
    void delBlank(QString &str); //去除空格函数
    void toWeb(QString myUrl);

private slots:

   // void on_actionShowAbout_triggereed(); //弹出关于对话框
  //  void on_action2AddSerial_triggereed();//添加串口
   // void on_action4Clear_triggereed();//计数清零
   // void on_pushButton_clicked();
   // void on_pushButton2_clickeed();//发送串口
   // void on_pushButton3_clickeed();//清除内容
   // void on_pushButton4_clickeed();//保存内容
  //  void on_pushButton5_clickeed();//计数清零


void on_pushButton_clicked();//打开/关闭 串口

void on_pushButton_5_clicked();//计数清零

void on_pushButton_2_clicked();//发送串口

void on_pushButton_3_clicked();//清除内容

void on_pushButton_4_clicked();//保存内容

void on_action_2_triggered();//打开串口

void on_action_5_triggered();//添加波特率

void on_action_triggered();//关于信息

void updateMyData();//刷新数据


void on_label_9_linkActivated(const QString &link); //超链接事件

private:
    Ui::MainWindow *ui;
    Dialog aboutdialog;
    QSerialPort *mySerialPort;
    QSerialPortInfo *mySerialPortInfo;
    QByteArray requestData;
    QTimer *timer;
    QTimer *sendTimer;
    qint32 receiveBytes;
    qint32 sendBytes;
    qint32 currentSend=0;
    qint32 currentReceive=0;



};

#endif // MAINWINDOW_H

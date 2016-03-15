#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<aboutDialog.h>
#include<QSettings>
class QSerialPort;
class QSerialPortInfo;
class QTimer;
class QTcpServer;
class QTcpSocket;


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
    void toWeb(QString myUrl);   //跳转到网站的超链接
    void addNewTcpConnect();    //客户端 添加新的连接
    bool isValidIP(QString ip); //检测ip地址的合法性
    void closeEvent(QCloseEvent *event);//窗口关闭事件


private slots:
    void on_openSerial_clicked();//打开/关闭 串口
    void on_clearCount_clicked();//计数清零
    void on_sendData_clicked();//发送串口
    void on_clearData_clicked();//清除内容
    void on_saveData_clicked();//保存内容
    void on_serialAdd_triggered();//打开串口
    void on_addBaud_triggered();//添加波特率
    void on_about_triggered();//关于信息
    void on_label_9_linkActivated(const QString &link); //超链接事件
    void on_changeMode_currentChanged(int index); //串口、网口转换
    void on_serverCreate_clicked(bool checked);//创建服务端radioButtonEvent
    void on_clientCreate_clicked(bool checked);//创建客户端radioButtonEvent
    void disconnectHost();//主机下线
    void connectHost();//主机上线
    void updateMyData();//刷新数据
    void newListen(); //服务器端 添加TCP的监听事件
    void acceptConnections(); //服务器端 接受客户端的连接


private:
    Ui::MainWindow *ui;
    Dialog aboutdialog;
    QSerialPort *mySerialPort;
    QByteArray requestData;
    QTimer *timer;
    QTimer *sendTimer;
    qint32 receiveBytes;
    qint32 sendBytes;
    qint32 currentSend;
    qint32 currentReceive;
    qint8 currentMode;//当前模式
    QString lastState;//用来记录当前串口、网口状态。
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    bool createClient;//默认创建客户端为true
    bool createServer;
    QSettings mySettings;





};

#endif // MAINWINDOW_H

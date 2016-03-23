#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"mylabel.h"

class QPainter;
class QLabel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     QImage   *myImage2; //经过处理的图片
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QPainter *painter;
    QImage   myImage;//图片
    QImage *myImage3; //保存原始图片
    QString imageName;//图片路径
    QTransform transform; //图片旋转
    QMatrix matrix; //图片旋转角度
    QPoint beginPoint;//原始坐标
    QPoint lastPoint;//前一次放大时的坐标
    myLabel *drawLabel; //重写label
    int imageWidth;          //scrollArea中心点
    int imageHeight;
    int picSize; //图片放大/缩小的倍数
    int picPosition;//图片旋转角度
    int lastPosition; //图片的上一次的角度
    bool hasTrans;  //判断上一个动作是旋转
    bool isPen;
    int picSizeCount; //放大、缩小倍数
    int picSliderCount; //滑块上一次的值
    int initWidth;//图像初始高度
    int initHeight;//图像初始宽度

    void drawPaint(); //绘制图形（测试版）
    void transformImage();// 调整图像位置 大小
private slots:
    void on_actionOpen_triggered(); //菜单栏打开图片
    void on_imageRotate_sliderMoved(int position);//旋转图片
    void on_pushButton_clicked(); //放大图片
    void on_pushButton_2_clicked();//缩小图片
    void on_horizontalSlider_sliderMoved(int position); //显示比例

    void on_penButton_clicked();//画笔点击事件

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
  //  bool eventFilter(QObject *obj,QEvent *event);   //事件过滤器
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPainter;

class QLabel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPainter *painter;
    QImage   myImage;//图片
    QImage   *myImage2; //经过处理的图片
    QImage *myImage3; //保存原始图片
    QLabel *labelWidget;//放置图片的label
    QString imageName;//图片路径
    QTransform transform; //图片旋转
    QMatrix matrix; //图片旋转角度
    int imageWidth;          //scrollArea中心点
    int imageHeight;
    int picSize; //图片放大/缩小的倍数
    int picPosition;//图片旋转角度
    bool hasTrans;

    void drawPaint(); //绘制图形（测试版）
    void transformImage();// 调整图像位置 大小
private slots:
    void on_actionOpen_triggered(); //菜单栏打开图片
   //图片旋转

    void on_imageRotate_sliderMoved(int position);//旋转图片

    void on_pushButton_clicked(); //放大图片

    void on_pushButton_2_clicked();//缩小图片

    void on_horizontalSlider_sliderMoved(int position); //显示比例

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H

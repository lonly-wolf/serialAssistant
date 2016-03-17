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
    QImage  *myImage;//图片
    QLabel *labelWidget;//放置图片的label
    QString imageName;//图片路径

    void drawPaint(); //绘制图形（测试版）
    void transformImage();// 调整图像位置 大小
private slots:
    void on_actionOpen_triggered(); //菜单栏打开图片
   //图片旋转

    void on_imageRotate_sliderMoved(int position);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H

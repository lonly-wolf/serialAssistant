#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QPainter;

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
    void drawPaint();



protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H

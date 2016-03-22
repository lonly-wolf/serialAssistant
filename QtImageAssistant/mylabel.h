#ifndef MYLABEL_H
#define MYLABEL_H
#include <QWidget>
#include<QLabel>
#include<QPoint>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QLabel *parent = 0);
    bool isClicking;
    bool isPen;
    void setImage(QString name);




signals:

public slots:

private:
     QPoint beginPoint;//原始坐标
     QPoint currentPoint;
     QPoint beginPointer;
     QPoint originalPoint;
     QPainter *myPainter;
     QList<QPointF> pointArray;
     QPointF straightLine[2];
     QString imageName;
     QImage myImage;




protected:
     void paintEvent(QPaintEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
     void mousePressEvent(QMouseEvent *event);
   // void mouseDoubleClickEvent(QMouseEvent *event);
  //  bool eventFilter(QObject *obj,QEvent *event);   //事件过滤器

};

#endif // MYLABEL_H

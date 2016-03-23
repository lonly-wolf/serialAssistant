#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>

class QPoint;
class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QLabel *parent = 0);
    bool isClicking;
    bool isPen;
    QImage myImage;
    void setImage(QString name);
    void setImageByImage(QImage *image);
    void setImageWidth(int width);
    void setImageHeight(int height);
    void setImageRotate(QMatrix matrix);
    QImage getMyImage();

    ~myLabel();
signals:

public slots:

private:
     QPoint beginPoint;//原始坐标
     QPoint currentPoint;
     QPoint beginPointer;
     QPoint originalPoint;
     QPainter *myPainter;
     QPainter *showPicPainter;
     QList<QPointF> pointArray;
     QPointF straightLine[2];
     QString imageName;
     QMatrix myMatrix;

     QPainter *linePainter;
     bool isLoadPic;

protected:
     void paintEvent(QPaintEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
     void mousePressEvent(QMouseEvent *event);
};

#endif // MYLABEL_H

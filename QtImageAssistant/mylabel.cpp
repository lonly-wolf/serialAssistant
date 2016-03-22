#include "mylabel.h"
#include<QLabel>
#include<QPixmap>
#include<QMouseEvent>
#include<QPainter>
#include<QPointF>
#include<QDebug>

myLabel::myLabel(QLabel *parent) : QLabel(parent)
{
    myPainter=new QPainter;
    isClicking=false;
    isPen=false;


}

void myLabel::mousePressEvent(QMouseEvent *event)
{
    QMouseEvent *mouseEvent=static_cast<QMouseEvent *>(event);
    beginPoint.setX(mouseEvent->pos().x());
    beginPoint.setY(mouseEvent->pos().y());
   QLabel::mousePressEvent(event);
    if(this->isPen){
        beginPointer.setX(mouseEvent->pos().x());
        beginPointer.setY(mouseEvent->pos().y());
        qDebug("clicked position is :,%d,%d",beginPointer.x(),beginPointer.y());
    }
}

void myLabel::mouseMoveEvent(QMouseEvent *event)
{

    QMouseEvent *mouseEvent=static_cast<QMouseEvent *>(event);
    this->currentPoint.setX(mouseEvent->pos().x());
    this->currentPoint.setY(mouseEvent->pos().y());
    if(!this->isPen){

        this->setGeometry(mouseEvent->pos().x()-beginPoint.x()+this->pos().x(),mouseEvent->pos().y()-beginPoint.y()+this->pos().y(),this->width(),this->height());

    }
    else if(this->isPen){
        //绘制直线
        if(1)
        {
            straightLine[0]=QPointF(beginPointer.x(),beginPointer.y());
            straightLine[1]=QPointF(currentPoint.x(),currentPoint.y());
            beginPoint.setX( mouseEvent->x());
            beginPoint.setY(mouseEvent->y());
            QPainter linePainter(&myImage);
            QPen pen(Qt::blue);
            QBrush brush1(Qt::red,Qt::Dense3Pattern);  //用指定的颜色和模式绘制图形
            pen.setBrush(brush1);
            pen.setWidth(8);
            pen.setCapStyle(Qt::RoundCap); //设置线的末端的风格 共三种
            pen.setJoinStyle(Qt::RoundJoin);//设置坐标与连接线之间的风格
            linePainter.setPen(pen);
            QLineF myLine(straightLine[0],straightLine[1]);
            linePainter.drawImage(0,0,myImage);

        }
       // pointArray.append(QPointF(beginPointer.x(),beginPointer.y()));
       // pointArray.append(QPointF(currentPoint.x(),currentPoint.y()));
        update();
    }


}

void myLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(this->isPen){
        pointArray.append(QPointF(beginPointer.x(),beginPointer.y()));
        pointArray.append(QPointF(currentPoint.x(),currentPoint.y()));
        update();

    }

}

//重写label方法
void myLabel::paintEvent(QPaintEvent *event)
{

if(this->isPen){
    myPainter->begin(this);
    myPainter->drawImage(0,0,myImage);
    QLineF myLine(straightLine[0],straightLine[1]);
    myPainter->drawLine(myLine);

/*
    if(1){
        QLineF myLine(straightLine[0],straightLine[1]);
        myPainter->drawLine(myLine);
    }
    else{
        for(int i=0;i<pointArray.size()-1;i+=2){
            QLineF myLine(pointArray[i],pointArray[i+1]);
            myPainter->drawLine(myLine);
        }

    }
    */
    myPainter->end();
    qDebug()<<"reDrawing------------------------------------------";
}


}

//获取图片路径
 void  myLabel::setImage(QString name)
 {
     this->imageName=name;
     myImage.load(imageName);

 }



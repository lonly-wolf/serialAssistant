#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    painter=new QPainter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::drawPaint()
{
    painter->begin(this);
    QPen pen(Qt::blue);
    QBrush brush1(Qt::blue,Qt::Dense3Pattern);  //用指定的颜色和模式绘制图形

    pen.setBrush(brush1);
    pen.setWidth(6);
    pen.setCapStyle(Qt::RoundCap); //设置线的末端的风格 共三种
    pen.setJoinStyle(Qt::RoundJoin);//设置坐标与连接线之间的风格
    painter->setPen(pen);
    painter->drawLine(10,50,100,40);
    painter->drawRect(120,50,80,80);
    QRect rect(230,50,80,80);
    painter->drawRoundedRect(rect,10,10); //绘制圆角矩形

    QPointF p1[3]={

         QPointF(120,140),
         QPointF(150,170),
         QPointF(120,190)
     };
    QPointF p2[3]={

         QPointF(180,140),
         QPointF(270,170),
         QPointF(180,320)
     };

    painter->drawPolyline(p1,3); //通过线绘制指针支点
    painter->drawPolygon(p2,3);//以指针支点绘制多边形

    painter->setFont(QFont("Times",20)); //设置字体
    QRect fontRect(10,150,220,180);
    QPixmap image(300,200);


    painter->begin(&image);
    painter->drawText(fontRect,Qt::AlignCenter,QStringLiteral("我的世界"));
    painter->end();

}

void MainWindow::paintEvent(QPaintEvent *event)
{
   drawPaint();

}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>
#include<QLabel>
#include<QFileDialog>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    myImage=new QImage;
    labelWidget=new QLabel;
    painter=new QPainter(this);
    //设置scrollerArea的滚动条策略
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setAlignment(Qt::AlignCenter);
    //设置scrollerArea中的内容居中
    labelWidget->setContentsMargins(ui->scrollArea->width()/2- myImage->width()/2,ui->scrollArea->height()/2-myImage->height()/2,ui->scrollArea->width()/2- myImage->width()/2,ui->scrollArea->height()/2-myImage->height()/2);
    ui->scrollArea->setWidget(labelWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete myImage;
    delete labelWidget;
    delete painter;
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

    painter->drawText(fontRect,Qt::AlignCenter,QStringLiteral("我的世界"));
    painter->drawRect(200,200,200,300);
    //设置渐变模式
    QRadialGradient gradient(100,100,50,120,120);
    gradient.setColorAt(0,Qt::black);
    gradient.setColorAt(1,Qt::red);
   // gradient.setSpread(QGradient::RepeatSpread);
    gradient.setSpread(QGradient::RepeatSpread);
    QBrush brush3(gradient);
    painter->setBrush(brush3);
    painter->drawRect(50,50,300,300);

    painter->end();

}
//转换图像
void MainWindow::transformImage()
{   QPainter myPainter;
    QImage image(":525897.png");

    myPainter.begin(&image);

    QPen pen(Qt::blue,1,Qt::DashLine);
    myPainter.setPen(pen);
    myPainter.drawRect(50,50,100,100);

   QTransform transform;
   transform.translate(50,50); //改变坐标
   transform.rotate(45);       //旋转
   transform.scale(0.5,0.5);   //放大


   myPainter.setTransform(transform);
   myPainter.drawImage(0,0,image);
   myPainter.end();

   //ui->label->resize(QSize(image.width()/3,image.height()/3));
   //ui->label->setPixmap(QPixmap::fromImage(image));
   //在scrollArea添加label图片



}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //drawPaint();
   //transformImage();
    qDebug()<<"paintEvent loaded!";

}


//打开图片函数
void MainWindow::on_actionOpen_triggered()
{
  imageName=QFileDialog::getOpenFileName(this,QStringLiteral("Please open a picture"),"","Images (*.png *.bmp *.jpg *.tif *.GIF)");
  if(!imageName.isEmpty()){
      if(!(myImage->load(imageName))){
          QMessageBox::warning(this,"Falied to open the picture","Fail to open the picture",QMessageBox::Ok);
          return;
      }
      else{
          labelWidget->setPixmap(QPixmap::fromImage(*myImage));
          qDebug()<<"myImage loaded2";
          labelWidget->setContentsMargins(ui->scrollArea->width()/2- myImage->width()/2,ui->scrollArea->height()/2-myImage->height()/2,ui->scrollArea->width()/2- myImage->width()/2,ui->scrollArea->height()/2-myImage->height()/2);
          qDebug()<<"myImage loaded3";
          ui->scrollArea->setWidget(labelWidget);
          return;
      }
  }
  else{
      QMessageBox::warning(this,"Falied to open the picture",QStringLiteral("no picture has been selected!"),QMessageBox::Ok);
      return;
  }
}

//旋转图片
void MainWindow::on_imageRotate_sliderMoved(int position)
{
    qDebug()<<position;
    ui->label->setText("rotate:" + QString::number(position,10));

}

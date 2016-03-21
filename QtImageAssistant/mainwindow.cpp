#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>
#include<QLabel>
#include<QFileDialog>
#include<QMessageBox>
#include<QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    labelWidget=new QLabel;
    myImage2=new QImage;
    painter=new QPainter;
    drawLabel=new myLabel;
    drawLabel->setStyleSheet("background-color:black");

    //设置scrollerArea的滚动条策略
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    labelWidget->setAlignment(Qt::AlignCenter);
    labelWidget->setText("pictureShow~");
    labelWidget->setAutoFillBackground(true);
    //labelWidget->setStyleSheet("background-color:black");
    ui->scrollArea->setAlignment(Qt::AlignCenter);
    ui->scrollArea->setWidget(drawLabel);
    labelWidget->installEventFilter(this); //控件事件过滤器
    picSize=1;
    picPosition=0;
    hasTrans=false;
    lastPosition=ui->imageRotate->value();
    picSizeCount=0;
    picSliderCount=0;
    lastPoint.setX(labelWidget->pos().x());
    lastPoint.setY(labelWidget->pos().y());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete labelWidget;
    delete painter;
}


void MainWindow::drawPaint()
{
    painter->begin(drawLabel);
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

   // painter->begin(&myImage);
    //transform.rotate(position);
  // painter->setTransform(transform);
  // painter->translate(centerX,centerY);
   //QRectF rect(ui->scrollArea->width()/2,ui->scrollArea->height()/2,myImage.width(),myImage.height());

  // labelWidget->clear();
  // labelWidget->show();

  // painter->drawImage(0,0,myImage);
  // labelWidget->resize(myImage.width(),myImage.height());

 //  painter->end();

}

void MainWindow::paintEvent(QPaintEvent *event)
{
     drawPaint();
  // transformImage();
    qDebug()<<"paintEvent loaded!";
}


//打开图片函数
void MainWindow::on_actionOpen_triggered()
{
  imageName=QFileDialog::getOpenFileName(this,QStringLiteral("Please open a picture"),"","Images (*.png *.bmp *.jpg *.tif *.GIF)");
  if(!imageName.isEmpty()){
      if(!(myImage.load(imageName))){
          QMessageBox::warning(this,"Falied to open the picture","Fail to open the picture",QMessageBox::Ok);
          return;
      }
      else{
          *myImage2=myImage; //将加载的图片信息拷贝给myImage2
          imageWidth=myImage2->width();
          imageHeight=myImage2->height();
          labelWidget->setPixmap(QPixmap::fromImage(myImage));

          qDebug()<<"myImage loaded2";
         // labelWidget->setContentsMargins(ui->scrollArea->width()/2- myImage2->width()/2,ui->scrollArea->height()/2-myImage2->height()/2,ui->scrollArea->width()/2- myImage2->width()/2,ui->scrollArea->height()/2-myImage2->height()/2);
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
    picPosition=position;
    if(!myImage.isNull()){
         hasTrans=true;
        qDebug()<<position;
        ui->label->setText("rotate:" + QString::number(position,10));
        if(position>=lastPosition){
           matrix.rotate(position-lastPosition);
           lastPosition=position;
        }
        else if((position<lastPosition)){
            matrix.rotate((position-lastPosition));

            lastPosition=position;
        }

        *myImage2=myImage.transformed(matrix);
        *myImage2=myImage2->scaled(imageWidth,imageHeight,Qt::KeepAspectRatio);
        labelWidget->setPixmap(QPixmap::fromImage(*myImage2));
    }
    else{
        return;
    }
}

//放大图片
void MainWindow::on_pushButton_clicked()
{

if(!myImage.isNull()){
     if(myImage2->width()<=8192 && (myImage2->height())<=8192 && picSizeCount<=7 ){
         if(hasTrans){
              matrix.rotate(0);
              myImage=myImage.transformed(matrix);
         }
        *myImage2=myImage.scaled(myImage2->width()/0.8,myImage2->height()/0.8,Qt::KeepAspectRatio);
         labelWidget->setPixmap(QPixmap::fromImage(*myImage2));

         imageWidth=myImage2->width();
         imageHeight=myImage2->height();
         hasTrans=false;
         picSizeCount+=1;
         ui->horizontalSlider->setValue(picSizeCount);
         picSliderCount=ui->horizontalSlider->value();
         qDebug()<<picSizeCount;
     }
}
}

// 缩小图片
void MainWindow::on_pushButton_2_clicked()
{
   // myImage=*myImage2;
    if(!myImage.isNull() && picSizeCount>-7 ){
        if(myImage2->width()>=30 && myImage2->height()>=30){
            if(hasTrans){
                 matrix.rotate(0);
                 myImage=myImage.transformed(matrix);
               // labelWidget->setPixmap(QPixmap::fromImage(*myImage2));
            }
           *myImage2=myImage.scaled(myImage2->width()*0.8,myImage2->height()*0.8,Qt::KeepAspectRatio);//设置无损缩放
          // labelWidget->setContentsMargins(ui->scrollArea->width()/2- myImage2->width()/2,ui->scrollArea->height()/2-myImage2->height()/2,ui->scrollArea->width()/2- myImage2->width()/2,ui->scrollArea->height()/2-myImage2->height()/2);
            labelWidget->setPixmap(QPixmap::fromImage(*myImage2));

            imageWidth=myImage2->width();
            imageHeight=myImage2->height();
           //myImage=*myImage2;
            hasTrans=false;
            picSizeCount-=1;
            ui->horizontalSlider->setValue(picSizeCount);
            picSliderCount=ui->horizontalSlider->value();
            qDebug()<<picSizeCount;
        }
    }

}
//水平滚动放大条
void MainWindow::on_horizontalSlider_sliderMoved(int position)
{

    if(position>=picSliderCount){
        on_pushButton_clicked();
    }
    else if(position<picSliderCount){
        on_pushButton_2_clicked();
    }

}

//事件过滤器
bool MainWindow::eventFilter(QObject *obj,QEvent *event){
    if(event->type()==QEvent::MouseButtonPress && obj==labelWidget){
        //图像拖动事件
        QMouseEvent *mouseEvent=static_cast<QMouseEvent *>(event);
        beginPoint.setX(mouseEvent->pos().x());
        beginPoint.setY(mouseEvent->pos().y());
        qDebug("begin point:%d, %d",mouseEvent->pos().x(),mouseEvent->pos().y());
        return true;
    }
    else if(event->type()==QEvent::MouseMove && obj==labelWidget){
        //图像拖动事件
        QMouseEvent *mouseEvent=static_cast<QMouseEvent *>(event);
        //endPoint.setX(mouseEvent->pos().x());
      //  endPoint.setY(mouseEvent->pos().y());
        qDebug("mouse is moving:%d, %d",mouseEvent->pos().x(),mouseEvent->pos().y());
        qDebug("labelWidget position::%d,%d",labelWidget->pos().x(),labelWidget->pos().y());
        labelWidget->setGeometry(mouseEvent->pos().x()-beginPoint.x()+labelWidget->pos().x(),mouseEvent->pos().y()-beginPoint.y()+labelWidget->pos().y(),labelWidget->width(),labelWidget->height());
        return true;
    }
    else if(event->type()==QEvent::MouseButtonDblClick && obj==labelWidget){
        //双击放大事件
        if(!myImage.isNull()){
             if(myImage2->width()<=8192 && (myImage2->height())<=8192 && picSizeCount<=7 ){
                 if(hasTrans){
                      matrix.rotate(0);
                      myImage=myImage.transformed(matrix);
                 }
                *myImage2=myImage.scaled(myImage2->width()/0.8,myImage2->height()/0.8,Qt::KeepAspectRatio);
                labelWidget->setPixmap(QPixmap::fromImage(*myImage2));
                // labelWidget->size().setWidth(myImage2->width());
                // labelWidget->size().setHeight(myImage2->height());
                // labelWidget->move(ui->scrollArea->width()/2-beginPoint.x(),ui->scrollArea->height()/2-beginPoint.y());
               //  labelWidget->setGeometry(ui->scrollArea->width()/2-beginPoint.x()+labelWidget->x(),ui->scrollArea->width()/2-beginPoint.x()+labelWidget->x(),labelWidget->width(),labelWidget->height());
                 imageWidth=myImage2->width();
                 imageHeight=myImage2->height();
                 hasTrans=false;
                 picSizeCount+=1;
                 ui->horizontalSlider->setValue(picSizeCount);
                 picSliderCount=ui->horizontalSlider->value();
                 labelWidget->setGeometry(300,500,labelWidget->width(),labelWidget->height());


                 qDebug("doubleClicked::old labelWidget position::%d, %d",labelWidget->pos().x(),labelWidget->pos().y());
              }
        }


    }
    else{
        //标准的处理进程
        return QObject::eventFilter(obj,event);
    }
}


//鼠标移事件
void MainWindow::mouseMoveEvent(QMouseEvent *event){



}

//鼠标双击事件
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){

}



//画笔点击事件
void MainWindow::on_penButton_clicked()
{
    drawPaint();
}

//重写label方法
void myLabel::paintEvent(QPaintEvent *event)
{
    //QLabel::paintEvent(event);
    QPainter painter(this);
        painter.setPen(QPen(Qt::red,2));
        painter.drawRect(QRect(100,200,200,200));
        qDebug()<<"myLabel";

}

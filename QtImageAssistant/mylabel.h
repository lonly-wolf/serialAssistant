#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>

class myLabel : public QWidget
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MYLABEL_H

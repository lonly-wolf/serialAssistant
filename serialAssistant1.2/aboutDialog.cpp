#include "aboutDialog.h"
#include "ui_aboutDialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label_9->setOpenExternalLinks(true);
    ui->label_9->setTextFormat(Qt::RichText);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_label_9_linkActivated(const QString &link)
{

}

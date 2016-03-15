/********************************************************************************
** Form generated from reading UI file 'aboutDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QFormLayout *formLayout;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(238, 360);
        formLayout = new QFormLayout(Dialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        groupBox_4 = new QGroupBox(Dialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout = new QHBoxLayout(groupBox_4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/FBT2.png")));

        horizontalLayout->addWidget(label_10);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);


        formLayout->setWidget(0, QFormLayout::SpanningRole, groupBox_4);

        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Andalus"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);

        formLayout->setWidget(1, QFormLayout::SpanningRole, label);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_2);

        textBrowser = new QTextBrowser(Dialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, textBrowser);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::FieldRole, verticalSpacer);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "About", 0));
        groupBox_4->setTitle(QString());
        label_10->setText(QString());
        label_9->setText(QApplication::translate("Dialog", "<a href=\"https://www.baidu.com\">www.focus-ebeam.com</a>", 0));
        label->setText(QApplication::translate("Dialog", "Qt\350\267\250\345\271\263\345\217\260\344\270\262\345\217\243\350\260\203\350\257\225\345\212\251\346\211\213", 0));
        label_2->setText(QApplication::translate("Dialog", "<font color='green'>\350\201\232\346\235\237\347\247\221\346\212\200\350\275\257\344\273\266\347\240\224\345\217\221\351\203\250</font>", 0));
        textBrowser->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#55aa7f;\">\350\256\270\345\217\257\345\243\260\346\230\216<br /></span><span style=\" color:#55aa7f;\"><br /><br />\302\240\302\240\302\240\302\240\302\240QCom\302\240\346\230\257\350\207\252\347\224\261\350\275\257\344\273\266\357\274\233\346\202\250\345\217\257\344\273\245\346\214\211\347\205\247\350\207\252\347\224\261\350\275\257\344\273\266\345\237\272\351\207\221\344\274\232\346\211\200\345\217\221\350\241\250\347\232\204\302\240GNU\302\240GPL\302\240\345\215\217\350\256\256\350\207\252\347"
                        "\224\261\345\217\221\346\224\276\345\222\214/\346\210\226\344\277\256\346\224\271\345\256\203\357\274\233\351\207\207\347\224\250\345\215\217\350\256\256\347\232\204\347\254\254\302\2403\302\240\347\211\210\357\274\214\346\210\226\350\200\205(\346\240\271\346\215\256\346\202\250\347\232\204\351\200\211\346\213\251)\344\273\273\344\275\225\346\233\264\351\253\230\347\211\210\346\234\254\343\200\202<br /><br />\302\240\302\240\302\240\302\240\345\217\221\350\241\250\347\232\204\347\233\256\347\232\204\346\230\257\345\270\214\346\234\233\345\256\203\350\203\275\345\244\237\345\257\271\346\202\250\346\234\211\347\224\250\357\274\214\344\275\206\346\210\221\344\273\254\346\262\241\346\234\211\344\273\273\344\275\225\344\277\235\350\257\201\357\274\233\345\257\271\344\272\216\344\273\245\344\273\273\344\275\225\347\224\250\351\200\224\344\275\277\347\224\250\345\256\203\346\211\200\351\200\240\346\210\220\347\232\204\344\273\273\344\275\225\347\233\264\346\216\245\346\210\226\351\227\264\346\216\245\345\220\216\346\236"
                        "\234\351\203\275\344\270\215\346\211\277\346\213\205\344\273\273\344\275\225\350\264\243\344\273\273\343\200\202\350\257\267\345\217\202\347\234\213\302\240GNU\302\240GPL\302\240\345\215\217\350\256\256\344\270\255\347\232\204\347\273\206\350\212\202\343\200\202<br /><br />\302\240\302\240\302\240\302\240\346\202\250\345\272\224\350\257\245\345\234\250\346\224\266\345\210\260\350\257\245\347\250\213\345\272\217\347\232\204\345\220\214\346\227\266\346\224\266\345\210\260\344\272\206GNU\302\240GPL\345\215\217\350\256\256\347\232\204\345\211\257\346\234\254\343\200\202\345\246\202\346\236\234\346\262\241\346\234\211\347\232\204\350\257\235\357\274\214\350\257\267\345\217\202\350\247\201\357\274\210</span><a href=\"http://www.gnu.org/licenses\"><span style=\" text-decoration: underline; color:#55aa7f;\">http://www.focus-ebeam.com/help.doc</span></a><span style=\" color:#55aa7f;\">\302\240\357\274\211\343\200\202 </span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H

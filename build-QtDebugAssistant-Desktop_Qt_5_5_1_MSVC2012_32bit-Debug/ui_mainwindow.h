/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *about;
    QAction *serialAdd;
    QAction *action_3;
    QAction *cleanerCount;
    QAction *addBaud;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QTabWidget *changeMode;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *stopBitCB;
    QComboBox *serialCB;
    QLabel *label;
    QLabel *label_5;
    QComboBox *baudRateCB;
    QComboBox *checkCB;
    QLabel *label_4;
    QComboBox *dataBitCB;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_5;
    QRadioButton *serverCreate;
    QTextEdit *hostPort;
    QRadioButton *clientCreate;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *ipAddr;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *openSerial;
    QPushButton *clearCount;
    QPushButton *sendData;
    QPushButton *clearData;
    QPushButton *saveData;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton;
    QRadioButton *showHex;
    QCheckBox *isHexSend;
    QLabel *label_6;
    QLabel *label_12;
    QPlainTextEdit *receiveContext;
    QLabel *label_7;
    QLabel *label_8;
    QCheckBox *constantSend;
    QSpinBox *constantTime;
    QLabel *label_11;
    QPlainTextEdit *sendContext;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLabel *label_9;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_A;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(708, 507);
        about = new QAction(MainWindow);
        about->setObjectName(QStringLiteral("about"));
        serialAdd = new QAction(MainWindow);
        serialAdd->setObjectName(QStringLiteral("serialAdd"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        cleanerCount = new QAction(MainWindow);
        cleanerCount->setObjectName(QStringLiteral("cleanerCount"));
        addBaud = new QAction(MainWindow);
        addBaud->setObjectName(QStringLiteral("addBaud"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        changeMode = new QTabWidget(centralWidget);
        changeMode->setObjectName(QStringLiteral("changeMode"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        stopBitCB = new QComboBox(groupBox);
        stopBitCB->setObjectName(QStringLiteral("stopBitCB"));

        gridLayout->addWidget(stopBitCB, 0, 9, 1, 1);

        serialCB = new QComboBox(groupBox);
        serialCB->setObjectName(QStringLiteral("serialCB"));

        gridLayout->addWidget(serialCB, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 8, 1, 1);

        baudRateCB = new QComboBox(groupBox);
        baudRateCB->setObjectName(QStringLiteral("baudRateCB"));

        gridLayout->addWidget(baudRateCB, 0, 3, 1, 1);

        checkCB = new QComboBox(groupBox);
        checkCB->setObjectName(QStringLiteral("checkCB"));

        gridLayout->addWidget(checkCB, 0, 7, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 6, 1, 1);

        dataBitCB = new QComboBox(groupBox);
        dataBitCB->setObjectName(QStringLiteral("dataBitCB"));

        gridLayout->addWidget(dataBitCB, 0, 5, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 1, 9, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 4, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        changeMode->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        serverCreate = new QRadioButton(groupBox_5);
        serverCreate->setObjectName(QStringLiteral("serverCreate"));
        serverCreate->setGeometry(QRect(10, 30, 89, 16));
        hostPort = new QTextEdit(groupBox_5);
        hostPort->setObjectName(QStringLiteral("hostPort"));
        hostPort->setGeometry(QRect(340, 10, 61, 31));
        hostPort->setAcceptRichText(false);
        clientCreate = new QRadioButton(groupBox_5);
        clientCreate->setObjectName(QStringLiteral("clientCreate"));
        clientCreate->setGeometry(QRect(10, 0, 89, 16));
        clientCreate->setChecked(true);
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(100, 10, 61, 20));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(290, 10, 41, 20));
        ipAddr = new QComboBox(groupBox_5);
        ipAddr->setObjectName(QStringLiteral("ipAddr"));
        ipAddr->setGeometry(QRect(160, 10, 121, 22));
        ipAddr->setEditable(true);

        gridLayout_6->addWidget(groupBox_5, 0, 0, 1, 1);

        changeMode->addTab(tab_4, QString());

        gridLayout_5->addWidget(changeMode, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        openSerial = new QPushButton(groupBox_2);
        openSerial->setObjectName(QStringLiteral("openSerial"));

        gridLayout_3->addWidget(openSerial, 0, 0, 1, 1);

        clearCount = new QPushButton(groupBox_2);
        clearCount->setObjectName(QStringLiteral("clearCount"));

        gridLayout_3->addWidget(clearCount, 1, 0, 1, 1);

        sendData = new QPushButton(groupBox_2);
        sendData->setObjectName(QStringLiteral("sendData"));

        gridLayout_3->addWidget(sendData, 2, 0, 1, 1);

        clearData = new QPushButton(groupBox_2);
        clearData->setObjectName(QStringLiteral("clearData"));

        gridLayout_3->addWidget(clearData, 3, 0, 1, 1);

        saveData = new QPushButton(groupBox_2);
        saveData->setObjectName(QStringLiteral("saveData"));

        gridLayout_3->addWidget(saveData, 4, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 0, 2, 2, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        gridLayout_2->addWidget(radioButton, 0, 3, 1, 1);

        showHex = new QRadioButton(groupBox_3);
        showHex->setObjectName(QStringLiteral("showHex"));

        gridLayout_2->addWidget(showHex, 0, 4, 1, 1);

        isHexSend = new QCheckBox(groupBox_3);
        isHexSend->setObjectName(QStringLiteral("isHexSend"));
        isHexSend->setChecked(false);

        gridLayout_2->addWidget(isHexSend, 2, 3, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 0, 1, 1, 1);

        receiveContext = new QPlainTextEdit(groupBox_3);
        receiveContext->setObjectName(QStringLiteral("receiveContext"));

        gridLayout_2->addWidget(receiveContext, 1, 0, 1, 7);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 2, 5, 1, 1);

        constantSend = new QCheckBox(groupBox_3);
        constantSend->setObjectName(QStringLiteral("constantSend"));

        gridLayout_2->addWidget(constantSend, 2, 4, 1, 1);

        constantTime = new QSpinBox(groupBox_3);
        constantTime->setObjectName(QStringLiteral("constantTime"));
        constantTime->setMaximum(10000);
        constantTime->setValue(1000);

        gridLayout_2->addWidget(constantTime, 2, 6, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 2, 1, 1, 1);

        sendContext = new QPlainTextEdit(groupBox_3);
        sendContext->setObjectName(QStringLiteral("sendContext"));

        gridLayout_2->addWidget(sendContext, 3, 0, 1, 7);


        gridLayout_5->addWidget(groupBox_3, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 281, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout = new QHBoxLayout(groupBox_4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/FBT2.png")));

        horizontalLayout->addWidget(label_10);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);


        gridLayout_5->addWidget(groupBox_4, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 708, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_A = new QMenu(menuBar);
        menu_A->setObjectName(QStringLiteral("menu_A"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_A->menuAction());
        menu->addAction(serialAdd);
        menu->addSeparator();
        menu->addAction(cleanerCount);
        menu->addSeparator();
        menu->addAction(addBaud);
        menu_A->addAction(about);

        retranslateUi(MainWindow);

        changeMode->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\201\232\346\235\237\347\247\221\346\212\200\350\275\257\344\273\266\347\240\224\345\217\221\351\203\250", 0));
        about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\344\270\262\345\217\243\345\212\251\346\211\213", 0));
        serialAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\262\345\217\243", 0));
        action_3->setText(QApplication::translate("MainWindow", "\350\256\241\346\225\260\346\270\205\351\233\266", 0));
        cleanerCount->setText(QApplication::translate("MainWindow", "\350\256\241\346\225\260\346\270\205\351\233\266", 0));
        addBaud->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\263\242\347\211\271\347\216\207", 0));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207:", 0));
        stopBitCB->clear();
        stopBitCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "1.5", 0)
         << QApplication::translate("MainWindow", "2", 0)
        );
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243:", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215:", 0));
        baudRateCB->clear();
        baudRateCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1200", 0)
         << QApplication::translate("MainWindow", "1800", 0)
         << QApplication::translate("MainWindow", "2400", 0)
         << QApplication::translate("MainWindow", "4800", 0)
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "14400", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "38400", 0)
         << QApplication::translate("MainWindow", "56000", 0)
         << QApplication::translate("MainWindow", "57600", 0)
         << QApplication::translate("MainWindow", "76800", 0)
         << QApplication::translate("MainWindow", "115200", 0)
         << QApplication::translate("MainWindow", "128000", 0)
         << QApplication::translate("MainWindow", "256000", 0)
        );
        checkCB->clear();
        checkCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "empty", 0)
         << QApplication::translate("MainWindow", "odd", 0)
         << QApplication::translate("MainWindow", "even", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215:", 0));
        dataBitCB->clear();
        dataBitCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215:", 0));
        changeMode->setTabText(changeMode->indexOf(tab_3), QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        groupBox_5->setTitle(QString());
        serverCreate->setText(QApplication::translate("MainWindow", "\345\210\233\345\273\272\346\234\215\345\212\241\347\253\257", 0));
        hostPort->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">8888</p></body></html>", 0));
        clientCreate->setText(QApplication::translate("MainWindow", "\345\210\233\345\273\272\345\256\242\346\210\267\347\253\257", 0));
        label_13->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP:", 0));
        label_14->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267:", 0));
        changeMode->setTabText(changeMode->indexOf(tab_4), QApplication::translate("MainWindow", "\347\275\221\345\217\243\350\256\276\347\275\256", 0));
        groupBox_2->setTitle(QString());
        openSerial->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        clearCount->setText(QApplication::translate("MainWindow", "\350\256\241\346\225\260\346\270\205\351\233\266", 0));
        sendData->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
        clearData->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\225\260\346\215\256", 0));
        saveData->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\224\266\345\217\221", 0));
        radioButton->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\346\230\276\347\244\272", 0));
        showHex->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\346\230\276\347\244\272", 0));
        isHexSend->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", 0));
        label_6->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256\345\214\272\345\237\237:", 0));
        label_12->setText(QApplication::translate("MainWindow", "0", 0));
        receiveContext->setPlainText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256\345\214\272\345\237\237:", 0));
        label_8->setText(QApplication::translate("MainWindow", "\351\227\264\351\232\224(\346\257\253\347\247\222):", 0));
        constantSend->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\345\217\221\351\200\201", 0));
        label_11->setText(QApplication::translate("MainWindow", "0", 0));
        sendContext->setPlainText(QString());
        groupBox_4->setTitle(QString());
        label_10->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "<a href=\"https://www.baidu.com\">www.focus-ebeam.com</a>", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234(&F)", 0));
        menu_A->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

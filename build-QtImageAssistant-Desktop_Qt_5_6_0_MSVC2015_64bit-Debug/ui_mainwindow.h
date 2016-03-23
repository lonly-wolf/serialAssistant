/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *action_Outport;
    QAction *action_Print;
    QAction *grayAction;
    QAction *coldAction;
    QAction *action_5;
    QAction *mohuAction;
    QAction *sharpAction;
    QAction *action_8;
    QAction *action_9;
    QAction *action_10;
    QAction *lightAdd15;
    QAction *lightAdd30;
    QAction *lightAdd45;
    QAction *lightAdd65;
    QAction *lightAdd85;
    QAction *lightAdd100;
    QAction *action20;
    QAction *action30;
    QAction *action_12;
    QAction *warmAction2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *toolsBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QDial *imageRotate;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *penButton;
    QMenuBar *menuBar;
    QMenu *menu_f;
    QMenu *menu_Operate;
    QMenu *menu_About;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1307, 776);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image2.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        action_Outport = new QAction(MainWindow);
        action_Outport->setObjectName(QStringLiteral("action_Outport"));
        action_Print = new QAction(MainWindow);
        action_Print->setObjectName(QStringLiteral("action_Print"));
        grayAction = new QAction(MainWindow);
        grayAction->setObjectName(QStringLiteral("grayAction"));
        coldAction = new QAction(MainWindow);
        coldAction->setObjectName(QStringLiteral("coldAction"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        mohuAction = new QAction(MainWindow);
        mohuAction->setObjectName(QStringLiteral("mohuAction"));
        sharpAction = new QAction(MainWindow);
        sharpAction->setObjectName(QStringLiteral("sharpAction"));
        action_8 = new QAction(MainWindow);
        action_8->setObjectName(QStringLiteral("action_8"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_10 = new QAction(MainWindow);
        action_10->setObjectName(QStringLiteral("action_10"));
        lightAdd15 = new QAction(MainWindow);
        lightAdd15->setObjectName(QStringLiteral("lightAdd15"));
        lightAdd30 = new QAction(MainWindow);
        lightAdd30->setObjectName(QStringLiteral("lightAdd30"));
        lightAdd45 = new QAction(MainWindow);
        lightAdd45->setObjectName(QStringLiteral("lightAdd45"));
        lightAdd65 = new QAction(MainWindow);
        lightAdd65->setObjectName(QStringLiteral("lightAdd65"));
        lightAdd85 = new QAction(MainWindow);
        lightAdd85->setObjectName(QStringLiteral("lightAdd85"));
        lightAdd100 = new QAction(MainWindow);
        lightAdd100->setObjectName(QStringLiteral("lightAdd100"));
        action20 = new QAction(MainWindow);
        action20->setObjectName(QStringLiteral("action20"));
        action30 = new QAction(MainWindow);
        action30->setObjectName(QStringLiteral("action30"));
        action_12 = new QAction(MainWindow);
        action_12->setObjectName(QStringLiteral("action_12"));
        warmAction2 = new QAction(MainWindow);
        warmAction2->setObjectName(QStringLiteral("warmAction2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(1251, 521));
        scrollArea->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        scrollArea->setMouseTracking(true);
        scrollArea->setFocusPolicy(Qt::TabFocus);
        scrollArea->setAcceptDrops(true);
        scrollArea->setAutoFillBackground(true);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1270, 596));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        toolsBox = new QGroupBox(centralWidget);
        toolsBox->setObjectName(QStringLiteral("toolsBox"));
        toolsBox->setMinimumSize(QSize(1261, 80));
        toolsBox->setAcceptDrops(true);
        toolsBox->setAutoFillBackground(true);
        layoutWidget = new QWidget(toolsBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(590, 0, 71, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        imageRotate = new QDial(layoutWidget);
        imageRotate->setObjectName(QStringLiteral("imageRotate"));
        imageRotate->setMaximumSize(QSize(50, 64));
        imageRotate->setMaximum(360);

        verticalLayout->addWidget(imageRotate);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAutoFillBackground(false);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(toolsBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 20, 75, 31));
        pushButton_2 = new QPushButton(toolsBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(670, 20, 75, 31));
        horizontalSlider = new QSlider(toolsBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(990, 30, 281, 20));
        horizontalSlider->setMinimum(-7);
        horizontalSlider->setMaximum(7);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(toolsBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(930, 30, 54, 12));
        label_3 = new QLabel(toolsBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1000, 50, 16, 16));
        label_4 = new QLabel(toolsBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1260, 50, 21, 16));
        penButton = new QPushButton(toolsBox);
        penButton->setObjectName(QStringLiteral("penButton"));
        penButton->setGeometry(QRect(330, 30, 75, 31));

        gridLayout->addWidget(toolsBox, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1307, 23));
        menu_f = new QMenu(menuBar);
        menu_f->setObjectName(QStringLiteral("menu_f"));
        menu_Operate = new QMenu(menuBar);
        menu_Operate->setObjectName(QStringLiteral("menu_Operate"));
        menu_About = new QMenu(menuBar);
        menu_About->setObjectName(QStringLiteral("menu_About"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_f->menuAction());
        menuBar->addAction(menu_Operate->menuAction());
        menuBar->addAction(menu_About->menuAction());
        menuBar->addAction(menu->menuAction());
        menu_f->addAction(actionOpen);
        menu_f->addAction(actionSave);
        menu_f->addAction(action_Outport);
        menu_f->addAction(action_Print);
        menu->addAction(grayAction);
        menu->addAction(menu_2->menuAction());
        menu->addAction(action_5);
        menu->addAction(mohuAction);
        menu->addAction(sharpAction);
        menu->addAction(action_8);
        menu->addAction(action_9);
        menu->addAction(action_10);
        menu->addAction(warmAction2);
        menu_2->addAction(lightAdd15);
        menu_2->addAction(lightAdd30);
        menu_2->addAction(lightAdd45);
        menu_2->addAction(lightAdd65);
        menu_2->addAction(lightAdd85);
        menu_2->addAction(lightAdd100);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save &as", 0));
        action_Outport->setText(QApplication::translate("MainWindow", "&Outport", 0));
        action_Print->setText(QApplication::translate("MainWindow", "&Print", 0));
        grayAction->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\350\260\203\350\212\202", 0));
        coldAction->setText(QApplication::translate("MainWindow", "\345\206\267\350\211\262\350\260\203\350\212\202", 0));
        action_5->setText(QApplication::translate("MainWindow", "\351\245\261\345\222\214\345\272\246\350\260\203\350\212\202", 0));
        mohuAction->setText(QApplication::translate("MainWindow", "\346\250\241\347\263\212\345\214\226", 0));
        sharpAction->setText(QApplication::translate("MainWindow", "\351\224\220\345\214\226", 0));
        action_8->setText(QApplication::translate("MainWindow", "\351\207\221\345\261\236\345\214\226", 0));
        action_9->setText(QApplication::translate("MainWindow", "\350\276\271\346\241\206\350\256\276\347\275\256", 0));
        action_10->setText(QApplication::translate("MainWindow", "\346\250\241\347\263\212\350\276\271\346\241\206", 0));
        lightAdd15->setText(QApplication::translate("MainWindow", "+15%", 0));
        lightAdd30->setText(QApplication::translate("MainWindow", "+30%", 0));
        lightAdd45->setText(QApplication::translate("MainWindow", "+45%", 0));
        lightAdd65->setText(QApplication::translate("MainWindow", "+65%", 0));
        lightAdd85->setText(QApplication::translate("MainWindow", "+85%", 0));
        lightAdd100->setText(QApplication::translate("MainWindow", "+100%", 0));
        action20->setText(QApplication::translate("MainWindow", "20", 0));
        action30->setText(QApplication::translate("MainWindow", "30", 0));
        action_12->setText(QString());
        warmAction2->setText(QApplication::translate("MainWindow", "\346\232\226\350\211\262\350\260\203\350\212\202", 0));
        toolsBox->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", 0));
        label->setText(QApplication::translate("MainWindow", " rotate:0", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\257\224\344\276\213", 0));
        label_3->setText(QApplication::translate("MainWindow", "-", 0));
        label_4->setText(QApplication::translate("MainWindow", "+", 0));
        penButton->setText(QApplication::translate("MainWindow", "\347\224\273\347\254\224", 0));
        menu_f->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_Operate->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menu_About->setTitle(QApplication::translate("MainWindow", "&About", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\351\253\230\347\272\247", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\344\272\256\345\272\246\350\260\203\350\212\202", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

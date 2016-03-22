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
#include <QtWidgets/QComboBox>
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
    QComboBox *penType;
    QMenuBar *menuBar;
    QMenu *menu_f;
    QMenu *menu_Operate;
    QMenu *menu_About;
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
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1287, 613));
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
        penButton->setGeometry(QRect(20, 30, 75, 31));
        penType = new QComboBox(toolsBox);
        penType->setObjectName(QStringLiteral("penType"));
        penType->setGeometry(QRect(120, 30, 69, 22));

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
        menu_f->addAction(actionOpen);
        menu_f->addAction(actionSave);
        menu_f->addAction(actionSave_as);
        menu_f->addAction(action_Outport);
        menu_f->addAction(action_Print);

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
        toolsBox->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", 0));
        label->setText(QApplication::translate("MainWindow", " rotate:0", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\257\224\344\276\213", 0));
        label_3->setText(QApplication::translate("MainWindow", "-", 0));
        label_4->setText(QApplication::translate("MainWindow", "+", 0));
        penButton->setText(QApplication::translate("MainWindow", "\347\224\273\347\254\224", 0));
        penType->clear();
        penType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\233\264\347\272\277", 0)
         << QApplication::translate("MainWindow", "\347\237\251\345\275\242", 0)
         << QApplication::translate("MainWindow", "\345\234\206", 0)
         << QApplication::translate("MainWindow", "\350\207\252\347\224\261\347\273\230\345\210\266", 0)
        );
        menu_f->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_Operate->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menu_About->setTitle(QApplication::translate("MainWindow", "&About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

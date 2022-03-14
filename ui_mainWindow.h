/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *inforaction;
    QAction *seqaction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *MACline;
    QLineEdit *Passline;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *SNline;
    QLineEdit *Falseline;
    QLineEdit *Serialline;
    QPushButton *seqrunbtn;
    QLabel *label_8;
    QLineEdit *Timeline;
    QLabel *label_7;
    QLineEdit *Yieldline;
    QLabel *labeltitle;
    QTableWidget *displaylist;
    QLabel *label;
    QLineEdit *PCBline;
    QProgressBar *operateress;
    QLineEdit *seqpath;
    QLabel *label_9;
    QPushButton *seqopenbtn;
    QPushButton *openinfor;
    QCheckBox *checkBox;
    QLineEdit *beginarr;
    QLineEdit *endarr;
    QRadioButton *onlinebtn;
    QMenuBar *menuBar;
    QMenu *menuseqtest;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(872, 678);
        inforaction = new QAction(MainWindow);
        inforaction->setObjectName(QStringLiteral("inforaction"));
        seqaction = new QAction(MainWindow);
        seqaction->setObjectName(QStringLiteral("seqaction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 8, 7, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 8, 10, 1, 1);

        MACline = new QLineEdit(centralWidget);
        MACline->setObjectName(QStringLiteral("MACline"));

        gridLayout->addWidget(MACline, 8, 4, 1, 2);

        Passline = new QLineEdit(centralWidget);
        Passline->setObjectName(QStringLiteral("Passline"));

        gridLayout->addWidget(Passline, 8, 8, 1, 2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 8, 3, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 9, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 9, 3, 1, 1);

        SNline = new QLineEdit(centralWidget);
        SNline->setObjectName(QStringLiteral("SNline"));

        gridLayout->addWidget(SNline, 9, 1, 1, 2);

        Falseline = new QLineEdit(centralWidget);
        Falseline->setObjectName(QStringLiteral("Falseline"));

        gridLayout->addWidget(Falseline, 8, 11, 1, 1);

        Serialline = new QLineEdit(centralWidget);
        Serialline->setObjectName(QStringLiteral("Serialline"));

        gridLayout->addWidget(Serialline, 9, 4, 1, 2);

        seqrunbtn = new QPushButton(centralWidget);
        seqrunbtn->setObjectName(QStringLiteral("seqrunbtn"));

        gridLayout->addWidget(seqrunbtn, 10, 0, 1, 12);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 9, 10, 1, 1);

        Timeline = new QLineEdit(centralWidget);
        Timeline->setObjectName(QStringLiteral("Timeline"));

        gridLayout->addWidget(Timeline, 9, 8, 1, 2);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 9, 7, 1, 1);

        Yieldline = new QLineEdit(centralWidget);
        Yieldline->setObjectName(QStringLiteral("Yieldline"));

        gridLayout->addWidget(Yieldline, 9, 11, 1, 1);

        labeltitle = new QLabel(centralWidget);
        labeltitle->setObjectName(QStringLiteral("labeltitle"));
        QFont font1;
        font1.setPointSize(20);
        labeltitle->setFont(font1);
        labeltitle->setAcceptDrops(false);
        labeltitle->setLayoutDirection(Qt::LeftToRight);
        labeltitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labeltitle, 4, 0, 1, 12);

        displaylist = new QTableWidget(centralWidget);
        if (displaylist->columnCount() < 6)
            displaylist->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        displaylist->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        displaylist->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        displaylist->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        displaylist->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        displaylist->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        displaylist->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (displaylist->rowCount() < 6)
            displaylist->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        displaylist->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        displaylist->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        displaylist->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        displaylist->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        displaylist->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        displaylist->setVerticalHeaderItem(5, __qtablewidgetitem11);
        displaylist->setObjectName(QStringLiteral("displaylist"));

        gridLayout->addWidget(displaylist, 6, 0, 1, 12);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 8, 0, 1, 1);

        PCBline = new QLineEdit(centralWidget);
        PCBline->setObjectName(QStringLiteral("PCBline"));

        gridLayout->addWidget(PCBline, 8, 1, 1, 2);

        operateress = new QProgressBar(centralWidget);
        operateress->setObjectName(QStringLiteral("operateress"));
        operateress->setValue(24);

        gridLayout->addWidget(operateress, 7, 0, 1, 12);

        seqpath = new QLineEdit(centralWidget);
        seqpath->setObjectName(QStringLiteral("seqpath"));

        gridLayout->addWidget(seqpath, 0, 0, 1, 9);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 9, 2, 3);

        seqopenbtn = new QPushButton(centralWidget);
        seqopenbtn->setObjectName(QStringLiteral("seqopenbtn"));

        gridLayout->addWidget(seqopenbtn, 1, 0, 1, 1);

        openinfor = new QPushButton(centralWidget);
        openinfor->setObjectName(QStringLiteral("openinfor"));

        gridLayout->addWidget(openinfor, 1, 1, 1, 1);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);

        gridLayout->addWidget(checkBox, 1, 7, 1, 1);

        beginarr = new QLineEdit(centralWidget);
        beginarr->setObjectName(QStringLiteral("beginarr"));

        gridLayout->addWidget(beginarr, 1, 2, 1, 1);

        endarr = new QLineEdit(centralWidget);
        endarr->setObjectName(QStringLiteral("endarr"));

        gridLayout->addWidget(endarr, 1, 3, 1, 1);

        onlinebtn = new QRadioButton(centralWidget);
        onlinebtn->setObjectName(QStringLiteral("onlinebtn"));
        onlinebtn->setFont(font);

        gridLayout->addWidget(onlinebtn, 1, 5, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 872, 22));
        menuseqtest = new QMenu(menuBar);
        menuseqtest->setObjectName(QStringLiteral("menuseqtest"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuseqtest->menuAction());
        menuseqtest->addAction(inforaction);
        menuseqtest->addAction(seqaction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "use the C++", Q_NULLPTR));
        inforaction->setText(QApplication::translate("MainWindow", "information", Q_NULLPTR));
        seqaction->setText(QApplication::translate("MainWindow", "seqtest", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Pass", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "False", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "MAC", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "SN", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "SERIAL", Q_NULLPTR));
        seqrunbtn->setText(QApplication::translate("MainWindow", "run the sequence", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Yield", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Time", Q_NULLPTR));
        labeltitle->setText(QApplication::translate("MainWindow", "i like the C++,its my like", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = displaylist->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "project", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = displaylist->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "value", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = displaylist->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "uplimit", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = displaylist->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "downlimit", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = displaylist->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "statues", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = displaylist->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "result", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = displaylist->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = displaylist->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = displaylist->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = displaylist->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = displaylist->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = displaylist->verticalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "PCBID", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><img src=\":/new/prefix1/D:/information/imagemic/\347\253\213\350\256\257log\345\233\276\347\211\207.png\"/></p></body></html>", Q_NULLPTR));
        seqopenbtn->setText(QApplication::translate("MainWindow", "openseq", Q_NULLPTR));
        openinfor->setText(QApplication::translate("MainWindow", "openinfor", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "onMes", Q_NULLPTR));
        onlinebtn->setText(QApplication::translate("MainWindow", "online", Q_NULLPTR));
        menuseqtest->setTitle(QApplication::translate("MainWindow", " operatemenu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

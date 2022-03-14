/********************************************************************************
** Form generated from reading UI file 'seqdesign.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEQDESIGN_H
#define UI_SEQDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seqdesign
{
public:
    QGridLayout *gridLayout;
    QPushButton *upbtn;
    QPushButton *downbtn;
    QPushButton *intoseq;
    QPushButton *outseq;
    QLabel *openlab;
    QListWidget *outputorder;
    QPushButton *openbtn;
    QPushButton *SaveButton;
    QLabel *SavePathlab;
    QLineEdit *SavePath;
    QLineEdit *openline;
    QListWidget *inputorder;

    void setupUi(QWidget *seqdesign)
    {
        if (seqdesign->objectName().isEmpty())
            seqdesign->setObjectName(QStringLiteral("seqdesign"));
        seqdesign->resize(774, 601);
        gridLayout = new QGridLayout(seqdesign);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        upbtn = new QPushButton(seqdesign);
        upbtn->setObjectName(QStringLiteral("upbtn"));

        gridLayout->addWidget(upbtn, 3, 2, 1, 1);

        downbtn = new QPushButton(seqdesign);
        downbtn->setObjectName(QStringLiteral("downbtn"));

        gridLayout->addWidget(downbtn, 4, 2, 1, 1);

        intoseq = new QPushButton(seqdesign);
        intoseq->setObjectName(QStringLiteral("intoseq"));

        gridLayout->addWidget(intoseq, 1, 2, 1, 1);

        outseq = new QPushButton(seqdesign);
        outseq->setObjectName(QStringLiteral("outseq"));

        gridLayout->addWidget(outseq, 2, 2, 1, 1);

        openlab = new QLabel(seqdesign);
        openlab->setObjectName(QStringLiteral("openlab"));

        gridLayout->addWidget(openlab, 6, 0, 1, 1);

        outputorder = new QListWidget(seqdesign);
        outputorder->setObjectName(QStringLiteral("outputorder"));

        gridLayout->addWidget(outputorder, 0, 3, 5, 2);

        openbtn = new QPushButton(seqdesign);
        openbtn->setObjectName(QStringLiteral("openbtn"));

        gridLayout->addWidget(openbtn, 6, 4, 1, 1);

        SaveButton = new QPushButton(seqdesign);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));

        gridLayout->addWidget(SaveButton, 5, 4, 1, 1);

        SavePathlab = new QLabel(seqdesign);
        SavePathlab->setObjectName(QStringLiteral("SavePathlab"));

        gridLayout->addWidget(SavePathlab, 5, 0, 1, 1);

        SavePath = new QLineEdit(seqdesign);
        SavePath->setObjectName(QStringLiteral("SavePath"));

        gridLayout->addWidget(SavePath, 5, 1, 1, 3);

        openline = new QLineEdit(seqdesign);
        openline->setObjectName(QStringLiteral("openline"));

        gridLayout->addWidget(openline, 6, 1, 1, 3);

        inputorder = new QListWidget(seqdesign);
        new QListWidgetItem(inputorder);
        new QListWidgetItem(inputorder);
        new QListWidgetItem(inputorder);
        new QListWidgetItem(inputorder);
        inputorder->setObjectName(QStringLiteral("inputorder"));

        gridLayout->addWidget(inputorder, 0, 0, 5, 2);


        retranslateUi(seqdesign);

        QMetaObject::connectSlotsByName(seqdesign);
    } // setupUi

    void retranslateUi(QWidget *seqdesign)
    {
        seqdesign->setWindowTitle(QApplication::translate("seqdesign", "Form", Q_NULLPTR));
        upbtn->setText(QApplication::translate("seqdesign", "up", Q_NULLPTR));
        downbtn->setText(QApplication::translate("seqdesign", "down", Q_NULLPTR));
        intoseq->setText(QApplication::translate("seqdesign", "into", Q_NULLPTR));
        outseq->setText(QApplication::translate("seqdesign", "out", Q_NULLPTR));
        openlab->setText(QApplication::translate("seqdesign", "Openpath", Q_NULLPTR));
        openbtn->setText(QApplication::translate("seqdesign", "open", Q_NULLPTR));
        SaveButton->setText(QApplication::translate("seqdesign", "Save", Q_NULLPTR));
        SavePathlab->setText(QApplication::translate("seqdesign", "SavePath", Q_NULLPTR));

        const bool __sortingEnabled = inputorder->isSortingEnabled();
        inputorder->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = inputorder->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("seqdesign", "SC-operate", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = inputorder->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("seqdesign", "USB-operate", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = inputorder->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("seqdesign", "RS232-operate", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = inputorder->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("seqdesign", "GPIB-operate", Q_NULLPTR));
        inputorder->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class seqdesign: public Ui_seqdesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEQDESIGN_H

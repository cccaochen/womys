/********************************************************************************
** Form generated from reading UI file 'gpibdesign.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPIBDESIGN_H
#define UI_GPIBDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GPIBdesign
{
public:
    QGridLayout *gridLayout;
    QPushButton *Refresh;
    QLabel *order;
    QLabel *device;
    QLabel *title;
    QComboBox *devicelist;
    QListWidget *listWidget;
    QLineEdit *orderline;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *cutup;
    QLineEdit *cutdown;
    QPushButton *linebtn;

    void setupUi(QWidget *GPIBdesign)
    {
        if (GPIBdesign->objectName().isEmpty())
            GPIBdesign->setObjectName(QStringLiteral("GPIBdesign"));
        GPIBdesign->resize(377, 393);
        gridLayout = new QGridLayout(GPIBdesign);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Refresh = new QPushButton(GPIBdesign);
        Refresh->setObjectName(QStringLiteral("Refresh"));

        gridLayout->addWidget(Refresh, 3, 2, 1, 1);

        order = new QLabel(GPIBdesign);
        order->setObjectName(QStringLiteral("order"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        order->setFont(font);

        gridLayout->addWidget(order, 4, 0, 1, 1);

        device = new QLabel(GPIBdesign);
        device->setObjectName(QStringLiteral("device"));
        device->setFont(font);

        gridLayout->addWidget(device, 3, 0, 1, 1);

        title = new QLabel(GPIBdesign);
        title->setObjectName(QStringLiteral("title"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        title->setFont(font1);
        title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(title, 1, 0, 1, 2);

        devicelist = new QComboBox(GPIBdesign);
        devicelist->setObjectName(QStringLiteral("devicelist"));

        gridLayout->addWidget(devicelist, 3, 1, 1, 1);

        listWidget = new QListWidget(GPIBdesign);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 7, 0, 1, 3);

        orderline = new QLineEdit(GPIBdesign);
        orderline->setObjectName(QStringLiteral("orderline"));

        gridLayout->addWidget(orderline, 4, 1, 1, 1);

        label = new QLabel(GPIBdesign);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 5, 0, 1, 1);

        label_2 = new QLabel(GPIBdesign);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        cutup = new QLineEdit(GPIBdesign);
        cutup->setObjectName(QStringLiteral("cutup"));

        gridLayout->addWidget(cutup, 5, 1, 1, 1);

        cutdown = new QLineEdit(GPIBdesign);
        cutdown->setObjectName(QStringLiteral("cutdown"));

        gridLayout->addWidget(cutdown, 6, 1, 1, 1);

        linebtn = new QPushButton(GPIBdesign);
        linebtn->setObjectName(QStringLiteral("linebtn"));

        gridLayout->addWidget(linebtn, 6, 2, 1, 1);


        retranslateUi(GPIBdesign);

        QMetaObject::connectSlotsByName(GPIBdesign);
    } // setupUi

    void retranslateUi(QWidget *GPIBdesign)
    {
        GPIBdesign->setWindowTitle(QApplication::translate("GPIBdesign", "Form", Q_NULLPTR));
        Refresh->setText(QApplication::translate("GPIBdesign", "refresh", Q_NULLPTR));
        order->setText(QApplication::translate("GPIBdesign", "GPIB order list", Q_NULLPTR));
        device->setText(QApplication::translate("GPIBdesign", "GPIB device list", Q_NULLPTR));
        title->setText(QApplication::translate("GPIBdesign", "GPIB Control view", Q_NULLPTR));
        label->setText(QApplication::translate("GPIBdesign", "Cutup", Q_NULLPTR));
        label_2->setText(QApplication::translate("GPIBdesign", "Cutdown", Q_NULLPTR));
        linebtn->setText(QApplication::translate("GPIBdesign", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GPIBdesign: public Ui_GPIBdesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPIBDESIGN_H

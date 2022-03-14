/********************************************************************************
** Form generated from reading UI file 'usbdesign.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USBDESIGN_H
#define UI_USBDESIGN_H

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

class Ui_USBdesign
{
public:
    QGridLayout *gridLayout;
    QPushButton *refresh;
    QComboBox *devicelist;
    QLabel *device;
    QLabel *title;
    QLabel *order;
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *orderline;
    QLabel *label_2;
    QLineEdit *cutup;
    QLineEdit *cutdown;
    QPushButton *linebtn;

    void setupUi(QWidget *USBdesign)
    {
        if (USBdesign->objectName().isEmpty())
            USBdesign->setObjectName(QStringLiteral("USBdesign"));
        USBdesign->resize(515, 421);
        gridLayout = new QGridLayout(USBdesign);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        refresh = new QPushButton(USBdesign);
        refresh->setObjectName(QStringLiteral("refresh"));

        gridLayout->addWidget(refresh, 1, 2, 1, 1);

        devicelist = new QComboBox(USBdesign);
        devicelist->setObjectName(QStringLiteral("devicelist"));

        gridLayout->addWidget(devicelist, 1, 1, 1, 1);

        device = new QLabel(USBdesign);
        device->setObjectName(QStringLiteral("device"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        device->setFont(font);

        gridLayout->addWidget(device, 1, 0, 1, 1);

        title = new QLabel(USBdesign);
        title->setObjectName(QStringLiteral("title"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        title->setFont(font1);
        title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(title, 0, 0, 1, 3);

        order = new QLabel(USBdesign);
        order->setObjectName(QStringLiteral("order"));
        order->setFont(font);

        gridLayout->addWidget(order, 2, 0, 1, 1);

        listWidget = new QListWidget(USBdesign);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 5, 0, 1, 3);

        label = new QLabel(USBdesign);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        orderline = new QLineEdit(USBdesign);
        orderline->setObjectName(QStringLiteral("orderline"));

        gridLayout->addWidget(orderline, 2, 1, 1, 1);

        label_2 = new QLabel(USBdesign);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        cutup = new QLineEdit(USBdesign);
        cutup->setObjectName(QStringLiteral("cutup"));

        gridLayout->addWidget(cutup, 3, 1, 1, 1);

        cutdown = new QLineEdit(USBdesign);
        cutdown->setObjectName(QStringLiteral("cutdown"));

        gridLayout->addWidget(cutdown, 4, 1, 1, 1);

        linebtn = new QPushButton(USBdesign);
        linebtn->setObjectName(QStringLiteral("linebtn"));

        gridLayout->addWidget(linebtn, 4, 2, 1, 1);


        retranslateUi(USBdesign);

        QMetaObject::connectSlotsByName(USBdesign);
    } // setupUi

    void retranslateUi(QWidget *USBdesign)
    {
        USBdesign->setWindowTitle(QApplication::translate("USBdesign", "Form", Q_NULLPTR));
        refresh->setText(QApplication::translate("USBdesign", "refresh", Q_NULLPTR));
        device->setText(QApplication::translate("USBdesign", "USB device list", Q_NULLPTR));
        title->setText(QApplication::translate("USBdesign", "USB Control view", Q_NULLPTR));
        order->setText(QApplication::translate("USBdesign", "USB order list", Q_NULLPTR));
        label->setText(QApplication::translate("USBdesign", "Cutup", Q_NULLPTR));
        label_2->setText(QApplication::translate("USBdesign", "Cutdown", Q_NULLPTR));
        linebtn->setText(QApplication::translate("USBdesign", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class USBdesign: public Ui_USBdesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USBDESIGN_H

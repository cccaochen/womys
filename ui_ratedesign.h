/********************************************************************************
** Form generated from reading UI file 'ratedesign.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RATEDESIGN_H
#define UI_RATEDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ratedesign
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QLabel *Serialportlab;
    QComboBox *Serialport;
    QLabel *Buadratelab;
    QComboBox *Baudrate;
    QLabel *Databitslab;
    QComboBox *Databits;
    QLabel *Paritylab;
    QComboBox *Parity;
    QLabel *Stopbitslab;
    QComboBox *Stopbits;
    QLabel *Flowlab;
    QComboBox *FlowControls;
    QLabel *Orderlab;
    QLineEdit *orderline;
    QLabel *label;
    QLineEdit *cutup;
    QLabel *label_2;
    QLineEdit *cutdown;
    QPushButton *OKbtn;

    void setupUi(QWidget *ratedesign)
    {
        if (ratedesign->objectName().isEmpty())
            ratedesign->setObjectName(QStringLiteral("ratedesign"));
        ratedesign->resize(519, 484);
        verticalLayout = new QVBoxLayout(ratedesign);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        title = new QLabel(ratedesign);
        title->setObjectName(QStringLiteral("title"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(title);

        Serialportlab = new QLabel(ratedesign);
        Serialportlab->setObjectName(QStringLiteral("Serialportlab"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        Serialportlab->setFont(font1);

        verticalLayout->addWidget(Serialportlab);

        Serialport = new QComboBox(ratedesign);
        Serialport->setObjectName(QStringLiteral("Serialport"));

        verticalLayout->addWidget(Serialport);

        Buadratelab = new QLabel(ratedesign);
        Buadratelab->setObjectName(QStringLiteral("Buadratelab"));
        Buadratelab->setFont(font1);

        verticalLayout->addWidget(Buadratelab);

        Baudrate = new QComboBox(ratedesign);
        Baudrate->setObjectName(QStringLiteral("Baudrate"));

        verticalLayout->addWidget(Baudrate);

        Databitslab = new QLabel(ratedesign);
        Databitslab->setObjectName(QStringLiteral("Databitslab"));
        Databitslab->setFont(font1);

        verticalLayout->addWidget(Databitslab);

        Databits = new QComboBox(ratedesign);
        Databits->setObjectName(QStringLiteral("Databits"));

        verticalLayout->addWidget(Databits);

        Paritylab = new QLabel(ratedesign);
        Paritylab->setObjectName(QStringLiteral("Paritylab"));
        Paritylab->setFont(font1);

        verticalLayout->addWidget(Paritylab);

        Parity = new QComboBox(ratedesign);
        Parity->setObjectName(QStringLiteral("Parity"));

        verticalLayout->addWidget(Parity);

        Stopbitslab = new QLabel(ratedesign);
        Stopbitslab->setObjectName(QStringLiteral("Stopbitslab"));
        Stopbitslab->setFont(font1);

        verticalLayout->addWidget(Stopbitslab);

        Stopbits = new QComboBox(ratedesign);
        Stopbits->setObjectName(QStringLiteral("Stopbits"));

        verticalLayout->addWidget(Stopbits);

        Flowlab = new QLabel(ratedesign);
        Flowlab->setObjectName(QStringLiteral("Flowlab"));
        Flowlab->setFont(font1);

        verticalLayout->addWidget(Flowlab);

        FlowControls = new QComboBox(ratedesign);
        FlowControls->setObjectName(QStringLiteral("FlowControls"));

        verticalLayout->addWidget(FlowControls);

        Orderlab = new QLabel(ratedesign);
        Orderlab->setObjectName(QStringLiteral("Orderlab"));
        Orderlab->setFont(font1);

        verticalLayout->addWidget(Orderlab);

        orderline = new QLineEdit(ratedesign);
        orderline->setObjectName(QStringLiteral("orderline"));

        verticalLayout->addWidget(orderline);

        label = new QLabel(ratedesign);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);
        label->setCursor(QCursor(Qt::ArrowCursor));

        verticalLayout->addWidget(label);

        cutup = new QLineEdit(ratedesign);
        cutup->setObjectName(QStringLiteral("cutup"));

        verticalLayout->addWidget(cutup);

        label_2 = new QLabel(ratedesign);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        cutdown = new QLineEdit(ratedesign);
        cutdown->setObjectName(QStringLiteral("cutdown"));

        verticalLayout->addWidget(cutdown);

        OKbtn = new QPushButton(ratedesign);
        OKbtn->setObjectName(QStringLiteral("OKbtn"));

        verticalLayout->addWidget(OKbtn);


        retranslateUi(ratedesign);

        QMetaObject::connectSlotsByName(ratedesign);
    } // setupUi

    void retranslateUi(QWidget *ratedesign)
    {
        ratedesign->setWindowTitle(QApplication::translate("ratedesign", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("ratedesign", "RS232 Control view", Q_NULLPTR));
        Serialportlab->setText(QApplication::translate("ratedesign", "Serialport", Q_NULLPTR));
        Buadratelab->setText(QApplication::translate("ratedesign", "Buadrate", Q_NULLPTR));
        Databitslab->setText(QApplication::translate("ratedesign", "Databits", Q_NULLPTR));
        Paritylab->setText(QApplication::translate("ratedesign", "Parity", Q_NULLPTR));
        Stopbitslab->setText(QApplication::translate("ratedesign", "Stopbits", Q_NULLPTR));
        Flowlab->setText(QApplication::translate("ratedesign", "FlowControl", Q_NULLPTR));
        Orderlab->setText(QApplication::translate("ratedesign", "Order", Q_NULLPTR));
        label->setText(QApplication::translate("ratedesign", "Cutup", Q_NULLPTR));
        label_2->setText(QApplication::translate("ratedesign", "Cutdown", Q_NULLPTR));
        OKbtn->setText(QApplication::translate("ratedesign", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ratedesign: public Ui_ratedesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RATEDESIGN_H

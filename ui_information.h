/********************************************************************************
** Form generated from reading UI file 'information.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_H
#define UI_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_information
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *displaytable;
    QPushButton *seqbtn;
    QPushButton *OKbtn;

    void setupUi(QWidget *information)
    {
        if (information->objectName().isEmpty())
            information->setObjectName(QStringLiteral("information"));
        information->resize(623, 444);
        verticalLayout = new QVBoxLayout(information);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(information);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        displaytable = new QTableWidget(information);
        displaytable->setObjectName(QStringLiteral("displaytable"));

        verticalLayout->addWidget(displaytable);

        seqbtn = new QPushButton(information);
        seqbtn->setObjectName(QStringLiteral("seqbtn"));

        verticalLayout->addWidget(seqbtn);

        OKbtn = new QPushButton(information);
        OKbtn->setObjectName(QStringLiteral("OKbtn"));

        verticalLayout->addWidget(OKbtn);


        retranslateUi(information);

        QMetaObject::connectSlotsByName(information);
    } // setupUi

    void retranslateUi(QWidget *information)
    {
        information->setWindowTitle(QApplication::translate("information", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("information", "information update", Q_NULLPTR));
        seqbtn->setText(QApplication::translate("information", "openseq", Q_NULLPTR));
        OKbtn->setText(QApplication::translate("information", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class information: public Ui_information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_H

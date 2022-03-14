/********************************************************************************
** Form generated from reading UI file 'rename.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAME_H
#define UI_RENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rename
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Namelab;
    QLineEdit *Name;
    QPushButton *Okbtn;

    void setupUi(QWidget *Rename)
    {
        if (Rename->objectName().isEmpty())
            Rename->setObjectName(QStringLiteral("Rename"));
        Rename->resize(250, 95);
        verticalLayout = new QVBoxLayout(Rename);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Namelab = new QLabel(Rename);
        Namelab->setObjectName(QStringLiteral("Namelab"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Namelab->setFont(font);
        Namelab->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Namelab);

        Name = new QLineEdit(Rename);
        Name->setObjectName(QStringLiteral("Name"));

        verticalLayout->addWidget(Name);

        Okbtn = new QPushButton(Rename);
        Okbtn->setObjectName(QStringLiteral("Okbtn"));

        verticalLayout->addWidget(Okbtn);


        retranslateUi(Rename);

        QMetaObject::connectSlotsByName(Rename);
    } // setupUi

    void retranslateUi(QWidget *Rename)
    {
        Rename->setWindowTitle(QApplication::translate("Rename", "Form", Q_NULLPTR));
        Namelab->setText(QApplication::translate("Rename", "Newname", Q_NULLPTR));
        Okbtn->setText(QApplication::translate("Rename", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Rename: public Ui_Rename {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAME_H

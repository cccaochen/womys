/********************************************************************************
** Form generated from reading UI file 'landesign.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANDESIGN_H
#define UI_LANDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LANdesign
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *LANdesign)
    {
        if (LANdesign->objectName().isEmpty())
            LANdesign->setObjectName(QStringLiteral("LANdesign"));
        LANdesign->resize(409, 382);
        label = new QLabel(LANdesign);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 101, 16));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        comboBox = new QComboBox(LANdesign);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 50, 201, 22));
        label_2 = new QLabel(LANdesign);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 20, 211, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(LANdesign);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 91, 16));
        label_3->setFont(font);
        lineEdit = new QLineEdit(LANdesign);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 90, 201, 20));
        pushButton = new QPushButton(LANdesign);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 50, 61, 23));
        pushButton_2 = new QPushButton(LANdesign);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 90, 61, 23));
        textEdit = new QTextEdit(LANdesign);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 120, 381, 241));

        retranslateUi(LANdesign);

        QMetaObject::connectSlotsByName(LANdesign);
    } // setupUi

    void retranslateUi(QWidget *LANdesign)
    {
        LANdesign->setWindowTitle(QApplication::translate("LANdesign", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("LANdesign", "LAN device list", Q_NULLPTR));
        label_2->setText(QApplication::translate("LANdesign", "LAN Control view", Q_NULLPTR));
        label_3->setText(QApplication::translate("LANdesign", "LAN order list", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LANdesign", "refresh", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("LANdesign", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LANdesign: public Ui_LANdesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANDESIGN_H

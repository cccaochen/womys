/********************************************************************************
** Form generated from reading UI file 'scdesign.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCDESIGN_H
#define UI_SCDESIGN_H

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

class Ui_SCdesign
{
public:
    QGridLayout *gridLayout;
    QLineEdit *cutup;
    QLabel *title;
    QListWidget *listWidget;
    QLabel *SeqPathlab;
    QLineEdit *SeqPath;
    QPushButton *OpenPath;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *cutdown;
    QPushButton *decide;

    void setupUi(QWidget *SCdesign)
    {
        if (SCdesign->objectName().isEmpty())
            SCdesign->setObjectName(QStringLiteral("SCdesign"));
        SCdesign->resize(738, 400);
        gridLayout = new QGridLayout(SCdesign);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cutup = new QLineEdit(SCdesign);
        cutup->setObjectName(QStringLiteral("cutup"));

        gridLayout->addWidget(cutup, 3, 1, 1, 1);

        title = new QLabel(SCdesign);
        title->setObjectName(QStringLiteral("title"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(title, 1, 1, 1, 1);

        listWidget = new QListWidget(SCdesign);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 5, 0, 1, 3);

        SeqPathlab = new QLabel(SCdesign);
        SeqPathlab->setObjectName(QStringLiteral("SeqPathlab"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        SeqPathlab->setFont(font1);

        gridLayout->addWidget(SeqPathlab, 2, 0, 1, 1);

        SeqPath = new QLineEdit(SCdesign);
        SeqPath->setObjectName(QStringLiteral("SeqPath"));

        gridLayout->addWidget(SeqPath, 2, 1, 1, 1);

        OpenPath = new QPushButton(SCdesign);
        OpenPath->setObjectName(QStringLiteral("OpenPath"));

        gridLayout->addWidget(OpenPath, 2, 2, 1, 1);

        label = new QLabel(SCdesign);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_2 = new QLabel(SCdesign);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        cutdown = new QLineEdit(SCdesign);
        cutdown->setObjectName(QStringLiteral("cutdown"));

        gridLayout->addWidget(cutdown, 4, 1, 1, 1);

        decide = new QPushButton(SCdesign);
        decide->setObjectName(QStringLiteral("decide"));

        gridLayout->addWidget(decide, 4, 2, 1, 1);


        retranslateUi(SCdesign);

        QMetaObject::connectSlotsByName(SCdesign);
    } // setupUi

    void retranslateUi(QWidget *SCdesign)
    {
        SCdesign->setWindowTitle(QApplication::translate("SCdesign", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("SCdesign", "SoundCheck 12.0 Control view", Q_NULLPTR));
        SeqPathlab->setText(QApplication::translate("SCdesign", "Open Sequence Path", Q_NULLPTR));
        OpenPath->setText(QApplication::translate("SCdesign", "Open", Q_NULLPTR));
        label->setText(QApplication::translate("SCdesign", "Cutup", Q_NULLPTR));
        label_2->setText(QApplication::translate("SCdesign", "Cutdown", Q_NULLPTR));
        decide->setText(QApplication::translate("SCdesign", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SCdesign: public Ui_SCdesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCDESIGN_H

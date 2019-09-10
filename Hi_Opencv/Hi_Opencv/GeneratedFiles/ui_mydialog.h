/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mydialog
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *mydialog)
    {
        if (mydialog->objectName().isEmpty())
            mydialog->setObjectName(QStringLiteral("mydialog"));
        mydialog->resize(399, 241);
        label = new QLabel(mydialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 60, 241, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        label->setFont(font);
        pushButton = new QPushButton(mydialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 150, 75, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        pushButton->setFont(font1);

        retranslateUi(mydialog);
        QObject::connect(pushButton, SIGNAL(clicked()), mydialog, SLOT(hide()));

        QMetaObject::connectSlotsByName(mydialog);
    } // setupUi

    void retranslateUi(QDialog *mydialog)
    {
        mydialog->setWindowTitle(QApplication::translate("mydialog", "mydialog", Q_NULLPTR));
        label->setText(QApplication::translate("mydialog", "\350\276\223\345\205\245\346\234\211\350\257\257\357\274\214\350\257\267\350\276\223\345\205\245\346\255\243\345\245\207\346\225\260\343\200\202", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mydialog", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mydialog: public Ui_mydialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'warning.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNING_H
#define UI_WARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_warning
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *warning)
    {
        if (warning->objectName().isEmpty())
            warning->setObjectName(QStringLiteral("warning"));
        warning->resize(385, 325);
        label = new QLabel(warning);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 321, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        label->setFont(font);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        pushButton = new QPushButton(warning);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 230, 75, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton->setFont(font1);

        retranslateUi(warning);
        QObject::connect(pushButton, SIGNAL(clicked()), warning, SLOT(close()));

        QMetaObject::connectSlotsByName(warning);
    } // setupUi

    void retranslateUi(QDialog *warning)
    {
        warning->setWindowTitle(QApplication::translate("warning", "warning", Q_NULLPTR));
        label->setText(QApplication::translate("warning", "Incorrect input, Please enter positive number.", Q_NULLPTR));
        pushButton->setText(QApplication::translate("warning", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class warning: public Ui_warning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNING_H

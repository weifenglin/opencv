/********************************************************************************
** Form generated from reading UI file 'Hi_Opencv.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HI_OPENCV_H
#define UI_HI_OPENCV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hi_OpencvClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionblur;
    QAction *actiongaussian;
    QAction *actionmedian;
    QAction *actionBilateral;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_blur;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_gaussian;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_10;
    QLabel *label_in;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_12;
    QLabel *label_out;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_open;
    QPushButton *pushButton_start;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_w;
    QLineEdit *lineEdit_w;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_h;
    QLineEdit *lineEdit_h;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_i;
    QLineEdit *lineEdit_i;
    QSpacerItem *horizontalSpacer_6;
    QWidget *tab_2;
    QWidget *tab_3;
    QPushButton *Button_31;
    QPushButton *Button_33;
    QPushButton *Button_34;
    QPushButton *Button_35;
    QScrollArea *scrollArea_open31;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_open32;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_by1;
    QLabel *label_31;
    QLineEdit *lineEdit31;
    QPushButton *pushButton_open_2;
    QPushButton *pushButton_31;
    QPushButton *Button_32;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Hi_OpencvClass)
    {
        if (Hi_OpencvClass->objectName().isEmpty())
            Hi_OpencvClass->setObjectName(QStringLiteral("Hi_OpencvClass"));
        Hi_OpencvClass->resize(1043, 581);
        actionOpen = new QAction(Hi_OpencvClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(Hi_OpencvClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionblur = new QAction(Hi_OpencvClass);
        actionblur->setObjectName(QStringLiteral("actionblur"));
        actiongaussian = new QAction(Hi_OpencvClass);
        actiongaussian->setObjectName(QStringLiteral("actiongaussian"));
        actionmedian = new QAction(Hi_OpencvClass);
        actionmedian->setObjectName(QStringLiteral("actionmedian"));
        actionBilateral = new QAction(Hi_OpencvClass);
        actionBilateral->setObjectName(QStringLiteral("actionBilateral"));
        centralWidget = new QWidget(Hi_OpencvClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 1051, 531));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 77, 376));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        pushButton_blur = new QPushButton(layoutWidget);
        pushButton_blur->setObjectName(QStringLiteral("pushButton_blur"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        pushButton_blur->setFont(font);

        verticalLayout->addWidget(pushButton_blur);

        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pushButton_gaussian = new QPushButton(layoutWidget);
        pushButton_gaussian->setObjectName(QStringLiteral("pushButton_gaussian"));
        pushButton_gaussian->setFont(font);

        verticalLayout->addWidget(pushButton_gaussian);

        verticalSpacer_2 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font);

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setFont(font);

        verticalLayout->addWidget(pushButton_4);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(92, 9, 331, 381));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(50, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        verticalSpacer_10 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_10);

        label_in = new QLabel(layoutWidget1);
        label_in->setObjectName(QStringLiteral("label_in"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_in->sizePolicy().hasHeightForWidth());
        label_in->setSizePolicy(sizePolicy);
        label_in->setMinimumSize(QSize(0, 0));
        label_in->setScaledContents(true);

        verticalLayout_2->addWidget(label_in);

        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(430, 10, 321, 381));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(50, 20));
        label_2->setFont(font1);

        verticalLayout_3->addWidget(label_2);

        verticalSpacer_12 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_3->addItem(verticalSpacer_12);

        label_out = new QLabel(layoutWidget2);
        label_out->setObjectName(QStringLiteral("label_out"));
        sizePolicy.setHeightForWidth(label_out->sizePolicy().hasHeightForWidth());
        label_out->setSizePolicy(sizePolicy);
        label_out->setMinimumSize(QSize(0, 0));
        label_out->setScaledContents(true);

        verticalLayout_3->addWidget(label_out);

        layoutWidget3 = new QWidget(tab);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(760, 10, 186, 381));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_open = new QPushButton(layoutWidget3);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));
        pushButton_open->setFont(font);

        horizontalLayout_2->addWidget(pushButton_open);

        pushButton_start = new QPushButton(layoutWidget3);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setEnabled(false);
        pushButton_start->setFont(font);

        horizontalLayout_2->addWidget(pushButton_start);


        verticalLayout_4->addLayout(horizontalLayout_2);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        verticalSpacer_6 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_w = new QLabel(layoutWidget3);
        label_w->setObjectName(QStringLiteral("label_w"));
        label_w->setFont(font1);

        horizontalLayout_3->addWidget(label_w);

        lineEdit_w = new QLineEdit(layoutWidget3);
        lineEdit_w->setObjectName(QStringLiteral("lineEdit_w"));

        horizontalLayout_3->addWidget(lineEdit_w);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer_7 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_h = new QLabel(layoutWidget3);
        label_h->setObjectName(QStringLiteral("label_h"));
        label_h->setFont(font1);

        horizontalLayout_4->addWidget(label_h);

        lineEdit_h = new QLineEdit(layoutWidget3);
        lineEdit_h->setObjectName(QStringLiteral("lineEdit_h"));

        horizontalLayout_4->addWidget(lineEdit_h);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalSpacer_8 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_i = new QLabel(layoutWidget3);
        label_i->setObjectName(QStringLiteral("label_i"));
        label_i->setFont(font1);

        horizontalLayout_5->addWidget(label_i);

        lineEdit_i = new QLineEdit(layoutWidget3);
        lineEdit_i->setObjectName(QStringLiteral("lineEdit_i"));

        horizontalLayout_5->addWidget(lineEdit_i);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        Button_31 = new QPushButton(tab_3);
        Button_31->setObjectName(QStringLiteral("Button_31"));
        Button_31->setGeometry(QRect(10, 30, 91, 23));
        Button_31->setFont(font);
        Button_33 = new QPushButton(tab_3);
        Button_33->setObjectName(QStringLiteral("Button_33"));
        Button_33->setGeometry(QRect(10, 150, 91, 23));
        Button_33->setFont(font);
        Button_34 = new QPushButton(tab_3);
        Button_34->setObjectName(QStringLiteral("Button_34"));
        Button_34->setGeometry(QRect(10, 210, 91, 23));
        Button_34->setFont(font);
        Button_35 = new QPushButton(tab_3);
        Button_35->setObjectName(QStringLiteral("Button_35"));
        Button_35->setGeometry(QRect(10, 270, 91, 23));
        Button_35->setFont(font);
        scrollArea_open31 = new QScrollArea(tab_3);
        scrollArea_open31->setObjectName(QStringLiteral("scrollArea_open31"));
        scrollArea_open31->setGeometry(QRect(110, 30, 351, 321));
        scrollArea_open31->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 349, 319));
        scrollArea_open31->setWidget(scrollAreaWidgetContents);
        scrollArea_open32 = new QScrollArea(tab_3);
        scrollArea_open32->setObjectName(QStringLiteral("scrollArea_open32"));
        scrollArea_open32->setGeometry(QRect(450, 30, 351, 321));
        scrollArea_open32->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 349, 319));
        scrollArea_open32->setWidget(scrollAreaWidgetContents_2);
        label_by1 = new QLabel(tab_3);
        label_by1->setObjectName(QStringLiteral("label_by1"));
        label_by1->setGeometry(QRect(840, 60, 191, 20));
        label_31 = new QLabel(tab_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(840, 110, 111, 26));
        label_31->setFont(font1);
        lineEdit31 = new QLineEdit(tab_3);
        lineEdit31->setObjectName(QStringLiteral("lineEdit31"));
        lineEdit31->setGeometry(QRect(950, 110, 91, 20));
        pushButton_open_2 = new QPushButton(tab_3);
        pushButton_open_2->setObjectName(QStringLiteral("pushButton_open_2"));
        pushButton_open_2->setGeometry(QRect(854, 30, 91, 23));
        pushButton_31 = new QPushButton(tab_3);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        pushButton_31->setGeometry(QRect(940, 30, 81, 23));
        Button_32 = new QPushButton(tab_3);
        Button_32->setObjectName(QStringLiteral("Button_32"));
        Button_32->setGeometry(QRect(10, 90, 91, 23));
        Button_32->setFont(font);
        tabWidget->addTab(tab_3, QString());
        Hi_OpencvClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Hi_OpencvClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Hi_OpencvClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Hi_OpencvClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Hi_OpencvClass->setStatusBar(statusBar);

        retranslateUi(Hi_OpencvClass);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_median_show()));
        QObject::connect(pushButton_blur, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_blur_show()));
        QObject::connect(pushButton_gaussian, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_gaussian_show()));
        QObject::connect(pushButton_open, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_open()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_Bilateral_show()));
        QObject::connect(pushButton_start, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_start()));
        QObject::connect(Button_31, SIGNAL(clicked()), tabWidget, SLOT(on_sobel_show()));
        QObject::connect(Button_31, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_sobel_show()));
        QObject::connect(pushButton_open_2, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_byopen()));
        QObject::connect(pushButton_31, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_bystart()));
        QObject::connect(Button_32, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_laplace_show()));
        QObject::connect(Button_33, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_canny_show()));
        QObject::connect(Button_34, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_HoughLine_show()));
        QObject::connect(Button_35, SIGNAL(clicked()), Hi_OpencvClass, SLOT(on_findContours_show()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Hi_OpencvClass);
    } // setupUi

    void retranslateUi(QMainWindow *Hi_OpencvClass)
    {
        Hi_OpencvClass->setWindowTitle(QApplication::translate("Hi_OpencvClass", "Hi_Opencv", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("Hi_OpencvClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("Hi_OpencvClass", "Save", Q_NULLPTR));
        actionblur->setText(QApplication::translate("Hi_OpencvClass", "blur", Q_NULLPTR));
        actiongaussian->setText(QApplication::translate("Hi_OpencvClass", "gaussian", Q_NULLPTR));
        actionmedian->setText(QApplication::translate("Hi_OpencvClass", "median", Q_NULLPTR));
        actionBilateral->setText(QApplication::translate("Hi_OpencvClass", "Bilateral", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("Hi_OpencvClass", "<html><head/><body><p><br/></p><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QApplication::translate("Hi_OpencvClass", "<html><head/><body><p>dede</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        pushButton_blur->setText(QApplication::translate("Hi_OpencvClass", "blur", Q_NULLPTR));
        pushButton_gaussian->setText(QApplication::translate("Hi_OpencvClass", "gaussian", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Hi_OpencvClass", "median", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Hi_OpencvClass", "Bilateral", Q_NULLPTR));
        label->setText(QApplication::translate("Hi_OpencvClass", "input", Q_NULLPTR));
        label_in->setText(QString());
        label_2->setText(QApplication::translate("Hi_OpencvClass", "output", Q_NULLPTR));
        label_out->setText(QString());
        pushButton_open->setText(QApplication::translate("Hi_OpencvClass", "Open", Q_NULLPTR));
        pushButton_start->setText(QApplication::translate("Hi_OpencvClass", "start", Q_NULLPTR));
        label_3->setText(QApplication::translate("Hi_OpencvClass", "\345\233\276\345\203\217\346\250\241\347\263\212", Q_NULLPTR));
        label_w->setText(QApplication::translate("Hi_OpencvClass", "\345\203\217\347\264\240\345\256\275\345\272\246w\357\274\232", Q_NULLPTR));
        label_h->setText(QApplication::translate("Hi_OpencvClass", "\345\203\217\347\264\240\351\253\230\345\272\246h\357\274\232", Q_NULLPTR));
        label_i->setText(QApplication::translate("Hi_OpencvClass", "\345\206\205\346\240\270\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Hi_OpencvClass", "\345\233\276\345\203\217\346\250\241\347\263\212", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Hi_OpencvClass", "\345\233\276\345\203\217\345\271\263\346\273\221", Q_NULLPTR));
        Button_31->setText(QApplication::translate("Hi_OpencvClass", "Sobel\345\257\274\346\225\260", Q_NULLPTR));
        Button_33->setText(QApplication::translate("Hi_OpencvClass", "Canny \346\243\200\346\265\213", Q_NULLPTR));
        Button_34->setText(QApplication::translate("Hi_OpencvClass", "\351\234\215\345\244\253\347\272\277\345\217\230\346\215\242", Q_NULLPTR));
        Button_35->setText(QApplication::translate("Hi_OpencvClass", "\345\257\273\346\211\276\350\275\256\345\273\223", Q_NULLPTR));
        label_by1->setText(QApplication::translate("Hi_OpencvClass", "\350\257\267\351\200\211\346\213\251\345\212\237\350\203\275", Q_NULLPTR));
        label_31->setText(QApplication::translate("Hi_OpencvClass", "\351\231\215\345\231\252\345\206\205\346\240\270\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        pushButton_open_2->setText(QApplication::translate("Hi_OpencvClass", "open", Q_NULLPTR));
        pushButton_31->setText(QApplication::translate("Hi_OpencvClass", "start", Q_NULLPTR));
        Button_32->setText(QApplication::translate("Hi_OpencvClass", "Laplace\347\256\227\345\255\220", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Hi_OpencvClass", "\350\276\271\347\274\230\346\243\200\346\265\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Hi_OpencvClass: public Ui_Hi_OpencvClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HI_OPENCV_H

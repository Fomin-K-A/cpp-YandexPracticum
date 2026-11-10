/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_reset;
    QAction *action_close;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pb_sett_2;
    QPushButton *pb_button_1;
    QPushButton *pb_sett_1;
    QPushButton *pb_button_4;
    QPushButton *pb_button_3;
    QPushButton *pb_sett_4;
    QPushButton *pb_button_2;
    QPushButton *pb_sett_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(185, 169);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action->setCheckable(true);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_2->setCheckable(true);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        action_3->setCheckable(false);
        action_3->setChecked(false);
        action_reset = new QAction(MainWindow);
        action_reset->setObjectName("action_reset");
        action_close = new QAction(MainWindow);
        action_close->setObjectName("action_close");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        pb_sett_2 = new QPushButton(centralwidget);
        pb_sett_2->setObjectName("pb_sett_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_sett_2->sizePolicy().hasHeightForWidth());
        pb_sett_2->setSizePolicy(sizePolicy);
        pb_sett_2->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(pb_sett_2, 1, 1, 1, 1);

        pb_button_1 = new QPushButton(centralwidget);
        pb_button_1->setObjectName("pb_button_1");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pb_button_1->sizePolicy().hasHeightForWidth());
        pb_button_1->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(9);
        pb_button_1->setFont(font);

        gridLayout->addWidget(pb_button_1, 0, 0, 1, 1);

        pb_sett_1 = new QPushButton(centralwidget);
        pb_sett_1->setObjectName("pb_sett_1");
        sizePolicy.setHeightForWidth(pb_sett_1->sizePolicy().hasHeightForWidth());
        pb_sett_1->setSizePolicy(sizePolicy);
        pb_sett_1->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(pb_sett_1, 0, 1, 1, 1);

        pb_button_4 = new QPushButton(centralwidget);
        pb_button_4->setObjectName("pb_button_4");
        sizePolicy1.setHeightForWidth(pb_button_4->sizePolicy().hasHeightForWidth());
        pb_button_4->setSizePolicy(sizePolicy1);
        pb_button_4->setFont(font);

        gridLayout->addWidget(pb_button_4, 3, 0, 1, 1);

        pb_button_3 = new QPushButton(centralwidget);
        pb_button_3->setObjectName("pb_button_3");
        sizePolicy1.setHeightForWidth(pb_button_3->sizePolicy().hasHeightForWidth());
        pb_button_3->setSizePolicy(sizePolicy1);
        pb_button_3->setFont(font);

        gridLayout->addWidget(pb_button_3, 2, 0, 1, 1);

        pb_sett_4 = new QPushButton(centralwidget);
        pb_sett_4->setObjectName("pb_sett_4");
        sizePolicy.setHeightForWidth(pb_sett_4->sizePolicy().hasHeightForWidth());
        pb_sett_4->setSizePolicy(sizePolicy);
        pb_sett_4->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(pb_sett_4, 3, 1, 1, 1);

        pb_button_2 = new QPushButton(centralwidget);
        pb_button_2->setObjectName("pb_button_2");
        sizePolicy1.setHeightForWidth(pb_button_2->sizePolicy().hasHeightForWidth());
        pb_button_2->setSizePolicy(sizePolicy1);
        pb_button_2->setFont(font);

        gridLayout->addWidget(pb_button_2, 1, 0, 1, 1);

        pb_sett_3 = new QPushButton(centralwidget);
        pb_sett_3->setObjectName("pb_sett_3");
        sizePolicy.setHeightForWidth(pb_sett_3->sizePolicy().hasHeightForWidth());
        pb_sett_3->setSizePolicy(sizePolicy);
        pb_sett_3->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(pb_sett_3, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(action_close, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Magic Buttons", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\257\320\275\320\264\320\265\320\272\321\201", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\237\321\200\320\260\320\272\321\202\320\270\320\272\321\203\320\274", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        action_reset->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\321\203", nullptr));
        action_close->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203", nullptr));
        pb_sett_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pb_button_1->setText(QCoreApplication::translate("MainWindow", "\320\232\320\275\320\276\320\277\320\272\320\260 1", nullptr));
        pb_sett_1->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pb_button_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\275\320\276\320\277\320\272\320\260 4", nullptr));
        pb_button_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\275\320\276\320\277\320\272\320\260 3", nullptr));
        pb_sett_4->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pb_button_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\275\320\276\320\277\320\272\320\260 2", nullptr));
        pb_sett_3->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

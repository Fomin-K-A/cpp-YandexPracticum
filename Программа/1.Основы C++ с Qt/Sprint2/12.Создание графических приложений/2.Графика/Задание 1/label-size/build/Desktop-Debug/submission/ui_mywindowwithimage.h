/********************************************************************************
** Form generated from reading UI file 'mywindowwithimage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWINDOWWITHIMAGE_H
#define UI_MYWINDOWWITHIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWindowWithImage
{
public:
    QWidget *centralwidget;
    QLabel *lbl_pixmap;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyWindowWithImage)
    {
        if (MyWindowWithImage->objectName().isEmpty())
            MyWindowWithImage->setObjectName("MyWindowWithImage");
        MyWindowWithImage->resize(340, 240);
        MyWindowWithImage->setMinimumSize(QSize(340, 240));
        MyWindowWithImage->setMaximumSize(QSize(340, 240));
        centralwidget = new QWidget(MyWindowWithImage);
        centralwidget->setObjectName("centralwidget");
        lbl_pixmap = new QLabel(centralwidget);
        lbl_pixmap->setObjectName("lbl_pixmap");
        lbl_pixmap->setGeometry(QRect(40, 30, 251, 101));
        MyWindowWithImage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyWindowWithImage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 340, 24));
        MyWindowWithImage->setMenuBar(menubar);
        statusbar = new QStatusBar(MyWindowWithImage);
        statusbar->setObjectName("statusbar");
        MyWindowWithImage->setStatusBar(statusbar);

        retranslateUi(MyWindowWithImage);

        QMetaObject::connectSlotsByName(MyWindowWithImage);
    } // setupUi

    void retranslateUi(QMainWindow *MyWindowWithImage)
    {
        MyWindowWithImage->setWindowTitle(QCoreApplication::translate("MyWindowWithImage", "My Window With Image", nullptr));
        lbl_pixmap->setText(QCoreApplication::translate("MyWindowWithImage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWindowWithImage: public Ui_MyWindowWithImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWINDOWWITHIMAGE_H

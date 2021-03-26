/********************************************************************************
** Form generated from reading UI file 'ExamGuide.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMGUIDE_H
#define UI_EXAMGUIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamGuideClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamGuideClass)
    {
        if (ExamGuideClass->objectName().isEmpty())
            ExamGuideClass->setObjectName(QString::fromUtf8("ExamGuideClass"));
        ExamGuideClass->resize(600, 400);
        menuBar = new QMenuBar(ExamGuideClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ExamGuideClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamGuideClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ExamGuideClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ExamGuideClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ExamGuideClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ExamGuideClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ExamGuideClass->setStatusBar(statusBar);

        retranslateUi(ExamGuideClass);

        QMetaObject::connectSlotsByName(ExamGuideClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamGuideClass)
    {
        ExamGuideClass->setWindowTitle(QCoreApplication::translate("ExamGuideClass", "ExamGuide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamGuideClass: public Ui_ExamGuideClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMGUIDE_H

/********************************************************************************
** Form generated from reading UI file 'UserWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *IssueslistWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *DescriptionlineEdit;
    QLabel *label_2;
    QLineEdit *StatelineEdit;
    QLabel *label_3;
    QLineEdit *ReporterlineEdit;
    QLabel *label_4;
    QLineEdit *SolverlineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddpushButton;
    QPushButton *SolvepushButton;
    QPushButton *RemovepushButton;

    void setupUi(QWidget *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(747, 520);
        verticalLayout = new QVBoxLayout(UserWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        IssueslistWidget = new QListWidget(UserWindow);
        IssueslistWidget->setObjectName(QString::fromUtf8("IssueslistWidget"));

        verticalLayout->addWidget(IssueslistWidget);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(UserWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        DescriptionlineEdit = new QLineEdit(UserWindow);
        DescriptionlineEdit->setObjectName(QString::fromUtf8("DescriptionlineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, DescriptionlineEdit);

        label_2 = new QLabel(UserWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        StatelineEdit = new QLineEdit(UserWindow);
        StatelineEdit->setObjectName(QString::fromUtf8("StatelineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, StatelineEdit);

        label_3 = new QLabel(UserWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        ReporterlineEdit = new QLineEdit(UserWindow);
        ReporterlineEdit->setObjectName(QString::fromUtf8("ReporterlineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ReporterlineEdit);

        label_4 = new QLabel(UserWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        SolverlineEdit = new QLineEdit(UserWindow);
        SolverlineEdit->setObjectName(QString::fromUtf8("SolverlineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, SolverlineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        AddpushButton = new QPushButton(UserWindow);
        AddpushButton->setObjectName(QString::fromUtf8("AddpushButton"));
        QFont font1;
        font1.setPointSize(14);
        AddpushButton->setFont(font1);

        horizontalLayout->addWidget(AddpushButton);

        SolvepushButton = new QPushButton(UserWindow);
        SolvepushButton->setObjectName(QString::fromUtf8("SolvepushButton"));
        SolvepushButton->setFont(font1);

        horizontalLayout->addWidget(SolvepushButton);

        RemovepushButton = new QPushButton(UserWindow);
        RemovepushButton->setObjectName(QString::fromUtf8("RemovepushButton"));
        RemovepushButton->setFont(font1);

        horizontalLayout->addWidget(RemovepushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QWidget *UserWindow)
    {
        UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "UserWindow", nullptr));
        label->setText(QCoreApplication::translate("UserWindow", "Description", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindow", "State", nullptr));
        label_3->setText(QCoreApplication::translate("UserWindow", "Reporter", nullptr));
        label_4->setText(QCoreApplication::translate("UserWindow", "Solver", nullptr));
        AddpushButton->setText(QCoreApplication::translate("UserWindow", "Add Issue", nullptr));
        SolvepushButton->setText(QCoreApplication::translate("UserWindow", "Solve Issue", nullptr));
        RemovepushButton->setText(QCoreApplication::translate("UserWindow", "Remove Issue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H

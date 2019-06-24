/********************************************************************************
** Form generated from reading UI file 'Programmer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMER_H
#define UI_PROGRAMMER_H

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

class Ui_ProgrammerClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *issuesList;
    QFormLayout *formLayout;
    QLineEdit *issueInput;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *solveButton;

    void setupUi(QWidget *ProgrammerClass)
    {
        if (ProgrammerClass->objectName().isEmpty())
            ProgrammerClass->setObjectName(QString::fromUtf8("ProgrammerClass"));
        ProgrammerClass->resize(600, 400);
        verticalLayout_2 = new QVBoxLayout(ProgrammerClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        issuesList = new QListWidget(ProgrammerClass);
        issuesList->setObjectName(QString::fromUtf8("issuesList"));

        verticalLayout->addWidget(issuesList);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        issueInput = new QLineEdit(ProgrammerClass);
        issueInput->setObjectName(QString::fromUtf8("issueInput"));

        formLayout->setWidget(1, QFormLayout::FieldRole, issueInput);

        label = new QLabel(ProgrammerClass);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton = new QPushButton(ProgrammerClass);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);

        removeButton = new QPushButton(ProgrammerClass);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        horizontalLayout->addWidget(removeButton);

        solveButton = new QPushButton(ProgrammerClass);
        solveButton->setObjectName(QString::fromUtf8("solveButton"));

        horizontalLayout->addWidget(solveButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ProgrammerClass);

        QMetaObject::connectSlotsByName(ProgrammerClass);
    } // setupUi

    void retranslateUi(QWidget *ProgrammerClass)
    {
        ProgrammerClass->setWindowTitle(QApplication::translate("ProgrammerClass", "Programmer", nullptr));
        label->setText(QApplication::translate("ProgrammerClass", "Issue Description", nullptr));
        addButton->setText(QApplication::translate("ProgrammerClass", "Add", nullptr));
        removeButton->setText(QApplication::translate("ProgrammerClass", "Remove", nullptr));
        solveButton->setText(QApplication::translate("ProgrammerClass", "Solve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgrammerClass: public Ui_ProgrammerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMER_H

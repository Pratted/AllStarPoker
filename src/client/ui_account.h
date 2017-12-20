/********************************************************************************
** Form generated from reading UI file 'account.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNT_H
#define UI_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Account
{
public:
    QLineEdit *line_username;
    QLineEdit *line_password;
    QLineEdit *line_password2;
    QLineEdit *line_email;
    QPushButton *button_cancel;
    QPushButton *button_create_account;
    QCheckBox *checkbox_username;
    QCheckBox *checkbox_password2;
    QCheckBox *checkbox_email;
    QCheckBox *checkbox_password;

    void setupUi(QDialog *Account)
    {
        if (Account->objectName().isEmpty())
            Account->setObjectName(QStringLiteral("Account"));
        Account->resize(640, 320);
        Account->setToolTipDuration(-5);
        line_username = new QLineEdit(Account);
        line_username->setObjectName(QStringLiteral("line_username"));
        line_username->setGeometry(QRect(130, 90, 181, 20));
        line_username->setMaxLength(16);
        line_password = new QLineEdit(Account);
        line_password->setObjectName(QStringLiteral("line_password"));
        line_password->setGeometry(QRect(130, 130, 181, 20));
        line_password->setEchoMode(QLineEdit::Password);
        line_password2 = new QLineEdit(Account);
        line_password2->setObjectName(QStringLiteral("line_password2"));
        line_password2->setGeometry(QRect(130, 170, 181, 20));
        line_password2->setEchoMode(QLineEdit::Password);
        line_email = new QLineEdit(Account);
        line_email->setObjectName(QStringLiteral("line_email"));
        line_email->setGeometry(QRect(130, 210, 181, 20));
        button_cancel = new QPushButton(Account);
        button_cancel->setObjectName(QStringLiteral("button_cancel"));
        button_cancel->setGeometry(QRect(360, 270, 121, 24));
        button_create_account = new QPushButton(Account);
        button_create_account->setObjectName(QStringLiteral("button_create_account"));
        button_create_account->setGeometry(QRect(500, 270, 121, 24));
        checkbox_username = new QCheckBox(Account);
        checkbox_username->setObjectName(QStringLiteral("checkbox_username"));
        checkbox_username->setGeometry(QRect(330, 90, 271, 19));
        checkbox_username->setCheckable(true);
        checkbox_password2 = new QCheckBox(Account);
        checkbox_password2->setObjectName(QStringLiteral("checkbox_password2"));
        checkbox_password2->setGeometry(QRect(330, 170, 281, 19));
        checkbox_email = new QCheckBox(Account);
        checkbox_email->setObjectName(QStringLiteral("checkbox_email"));
        checkbox_email->setGeometry(QRect(330, 210, 281, 19));
        checkbox_password = new QCheckBox(Account);
        checkbox_password->setObjectName(QStringLiteral("checkbox_password"));
        checkbox_password->setGeometry(QRect(330, 130, 291, 19));

        retranslateUi(Account);

        QMetaObject::connectSlotsByName(Account);
    } // setupUi

    void retranslateUi(QDialog *Account)
    {
        Account->setWindowTitle(QApplication::translate("Account", "Create an Account", Q_NULLPTR));
        line_username->setPlaceholderText(QApplication::translate("Account", "Username", Q_NULLPTR));
        line_password->setPlaceholderText(QApplication::translate("Account", "Password", Q_NULLPTR));
        line_password2->setPlaceholderText(QApplication::translate("Account", "Confirm Password", Q_NULLPTR));
        line_email->setPlaceholderText(QApplication::translate("Account", "Email", Q_NULLPTR));
        button_cancel->setText(QApplication::translate("Account", "Cancel", Q_NULLPTR));
        button_create_account->setText(QApplication::translate("Account", "Create Account", Q_NULLPTR));
        checkbox_username->setText(QString());
        checkbox_password2->setText(QString());
        checkbox_email->setText(QString());
        checkbox_password->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Account: public Ui_Account {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_H

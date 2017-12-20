/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QPushButton *button_login;
    QLineEdit *line_username;
    QLineEdit *line_password;
    QPushButton *button_create_account;
    QLabel *label_status;
    QLineEdit *line_hostname;
    QPushButton *button_connect_direct;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(640, 320);
        LoginWindow->setToolTipDuration(1);
        LoginWindow->setAutoFillBackground(false);
        LoginWindow->setStyleSheet(QStringLiteral("background-image:url(\\\"loginwallpaper.jpg\\\"); background-position: center; "));
        button_login = new QPushButton(LoginWindow);
        button_login->setObjectName(QStringLiteral("button_login"));
        button_login->setGeometry(QRect(420, 80, 171, 24));
        line_username = new QLineEdit(LoginWindow);
        line_username->setObjectName(QStringLiteral("line_username"));
        line_username->setGeometry(QRect(160, 90, 200, 30));
        line_password = new QLineEdit(LoginWindow);
        line_password->setObjectName(QStringLiteral("line_password"));
        line_password->setGeometry(QRect(160, 130, 200, 30));
        line_password->setLayoutDirection(Qt::LeftToRight);
        line_password->setEchoMode(QLineEdit::Password);
        button_create_account = new QPushButton(LoginWindow);
        button_create_account->setObjectName(QStringLiteral("button_create_account"));
        button_create_account->setGeometry(QRect(430, 140, 161, 24));
        label_status = new QLabel(LoginWindow);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setGeometry(QRect(170, 180, 181, 17));
        line_hostname = new QLineEdit(LoginWindow);
        line_hostname->setObjectName(QStringLiteral("line_hostname"));
        line_hostname->setGeometry(QRect(60, 230, 201, 25));
        button_connect_direct = new QPushButton(LoginWindow);
        button_connect_direct->setObjectName(QStringLiteral("button_connect_direct"));
        button_connect_direct->setGeometry(QRect(300, 230, 171, 24));
        line_username->raise();
        line_password->raise();
        button_login->raise();
        button_create_account->raise();
        label_status->raise();
        line_hostname->raise();
        button_connect_direct->raise();

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Login", Q_NULLPTR));
        button_login->setText(QApplication::translate("LoginWindow", "Login", Q_NULLPTR));
        line_username->setText(QString());
        line_username->setPlaceholderText(QApplication::translate("LoginWindow", "Username", Q_NULLPTR));
        line_password->setText(QString());
        line_password->setPlaceholderText(QApplication::translate("LoginWindow", "Password", Q_NULLPTR));
        button_create_account->setText(QApplication::translate("LoginWindow", "Create Account", Q_NULLPTR));
        label_status->setText(QString());
        button_connect_direct->setText(QApplication::translate("LoginWindow", "Connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

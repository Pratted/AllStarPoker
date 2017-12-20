/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralWidget;
    QLabel *background;
    QTableWidget *wiget_table;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->setEnabled(true);
        MainMenu->resize(1284, 807);
        centralWidget = new QWidget(MainMenu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        background = new QLabel(centralWidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 1284, 760));
        background->setPixmap(QPixmap(QString::fromUtf8("mainmenu.jpg")));
        background->setScaledContents(true);
        wiget_table = new QTableWidget(centralWidget);
        if (wiget_table->columnCount() < 8)
            wiget_table->setColumnCount(8);
        if (wiget_table->rowCount() < 1)
            wiget_table->setRowCount(1);
        wiget_table->setObjectName(QStringLiteral("wiget_table"));
        wiget_table->setGeometry(QRect(110, 150, 1011, 341));
        wiget_table->setStyleSheet(QLatin1String("background-color: rgba(255,255,255,220);\n"
"border-radius: 20px;\n"
""));
        wiget_table->setRowCount(1);
        wiget_table->setColumnCount(8);
        MainMenu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainMenu);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1284, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainMenu->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "AllStarPoker", Q_NULLPTR));
        background->setText(QString());
        menuFile->setTitle(QApplication::translate("MainMenu", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QObject>
#include <QDialog>

class Client;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT
friend class Client;

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H

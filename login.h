#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "secondpageuser.h"
#include "secondpageadmin.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class login;
}
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushbuttoncustomer_clicked();

    void on_Pushbuttonadmin_clicked();

private:
    Ui::login *ui;
    secondpageuser *secondpageuser;
    secondpageadmin *secondpageadmin;
};
#endif // LOGIN_H

#ifndef SECONDPAGEADMIN_H
#define SECONDPAGEADMIN_H

#include <QDialog>
#include "adminlogin.h"
namespace Ui {
class secondpageadmin;
}

class secondpageadmin : public QDialog
{
    Q_OBJECT

public:
    explicit secondpageadmin(QWidget *parent = nullptr);
    ~secondpageadmin();

private slots:
    void on_login_clicked();

private:
    Ui::secondpageadmin *ui;
    adminlogin *adminlogin;
    bool loginSuccess = false;
protected:
    void accept() override;
    void closeEvent(QCloseEvent *event) override;

};

#endif // SECONDPAGEADMIN_H

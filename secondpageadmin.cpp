#include "secondpageadmin.h"
#include "ui_secondpageadmin.h"
#include <QMessageBox>
#include <QCloseEvent>


secondpageadmin::secondpageadmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondpageadmin)
{
    ui->setupUi(this);
    connect(ui->BACK, &QPushButton::clicked, [this]() {
        this->close();                  // closes secondpageadmin
        if(parentWidget()) {
            parentWidget()->show();    // shows the login window again
        }
    });
    setWindowFlags(Qt::Window
                   | Qt::WindowMinimizeButtonHint
                   | Qt::WindowMaximizeButtonHint
                   | Qt::WindowCloseButtonHint);
}

secondpageadmin::~secondpageadmin()
{
    delete ui;
}

void secondpageadmin::on_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "CinemaXx" && password == "Cinequad"){
    loginSuccess = true;
        hide();
        adminlogin=new class adminlogin(this);
        adminlogin->show();
        adminlogin->showMaximized();
    }
    else {
        loginSuccess = false;
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("LOGIN");
        msgBox.setText("Username or Password is incorrect");

        msgBox.setStyleSheet(
            "QLabel{color:white;}"
            "QMessageBox{background-color:#2b2b2b;}"
            "QPushButton{color:white;}"
            );

        msgBox.exec();

}

}
void secondpageadmin::accept()
{
    if (loginSuccess)
        QDialog::accept();   // Prevent QDialog from closing automatically
}
void secondpageadmin::closeEvent(QCloseEvent *event)
{
    // Allow user to close via X button
    event->accept();
}

#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

   /* QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QPixmap(":/images/12bb9b4d8afb97f7ac2a25f6e67962b6.jpg")));
    this->setPalette(palette);*/
    setWindowFlags(Qt::Window
                   | Qt::WindowMinimizeButtonHint
                   | Qt::WindowMaximizeButtonHint
                   | Qt::WindowCloseButtonHint);

}

login::~login()
{
    delete ui;
}

/*void login::on_pushbuttoncostumer_clicked()
{
    secondpageuser secondpageuser;
    secondpageuser.setModal (true);
    secondpageuser.exec();
}

void login::on_Pushbuttonadmin_clicked()
{
    secondpageadmin secondpageadmin;
    secondpageadmin.setModal (true);
    secondpageadmin.exec();
}

*/
void login::on_pushbuttoncustomer_clicked()
{
    // hide();
    secondpageuser = new class secondpageuser(this);  // always create new
    secondpageuser->showMaximized();
}

void login::on_Pushbuttonadmin_clicked()
{
    // DO NOT hide() login
    secondpageadmin = new class secondpageadmin(); // Remove parent
    secondpageadmin->showMaximized();
}

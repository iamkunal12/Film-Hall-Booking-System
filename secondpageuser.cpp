#include "secondpageuser.h"
#include "ui_secondpageuser.h"
#include "moviemanager.h"
#include <QShowEvent>

secondpageuser::secondpageuser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondpageuser)
{
    ui->setupUi(this);


    connect(ui->BACK, &QPushButton::clicked, [this]() {
        this->close();                  // Close current page
        if(parentWidget()) {
            parentWidget()->show();    // Show main window
        }
    });
    setWindowFlags(Qt::Window
                   | Qt::WindowMinimizeButtonHint
                   | Qt::WindowMaximizeButtonHint
                   | Qt::WindowCloseButtonHint);
}
void secondpageuser::refreshMovies()
{
    // Movie 1
    if (MovieManager::movieAvailable["movie1"]) {
        ui->photolabel1->show();
        ui->name1->show();
        ui->duration1->show();
        ui->language1->show();
        ui->select1->show();
    } else {
        ui->photolabel1->hide();
        ui->name1->hide();
        ui->duration1->hide();
        ui->language1->hide();
        ui->select1->hide();
    }

    // Movie 2
    if (MovieManager::movieAvailable["movie2"]) {
        ui->photolabel2->show();
        ui->name2->show();
        ui->duration2->show();
        ui->language2->show();
        ui->select2->show();
    } else {
        ui->photolabel2->hide();
        ui->name2->hide();
        ui->duration2->hide();
        ui->language2->hide();
        ui->select2->hide();
    }

    // Movie 3
    if (MovieManager::movieAvailable["movie3"]) {
        ui->photolabel3->show();
        ui->name3->show();
        ui->duration3->show();
        ui->language3->show();
        ui->select3->show();
    } else {
        ui->photolabel3->hide();
        ui->name3->hide();
        ui->duration3->hide();
        ui->language3->hide();
        ui->select3->hide();
    }

    // Movie 4
    if (MovieManager::movieAvailable["movie4"]) {
        ui->photolabel4->show();
        ui->name4->show();
        ui->duration4->show();
        ui->language4->show();
        ui->select4->show();
    } else {
        ui->photolabel4->hide();
        ui->name4->hide();
        ui->duration4->hide();
        ui->language4->hide();
        ui->select4->hide();
    }
}
void secondpageuser::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);

    refreshMovies();
}

secondpageuser::~secondpageuser()
{
    delete ui;
}
void secondpageuser::on_select1_clicked()
{   hide();
    seats1 = new class seats1(this);
    seats1->showMaximized();
}
void secondpageuser::on_select2_clicked()
{   hide();
    seats2 = new class seats2(this);
    seats2->showMaximized();
}
void secondpageuser::on_select3_clicked()
{   hide();
    seats3 = new class seats3(this);
    seats3->showMaximized();
}
void secondpageuser::on_select4_clicked()
{   hide();
    seats4 = new class seats4(this);
    seats4->showMaximized();
}


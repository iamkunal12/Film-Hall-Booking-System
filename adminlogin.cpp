#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "moviemanager.h"

adminlogin::adminlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminlogin)
{
    ui->setupUi(this);
    connect(ui->removebtn1, &QPushButton::clicked, [=]() {
        ui->photolabel1->deleteLater();
        ui->name1->deleteLater();
        ui->duration1->deleteLater();
        ui->language1->deleteLater();
        ui->removebtn1->deleteLater();
        MovieManager::movieAvailable["movie1"] = false;
});
    connect(ui->removebtn2, &QPushButton::clicked, [=]() {
            ui->photolabel2->deleteLater();
            ui->name2->deleteLater();
            ui->duration2->deleteLater();
            ui->language2->deleteLater();
            ui->removebtn2->deleteLater();
            MovieManager::movieAvailable["movie2"] = false;
});
    connect(ui->removebtn3, &QPushButton::clicked, [=]() {
            ui->photolabel3->deleteLater();
            ui->name3->deleteLater();
            ui->duration3->deleteLater();
            ui->language3->deleteLater();
            ui->removebtn3->deleteLater();
            MovieManager::movieAvailable["movie3"] = false;
});
    connect(ui->removebtn4, &QPushButton::clicked, [=]() {
            ui->photolabel4->deleteLater();
            ui->name4->deleteLater();
            ui->duration4->deleteLater();
            ui->language4->deleteLater();
            ui->removebtn4->deleteLater();
            MovieManager::movieAvailable["movie4"] = false;
});

    // Optional: make it behave like a normal window
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

adminlogin::~adminlogin()
{
    delete ui;
}

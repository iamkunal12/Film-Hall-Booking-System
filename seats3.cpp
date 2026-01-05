#include "seats3.h"
#include "ui_seats3.h"

seats3::seats3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::seats3)
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

seats3::~seats3()
{
    delete ui;
}


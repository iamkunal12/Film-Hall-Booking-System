#include "seats2.h"
#include "ui_seats2.h"

seats2::seats2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::seats2)
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

seats2::~seats2()
{
    delete ui;
}

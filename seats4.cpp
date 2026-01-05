#include "seats4.h"
#include "ui_seats4.h"

seats4::seats4(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::seats4)
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

seats4::~seats4()
{
    delete ui;
}

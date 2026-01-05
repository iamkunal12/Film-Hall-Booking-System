#include "seats1.h"
#include "ui_seats1.h"

seats1::seats1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::seats1)
{
    ui->setupUi(this);

    // --- BACK button ---
    connect(ui->BACK, &QPushButton::clicked, [this]() {
        this->close();
        if(parentWidget()) parentWidget()->show();
    });

    // --- Window flags ---
    setWindowFlags(Qt::Window
                   | Qt::WindowMinimizeButtonHint
                   | Qt::WindowMaximizeButtonHint
                   | Qt::WindowCloseButtonHint);

    // --- All seat buttons ---
    allSeats = {
        ui->A1, ui->A2, ui->A3, ui->A4, ui->A5, ui->A6, ui->A7, ui->A8, ui->A9, ui->A10,
        ui->A11, ui->A12, ui->A13, ui->A14, ui->A15,
        ui->B1, ui->B2, ui->B3, ui->B4, ui->B5, ui->B6, ui->B7, ui->B8, ui->B9, ui->B10,
        ui->B11, ui->B12, ui->B13, ui->B14, ui->B15,
        ui->C1, ui->C2, ui->C3, ui->C4, ui->C5, ui->C6, ui->C7, ui->C8, ui->C9, ui->C10,
        ui->C11, ui->C12, ui->C13, ui->C14,
        ui->D1, ui->D2, ui->D3, ui->D4, ui->D5, ui->D6, ui->D7, ui->D8, ui->D9, ui->D10,
        ui->D11, ui->D12, ui->D13, ui->D14,
        ui->E1, ui->E2, ui->E3, ui->E4, ui->E5, ui->E6, ui->E7, ui->E8, ui->E9, ui->E10,
        ui->E11, ui->E12, ui->E13, ui->E14,
        ui->F1, ui->F2, ui->F3, ui->F4, ui->F5, ui->F6, ui->F7, ui->F8, ui->F9, ui->F10,
        ui->F11, ui->F12, ui->F13, ui->F14, ui->F15, ui->F16
    };

    // --- Connect all seat buttons ---
    for (QPushButton* seat : allSeats)
        connect(seat, &QPushButton::clicked, this, &seats1::seatClicked);

    // --- Connect Book & Cancel buttons ---
    connect(ui->bookBtn, &QPushButton::clicked, this, &seats1::on_bookBtn_clicked);



}

seats1::~seats1()
{
    delete ui;
}

// --- Toggle seat selection ---
void seats1::seatClicked()
{
    QPushButton* seat = qobject_cast<QPushButton*>(sender());
    if (!seat) return;

    if (!seat->isEnabled()) return; // ignore booked (green) seats

    if (selectedSeats.contains(seat)) {
        selectedSeats.removeOne(seat);
        seat->setStyleSheet(""); // back to white
    } else {
        selectedSeats.append(seat);
        seat->setStyleSheet("background-color: orange"); // selected
    }
}

// --- Book selected seats ---
void seats1::on_bookBtn_clicked()
{
    for (QPushButton* seat : selectedSeats) {
        seat->setStyleSheet("background-color: green"); // mark booked
        seat->setEnabled(false); // prevent further selection
    }
    selectedSeats.clear();
}


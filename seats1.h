#ifndef SEATS1_H
#define SEATS1_H

#include <QDialog>
#include <QVector>
#include <QPushButton>

namespace Ui {
class seats1;
}

class seats1 : public QDialog
{
    Q_OBJECT

public:
    explicit seats1(QWidget *parent = nullptr);
    ~seats1();

private slots:
    void seatClicked();           // Toggle selection
    void on_bookBtn_clicked();    // Book selected seats


private:
    Ui::seats1 *ui;
    QVector<QPushButton*> allSeats;      // All seats in the cinema
    QVector<QPushButton*> selectedSeats; // Currently selected seats
};

#endif

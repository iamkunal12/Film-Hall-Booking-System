#ifndef SECONDPAGEUSER_H
#define SECONDPAGEUSER_H

#include <QMainWindow>
#include "seats1.h"
#include "seats2.h"
#include "seats3.h"
#include "seats4.h"

namespace Ui {
class secondpageuser;
}

class secondpageuser : public QDialog
{
    Q_OBJECT

public:
    explicit secondpageuser(QWidget *parent = nullptr);
    ~secondpageuser();

    void refreshMovies();

private slots:
    void on_select1_clicked();
    void on_select2_clicked();
    void on_select3_clicked();
    void on_select4_clicked();
protected:
    void showEvent(QShowEvent *event) override;
private:
    Ui::secondpageuser *ui;
    seats1 *seats1;
    seats2 *seats2;
    seats3 *seats3;
    seats4 *seats4;

};
#endif

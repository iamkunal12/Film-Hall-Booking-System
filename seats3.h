#ifndef SEATS3_H
#define SEATS3_H

#include <QDialog>

namespace Ui {
class seats3;
}

class seats3 : public QDialog
{
    Q_OBJECT

public:
    explicit seats3(QWidget *parent = nullptr);
    ~seats3();

private:
    Ui::seats3 *ui;
};

#endif // SEATS3_H

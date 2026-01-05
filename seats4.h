#ifndef SEATS4_H
#define SEATS4_H

#include <QDialog>

namespace Ui {
class seats4;
}

class seats4 : public QDialog
{
    Q_OBJECT

public:
    explicit seats4(QWidget *parent = nullptr);
    ~seats4();

private:
    Ui::seats4 *ui;
};

#endif // SEATS4_H

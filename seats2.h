#ifndef SEATS2_H
#define SEATS2_H
#include <QDialog>
namespace Ui {
class seats2;
}

class seats2 : public QDialog
{
    Q_OBJECT

public:
    explicit seats2(QWidget *parent = nullptr);
    ~seats2();

private:
    Ui::seats2 *ui;
};

#endif // SEATS2_H

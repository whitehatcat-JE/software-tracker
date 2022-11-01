#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <QWidget>

namespace Ui {
class Management;
}

class Management : public QWidget
{
    Q_OBJECT

public:
    explicit Management(QWidget *parent = nullptr);
    ~Management();

private:
    Ui::Management *ui;
};

#endif // MANAGEMENT_H

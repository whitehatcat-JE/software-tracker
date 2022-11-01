#ifndef NAVBAR_H
#define NAVBAR_H

#include <QWidget>

namespace Ui {
class NavBar;
}

class NavBar : public QWidget
{
    Q_OBJECT

public:
    explicit NavBar(QWidget *parent = nullptr);
    ~NavBar();

private:
    Ui::NavBar *ui;
};

#endif // NAVBAR_H

#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QWidget>

namespace Ui {
class UserManagement;
}

class UserManagement : public QWidget
{
    Q_OBJECT

public:
    explicit UserManagement(QWidget *parent = nullptr);
    ~UserManagement();

private:
    Ui::UserManagement *ui;
};

#endif // USERMANAGEMENT_H

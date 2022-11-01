#ifndef GROUPMANAGEMENT_H
#define GROUPMANAGEMENT_H

#include <QWidget>

namespace Ui {
class GroupManagement;
}

class GroupManagement : public QWidget
{
    Q_OBJECT

public:
    explicit GroupManagement(QWidget *parent = nullptr);
    ~GroupManagement();

private:
    Ui::GroupManagement *ui;
};

#endif // GROUPMANAGEMENT_H

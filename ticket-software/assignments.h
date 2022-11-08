#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class Assignments;
}

class Assignments : public QWidget
{
    Q_OBJECT
public:
    explicit Assignments(QWidget *parent = nullptr);
    ~Assignments();

private slots:
    void on_ticketsButton_toggled(bool checked);

    void on_groupsButton_toggled(bool checked);

    void on_projectsButton_toggled(bool checked);

private:
    Ui::Assignments *ui;
};

#endif // ASSIGNMENTS_H

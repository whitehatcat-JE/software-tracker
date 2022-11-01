#ifndef PROJECTMANAGEMENT_H
#define PROJECTMANAGEMENT_H

#include <QWidget>

namespace Ui {
class ProjectManagement;
}

class ProjectManagement : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectManagement(QWidget *parent = nullptr);
    ~ProjectManagement();

private:
    Ui::ProjectManagement *ui;
};

#endif // PROJECTMANAGEMENT_H

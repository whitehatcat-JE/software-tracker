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

private slots:
    void on_createProjectButton_clicked();

private:
    Ui::ProjectManagement *ui;
    void reloadProjects();
    void deleteProject(int projectID);
};

#endif // PROJECTMANAGEMENT_H

#ifndef PROJECT_H
#define PROJECT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QVector>

#include "filemanager.h"
namespace Ui {
class Project;
}

class Project : public QWidget
{
    Q_OBJECT

public:
    explicit Project(int projectID, QWidget *parent = nullptr);
    ~Project();

private slots:
    void on_lineEditPassword_textChanged(const QString &query);

private:
    Ui::Project *ui;
    int assignedIdentifier;
    QVector<QPushButton*> displayedTickets;
};

#endif // PROJECT_H

#ifndef MANAGEMENTSELECTION_H
#define MANAGEMENTSELECTION_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "filemanager.h"

namespace Ui {
class ManagementSelection;
}

class ManagementSelection : public QWidget
{
    Q_OBJECT

public:
    explicit ManagementSelection(int selectionType, int id, QWidget *parent = nullptr);
    ~ManagementSelection();

private slots:
    void on_profileButton_clicked();

    void on_assignButton_clicked();

    void on_managementButton_clicked();

    void on_logoutButton_clicked();

    void on_backButton_clicked();

private:
    Ui::ManagementSelection *ui;
    bool closing = true;
    int type;
    int objID;

    void changeListing(int id, QPushButton* button, int secondaryID = 0);
};

#endif // MANAGEMENTSELECTION_H

#ifndef PROFILEVIEWER_H
#define PROFILEVIEWER_H

#include <QMainWindow>

#include "filemanager.h"

namespace Ui {
class ProfileViewer;
}

class ProfileViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProfileViewer(QWidget *parent = nullptr);
    ~ProfileViewer();

private slots:
    void on_managementButton_2_clicked();

    void on_assignButton_2_clicked();

    void on_profileButton_2_clicked();

    void on_logoutButton_2_clicked();

private:
    Ui::ProfileViewer *ui;
    bool closing = true;
};

#endif // PROFILEVIEWER_H

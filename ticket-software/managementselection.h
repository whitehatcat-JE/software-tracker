#ifndef MANAGEMENTSELECTION_H
#define MANAGEMENTSELECTION_H

#include <QWidget>

#include "filemanager.h"

namespace Ui {
class ManagementSelection;
}

class ManagementSelection : public QWidget
{
    Q_OBJECT

public:
    explicit ManagementSelection(QWidget *parent = nullptr);
    ~ManagementSelection();

private:
    Ui::ManagementSelection *ui;
};

#endif // MANAGEMENTSELECTION_H

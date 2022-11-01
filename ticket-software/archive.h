#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QWidget>

namespace Ui {
class Archive;
}

class Archive : public QWidget
{
    Q_OBJECT

public:
    explicit Archive(QWidget *parent = nullptr);
    ~Archive();

private:
    Ui::Archive *ui;
};

#endif // ARCHIVE_H

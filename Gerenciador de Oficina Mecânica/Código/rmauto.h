#ifndef RMAUTO_H
#define RMAUTO_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "oficinamec.h"

namespace Ui {
class rmAuto;
}

class rmAuto : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;

public:
    explicit rmAuto(OficinaMec * ofc, QWidget *parent = 0);
    ~rmAuto();

private slots:
    void on_butAuto_clicked();

    void on_butClient_clicked();

    void on_butRemover_clicked();

private:
    Ui::rmAuto *ui;
};

#endif // RMAUTO_H

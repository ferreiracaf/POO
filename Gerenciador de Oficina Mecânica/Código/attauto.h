#ifndef ATTAUTO_H
#define ATTAUTO_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "oficinamec.h"

namespace Ui {
class AttAuto;
}

class AttAuto : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;

public:
    explicit AttAuto(OficinaMec * ofc, QWidget *parent = 0);
    ~AttAuto();

private slots:
    void on_butCliente_clicked();

    void on_butAuto_clicked();

    void on_butAtt_clicked();

private:
    Ui::AttAuto *ui;
};

#endif // ATTAUTO_H

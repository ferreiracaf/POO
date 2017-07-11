#ifndef RMCLIENTE_H
#define RMCLIENTE_H

#include <QDialog>
#include <QMessageBox>
#include <QInputDialog>
#include "oficinamec.h"

namespace Ui {
class rmCliente;
}

class rmCliente : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;

public:
    explicit rmCliente(OficinaMec * ofc, QWidget *parent = 0);
    ~rmCliente();

private slots:
    void on_butCliente_clicked();

    void on_butRemover_clicked();

private:
    Ui::rmCliente *ui;
};

#endif // RMCLIENTE_H

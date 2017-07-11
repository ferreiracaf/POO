#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <QInputDialog>
#include "cliente.h"
#include "oficinamec.h"
#include "rmcliente.h"

namespace Ui {
class menuCliente;
}

class menuCliente : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;
public:
    explicit menuCliente(OficinaMec * ofc, QWidget *parent = 0);
    ~menuCliente();

private slots:
    void on_butBuscar_clicked();

    void on_butRemover_clicked();

    void on_butVoltar_clicked();

    void on_butCadastrar_clicked();

    void on_butListartd_clicked();

private:
    Ui::menuCliente *ui;
};

#endif // MENUCLIENTE_H

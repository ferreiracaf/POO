#ifndef CADASTRO_H
#define CADASTRO_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "oficinamec.h"
#include <memory>

namespace Ui {
class Cadastro;
}

class Cadastro : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;
public:
    explicit Cadastro(OficinaMec * ofc, QWidget *parent = 0);
    ~Cadastro();

private slots:
    void on_butOpt1_clicked();

    void on_butOpt2_clicked();

    void on_butCadastrar_clicked();

    void on_butTipo_clicked();

private:
    Ui::Cadastro *ui;
};

#endif // CADASTRO_H

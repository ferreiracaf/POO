#ifndef MENUAUTO_H
#define MENUAUTO_H

#include <QDialog>
#include <QMessageBox>
#include "oficinamec.h"
#include "cadastroauto.h"
#include "attauto.h"
#include "rmauto.h"

namespace Ui {
class menuAuto;
}

class menuAuto : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;

public:
    explicit menuAuto(OficinaMec * ofc, QWidget *parent = 0);
    ~menuAuto();

private slots:
    void on_butListartd_clicked();

    void on_butVoltar_clicked();

    void on_butCadastrar_clicked();

    void on_butMarca_clicked();

    void on_butModelo_clicked();

    void on_butPlaca_clicked();

    void on_butAno_clicked();

    void on_butAtualizar_clicked();

    void on_butRm_clicked();

private:
    Ui::menuAuto *ui;
};

#endif // MENUAUTO_H

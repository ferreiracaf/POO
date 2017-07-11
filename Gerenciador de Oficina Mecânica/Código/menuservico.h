#ifndef MENUSERVICO_H
#define MENUSERVICO_H

#include <QDialog>
#include "venderservico.h"
#include "oficinamec.h"
#include "cadastroserv.h"
#include "attservico.h"
#include "rmservico.h"

namespace Ui {
class menuServico;
}

class menuServico : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;

public:
    explicit menuServico(OficinaMec * ofc, QWidget *parent = 0);
    ~menuServico();

private slots:
    void on_butVoltar_clicked();

    void on_butVenderServ_clicked();

    void on_butListar_clicked();

    void on_butAdd_clicked();

    void on_butAtt_clicked();

    void on_butRm_clicked();

private:
    Ui::menuServico *ui;
};

#endif // MENUSERVICO_H

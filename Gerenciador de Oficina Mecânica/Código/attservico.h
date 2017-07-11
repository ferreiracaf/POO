#ifndef ATTSERVICO_H
#define ATTSERVICO_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "oficinamec.h"

namespace Ui {
class AttServico;
}

class AttServico : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;
public:
    explicit AttServico(OficinaMec * ofc, QWidget *parent = 0);
    ~AttServico();

private slots:
    void on_butServico_clicked();

    void on_butAtualizar_clicked();

private:
    Ui::AttServico *ui;
};

#endif // ATTSERVICO_H

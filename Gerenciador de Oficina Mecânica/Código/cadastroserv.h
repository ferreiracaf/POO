#ifndef CADASTROSERV_H
#define CADASTROSERV_H

#include "oficinamec.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class cadastroServ;
}

class cadastroServ : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;

public:
    explicit cadastroServ(OficinaMec * ofc,QWidget *parent = 0);
    ~cadastroServ();

private slots:
    void on_butAdd_clicked();

private:
    Ui::cadastroServ *ui;
};

#endif // CADASTROSERV_H

#ifndef OFICINAMECANICA_H
#define OFICINAMECANICA_H

#include <QMainWindow>
#include <QMessageBox>
#include "oficinamec.h"

namespace Ui {
class OficinaMecanica;
}

class OficinaMecanica : public QMainWindow
{
    Q_OBJECT
    OficinaMec * ofc;
public:
    explicit OficinaMecanica(OficinaMec * ofc, QWidget *parent = 0);
    ~OficinaMecanica();

private slots:
    void on_butSair_clicked();

    void on_butClient_clicked();

    void on_butAutos_clicked();

    void on_butServicos_clicked();

    void on_butSaldo_clicked();

private:
    Ui::OficinaMecanica *ui;
};

#endif // OFICINAMECANICA_H

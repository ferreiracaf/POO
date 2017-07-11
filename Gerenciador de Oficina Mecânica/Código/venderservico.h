#ifndef VENDERSERVICO_H
#define VENDERSERVICO_H

#include <QDialog>
#include <QMessageBox>
#include <QInputDialog>
#include "oficinamec.h"

char convert(int num);
string floatToString(float num);

namespace Ui {
class venderServico;
}

class venderServico : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;
public:
    explicit venderServico(OficinaMec * ofc, QWidget *parent = 0);
    ~venderServico();

private slots:
    void on_butServico_clicked();

    void on_butCliente_clicked();

    void on_butAuto_clicked();

    void on_butVender_clicked();

private:
    Ui::venderServico *ui;
};

#endif // VENDERSERVICO_H

#ifndef CADASTROAUTO_H
#define CADASTROAUTO_H

#include <QDialog>
#include <QMessageBox>
#include <QInputDialog>
#include "oficinamec.h"

namespace Ui {
class cadastroAuto;
}

class cadastroAuto : public QDialog
{
    Q_OBJECT
    OficinaMec *ofc;
public:
    explicit cadastroAuto(OficinaMec * ofc, QWidget *parent = 0);
    ~cadastroAuto();

private slots:
    void on_butDono_clicked();

    void on_butMarca_clicked();

    void on_butModel_clicked();

    void on_butAno_clicked();

    void on_butPlaca_clicked();

    void on_pushButton_6_clicked();

    void on_butTipo_clicked();

private:
    Ui::cadastroAuto *ui;
};

#endif // CADASTROAUTO_H

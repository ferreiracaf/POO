#ifndef RMSERVICO_H
#define RMSERVICO_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "oficinamec.h"

namespace Ui {
class rmServico;
}

class rmServico : public QDialog
{
    Q_OBJECT
    OficinaMec * ofc;

public:
    explicit rmServico(OficinaMec * ofc, QWidget *parent = 0);
    ~rmServico();

private slots:
    void on_butServico_clicked();

    void on_butRemover_clicked();

private:
    Ui::rmServico *ui;
};

#endif // RMSERVICO_H

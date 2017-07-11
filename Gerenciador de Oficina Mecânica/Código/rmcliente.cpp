#include "rmcliente.h"
#include "ui_rmcliente.h"

rmCliente::rmCliente(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rmCliente)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

rmCliente::~rmCliente()
{
    delete ui;
}

void rmCliente::on_butCliente_clicked()
{
    bool ok;
    QStringList list;
    for (Cliente * c : ofc->clientes)
        list << QString::fromStdString(c->getNome());
    QString cliente = QInputDialog::getItem(this, "Clientes", "Selecione o cliente:",
                                         list, 0, false, &ok);
    if (ok && !cliente.isEmpty())
        ui->lEditCliente->setText(cliente);
}

void rmCliente::on_butRemover_clicked()
{
    string nome = ui->lEditCliente->text().toStdString();
    if(ofc->rmCliente(nome)){
        QMessageBox::information(this, "Foi boa!", "Cliente removido com sucesso.");
        hide();
    }
    else {
        QMessageBox::critical(this, "Erro!", "Não foi possível remover o "
                                                "cliente.");
    }
}

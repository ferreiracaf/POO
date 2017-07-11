#include "menucliente.h"
#include "ui_menucliente.h"
#include "cadastro.h"


menuCliente::menuCliente(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuCliente)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

menuCliente::~menuCliente()
{
    delete ui;
}

void menuCliente::on_butBuscar_clicked()
{
    string nome = ui->lEditBuscarClient->text().toStdString();
    if(nome == "")
        QMessageBox::warning(this, "Erro!", "Entrada inválida ou caixa de"
                                            " texto vazia.");
    else{
        Cliente * aux = ofc->buscarCliente(nome);
        if(aux == nullptr)
            QMessageBox::warning(this, "Erro!", "Cliente inexistente!");
        else{
            QMessageBox::information(this, "Cliente encontrado!",
                                     QString::fromStdString(aux->toString()));
        }
    }
}

void menuCliente::on_butRemover_clicked()
{
    rmCliente client(ofc, this);
    client.setModal(true);
    client.exec();

}

void menuCliente::on_butVoltar_clicked()
{
    QDialog * a = static_cast<QDialog *>(parent());
    a->show();
    hide();
}

void menuCliente::on_butCadastrar_clicked()
{
    Cadastro cadastro(ofc, this);
    cadastro.setModal(true);
    cadastro.exec();
}

void menuCliente::on_butListartd_clicked()
{
    QString lista = QString::fromStdString(ofc->listarClientes());
    QMessageBox::information(this,"Clientes", lista);
}

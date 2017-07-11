#include "rmauto.h"
#include "ui_rmauto.h"

rmAuto::rmAuto(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rmAuto)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

rmAuto::~rmAuto()
{
    delete ui;
}

void rmAuto::on_butAuto_clicked()
{
    if(ui->lEditClient->text() == ""){
        QMessageBox::warning(this, "Erro!", "Nenhum cliente selecionado, por favor"
                                            " selecione o cliente antes de"
                                            " escolher o automóvel.");
        return;
    }
    bool ok;
    QStringList list;
    string nomeClient = ui->lEditClient->text().toStdString();
    Cliente * c = ofc->buscarCliente(nomeClient);
    for (Automovel * a : c->veiculos)
        list << QString::fromStdString(a->getInfo());
    QString automovel = QInputDialog::getItem(this, "Automóveis",
                                              "Selecione o automóvel:", list,
                                              0, false, &ok);
    if (ok && !automovel.isEmpty())
        ui->lEditAuto->setText(automovel);
}

void rmAuto::on_butClient_clicked()
{
    bool ok;
    QStringList list;
    for (Cliente * c : ofc->clientes)
        list << QString::fromStdString(c->getNome());
    QString client = QInputDialog::getItem(this, "Clientes", "Selecione o cliente:",
                                           list, 0, false, &ok);
    if (ok && !client.isEmpty())
        ui->lEditClient->setText(client);
}

void rmAuto::on_butRemover_clicked()
{
    string nomeClient = ui->lEditClient->text().toStdString();
    string placa;
    string aux = ui->lEditAuto->text().toStdString();
    if(aux == "" || nomeClient == ""){
        QMessageBox::warning(this, "Erro!", "Selecione um cliente e um automovel");
        return;
    }
    for(int i = 0; i < 7; i++)
        placa.push_back(aux[i]);
    Cliente * c = ofc->buscarCliente(nomeClient);
    if(c->rmAuto(placa)){
        QMessageBox::information(this, "Foi boa!", "Automóvel removido com sucesso.");
        hide();
    }
    else
        QMessageBox::critical(this, "Erro!", "Não foi possível remover o automóvel");
}

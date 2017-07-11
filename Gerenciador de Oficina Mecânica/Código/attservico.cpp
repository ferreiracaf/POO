#include "attservico.h"
#include "ui_attservico.h"
#include "venderservico.h"

AttServico::AttServico(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AttServico)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

AttServico::~AttServico()
{
    delete ui;
}

void AttServico::on_butServico_clicked()
{
    bool ok;
    QStringList list;
    for (Servico s : ofc->servicos)
        list << QString::fromStdString(s.getNome());
    QString serv = QInputDialog::getItem(this, "Serviços", "Selecione o serviço:",
                                         list, 0, false, &ok);
    if (ok && !serv.isEmpty()){
        ui->lEditServico->setText(serv);
        string aux = ui->lEditServico->text().toStdString();
        float preco = ofc->getServico(aux)->getPreco();
        ui->lEditPreco->setText(QString::fromStdString(floatToString(preco)));
    }
}

void AttServico::on_butAtualizar_clicked()
{
    if(ui->lEditServico->text() == ""){
        QMessageBox::critical(this, "Erro!", "Serviço não selecionado.");
        return;
    }

    string novoNome = ui->lEditNewServco->text().toStdString();
    float novoPreco = ui->sBoxPreco->valueFromText(ui->sBoxPreco->text());

    if(novoNome == "" && novoPreco <= 0.0){
        QMessageBox::critical(this, "Erro!", "Dados insuficientes para atualizar"
                                             " serviço.");
        return;
    }

    if(novoNome == "" && novoPreco > 0.0){
        Servico * serv = ofc->getServico(ui->lEditServico->text().toStdString());
        serv->setPreco(novoPreco);
        QMessageBox::information(this, "Foi boa!", "Preço alterado com sucesso.");
        hide();
    }

    if(novoNome != "" && novoPreco <= 0.0){
        Servico * serv = ofc->getServico(ui->lEditServico->text().toStdString());
        serv->setNome(novoNome);
        QMessageBox::information(this, "Foi boa!", "Nome alterado com sucesso.");
        hide();
    }

    if(novoNome != "" && novoPreco > 0.0){
        Servico * serv = ofc->getServico(ui->lEditServico->text().toStdString());
        serv->setNome(novoNome);
        serv->setPreco(novoPreco);
        QMessageBox::information(this, "Foi boa!", "Nome e preço alterados com"
                                                   " sucesso.");
        hide();
    }
}

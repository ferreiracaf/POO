#include "menuauto.h"
#include "ui_menuauto.h"

menuAuto::menuAuto(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuAuto)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

menuAuto::~menuAuto()
{
    delete ui;
}

void menuAuto::on_butListartd_clicked()
{
    QString lista = QString::fromStdString(ofc->listarVeiculos());
    QMessageBox::information(this,"Automóveis", lista);
}

void menuAuto::on_butVoltar_clicked()
{
    QDialog * a = static_cast<QDialog *>(parent());
    a->show();
    hide();
}

void menuAuto::on_butCadastrar_clicked()
{
    cadastroAuto cadastro(ofc, this);
    cadastro.setModal(true);
    cadastro.exec();
}

void menuAuto::on_butMarca_clicked()
{
    if(ui->lEditBusca->text() == ""){
        QMessageBox::warning(this, "", "Entrada inválida ou caixa de texto vazia.");
        return;
    }

    int aux = 0;
    stringstream ss;
    for(Cliente * c : ofc->clientes)
        for(Automovel * aut : c->veiculos)
            if(aut->getMarca() == ui->lEditBusca->text().toStdString()){
                ss << aut->toString() << endl << "  ---------" << endl;
                aux++;
            }
    if (aux > 0){
        QMessageBox::information(this, "Automóveis encontrados:",
                                 QString::fromStdString(ss.str()));
        return;
    }
    QMessageBox::warning(this, "", "Nenhum automóvel encontrado!");
}

void menuAuto::on_butModelo_clicked()
{
    if(ui->lEditBusca->text() == ""){
        QMessageBox::warning(this, "", "Entrada inválida ou caixa de texto vazia.");
        return;
    }

    int aux = 0;
    stringstream ss;
    for(Cliente * c : ofc->clientes)
        for(Automovel * aut : c->veiculos)
            if(aut->getModelo() == ui->lEditBusca->text().toStdString()){
                ss << aut->toString() << endl << "  ---------" << endl;
                aux++;
            }
    if (aux > 0){
        QMessageBox::information(this, "Automóveis encontrados:",
                                 QString::fromStdString(ss.str()));
        return;
    }
    QMessageBox::warning(this, "", "Nenhum automóvel encontrado!");
}

void menuAuto::on_butPlaca_clicked()
{
    if(ui->lEditBusca->text() == ""){
        QMessageBox::warning(this, "", "Entrada inválida ou caixa de texto vazia.");
        return;
    }

    int aux = 0;
    stringstream ss;
    for(Cliente * c : ofc->clientes)
        for(Automovel * aut : c->veiculos)
            if(aut->getPlaca() == ui->lEditBusca->text().toStdString()){
                ss << aut->toString() << endl << "  ---------" << endl;
                aux++;
            }
    if (aux > 0){
        QMessageBox::information(this, "Automóveis encontrados:",
                                 QString::fromStdString(ss.str()));
        return;
    }
    QMessageBox::warning(this, "", "Nenhum automóvel encontrado!");
}

void menuAuto::on_butAno_clicked()
{
    if(ui->lEditBusca->text() == ""){
        QMessageBox::warning(this, "", "Entrada inválida ou caixa de texto vazia.");
        return;
    }

    int aux = 0;
    stringstream ss;
    for(Cliente * c : ofc->clientes)
        for(Automovel * aut : c->veiculos)
            if(aut->getAno() == ui->lEditBusca->text().toStdString()){
                ss << aut->toString() << endl << "  ---------" << endl;
                aux++;
            }
    if (aux > 0){
        QMessageBox::information(this, "Automóveis encontrados:",
                                 QString::fromStdString(ss.str()));
        return;
    }
    QMessageBox::warning(this, "", "Nenhum automóvel encontrado!");
}

void menuAuto::on_butAtualizar_clicked()
{
    AttAuto aut(ofc, this);
    aut.setModal(true);
    aut.exec();
}

void menuAuto::on_butRm_clicked()
{
    rmAuto aut(ofc, this);
    aut.setModal(true);
    aut.exec();
}

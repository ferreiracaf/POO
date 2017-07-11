#include "cadastroserv.h"
#include "ui_cadastroserv.h"

cadastroServ::cadastroServ(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroServ)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

cadastroServ::~cadastroServ()
{
    delete ui;
}

void cadastroServ::on_butAdd_clicked()
{
    string nome = ui->lEditNome->text().toStdString();
    if(nome == ""){
        QMessageBox::critical(this, "Erro!", "Dados insuficientes para adicionar"
                                             " servico.");
        return;
    }
    float preco = ui->sBoxPreco->valueFromText(ui->sBoxPreco->text());
    if(preco <= 0.0){
        QMessageBox::critical(this, "Erro!", "Preço invalido.");
        return;
    }
    if(ofc->addServico(Servico(nome, preco))){
        QMessageBox::information(this, "Foi boa!", "Serviço adicionado com sucesso.");
        hide();
    }
    else
        QMessageBox::critical(this, "Erro!", "Não foi possível adicionar o serviço.");
}

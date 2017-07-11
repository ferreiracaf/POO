#include "cadastro.h"
#include "ui_cadastro.h"

Cadastro::Cadastro(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cadastro)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

Cadastro::~Cadastro()
{
    delete ui;
}

void Cadastro::on_butOpt1_clicked()
{
    bool ok;
    QString nome = QInputDialog::getText(this, "Cadastro", "Insira o nome do cliente:",
                                         QLineEdit::Normal, "Carlos Ferreira", &ok,
                                         Qt::WindowTitleHint);
    if(ok && !nome.isEmpty())
        ui->lEditNome->setText(nome);
}

void Cadastro::on_butOpt2_clicked()
{
    bool ok;
    QString numero = QInputDialog::getText(this, "Cadastro", "Insira o telefone do cliente:",
                                         QLineEdit::Normal, "8896165563", &ok,
                                         Qt::WindowTitleHint);
    for(QChar c : numero)
        if(c < '0' || c > '9'){
            QMessageBox::critical(this, "Erro!", "Número inválido.");
            return;
        }
    if(ok && !numero.isEmpty())
            ui->lEditNum->setText(numero);
}

void Cadastro::on_butCadastrar_clicked()
{
    if(ui->lEditNome->text() == ""){
        QMessageBox::critical(this, "Erro!", "Dados insuficientes para criar o cliente.");
        return;
    }
    if(ui->lEditTipo->text() == ""){
        QMessageBox::critical(this, "Erro!", "Dados insuficientes para criar o cliente.");
        return;
    }
    if(ui->lEditNum->text() == ""){
        QMessageBox::critical(this, "Erro!", "Dados insuficientes para criar o cliente.");
        return;
    }

    QString tipo = ui->lEditTipo->text();
    if(tipo == "Comum"){
        if(ofc->addCliente(new ClienteComum(ui->lEditNome->text().toStdString(),
                                       ui->lEditNum->text().toStdString()))){
            QMessageBox::information(this, "Foi boa!", "Cliente comum cadastrado"
                                                       " com sucesso!");
            hide();
        }
        else
            QMessageBox::critical(this, "Erro", "Não foi possível cadastrar o cliente!");
    }
    else {
        if(ofc->addCliente(new ClienteVip(ui->lEditNome->text().toStdString(),
                                       ui->lEditNum->text().toStdString()))){
            QMessageBox::information(this, "Foi boa!", "Cliente VIP cadastrado"
                                                       " com sucesso!");
            hide();
        }
        else
            QMessageBox::critical(this, "Erro", "Não foi possível cadastrar o cliente!");
    }
}

void Cadastro::on_butTipo_clicked()
{
    bool ok;
    QStringList list;
    list << "Comum";
    list << "VIP";
    QString tipo = QInputDialog::getItem(this, "Tipo", "Selecione o tipo:",
                                         list, 0, false, &ok);
    if (ok && !tipo.isEmpty())
        ui->lEditTipo->setText(tipo);
}

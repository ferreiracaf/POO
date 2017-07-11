#include "cadastroauto.h"
#include "ui_cadastroauto.h"

cadastroAuto::cadastroAuto(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroAuto)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

cadastroAuto::~cadastroAuto()
{
    delete ui;
}

void cadastroAuto::on_butDono_clicked()
{
    bool ok;
    QStringList list;
    for (Cliente * c : ofc->clientes)
        list << QString::fromStdString(c->getNome());
    QString dono = QInputDialog::getItem(this, "Clientes", "Selecione o cliente:",
                                         list, 0, false, &ok);
    if (ok && !dono.isEmpty())
        ui->lEditdono->setText(dono);

}

void cadastroAuto::on_butMarca_clicked()
{
    bool ok;
    QString marca = QInputDialog::getText(this, "Cadastro", "Insira a marca do automóvel:",
                                          QLineEdit::Normal, "Volkswagen", &ok,
                                          Qt::WindowTitleHint);
    if(ok && !marca.isEmpty())
        ui->lEditMarca->setText(marca);
}

void cadastroAuto::on_butModel_clicked()
{
    bool ok;
    QString model = QInputDialog::getText(this, "Cadastro", "Insira o modelo do automóvel:",
                                          QLineEdit::Normal, "Gol", &ok,
                                          Qt::WindowTitleHint);
    if(ok && !model.isEmpty())
        ui->lEditModel->setText(model);
}

void cadastroAuto::on_butAno_clicked()
{
    bool ok;
    QString ano = QInputDialog::getText(this, "Cadastro", "Insira o ano do automóvel:",
                                        QLineEdit::Normal, "2017", &ok,
                                        Qt::WindowTitleHint);
    if(ok && !ano.isEmpty())
        ui->lEditAno->setText(ano);
}

void cadastroAuto::on_butPlaca_clicked()
{
    bool ok;
    QString model = QInputDialog::getText(this, "Cadastro", "Insira a placa do automóvel:",
                                          QLineEdit::Normal, "hxy1234", &ok,
                                          Qt::WindowTitleHint);
    if(ok && !model.isEmpty())
        ui->lEditplaca->setText(model);
}

void cadastroAuto::on_pushButton_6_clicked()
{

    string marca = ui->lEditMarca->text().toStdString();
    string modelo = ui->lEditModel->text().toStdString();
    string placa = ui->lEditplaca->text().toStdString();
    Cliente * c = ofc->searchCliente(ui->lEditdono->text().toStdString());
    string ano = ui->lEditAno->text().toStdString();
    AUTO tipo;
    if(ui->lEditTipo->text() == "Carro")
        tipo = CARRO;
    else
        tipo = MOTO;

    if(marca == "" || modelo == "" || placa == "" || c == nullptr ||
            ui->lEditTipo->text() == ""){
        QMessageBox::critical(this, "Erro", "Dados insuficientes para cadastrar "
                                            "automovel!");
        return;
    }
    if(ano == "")
        ano = "~";

    if(tipo == CARRO){
        if(c->addAuto(new Carro(marca, modelo, placa, c, ano))){
            QMessageBox::information(this, "Foi boa!", "Carro cadastrado com sucesso!");
            hide();
        }
        else
            QMessageBox::critical(this, "Erro", "Não foi possível cadastrar o automóvel!");
    }
    else{
        if(c->addAuto(new Moto(marca, modelo, placa, c, ano))){
            QMessageBox::information(this, "Foi boa!", "Moto cadastrada com sucesso!");
            hide();
        }
        else
            QMessageBox::critical(this, "Erro", "Não foi possível cadastrar o automóvel!");
    }
}

void cadastroAuto::on_butTipo_clicked()
{
    bool ok;
    QStringList list;
    list << "Carro";
    list << "Moto";
    QString tipo = QInputDialog::getItem(this, "Tipo", "Selecione o tipo:",
                                         list, 0, false, &ok);
    if (ok && !tipo.isEmpty())
        ui->lEditTipo->setText(tipo);
}

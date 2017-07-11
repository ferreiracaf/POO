#include "attauto.h"
#include "ui_attauto.h"

AttAuto::AttAuto(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AttAuto)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

AttAuto::~AttAuto()
{
    delete ui;
}

void AttAuto::on_butCliente_clicked()
{
    bool ok;
    QStringList list;
    for (Cliente * c : ofc->clientes)
        list << QString::fromStdString(c->getNome());
    QString client = QInputDialog::getItem(this, "Clientes", "Selecione o cliente:",
                                           list, 0, false, &ok);
    if (ok && !client.isEmpty())
        ui->lEditCliente->setText(client);
}

void AttAuto::on_butAuto_clicked()
{
    if(ui->lEditCliente->text() == ""){
        QMessageBox::warning(this, "Erro!", "Nenhum cliente selecionado, por favor"
                                            " selecione o cliente antes de"
                                            " escolher o automóvel.");
        return;
    }
    bool ok;
    QStringList list;
    string nomeClient = ui->lEditCliente->text().toStdString();
    Cliente * c = ofc->buscarCliente(nomeClient);
    for (Automovel * a : c->veiculos)
        list << QString::fromStdString(a->getInfo());
    QString automovel = QInputDialog::getItem(this, "Automóveis", "Selecione o "
                                                                  "automóvel:", list, 0, false, &ok);
    if (ok && !automovel.isEmpty())
        ui->lEditAuto->setText(automovel);
}

void AttAuto::on_butAtt_clicked()
{
    string nomeCliente = ui->lEditCliente->text().toStdString();
    string placa;
    string aux = ui->lEditAuto->text().toStdString();

    if(nomeCliente == "" || aux == ""){
        QMessageBox::warning(this, "Erro!", "Selecione um cliente e um automóvel.");
        return;
    }

    for(int i = 0; i < 7; i++)
        placa.push_back(aux[i]);

    string newMarca = ui->lEditNewMarca->text().toStdString();
    string newModelo = ui->lEditNewModelo->text().toStdString();
    string newPlaca = ui->lEditNewPlaca->text().toStdString();
    string newAno = ui->lEditNewAno->text().toStdString();
    if(newAno == "")
        newAno = "~";

    if(newMarca == "" && newModelo == "" && newPlaca == "" && newAno == "~"){
        QMessageBox::warning(this, "Erro!", "Dados insuficientes para atualizar"
                                            " automóvel");
        return;
    }

    Cliente * c = ofc->buscarCliente(nomeCliente);
    Automovel * a = c->getAuto(placa);

    if(newMarca != ""){
        a->setMarca(newMarca);
    }
    if(newModelo != ""){
        a->setModelo(newModelo);
    }
    if(newPlaca != ""){
        a->setPlaca(newPlaca);
    }
    if(newAno != "~"){
        for(char x : newAno)
            if(x < '0' || x > '9'){
                QMessageBox::warning(this, "Erro!", "Ano inválido.");
                return;
            }
        a->setAno(newAno);
    }
    QMessageBox::information(this, "Foi boa!", "Automóvel atualizado com sucesso.");
    hide();
}

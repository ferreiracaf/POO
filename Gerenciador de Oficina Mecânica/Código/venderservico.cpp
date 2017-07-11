#include "venderservico.h"
#include "ui_venderservico.h"

venderServico::venderServico(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::venderServico)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

venderServico::~venderServico()
{
    delete ui;
}

void venderServico::on_butServico_clicked()
{
    bool ok;
    QStringList list;
    for (Servico s : ofc->servicos)
        list << QString::fromStdString(s.getNome());
    QString serv = QInputDialog::getItem(this, "Serviços", "Selecione o serviço:",
                                         list, 0, false, &ok);
    if (ok && !serv.isEmpty()){
        ui->lEditServ->setText(serv);
        string aux = ui->lEditServ->text().toStdString();
        float preco = ofc->getServico(aux)->getPreco();
        ui->lEditPreco->setText(QString::fromStdString(floatToString(preco)));
    }
}

void venderServico::on_butCliente_clicked()
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

void venderServico::on_butAuto_clicked()
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
    QString automovel = QInputDialog::getItem(this, "Automóveis", "Selecione o "
                                                "automóvel:", list, 0, false, &ok);
    if (ok && !automovel.isEmpty())
        ui->lEditAuto->setText(automovel);
}

char convert(int num){
    char ret;
    switch (num) {
    case 0:
        ret = '0';
        break;
    case 1:
        ret = '1';
        break;
    case 2:
        ret = '2';
        break;
    case 3:
        ret = '3';
        break;
    case 4:
        ret = '4';
        break;
    case 5:
        ret = '5';
        break;
    case 6:
        ret = '6';
        break;
    case 7:
        ret = '7';
        break;
    case 8:
        ret = '8';
        break;
    case 9:
        ret = '9';
        break;
    default:
        break;
    }
    return ret;
}
string floatToString(float num){
    int _1 = num * 100;
    _1 = _1 % 10;
    int _2 = num * 10;
    _2 = _2 % 10;
    int _3 = num;
    _3 = _3 % 10;
    int _4 = num / 10;
    _4 = _4 % 10;
    int _5 = num / 100;
    _5 = _5 % 10;
    int _6 = num / 1000;
    _6 = _6 % 10;

    string ret;
    ret.push_back(convert(_6));
    ret.push_back(convert(_5));
    ret.push_back(convert(_4));
    ret.push_back(convert(_3));
    ret.push_back(',');
    ret.push_back(convert(_2));
    ret.push_back(convert(_1));
    for(int i = 0; i < 7; i++)
        if(ret.at(0) == '0' && ret.at(1) != ',')
            ret.erase(ret.begin());
    return ret;
}

void venderServico::on_butVender_clicked()
{
    if(ui->lEditServ->text() == ""){
        QMessageBox::warning(this, "Erro!", "Dados insuficientes para vender um serviço.");
        return;
    }
    if(ui->lEditClient->text() == ""){
        QMessageBox::warning(this, "Erro!", "Dados insuficientes para vender um serviço.");
        return;
    }
    if(ui->lEditAuto->text() == ""){
        QMessageBox::warning(this, "Erro!", "Dados insuficientes para vender um serviço.");
        return;
    }
    string s = ui->lEditServ->text().toStdString();
    Cliente * c = ofc->buscarCliente(ui->lEditClient->text().toStdString());
    QString p;
    for(int i = 0; i < 7; i++)
        p.push_back(ui->lEditAuto->text().at(i));

    if(ofc->venderServ(s, c, p.toStdString())){
        QMessageBox::information(this, "Foi boa!", "Venda concluída com sucesso!");
        hide();
    }
    else
        QMessageBox::warning(this, "Erro!", "Não foi possível realizar a venda.");
}

#include "oficinamecanica.h"
#include "ui_oficinamecanica.h"
#include "menucliente.h"
#include "menuauto.h"
#include "menuservico.h"

OficinaMecanica::OficinaMecanica(OficinaMec * ofc, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OficinaMecanica)
{
    ui->setupUi(this);
    ui->labelPic->setPixmap(QPixmap("/home/carlos/Imagens/vdc.png"));
    this->ofc = ofc;
}

OficinaMecanica::~OficinaMecanica()
{
    delete ui;
}

void OficinaMecanica::on_butSair_clicked()
{
    int resp = QMessageBox::warning(this, "Alerta", "Você realmente deseja sair?",
                                    QMessageBox::Cancel, QMessageBox::Ok);
    if(resp == QMessageBox::Ok)
        qApp->quit();
}

void OficinaMecanica::on_butClient_clicked()
{
    hide();
    menuCliente mClient(ofc, this);
    mClient.setModal(true);
    mClient.exec();
}

void OficinaMecanica::on_butAutos_clicked()
{
    hide();
    menuAuto mAuto(ofc, this);
    mAuto.setModal(true);
    mAuto.exec();
}

void OficinaMecanica::on_butServicos_clicked()
{
    hide();
    menuServico mServ(ofc, this);
    mServ.setModal(true);
    mServ.exec();
}

void OficinaMecanica::on_butSaldo_clicked()
{
    stringstream ss;
    ss << "Saldo atual, R$: " << floatToString(ofc->getSaldo()) << endl;;
    QMessageBox::information(this, "Saldo da oficina", QString::fromStdString(ss.str()));
}

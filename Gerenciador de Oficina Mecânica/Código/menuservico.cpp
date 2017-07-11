#include "menuservico.h"
#include "ui_menuservico.h"

menuServico::menuServico(OficinaMec *ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuServico)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

menuServico::~menuServico()
{
    delete ui;
}

void menuServico::on_butVoltar_clicked()
{
    QDialog * a = static_cast<QDialog *>(parent());
    a->show();
    hide();
}

void menuServico::on_butVenderServ_clicked()
{
    venderServico serv(ofc, this);
    serv.setModal(true);
    serv.exec();
}

void menuServico::on_butListar_clicked()
{
    stringstream lista;
    for(Servico s : ofc->servicos)
        lista << s.getNome() << " - R$: " << floatToString(s.getPreco())
              << endl << "----------" << endl;
    QMessageBox::information(this,"Servicos", QString::fromStdString(lista.str()));
}

void menuServico::on_butAdd_clicked()
{
    cadastroServ serv(ofc, this);
    serv.setModal(true);
    serv.exec();
}

void menuServico::on_butAtt_clicked()
{
    AttServico serv(ofc, this);
    serv.setModal(true);
    serv.exec();
}

void menuServico::on_butRm_clicked()
{
    rmServico serv(ofc, this);
    serv.setModal(true);
    serv.exec();
}

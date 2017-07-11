#include "rmservico.h"
#include "ui_rmservico.h"

rmServico::rmServico(OficinaMec * ofc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rmServico)
{
    ui->setupUi(this);
    this->ofc = ofc;
}

rmServico::~rmServico()
{
    delete ui;
}

void rmServico::on_butServico_clicked()
{
    bool ok;
    QStringList list;
    for (Servico s : ofc->servicos)
        list << QString::fromStdString(s.getNome());
    QString serv = QInputDialog::getItem(this, "Serviços", "Selecione o serviço:",
                                         list, 0, false, &ok);
    if (ok && !serv.isEmpty()){
        ui->lEditServico->setText(serv);
    }
}


void rmServico::on_butRemover_clicked()
{
    if(ui->lEditServico->text() == ""){
        QMessageBox::warning(this, "Erro!", "Selecione um serviço.");
        return;
    }
    string nome = ui->lEditServico->text().toStdString();
    if(ofc->rmServico(nome)){
        QMessageBox::information(this, "Foi boa!", "Serviço removido com sucesso.");
        hide();
    }
    else
        QMessageBox::critical(this, "Erro!", "Não foi possível remover o serviço.");
}

#include "oficinamecanica.h"
#include <QApplication>
#include "oficinamec.h"


int main(int argc, char *argv[])
{
    // INICIALIZACAO
    OficinaMec ofc("Oficina");
    ofc.addServico(Servico("Lavagem", 75.55));
    ofc.addServico(Servico("Troca de Óleo", 149.90));
    ClienteComum a("Joao", "123455");
    ClienteVip b("Paulo");

    ofc.addCliente(&a);
    ofc.addCliente(&b);

    Carro x("Volkswagen", "Up!", "nux6954", &a, "2012");
    Moto y("Honda", "Fan", "nux5454", &a, "2015");
    Carro z("Volkswagen", "Gol", "oir7788", &a, "2007");

    a.addAuto(&x);
    a.addAuto(&y);
    b.addAuto(&z);

    //----------------------------------

    QApplication app(argc, argv);
    OficinaMecanica w(&ofc);
    w.show();

    return app.exec();
}

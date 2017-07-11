#ifndef OFICINAMEC_H
#define OFICINAMEC_H

#include <iostream>
#include <vector>
#include "servico.h"
#include "cliente.h"
#include "venda.h"

using namespace std;

class OficinaMec
{
    string nome;
    vector<Cliente*> clientes;
    vector<Servico> servicos;
    vector<Venda> vendas;
    float saldo;
public:
    OficinaMec(string nome);
    string getNome() const;
    void setNome(const string &value);
    bool addCliente(Cliente * client);
    bool addServico(Servico serv);
    Servico * getServico(string serv);
    bool venderServ(string serv, Cliente * client, string placa);
    string listarClientes();
    Cliente * buscarCliente(string nome);
    string listarVeiculos();
    Cliente * searchCliente(string nome);
    void listarServicos();
    float getSaldo() const;
    bool rmCliente(string nome);
    bool rmServico(string nome);

    friend class menuAuto;
    friend class cadastroAuto;
    friend class venderServico;
    friend class menuServico;
    friend class AttServico;
    friend class AttAuto;
    friend class rmCliente;
    friend class rmAuto;
    friend class rmServico;
};

#endif // OFICINAMEC_H

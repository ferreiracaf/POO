#ifndef VENDA_H
#define VENDA_H

#include <iostream>

using namespace std;

class Venda{
private:
    string servico;
    string nomeCliente;
    string telefoneCliente;
    string descricaoAuto;
public:
    Venda(string servico, string nome, string telefone, string descricao);
    string getServico() const;
    void setServico(const string &value);
    string getNomeCliente() const;
    void setNomeCliente(const string &value);
    string getTelefoneCliente() const;
    void setTelefoneCliente(const string &value);
    string getDescricaoAuto() const;
    void setDescricaoAuto(const string &value);
};

#endif // VENDA_H

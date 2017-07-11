#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include "automovel.h"

enum CLIENTE {COMUM, VIP};

using namespace std;

class Cliente
{
    string nome;
    string telefone;
    vector<Automovel*> veiculos;
public:
    Cliente(string nome, string telefone = "~");
    string getNome() const;
    void setNome(const string &value);
    string getTelefone() const;
    void setTelefone(const string &value);
    string toString() const;
    bool addAuto(Automovel * aut);
    bool rmAuto(string placa);
    Automovel * getAuto(string placa);
    string showAuto() const;
    virtual CLIENTE getTipo() = 0;
    void rmAllVeiculos();

    friend class menuAuto;
    friend class venderServico;
    friend class AttAuto;
    friend class OficinaMec;
    friend class rmAuto;
};

class ClienteComum : public Cliente
{
public:
    ClienteComum(string nome, string telefone = "~");
    CLIENTE getTipo();
};

class ClienteVip : public Cliente
{
public:
    ClienteVip(string nome, string telefone = "~");
    CLIENTE getTipo();
};

#endif // CLIENTE_H

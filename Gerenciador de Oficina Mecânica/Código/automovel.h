#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H

#include <iostream>
#include <sstream>
#include <memory>

enum AUTO{
    MOTO,
    CARRO
};

using namespace std;

class Cliente;

class Automovel
{
    string marca;
    string modelo;
    string ano;
    string placa;
    Cliente * cliente;
public:
    Automovel(string marca, string modelo, string placa,
              Cliente * client, string ano = "~");

    string getPlaca() const;
    void setPlaca(const string &value);
    Cliente *getCliente() const;
    void setCliente(Cliente *value);
    string toString() const;
    string getInfo() const;
    ~Automovel(){}
    string getMarca() const;
    void setMarca(const string &value);
    string getAno() const;
    void setAno(const string &value);
    string getModelo() const;
    void setModelo(const string &value);
    virtual AUTO getTipo() = 0;

    friend class Cliente;
};

class Moto : public Automovel
{
    AUTO tipo{MOTO};
public:
    Moto(string marca, string modelo, string placa,
         Cliente * client, string ano = "~");
    AUTO getTipo();
    void setTipo(AUTO value);
};

class Carro : public Automovel
{
    AUTO tipo{CARRO};
public:
    Carro(string marca, string modelo, string placa,
          Cliente * client, string ano = "~");
    AUTO getTipo();
    void setTipo(AUTO value);
};

#endif // AUTOMOVEL_H

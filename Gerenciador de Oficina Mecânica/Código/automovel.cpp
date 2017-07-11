#include "automovel.h"
#include "cliente.h"

string Automovel::getMarca() const
{
    return marca;
}

void Automovel::setMarca(const string &value)
{
    marca = value;
}

string Automovel::getAno() const
{
    return ano;
}

void Automovel::setAno(const string &value)
{
    ano = value;
}

string Automovel::getModelo() const
{
    return modelo;
}

void Automovel::setModelo(const string &value)
{
    modelo = value;
}

Automovel::Automovel(string marca, string modelo, string placa,
                     Cliente *client, string ano):
    ano(ano)
{
    this->marca = marca;
    this->modelo = modelo;
    this->placa = placa;
    this->cliente = client;
}

Cliente *Automovel::getCliente() const
{
    return cliente;
}

void Automovel::setCliente(Cliente *value)
{
    cliente = value;
}

string Automovel::getPlaca() const
{
    return placa;
}

void Automovel::setPlaca(const string &value)
{
    placa = value;
}

string Automovel::toString() const{
    stringstream ss;
    ss << marca << ", " << modelo << " - " << ano
       << endl << "Placa: " << placa << " Dono: " << cliente->getNome();
    return ss.str();
}

string Automovel::getInfo() const{
    stringstream ss;
    ss << placa << " - " << marca << ", "
       << modelo << " - " << ano;
    return ss.str();
}

void Moto::setTipo(AUTO value)
{
    tipo = value;
}

Moto::Moto(string marca, string modelo, string placa, Cliente *client, string ano):
    Automovel(marca, modelo, placa, client, ano)
{}

AUTO Moto::getTipo(){
    return tipo;
}

void Carro::setTipo(AUTO value)
{
    tipo = value;
}

Carro::Carro(string marca, string modelo, string placa, Cliente *client, string ano):
    Automovel(marca, modelo, placa, client, ano)
{}

AUTO Carro::getTipo(){
    return tipo;
}

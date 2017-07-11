#include "cliente.h"



string Cliente::getTelefone() const
{
    return telefone;
}

void Cliente::setTelefone(const string &value)
{
    telefone = value;
}

string Cliente::toString() const{
    stringstream ss;
    ss << nome << ", tel: " << telefone << endl << "Veiculos:" << endl;
    for(Automovel * aut : veiculos)
        ss << aut->toString() << endl;
    ss << "----------";
    return ss.str();
}

bool Cliente::addAuto(Automovel *aut){
    for(Automovel * a : veiculos)
        if(a->getPlaca() == aut->getPlaca())
            return false;
    veiculos.push_back(aut);
    aut->cliente = this;
    return true;
}

bool Cliente::rmAuto(string placa){
    for(int i = 0; i < (int) veiculos.size(); i++)
            if(veiculos[i]->getPlaca() == placa){
                veiculos.erase(veiculos.begin() + i);
                return true;
            }
        return false;
}

Automovel *Cliente::getAuto(string placa){
    for(Automovel * a : veiculos)
            if(a->getPlaca() == placa)
                return a;
        return nullptr;
}

string Cliente::showAuto() const{
    stringstream ss;
        for (Automovel * a : veiculos)
            ss << a->toString() << endl << "----------" << endl;
        return ss.str();
}

void Cliente::rmAllVeiculos(){
    int tam = veiculos.size();
    for(int i = 0; i < tam; i++){
        veiculos.erase(veiculos.begin());
    }
}

Cliente::Cliente(string nome, string telefone):
    telefone(telefone)
{
    this->nome = nome;
}

string Cliente::getNome() const
{
    return nome;
}

void Cliente::setNome(const string &value)
{
    nome = value;
}

ClienteComum::ClienteComum(string nome, string telefone):
    Cliente(nome, telefone)
{}

CLIENTE ClienteComum::getTipo(){
    return COMUM;
}

ClienteVip::ClienteVip(string nome, string telefone):
    Cliente(nome, telefone)
{}

CLIENTE ClienteVip::getTipo(){
    return VIP;
}

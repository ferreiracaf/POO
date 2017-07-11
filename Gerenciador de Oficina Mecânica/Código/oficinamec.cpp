#include "oficinamec.h"

float OficinaMec::getSaldo() const
{
    return saldo;
}

bool OficinaMec::rmCliente(string nome){
    for(int i = 0; i < (int) clientes.size(); i++){
        if(clientes[i]->getNome() == nome){
            clientes[i]->rmAllVeiculos();
            if((int) clientes[i]->veiculos.size() == 0){
                clientes.erase(clientes.begin() + i);
                return true;
            }
        }
    }
    return false;
}

bool OficinaMec::rmServico(string nome){
    for(int i = 0; i < (int) servicos.size(); i++)
        if(servicos[i].getNome() == nome){
            servicos.erase(servicos.begin() + i);
            return true;
        }
    return false;
}

OficinaMec::OficinaMec(string nome)
{
    this->nome = nome;
}

string OficinaMec::getNome() const
{
    return nome;
}

void OficinaMec::setNome(const string &value)
{
    nome = value;
}

bool OficinaMec::addCliente(Cliente *client){
    for(Cliente * c : clientes)
        if(c->getNome() == client->getNome())
            return false;
    clientes.push_back(client);
    return true;
}

bool OficinaMec::addServico(Servico serv){
    for(Servico s : servicos)
        if(s.getNome() == serv.getNome())
            return false;
    servicos.push_back(serv);
    return true;
}

Servico *OficinaMec::getServico(string serv){
    for(int i = 0; i < (int) servicos.size(); i++)
        if(serv == servicos[i].getNome())
            return &servicos[i];
    return nullptr;
}

bool OficinaMec::venderServ(string serv, Cliente *client, string placa){
    Servico * s = getServico(serv);
    if(s == nullptr)
        return false;
    Automovel * a = client->getAuto(placa);
    if(a == nullptr)
        return false;
    if(client->getTipo() == COMUM){
        saldo += s->getPreco();
        vendas.push_back(Venda(s->getNome(), client->getNome(),
                               client->getTelefone(), a->toString()));
        return true;
    }
    else if (client->getTipo() == VIP) {
        saldo += s->getPreco()*2;
        vendas.push_back(Venda(s->getNome(), client->getNome(),
                               client->getTelefone(), a->toString()));
        return true;
    }
    return false;
}

string OficinaMec::listarClientes(){
    stringstream ss;
    for (Cliente * c : clientes)
        ss << c->getNome() << endl << "---------" << endl;
    return ss.str();
}

Cliente *OficinaMec::buscarCliente(string nome){
    for (Cliente * c : clientes)
        if(c->getNome() == nome)
            return c;
    return nullptr;
}

string OficinaMec::listarVeiculos(){
    stringstream ss;
    for(Cliente * c : clientes)
        ss << c->showAuto();
    return ss.str();
}

Cliente *OficinaMec::searchCliente(string nome){
    for(Cliente * c : clientes)
        if(c->getNome() == nome)
            return c;
    return nullptr;
}

void OficinaMec::listarServicos(){
    cout << "Servicos oferecidos:" << endl;
    for (Servico s : servicos)
        cout << s.getNome() << " - R$:"<< s.getPreco() << endl;
    cout << "##################" << endl;
}

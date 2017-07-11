#include "venda.h"

string Venda::getServico() const
{
    return servico;
}

void Venda::setServico(const string &value)
{
    servico = value;
}

string Venda::getNomeCliente() const
{
    return nomeCliente;
}

void Venda::setNomeCliente(const string &value)
{
    nomeCliente = value;
}

string Venda::getTelefoneCliente() const
{
    return telefoneCliente;
}

void Venda::setTelefoneCliente(const string &value)
{
    telefoneCliente = value;
}

string Venda::getDescricaoAuto() const
{
    return descricaoAuto;
}

void Venda::setDescricaoAuto(const string &value)
{
    descricaoAuto = value;
}

Venda::Venda(string servico, string nome, string telefone, string descricao){
    this->servico = servico;
    this->telefoneCliente = telefone;
    this->nomeCliente = nome;
    this->descricaoAuto = descricao;
}


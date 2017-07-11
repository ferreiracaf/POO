#include "servico.h"



float Servico::getPreco() const
{
    return preco;
}

void Servico::setPreco(float value)
{
    preco = value;
}

string Servico::getNome() const
{
    return nome;
}

void Servico::setNome(string nome)
{
    this->nome = nome;
}

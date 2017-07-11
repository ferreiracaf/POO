#ifndef SERVICO_H
#define SERVICO_H

#include <iostream>

using namespace std;

class Servico
{
    string nome;
    float preco;

public:
    Servico(string nome, float preco)
    {
        this->nome = nome;
        this->preco = preco;
    }
    string getNome() const;
    void setNome(string nome);
    float getPreco() const;
    void setPreco(float value);
};

#endif // SERVICO_H

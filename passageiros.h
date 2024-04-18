//
// Created by guilh on 18/04/2024.
//
#include <iostream>
#include <string>


using namespace std;

#ifndef SEGUNDO_PROJETO_EDA_PASSAGEIROS_H
#define SEGUNDO_PROJETO_EDA_PASSAGEIROS_H
struct passageiros{
    string numBilhete;
    string primeiroNome;
    string ultimoNome;
    string nacionalidade;
    struct passageiros * next;
};

string* leFicheiroPrimeiroNome();
string* leFicheiroUltimoNome();
string* leFicheiroNacionalidade();

passageiros* adicionaPassageiro(passageiros* head, string numBilhete, string primeiroNome, string ultimoNome, string nacionalidade);
passageiros* criaPassageiros();
passageiros* adicionaPassageiroFila(passageiros* head, passageiros* passageiro);

#endif //SEGUNDO_PROJETO_EDA_PASSAGEIROS_H

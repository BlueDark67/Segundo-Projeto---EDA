
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

struct nodo{
    passageiros* passageiro;
    nodo* pDireita;
    nodo* pEsquerda;
};

struct noNacionalidade{
    string* nacionalidade;
    nodo* raiz;
    struct noNacionalidade* next;
};

string* leFicheiroPrimeiroNome();
string* leFicheiroUltimoNome();
string* leFicheiroNacionalidade();

passageiros* adicionaPassageiro(passageiros* head, string numBilhete, string primeiroNome, string ultimoNome, string nacionalidade);
passageiros* criaPassageiros();
passageiros* adicionaPassageiroFila(passageiros* head, passageiros* passageiro);

nodo* novoNodo(passageiros* passageiro);
nodo* inserirNodo(nodo* no, passageiros* passageiro);
nodo* criaArvore(passageiros* passageiro);
noNacionalidade* criaListaNacionalide(noNacionalidade* no, nodo* raiz);

void imprimeArvore(nodo* no, int profundidade);

int altura(nodo* no);
int contaNos(nodo* no);


#endif //SEGUNDO_PROJETO_EDA_PASSAGEIROS_H

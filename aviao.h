//
// Created by guilh on 18/04/2024.
//
#include <iostream>
#include <string>
#include "aeroporto.h"
#include "passageiros.h"

using namespace std;

#ifndef SEGUNDO_PROJETO_EDA_AVIAO_H
#define SEGUNDO_PROJETO_EDA_AVIAO_H

struct avioes{
    string nomeVoo;
    string modelo;
    string origem;
    string destino;
    int capacidade;
    int qtdPassageiros;
    passageiros* passageiroHead;
    struct avioes * next;
};

struct Node {
    avioes* aviao;
    struct Node* next;
};


string* leFicheiroNomeVoo();
string* leFicheiroModeloAviao();
string* leFicheiroOrigem();
string* leFicheiroDestino();

avioes* adicionaAvioes(avioes* head, string nomeVoo, string modelo, string origem, string destino, int capacidade, int qtdPassageiros);
avioes* criaAvioes();

Node* filaChegada(Node* tail, avioes* aviao);
Node* filaPista(Node* tail, avioes* aviao);
Node* filaPartida(Node* tail, avioes* aviao);

void adicionaPassageiroAviao(avioes* aviao);


#endif //SEGUNDO_PROJETO_EDA_AVIAO_H

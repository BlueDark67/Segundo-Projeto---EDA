
//
// Created by guilh on 18/04/2024.
//
#include <iostream>
#include <string>
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

string* leFicheiroNomeVoo();
string* leFicheiroModeloAviao();
string* leFicheiroOrigem();
string* leFicheiroDestino();

avioes* adicionaAvioes(avioes* head, string nomeVoo, string modelo, string origem, string destino, int capacidade, int qtdPassageiros);
avioes* criaAvioes();
avioes* adicionaAviaoFilaChegada(avioes* head, avioes* aviao);
avioes* adicionaAviaoFilaChegada2(avioes*& head, avioes* aviao);

void adicionaPassageiroAviao(avioes* aviao);
void apresentaInfoTodosAvioes(avioes* head);
void apresentaPassageiros(avioes* aviao);
void moverAviaoParaPista(avioes*& filaChegada, avioes*& filaPista, noNacionalidade*& listaNacionalidades);
void moverAviaoParaPista2(avioes*& filaChegada, avioes*& filaPista, noNacionalidade*& listaNacionalidades);
void moverAviaoParaPartida(avioes*&filaPista,avioes *&filaPartida);
void simularCiclo(avioes*& filaChegada, avioes*& filaPista, avioes *& filaPartida, noNacionalidade*& listaNacionalidades);
void moverAviaoParaEliminar(avioes*& filaPista, avioes*& filaEliminar);
void adicionaPassageiroAviao2(avioes* aviao, passageiros* passageiro);
void inserePassageiroNaArvore(noNacionalidade*& listaNacionalidades, avioes*& aviao);
void insereTodosPassageirosNaArvore(noNacionalidade* listaNacionalidades, avioes* filaPista);
void mostrarPassageiros(avioes* fila);
void mostrarPassageirosOrdemAlfabetica(avioes* fila);
void pesquisarPassageiro(avioes* filaChegada, avioes* filaPartida);
void editarNacionalidadePassageiro(avioes* fila);
void invertePrioridade(avioes*& fila);
void moverAviaoEmergenciaParaPista(avioes*& filaChegada, avioes*& filaPista, avioes*& filaPartida);

int tamanhoFilas(avioes* head);

#endif //SEGUNDO_PROJETO_EDA_AVIAO_H

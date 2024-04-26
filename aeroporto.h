
//
// Created by guilh on 18/04/2024.
//
#include <iostream>
#include <string>
#include "aviao.h"

using namespace std;

#ifndef SEGUNDO_PROJETO_EDA_AEROPORTO_H
#define SEGUNDO_PROJETO_EDA_AEROPORTO_H
void GuardaDadosAeroporto( avioes *&filaChegada, avioes *& filaPista, avioes *& filaPartida);
void carregarDadosAeroporto(avioes * filaChegada, avioes*& filaPista);
void menuG(avioes* filaChegada, avioes* filaPista, avioes* filaPartida);

int contarLinhas(string nomeFicheiro);

avioes* leFicheiroChegada(string nome1, string nome2);
#endif //SEGUNDO_PROJETO_EDA_AEROPORTO_H

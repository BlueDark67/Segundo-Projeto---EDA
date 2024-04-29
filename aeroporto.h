
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
void carregarDadosAeroporto(avioes*& filaChegada, avioes*& filaPista, avioes*& filaPartida ,string nomeFAC,string nomeFAP,string nomeFAPA, string nomeFPC, string nomeFPP, string nomeFPPA);
void menuG(avioes* filaChegada, avioes* filaPista, avioes* filaPartida);
void leFicheiroA(string nome1, avioes*& filaRetirada);
void leFicheiroP(string nome2, avioes*& filaRetirada);

int contarLinhas(string nomeFicheiro);


#endif //SEGUNDO_PROJETO_EDA_AEROPORTO_H

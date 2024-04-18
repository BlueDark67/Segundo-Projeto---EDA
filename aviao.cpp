//
// Created by guilh on 18/04/2024.
//
#include "passageiros.h"
#include "aviao.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string * leFicheiroNomeVoo(){
    const int max_linha = 80;
    auto * conteudoVoo = new string[max_linha];
    int linhaVoo = 0;
    string textoVoo;
    ifstream ficheiroVoo("voo.txt");
    while (getline (ficheiroVoo, textoVoo) && linhaVoo < max_linha) {
        conteudoVoo[linhaVoo] =textoVoo;
        linhaVoo++;
    }
    ficheiroVoo.close();
    return conteudoVoo;

}

string * leFicheiroModeloAviao(){
    const int max_linha = 32;
    auto * conteudoAviao = new string[max_linha];
    int linhaAviao = 0;
    string textoAviao;
    ifstream ficheiroAviao("modelo.txt");
    while (getline (ficheiroAviao, textoAviao) && linhaAviao < max_linha) {
        conteudoAviao[linhaAviao] =textoAviao;
        linhaAviao++;
    }
    ficheiroAviao.close();
    return conteudoAviao;

}

string * leFicheiroOrigem(){
    const int max_linha = 25;
    auto * conteudoOrigem = new string[max_linha];
    int linhaOrigem = 0;
    string textoOrigem;
    ifstream ficheiroOrigem("origem.txt");
    while (getline (ficheiroOrigem, textoOrigem) && linhaOrigem < max_linha) {
        conteudoOrigem[linhaOrigem] =textoOrigem;
        linhaOrigem++;
    }
    ficheiroOrigem.close();
    return conteudoOrigem;

}

string * leFicheiroDestino(){
    const int max_linha = 25;
    auto * conteudoDestino = new string[max_linha];
    int linhaDestino = 0;
    string textoDestino;
    ifstream ficheiroDestino("destino.txt");
    while (getline (ficheiroDestino, textoDestino) && linhaDestino < max_linha) {
        conteudoDestino[linhaDestino] =textoDestino;
        linhaDestino++;
    }
    ficheiroDestino.close();
    return conteudoDestino;

}

avioes* adicionaAvioes(avioes* head, string nomeVoo, string modelo, string origem, string destino, int capacidade, int qtdPassageiros){
    avioes* novoAviao = new avioes;
    novoAviao->nomeVoo = nomeVoo;
    novoAviao->modelo = modelo;
    novoAviao->origem = origem;
    novoAviao->destino = destino;
    novoAviao->capacidade = capacidade;
    novoAviao->qtdPassageiros = qtdPassageiros;
    novoAviao->next = head;
    return novoAviao;
}

avioes* criaAvioes(){
    string* conteudoNomeVoo = leFicheiroNomeVoo();
    string* conteudoModeloAviao = leFicheiroModeloAviao();
    string* conteudoOrigem = leFicheiroOrigem();
    string* conteudoDestino = leFicheiroDestino();
    string nomeVoo = conteudoNomeVoo[rand()%80];
    string modelo = conteudoModeloAviao[rand()%32];
    string origem = conteudoOrigem[rand()%25];
    string destino = conteudoDestino[rand()%25];
    int Capacidade = rand() % 6 + 10;
    int qtdPassageiros = Capacidade;
    avioes* novoAviao = adicionaAvioes(nullptr, nomeVoo, modelo, origem, destino, Capacidade, qtdPassageiros);
    novoAviao->passageiroHead = nullptr;
    return novoAviao;
}

Node* filaChegada(Node* tail, avioes* aviao){
    Node* novoNode = new Node;
    novoNode->aviao = aviao;
    novoNode->next = nullptr;
    if (tail == nullptr){
        tail = novoNode;
    } else {
        Node* temp = tail;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = novoNode;
    }
    return tail;
}

Node* filaPista(Node* tail, avioes* aviao){
    Node* novoNode = new Node;
    novoNode->aviao = aviao;
    novoNode->next = nullptr;
    if (tail == nullptr){
        tail = novoNode;
    } else {
        Node* temp = tail;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = novoNode;
    }
    return tail;
}

Node* filaPartida(Node* tail, avioes* aviao){
    Node* novoNode = new Node;
    novoNode->aviao = aviao;
    novoNode->next = nullptr;
    if (tail == nullptr){
        tail = novoNode;
    } else {
        Node* temp = tail;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = novoNode;
    }
    return tail;
}

void adicionaPassageiroAviao(avioes* aviao){
    aviao->passageiroHead = adicionaPassageiroFila(aviao->passageiroHead, criaPassageiros());
}



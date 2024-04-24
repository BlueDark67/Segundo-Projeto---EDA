//
// Created by guilh on 18/04/2024.
//
#include "passageiros.h"
#include "aviao.h"
#include <fstream>
#include <string>
#include <stdlib.h>

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
    novoAviao->next = nullptr;
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
    string destino = "Aeroporto EDA";
    int Capacidade = rand() % 6 + 10;
    int qtdPassageiros = Capacidade;
    avioes* novoAviao = adicionaAvioes(nullptr, nomeVoo, modelo, origem, destino, Capacidade, qtdPassageiros);
    novoAviao->passageiroHead = nullptr;
    return novoAviao;
}

avioes* adicionaAviaoFilaChegada(avioes* head, avioes* aviao){
    avioes* novoNode = new avioes;
    novoNode = aviao;
    novoNode->next = nullptr;
    if (head == nullptr){
        head = novoNode;
    } else {
        avioes* aux = head;
        while (aux->next != nullptr){
            aux = aux->next;
        }
        aux->next = novoNode;
    }
    return head;
}



void adicionaPassageiroAviao(avioes* aviao){
    for (int i = 0; i < aviao->capacidade; i++) {
        aviao->passageiroHead = adicionaPassageiroFila(aviao->passageiroHead, criaPassageiros());
    }
}

void apresentaInfoTodosAvioes(avioes* head) {
    avioes* aux = head;
    while (aux != nullptr) {
        avioes* aviao = aux;
        cout << "Nome do Voo: " << aviao->nomeVoo << endl;
        cout << "Modelo: " << aviao->modelo << endl;
        cout << "Origem: " << aviao->origem << endl;
        cout << "Destino: " << aviao->destino << endl;
        apresentaPassageiros(aviao);
        cout <<  endl;
        aux = aux->next;
    }
}

void apresentaPassageiros(avioes* aviao){
    passageiros* aux = aviao->passageiroHead;
    cout << "Passageiros: ";
    int i = 0;
    while (aux != nullptr && i <= aviao->qtdPassageiros) {
        if (i+1 == aviao->qtdPassageiros) {
            cout << aux->primeiroNome;
            break;
        } else {
            cout << aux->primeiroNome << ", ";
            aux = aux->next;
            i++;
        }
    }
    cout << endl;
}

void moverAviaoParaPista(avioes*& filaChegada, avioes*& filaPista) {
    if (filaChegada != nullptr) {
        avioes* aviaoAtual = filaChegada;
        filaChegada = filaChegada->next; // Remover o avião da fila de chegada
        aviaoAtual->next = nullptr;

        // Adicionar o avião à fila de pista
        if (filaPista == nullptr) {
            filaPista = aviaoAtual;
        } else {
            aviaoAtual->next = filaPista;
            filaPista = aviaoAtual;
        }

        apresentaInfoTodosAvioes(filaPista);
    } else {
        cout << "Nenhum aviao em aproximação para mover para a pista." << endl;
    }
}

// Função para adicionar um avião ao conjunto de aviões em aproximação
void adicionarAviaoAproximacao(avioes*& filaChegada) {
    string nomeVoo = "Novo Voo";
    string modelo = "Modelo";
    string origem = "Origem";
    string destino = "Destino";
    int capacidade = rand() % 6 + 10;
    int qtdPassageiros = capacidade;

    avioes* novoAviao = adicionaAvioes(nullptr, nomeVoo, modelo, origem, destino, capacidade, qtdPassageiros);
    novoAviao->next = filaChegada;
    filaChegada = novoAviao;

    cout << "Novo aviao adicionado à fila de chegada." << endl;
}

void simularCiclo(avioes*& filaChegada, avioes*& filaPista) {
    // Mover um avião do conjunto de aviões em aproximação para o conjunto de aviões em pista
    if (tamanhoFilas(filaChegada) <10){
        cout << "Apenas " << tamanhoFilas(filaChegada) << " avioes em chegada." << endl;
    }else{
        moverAviaoParaPista(filaChegada, filaPista);
        cout << "------Avioes em chegada-----\n" << endl;
        apresentaInfoTodosAvioes(filaChegada);

    }

}

void removeNo(avioes** head){
    if(*head == nullptr){
        cout << "Lista vazia" << endl;
    }
    avioes* aux = *head;
    *head = aux->next;
    delete aux;
}

int tamanhoFilas(avioes* head){
    avioes* aux = head;
    int tamanho = 0;
    while (aux != nullptr) {
        tamanho++;
        aux = aux->next;
    }
    return tamanho;
}








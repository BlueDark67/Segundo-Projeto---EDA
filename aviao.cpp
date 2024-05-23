//
// Created by guilh on 18/04/2024.
//
#include "passageiros.h"
#include "aviao.h"
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

/**
 * Função que lê o ficheiro primeiro_nome.txt
 * @return - conteudo do ficheiro primeiro_nome.txt
 */
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

/**
 * Função que lê o ficheiro modelo.txt
 * @return - conteudo do ficheiro modelo.txt
 */
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

/**
 * Função que lê o ficheiro origem.txt
 * @return - conteudo do ficheiro origem.txt
 */
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

/**
 * Função que lê o ficheiro destino.txt
 * @return - conteudo do ficheiro destino.txt
 */
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

/**
 * Função que cria um passageiro
 * @return - passageiro
 */
avioes* adicionaAvioes(avioes* head, string nomeVoo, string modelo, string origem, string destino, int capacidade, int qtdPassageiros){
    avioes* novoAviao = new avioes;
    novoAviao->nomeVoo = nomeVoo;
    novoAviao->modelo = modelo;
    novoAviao->origem = origem;
    novoAviao->destino = destino;
    novoAviao->capacidade = capacidade;
    novoAviao->qtdPassageiros = qtdPassageiros;
    novoAviao->next = nullptr;
    novoAviao->passageiroHead = nullptr;
    return novoAviao;
}

/**
 * Função que cria um passageiro
 * @return - passageiro
 */
avioes* criaAvioes(){
    string* conteudoNomeVoo = leFicheiroNomeVoo();
    string* conteudoModeloAviao = leFicheiroModeloAviao();
    string* conteudoOrigem = leFicheiroOrigem();

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

/**
 * Função que adiciona um passageiro à lista de passageiros
 * @param head - cabeça da lista de passageiros
 * @param passageiro - passageiro a adicionar
 * @return - lista de passageiros com o novo passageiro
 */
void adicionaPassageiroAviao(avioes* aviao){
    for (int i = 0; i < aviao->capacidade; i++) {
        aviao->passageiroHead = adicionaPassageiroFila(aviao->passageiroHead, criaPassageiros());
    }
}
/**
 * Função que adiciona um passageiro à lista de passageiros
 * @param head - cabeça da lista de passageiros
 * @param passageiro - passageiro a adicionar
 * @return - lista de passageiros com o novo passageiro
 */
void adicionaPassageiroAviao2(avioes* aviao, passageiros* passageiro){
    aviao->passageiroHead = adicionaPassageiroFila(aviao->passageiroHead, passageiro);
}

/**
 * Função que apresenta a informação de todos os aviões
 * @param head - cabeça da lista de aviões
 */
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
/**
 * Função que apresenta a informação de todos os passageiros
 * @param head - cabeça da lista de aviões
 */
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

/**
 * Função que adiciona um avião à lista de aviões
 * @param head - cabeça da lista de aviões
 * @param aviao - avião a adicionar
 * @return - lista de aviões com o novo avião
 */
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

/**
 * Função que adiciona um avião à lista de aviões
 * @param head - cabeça da lista de aviões
 * @param aviao - avião a adicionar
 * @return - lista de aviões com o novo avião
 */
avioes* adicionaAviaoFilaChegada2(avioes*& head, avioes* aviao){
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

/**
 * Função que move um avião da fila de chegada para a pista
 * @param filaChegada - fila de chegada
 * @param filaPista - fila de pista
 */
void moverAviaoParaPista(avioes*& filaChegada, avioes*& filaPista, noNacionalidade*& listaNacionalidades) {
    string* conteudoNomeVoo = leFicheiroNomeVoo();
    passageiros* passageirosAeroporto = nullptr;
    if (filaChegada != nullptr) {
        avioes* aviaoAtual = filaChegada;
        filaChegada = filaChegada->next; // Remover o avião da fila de chegada
        inserePassageiroNaArvore(listaNacionalidades, aviaoAtual);
        aviaoAtual->next = nullptr;
        if(conteudoNomeVoo!= nullptr) {
            aviaoAtual->nomeVoo = conteudoNomeVoo[rand() % 81];
            delete[] conteudoNomeVoo;
        }
        // Adicionar o avião à fila de pista
        if (filaPista == nullptr) {
            filaPista = aviaoAtual;
        } else {
            avioes* aux = filaPista;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = aviaoAtual;
        }
    } else {
        cout << "Nenhum aviao em aproximação para mover para a pista." << endl;
    }
    avioes* novoAviaoChegada = criaAvioes();
    adicionaPassageiroAviao(novoAviaoChegada);
    filaChegada = adicionaAviaoFilaChegada(filaChegada, novoAviaoChegada);

}

/**
 * Função que move um avião da fila de pista para a partida
 * @param filaPista - fila de pista
 * @param filaPartida - fila de partida
 */
void moverAviaoParaPartida(avioes*& filaPista, avioes*& filaPartida) {
    string* conteudoDestino = leFicheiroDestino();
    if (filaPista != nullptr) {
        avioes* aviaoAtual = filaPista;
        filaPista = filaPista->next; // Remover o avião da fila de Pista
        aviaoAtual->next = nullptr;
        if(conteudoDestino!= nullptr) {
            aviaoAtual->destino = conteudoDestino[rand() % 26];
            delete[] conteudoDestino;
        }

        // Adicionar o avião à fila de partida
        if (filaPartida == nullptr) {
            filaPartida = aviaoAtual;
        } else {
            avioes* aux = filaPartida;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = aviaoAtual;
        }
    } else {
        cout << "Nenhum aviao em pista para Partir ." << endl;
    }

}

/**
 * Função que move um avião da fila de partida para a fila de eliminar
 * @param filaPartida - fila de partida
 * @param filaEliminar - fila de eliminar
 */
void moverAviaoParaEliminar(avioes*& filaPartida, avioes*& filaEliminar) {
    if (filaPartida != nullptr) {
        avioes* aviaoAtual = filaPartida;
        filaPartida = filaPartida->next; // Remover o avião da fila de Pista
        aviaoAtual->next = nullptr;

        // Adicionar o avião à fila de partida
        if (filaEliminar == nullptr) {
            filaEliminar = aviaoAtual;
        } else {
            cout << "existem" << tamanhoFilas(filaEliminar) << "avioes em fila de eliminar" << endl;

        }
        delete filaEliminar;
    } else {
        cout << "Nenhum aviao em pista para Partir ." << endl;
    }
}

/**
 * Função que simula um ciclo
 * @param filaChegada - fila de chegada
 * @param filaPista - fila de pista
 * @param filaPartida - fila de partida
 */
void simularCiclo(avioes*& filaChegada, avioes*& filaPista, avioes *& filaPartida, noNacionalidade*& listaNacionalidade) {
    if(tamanhoFilas(filaChegada) == 10){
        moverAviaoParaPista(filaChegada, filaPista, listaNacionalidade);
        cout << "----------------------------" << endl;
        cout << "-------Avioes em chegada------" << endl;
        cout << "----------------------------" << endl;
        apresentaInfoTodosAvioes(filaChegada);
        cout << "----------------------------" << endl;
        cout << "------Avioes em Pista-------" << endl;
        cout << "----------------------------" << endl;
        apresentaInfoTodosAvioes(filaPista);
        if(tamanhoFilas(filaPista) == 7) {
            moverAviaoParaPartida(filaPista, filaPartida);
            cout << "----------------------------" << endl;
            cout << "------Avioes a Partir-------" << endl;
            cout << "----------------------------" << endl;
            apresentaInfoTodosAvioes(filaPartida);
            if(tamanhoFilas(filaPartida) == 5){
                avioes* filaEliminar = nullptr;
                moverAviaoParaEliminar(filaPartida, filaEliminar);
            }
        }

    }
    cout << "Escolha uma opcao: \n";
    cout << "(e)mergencia (o)pcoes (g)ravar (s)proximo ciclo \n";
}

/**
 * Função que calcula o tamanho de uma fila
 * @param head - cabeça da fila
 * @return - tamanho da fila
 */
int tamanhoFilas(avioes* head){
    avioes* aux = head;
    int tamanho = 0;
    while (aux != nullptr) {
        tamanho++;
        aux = aux->next;
    }
    return tamanho;
}

void inserePassageiroNaArvore(noNacionalidade*& listaNacionalidades, avioes*& aviao) {
    passageiros* passageiro = aviao->passageiroHead;
    while (passageiro != nullptr) {
        noNacionalidade* aux = listaNacionalidades;
        while (aux != nullptr) {
            if (*(aux->nacionalidade) == passageiro->nacionalidade) {
                aux->raiz = inserirNodo(aux->raiz, passageiro);
                break;
            }
            aux = aux->next;
        }
        passageiro = passageiro->next;
    }
    aviao->passageiroHead = nullptr;
    adicionaPassageiroAviao(aviao);
}

void insereTodosPassageirosNaArvore(noNacionalidade* listaNacionalidades, avioes* filaPista) {
    avioes* aviaoAtual = filaPista;
    while(aviaoAtual != nullptr) {
        inserePassageiroNaArvore(listaNacionalidades, aviaoAtual);
        aviaoAtual = aviaoAtual->next;
    }

}






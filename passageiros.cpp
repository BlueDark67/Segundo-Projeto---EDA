//
// Created by guilh on 18/04/2024.
//
#include "passageiros.h"
#include "aviao.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * Função que lê o ficheiro primeiro_nome.txt
 * @return - conteudo do ficheiro primeiro_nome.txt
 */
string* leFicheiroPrimeiroNome(){
    const int max_linha = 30;
    auto* conteudoPrimeiroNome = new string[max_linha];
    int linhaPN  =0;
    string textoPN;
    ifstream ficheiroPrimeiroNome("primeiro_nome.txt");
    while (getline (ficheiroPrimeiroNome, textoPN) && linhaPN < max_linha) {
        conteudoPrimeiroNome[linhaPN] =textoPN;
        linhaPN++;
    }
    ficheiroPrimeiroNome.close();
    return conteudoPrimeiroNome;
}

/**
 * Função que lê o ficheiro segundo_nome.txt
 * @return - conteudo do ficheiro segundo_nome.txt
 */
string* leFicheiroUltimoNome(){
    const int max_linha = 30;
    auto* conteudoUltimoNome = new string[max_linha];
    int linhaUN  =0;
    string textoUN;
    ifstream ficheiroUltimoNome("segundo_nome.txt");
    while (getline (ficheiroUltimoNome, textoUN) && linhaUN < max_linha) {
        conteudoUltimoNome[linhaUN] =textoUN;
        linhaUN++;
    }
    ficheiroUltimoNome.close();
    return conteudoUltimoNome;
}

/**
 * Função que lê o ficheiro nacionalidade.txt
 * @return - conteudo do ficheiro nacionalidade.txt
 */
string* leFicheiroNacionalidade(){
    const int max_linha = 21;
    auto* conteudoNacionalidade = new string[max_linha];
    int linhaN  =0;
    string textoN;
    ifstream ficheiroNacionalidade("nacionalidade.txt");
    while (getline (ficheiroNacionalidade, textoN) && linhaN < max_linha) {
        conteudoNacionalidade[linhaN] =textoN;
        linhaN++;
    }
    ficheiroNacionalidade.close();
    return conteudoNacionalidade;
}

/**
 * Função que adiciona um passageiro à lista de passageiros
 * @param head - cabeça da lista de passageiros
 * @param numBilhete - número do bilhete do passageiro
 * @param primeiroNome - primeiro nome do passageiro
 * @param ultimoNome - último nome do passageiro
 * @param nacionalidade - nacionalidade do passageiro
 * @return - lista de passageiros com o novo passageiro
 */
passageiros* adicionaPassageiro(passageiros* head, string numBilhete, string primeiroNome, string ultimoNome, string nacionalidade){
    passageiros* novoPassageiro = new passageiros;
    novoPassageiro->numBilhete = numBilhete;
    novoPassageiro->primeiroNome = primeiroNome;
    novoPassageiro->ultimoNome = ultimoNome;
    novoPassageiro->nacionalidade = nacionalidade;
    novoPassageiro->next = head;
    return novoPassageiro;
}

/**
 * Função que cria um passageiro aleatório
 * @return - passageiro criado
 */
passageiros* criaPassageiros(){
    string* conteudoPN = leFicheiroPrimeiroNome();
    string* conteudoUN = leFicheiroUltimoNome();
    string* conteudoN = leFicheiroNacionalidade();
    string primeiroNome = conteudoPN[rand()%29];
    string ultimoNome = conteudoUN[rand()%29];
    string nacionalidade = conteudoN[rand()%21];
    int numBilheteAleatorio = rand()%9000000+1000000;
    string numBilhete = "TK" + to_string(numBilheteAleatorio);
    return adicionaPassageiro(nullptr, numBilhete, primeiroNome, ultimoNome, nacionalidade);
}

/**
 * Função que adiciona um passageiro à lista de passageiros
 * @param head - cabeça da lista de passageiros
 * @param passageiro - passageiro a adicionar
 * @return - lista de passageiros com o novo passageiro
 */
passageiros* adicionaPassageiroFila(passageiros* head, passageiros* passageiro) {
    passageiro->next = nullptr;

    if (head == nullptr) {
        return passageiro;
    }else{
        passageiros* aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = passageiro;
        return head;
    }
}

nodo* novoNodo(passageiros* passageiro){
    nodo* no = new nodo;
    no->passageiro = passageiro;
    no->pDireita = nullptr;
    no->pEsquerda = nullptr;
    return no;
}

nodo* inserirNodo(nodo* no, passageiros* passageiro) {
    if (no == nullptr) {
        no = novoNodo(passageiro);
    } else {
        // Comparação alfabética dos nomes
        if (passageiro->primeiroNome < no->passageiro->primeiroNome) {
            no->pEsquerda = inserirNodo(no->pEsquerda, passageiro);
        } else if (passageiro->primeiroNome > no->passageiro->primeiroNome) {
            no->pDireita = inserirNodo(no->pDireita, passageiro);
        } else {
            // Se os primeiros nomes forem iguais, compare os últimos nomes
            if (passageiro->ultimoNome < no->passageiro->ultimoNome) {
                no->pEsquerda = inserirNodo(no->pEsquerda, passageiro);
            } else if (passageiro->ultimoNome > no->passageiro->ultimoNome) {
                no->pDireita = inserirNodo(no->pDireita, passageiro);
            } else {
                // Se os últimos nomes também forem iguais, compare os números de bilhete
                if (passageiro->numBilhete < no->passageiro->numBilhete) {
                    no->pEsquerda = inserirNodo(no->pEsquerda, passageiro);
                } else if (passageiro->numBilhete > no->passageiro->numBilhete) {
                    no->pDireita = inserirNodo(no->pDireita, passageiro);
                } else {
                    // Se todos os campos forem iguais, o passageiro já existe na árvore
                    cout << "Passageiro já existe" << endl;
                    return no;
                }
            }
        }
    }
    return no;
}

/*nodo* criaArvore(passageiros* passageiro) {
    noNacionalidade* head = nullptr;

    // Percorre a lista de passageiros para extrair as nacionalidades únicas
    while (passageiro != nullptr) {
        bool existe = false;
        noNacionalidade* temp = head;
        while (temp != nullptr) {
            if (temp->nacionalidade == passageiro->nacionalidade) {
                existe = true;
                break;
            }
            temp = temp->next;
        }

        if (!existe) {
            // Cria uma nova árvore para essa nacionalidade
            nodo* raiz = nullptr;
            raiz = inserirNodo(raiz, passageiro); // Insira aqui a lógica para inserir o primeiro nodo na árvore
            // Insere a nacionalidade na lista ligada
            head = insereNoNacionalidade(head, passageiro->nacionalidade, raiz);
        }

        passageiro = passageiro->next;
    }

    // Retorna o ponteiro para a raiz da árvore da primeira nacionalidade
    if (head != nullptr) {
        return head->raiz;
    } else {
        return nullptr; // Retorna nullptr se a lista de passageiros estiver vazia
    }
}*/

noNacionalidade* criaListaNacionalide(noNacionalidade* no, nodo* raiz){
    string* nacionalidades = leFicheiroNacionalidade();
    string nacionalidade;
    noNacionalidade* listaNacionalidade = nullptr;
    noNacionalidade* ultimoNo = nullptr;
    for(int i = 0; i < 20; i++){
        noNacionalidade* novoNo = new noNacionalidade;
        novoNo->nacionalidade = new string(nacionalidades[i]);
        novoNo->raiz = raiz;
        novoNo->next = nullptr;
        if(listaNacionalidade == nullptr){
            listaNacionalidade = novoNo;
        }else{
            ultimoNo->next = novoNo;
        }
        ultimoNo = novoNo;
    }
    delete[] nacionalidades;
    return listaNacionalidade;
}


void imprimeArvore(nodo* no, int profundidade) {
    if (no == nullptr) {
        return;
    }

    imprimeArvore(no->pDireita, profundidade + 1); // Visita o nó direito primeiro

    // Imprime espaços em branco de acordo com a profundidade do nó
    for(int i = 0; i < profundidade; i++) {
        cout << "             ";
    }

    // Imprime o nome do passageiro
    cout << no->passageiro->primeiroNome<< no->passageiro->ultimoNome << endl;

    imprimeArvore(no->pEsquerda, profundidade + 1); // Visita o nó esquerdo
}
int altura(nodo* no){
    if (no == nullptr) {
        return 0;
    }else{
        int altEsq = altura(no->pEsquerda);
        int altDir = altura(no->pDireita);
        if (altEsq > altDir) {
            return altEsq + 1;
        }else{
            return altDir + 1;
        }
    }
}

int contaNos(nodo* no){
    if (no == nullptr) {
        return 0;
    }else{
        return 1 + contaNos(no->pEsquerda) + contaNos(no->pDireita);
    }
}

passageiros* removerPassageiro(nodo*& raiz) {
    if (raiz == nullptr) {
        return nullptr;
    }

    passageiros* passageiroRemovido = nullptr;

    if (raiz->pEsquerda == nullptr && raiz->pDireita == nullptr) {
        passageiroRemovido = raiz->passageiro;
        delete raiz;
        raiz = nullptr;
    } else if (raiz->pEsquerda != nullptr && raiz->pDireita == nullptr) {
        passageiroRemovido = raiz->passageiro;
        nodo* temp = raiz;
        raiz = raiz->pEsquerda;
        delete temp;
    } else if (raiz->pEsquerda == nullptr && raiz->pDireita != nullptr) {
        passageiroRemovido = raiz->passageiro;
        nodo* temp = raiz;
        raiz = raiz->pDireita;
        delete temp;
    } else {
        nodo* temp = raiz->pEsquerda;
        nodo* parent = raiz;
        while (temp->pDireita != nullptr) {
            parent = temp;
            temp = temp->pDireita;
        }
        passageiroRemovido = temp->passageiro;
        if (parent->pDireita == temp) {
            parent->pDireita = temp->pEsquerda;
        } else {
            parent->pEsquerda = temp->pEsquerda;
        }
        delete temp;
    }

    return passageiroRemovido;
}
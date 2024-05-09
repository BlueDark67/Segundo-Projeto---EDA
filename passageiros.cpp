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

nodo* inserirNodo(nodo* no, passageiros* passageiro, int numPassageiros) {
    if (no == nullptr) {
        no = novoNodo(passageiro);
    } else {
        int num1Comparacao = passageiro->primeiroNome.compare(no->passageiro->primeiroNome);
        int num2Comparacao = passageiro->ultimoNome.compare(no->passageiro->ultimoNome);
        int num3Comparacao = passageiro->numBilhete.compare(no->passageiro->numBilhete);

        if (num1Comparacao == 0 && num2Comparacao == 0 && num3Comparacao == 0) {
            cout << "Passageiro já existe" << endl;
            return no;
        }

        if (num1Comparacao < 0) {
            no->pEsquerda = inserirNodo(no->pEsquerda, passageiro, numPassageiros);
        } else {
            no->pDireita = inserirNodo(no->pDireita, passageiro, numPassageiros);
        }

    }
    return no;

}

nodo* criaArvore(passageiros* passageiro){
    string nacionalidades[23];
    int num_nacionalidades = 0;
    while(passageiro != nullptr){
        bool existe = false;
        for(int i = 0; i < num_nacionalidades; i++){
            if(nacionalidades[i] == passageiro->nacionalidade){
                existe = true;
                break;
            }
        }
        if(!existe){
            nacionalidades[num_nacionalidades] = passageiro->nacionalidade;
            num_nacionalidades++;
        }
        passageiro = passageiro->next;
    }

    nodo* raiz = nullptr;
    for (int i = 0; i < num_nacionalidades; i++) {
        passageiros* passageiroAtual = passageiro;
        while(passageiroAtual != nullptr){
            if(passageiroAtual->nacionalidade == nacionalidades[i]){
                raiz = inserirNodo(raiz, passageiroAtual, num_nacionalidades);
            }
            passageiroAtual = passageiroAtual->next;
        }
    }

    return raiz;
}

void imprimeArvore(nodo* no, int nivel){
    if (no == nullptr) {
        cout << "Arvore vazia" << endl;
        return;
    }

    cout << "Nacionalidade: " << no->passageiro->nacionalidade << endl;
    imprimeArvore(no->pDireita, nivel + 1);
    for (int i = 0; i < nivel; i++) {
        cout << "\t";
    }
    cout << no->passageiro->primeiroNome << no->passageiro->ultimoNome << endl;
    imprimeArvore(no->pEsquerda, nivel + 1);
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


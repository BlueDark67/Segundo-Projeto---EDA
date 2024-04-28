//
// Created by guilh on 18/04/2024.
//
#include "passageiros.h"
#include "aviao.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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

passageiros* adicionaPassageiro(passageiros* head, string numBilhete, string primeiroNome, string ultimoNome, string nacionalidade){
    passageiros* novoPassageiro = new passageiros;
    novoPassageiro->numBilhete = numBilhete;
    novoPassageiro->primeiroNome = primeiroNome;
    novoPassageiro->ultimoNome = ultimoNome;
    novoPassageiro->nacionalidade = nacionalidade;
    novoPassageiro->next = head;
    return novoPassageiro;
}

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

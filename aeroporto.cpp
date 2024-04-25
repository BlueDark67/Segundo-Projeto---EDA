//
// Created by guilh on 18/04/2024.
//
#include <iostream>
#include <fstream>
#include "aeroporto.h"
#include "aviao.h"
#include "passageiros.h"

using namespace std;
void GuardaDadosAeroporto( avioes *&filaChegada, avioes *& filaPista, avioes *& filaPartida){
    int tamanhoC = tamanhoFilas(filaChegada);
    int tamanhoP = tamanhoFilas(filaPista);
    int tamanhoPa = tamanhoFilas(filaPartida);
    ofstream arquivoChegada("avioesChegada.txt");
    if (arquivoChegada.is_open()) {
        for (int i = 0; i < tamanhoC; i++) {
            arquivoChegada << filaChegada->nomeVoo << ","<< filaChegada->modelo << "," << filaChegada->origem << ","
                           << filaChegada->destino << "," << filaChegada->capacidade << "," << filaChegada->qtdPassageiros << endl;
            passageiros *passageiro = filaChegada->passageiroHead;
            while (passageiro != nullptr) {
                arquivoChegada << passageiro->numBilhete  << "," << passageiro->primeiroNome  <<
                               "," << passageiro->ultimoNome <<"," << passageiro->nacionalidade <<endl;
                passageiro = passageiro->next;
            }
            arquivoChegada << endl;
            filaChegada = filaChegada->next;
            cout << "\n" << endl;
        }
        arquivoChegada.close();
        cout << "Dados dos avioes em chegada foram gravados com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo para gravar os dados dos avioes em chegada." << endl;
    }

    ofstream arquivoPista("avioesPista.txt");
    if (arquivoPista.is_open()) {
        for (int i = 0; i < tamanhoP; i++) {
            arquivoPista << filaPista->nomeVoo << ","<< filaPista->modelo << "," << filaPista->origem << ","
                         << filaPista->destino << "," << filaPista->capacidade << "," << filaPista->qtdPassageiros << endl;
            passageiros *passageiro = filaPista->passageiroHead;
            while (passageiro != nullptr) {
                arquivoPista << passageiro->numBilhete  << "," << passageiro->primeiroNome  <<
                             "," << passageiro->ultimoNome <<"," << passageiro->nacionalidade <<endl;
                passageiro = passageiro->next;
            }
            arquivoPista << endl;
            filaPista = filaPista->next;
            cout << "\n" << endl;
        }
        arquivoPista.close();
        cout << "Dados dos avioes em Pista foram gravados com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo para gravar os dados dos avioes em pista." << endl;
    }

    ofstream arquivoPartida("avioesPartida.txt");
    if (arquivoPartida.is_open()) {
        for (int i = 0; i < tamanhoPa; i++) {
            arquivoPartida << filaPartida->nomeVoo << ","<< filaPartida->modelo << "," << filaPartida->origem << ","
                           << filaPartida->destino << "," << filaPartida->capacidade << "," << filaPartida->qtdPassageiros << endl;
            passageiros *passageiro = filaPartida->passageiroHead;
            while (passageiro != nullptr) {
                arquivoPartida << passageiro->numBilhete  << "," << passageiro->primeiroNome  <<
                               "," << passageiro->ultimoNome <<"," << passageiro->nacionalidade <<endl;
                passageiro = passageiro->next;
            }
            arquivoPartida << endl;
            filaPartida = filaPartida->next;
            cout << "\n" << endl;
        }
        arquivoPartida.close();
        cout << "Dados dos avioes em partida foram gravados com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo para gravar os dados dos avioes em partida." << endl;
    }
}

// Função para carregar os dados do aeroporto de um arquivo
void carregarDadosAeroporto(avioes * filaChegada, avioes*& filaPista) {
    ifstream arquivo("dados_aeroporto.txt");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo.is_open()) {
        // Limpa as filas existentes antes de carregar os novos dados
        // Implemente esta função se necessário
        // limparFilas(filaChegada, filaPista);

        string linha;
        string secao;
        while (getline(arquivo, linha)) {
            if (linha == "Fila de Chegada:") {
                secao = "Chegada";
            } else if (linha == "Fila de Pista:") {
                secao = "Pista";
            } else {
                if (secao == "Chegada") {
                    // Adicione o avião à fila de chegada conforme necessário
                    // Implemente essa lógica conforme a estrutura do seu programa
                } else if (secao == "Pista") {
                    // Adicione o avião à fila de pista conforme necessário
                    // Implemente essa lógica conforme a estrutura do seu programa
                }
            }
        }
        arquivo.close();
        cout << "Dados do aeroporto carregados com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo para carregar os dados do aeroporto." << endl;
    }
}

int contarLinhas(string nomeFicheiro) {
    ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return -1;
    }

    int numLinhas = 0;
    string linha;
    while (getline(ficheiro, linha)) {
        numLinhas++;
    }

    ficheiro.close();
    return numLinhas;
}

avioes* leFicheiroChegada(string nomeFicheiro){
    avioes* aviao2 = new avioes;
    string nomeVoo;
    string modelo;
    string origem;
    string destino;
    int capacidade;
    int qtdPassageiros;
    string numBilhete;
    string primeiroNome;
    string ultimoNome;
    string nacionalidade;
    passageiros* passageiroHead;
    ifstream ficheiroChegada(nomeFicheiro);
    if(ficheiroChegada.is_open()) {
        int i = 0;
        string aux;
        while (getline(ficheiroChegada, aux, ',') && i < 10) {
            getline(ficheiroChegada, nomeVoo, ',');
            getline(ficheiroChegada, modelo, ',');
            getline(ficheiroChegada, origem, ',');
            getline(ficheiroChegada, destino, ',');
            ficheiroChegada >> capacidade;
            ficheiroChegada >> qtdPassageiros;
            getline(ficheiroChegada, numBilhete, ',');
            getline(ficheiroChegada, primeiroNome, ',');
            getline(ficheiroChegada, ultimoNome, ',');
            getline(ficheiroChegada, nacionalidade, ',');
            aviao2->nomeVoo = nomeVoo;
            aviao2->modelo = modelo;
            aviao2->origem = origem;
            aviao2->destino = destino;
            aviao2->capacidade = capacidade;
            aviao2->qtdPassageiros = qtdPassageiros;
            passageiros* ultimoPassageiro = nullptr;
            for (int j = 0; j < qtdPassageiros; j++) {
                getline(ficheiroChegada, numBilhete, ',');
                getline(ficheiroChegada, primeiroNome, ',');
                getline(ficheiroChegada, ultimoNome, ',');
                getline(ficheiroChegada, nacionalidade, ',');
                passageiros* novoPassageiro = new passageiros;
                novoPassageiro->numBilhete = numBilhete;
                novoPassageiro->primeiroNome = primeiroNome;
                novoPassageiro->ultimoNome = ultimoNome;
                novoPassageiro->nacionalidade = nacionalidade;
                novoPassageiro->next = nullptr;
                if (ultimoPassageiro == nullptr) {
                    aviao2->passageiroHead = novoPassageiro;
                } else {
                    ultimoPassageiro->next = novoPassageiro;
                }
                ultimoPassageiro = novoPassageiro;
            }
            aviao2->next = nullptr;
            i++;
        }
        ficheiroChegada.close();
    } else {
        cout << "Erro ao abrir o arquivo para carregar os dados das secoes do armazem." << endl;
    }
    return aviao2;
}

void menuG(avioes* filaChegada, avioes* filaPista, avioes* filaPartida){
    string resposta2;
    do {
        cout << "Escolha uma opcao: \n" << endl;
        cout << "(c)arregar (g)ravar \n" << endl;
        cin >> resposta2;
        if (resposta2 == "c" || resposta2 == "C") {
            carregarDadosAeroporto(filaChegada, filaPista);
        } else if (resposta2 == "g" || resposta2 == "G") {
            GuardaDadosAeroporto(filaChegada, filaPista, filaPartida);
        }
    } while (resposta2 != "0");
}


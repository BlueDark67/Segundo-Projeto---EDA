//
// Created by guilh on 18/04/2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include "aeroporto.h"
#include "aviao.h"
#include "passageiros.h"


using namespace std;

/**
 * Função que guarda os dados do aeroporto num ficheiro
 * @return - os dados do aerorporto no ficheiro.txt
 */
void GuardaDadosAeroporto( avioes *&filaChegada, avioes *& filaPista, avioes *& filaPartida){
    int tamanhoC = tamanhoFilas(filaChegada);
    int tamanhoP = tamanhoFilas(filaPista);
    int tamanhoPa = tamanhoFilas(filaPartida);

    ofstream arquivoChegada("avioesChegada.txt");
    ofstream arquivoPassageirosChegada("passageirosChegada.txt");
    if (arquivoChegada.is_open()) {
        for (int i = 0; i < tamanhoC; i++) {
            if (filaChegada->next == nullptr) {
                arquivoChegada <<"|"<<filaChegada->nomeVoo << "|" << filaChegada->modelo << "|" << filaChegada->origem<< "|"
                               << filaChegada->destino << "|" << filaChegada->capacidade << "|"<< filaChegada->qtdPassageiros << "|";
            } else {
            arquivoChegada <<"|"<<filaChegada->nomeVoo << "|" << filaChegada->modelo << "|" << filaChegada->origem << "|"
                           << filaChegada->destino << "|" << filaChegada->capacidade << "|"<< filaChegada->qtdPassageiros << "|\n";
            }
            if(arquivoPassageirosChegada.is_open()){
                for (int j = 0; j < filaChegada->qtdPassageiros; j++){
                    if(filaChegada->next == nullptr && filaChegada->passageiroHead->next == nullptr) {
                        arquivoPassageirosChegada << filaChegada->passageiroHead->numBilhete << "|" << filaChegada->passageiroHead->primeiroNome <<"|"
                                                  << filaChegada->passageiroHead->ultimoNome << "|" << filaChegada->passageiroHead->nacionalidade << "|"<< filaChegada->nomeVoo << "|";
                    }else {
                        arquivoPassageirosChegada << filaChegada->passageiroHead->numBilhete << "|"<< filaChegada->passageiroHead->primeiroNome <<"|"
                                                  << filaChegada->passageiroHead->ultimoNome << "|" << filaChegada->passageiroHead->nacionalidade << "|"<< filaChegada->nomeVoo << "|\n";
                    }
                    filaChegada->passageiroHead = filaChegada->passageiroHead->next;
                }
            }else{
                cout << "Erro ao abrir o arquivo para gravar os dados dos passageiros dos avioes em chegada." << endl;
            }

            filaChegada = filaChegada->next;
        }
        arquivoChegada.close();
        arquivoPassageirosChegada.close();
        cout << "Dados dos avioes em chegada foram gravados com sucesso." << endl;
        cout << "Dados dos passageiros dos avioes em chegada foram gravados com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo para gravar os dados dos avioes em chegada." << endl;
    }

    ofstream arquivoPista("avioesPista.txt");
    ofstream arquivoPassageirosPista("passageirosPista.txt");
    if (arquivoPista.is_open()) {
        for (int i = 0; i < tamanhoP; i++) {
            if(filaPista->next == nullptr){
                arquivoPista <<"|" <<filaPista->nomeVoo << "|" << filaPista->modelo << "|" << filaPista->origem << "|"
                             << filaPista->destino << "|" << filaPista->capacidade << "|" << filaPista->qtdPassageiros << "|";
            }else {
                arquivoPista << "|"<< filaPista->nomeVoo << "|" << filaPista->modelo << "|" << filaPista->origem << "|"
                             << filaPista->destino << "|" << filaPista->capacidade << "|" << filaPista->qtdPassageiros<< "|" << endl;
            }
            if(arquivoPassageirosPista.is_open()){
                for (int j = 0; j < filaPista->qtdPassageiros; j++) {
                    if(filaPista->next == nullptr && filaPista->passageiroHead->next == nullptr) {
                        arquivoPassageirosPista << filaPista->passageiroHead->numBilhete << "|" << filaPista->passageiroHead->primeiroNome <<
                                                "|" << filaPista->passageiroHead->ultimoNome << "|" << filaPista->passageiroHead->nacionalidade;
                    }else {
                        arquivoPassageirosPista << filaPista->passageiroHead->numBilhete << "|" << filaPista->passageiroHead->primeiroNome <<"|"
                                                << filaPista->passageiroHead->ultimoNome << "|" << filaPista->passageiroHead->nacionalidade << "|\n";
                    }
                    filaPista->passageiroHead = filaPista->passageiroHead->next;
                }
            }else{
                cout << "Erro ao abrir o arquivo para gravar os dados dos passageiros dos avioes em pista." << endl;
            }

            filaPista = filaPista->next;
        }
        arquivoPista.close();
        cout << "Dados dos avioes em pista foram gravados com sucesso." << endl;
        cout << "Dados dos passageiros dos avioes em pista foram gravados com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo para gravar os dados dos avioes em chegada." << endl;
    }

    ofstream arquivoPartida("avioesPartida.txt");
    ofstream arquivoPassageirosPartida("passageirosPartida.txt");
    if (arquivoPartida.is_open()) {
        for (int i = 0; i < tamanhoPa; i++) {
            if(filaPartida->next == nullptr){
                arquivoPartida <<"|" <<filaPartida->nomeVoo << "|" << filaPartida->modelo << "|" << filaPartida->origem << "|"
                               << filaPartida->destino << "|" << filaPartida->capacidade << "|" << filaPartida->qtdPassageiros << "|";
            }else {
                arquivoPartida << "|"<<filaPartida->nomeVoo << "|" << filaPartida->modelo << "|" << filaPartida->origem<< "|"
                               << filaPartida->destino << "|" << filaPartida->capacidade << "|"<< filaPartida->qtdPassageiros << "|\n";
            }
            if(arquivoPassageirosPartida.is_open()){
                for (int j = 0; j < filaPartida->qtdPassageiros; j++) {
                    if(filaPartida->next == nullptr && filaPartida->passageiroHead->next == nullptr) {
                        arquivoPassageirosPartida << filaPartida->passageiroHead->numBilhete << "|" << filaPartida->passageiroHead->primeiroNome<< "|"
                                                  << filaPartida->passageiroHead->ultimoNome << "|" << filaPartida->passageiroHead->nacionalidade;
                    }else {
                        arquivoPassageirosPartida << filaPartida->passageiroHead->numBilhete << "|" << filaPartida->passageiroHead->primeiroNome<< "|"
                                                  << filaPartida->passageiroHead->ultimoNome << "|" << filaPartida->passageiroHead->nacionalidade << "|\n";
                    }
                    filaPartida->passageiroHead = filaPartida->passageiroHead->next;
                }
            }else{
                cout << "Erro ao abrir o arquivo para gravar os dados dos passageiros dos avioes em partida." << endl;
            }

            filaPartida = filaPartida->next;
        }
        arquivoPartida.close();
        cout << "Dados dos avioes em partida foram gravados com sucesso." << endl;
        cout << "Dados dos passageiros dos avioes em partida foram gravados com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo para gravar os dados dos avioes em Partida." << endl;
    }
}

/**
 * Função que carrega os dados do aeroporto de um ficheiro
 * @param filaChegada - fila de chegada
 * @param filaPista  - fila de pista
 * @param filaPartida - fila de partida
 * @param nomeFAC - nome do ficheiro de avioes em chegada
 * @param nomeFAP - nome do ficheiro de avioes em pista
 * @param nomeFAPA - nome do ficheiro de avioes em partida
 * @param nomeFPC - nome do ficheiro de passageiros em chegada
 * @param nomeFPP - nome do ficheiro de passageiros em pista
 * @param nomeFPPA - nome do ficheiro de passageiros em partida
 */
void carregarDadosAeroporto(avioes*& filaChegada, avioes*& filaPista, avioes*& filaPartida ,string nomeFAC,string nomeFAP,string nomeFAPA, string nomeFPC, string nomeFPP, string nomeFPPA) {
    leFicheiroA(nomeFAC, filaChegada);
    leFicheiroP(nomeFPC, filaChegada);
    leFicheiroA(nomeFAP, filaPista);
    leFicheiroP(nomeFPP, filaPista);
    leFicheiroA(nomeFAPA, filaPartida);
    leFicheiroP(nomeFPPA, filaPartida);
}

/**
 * Função que conta o número de linhas de um ficheiro
 * @param nomeFicheiro
 * @return - número de linhas
 */
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

/**
 * Função que lê o ficheiro avioesChegada.txt, avioesPista.txt e avioesPartida.txt
 * @param nome1 - nome do ficheiro
 * @param filaRetirada - fila de avioes
 */
void leFicheiroA(string nome1, avioes*& filaRetirada){
    string nomeVoo;
    string modelo;
    string origem;
    string destino;
    string nomeFicheiro1 = nome1; //AvioesChegada
    ifstream ficheiro(nomeFicheiro1);
    if (ficheiro.is_open()) {
        int i = 0;
        while (i < contarLinhas(nomeFicheiro1)) {
            string aux6;
            getline(ficheiro,aux6,'|');
            getline(ficheiro, nomeVoo, '|');
            getline(ficheiro, modelo, '|');
            getline(ficheiro, origem, '|');
            getline(ficheiro, destino, '|');
            string aux1;
            getline(ficheiro, aux1, '|');
            int aux2 = stoi(aux1); //getline só aceita string, por isso é necessário converter para int com stoi
            string aux3;
            getline(ficheiro, aux3, '|');
            int aux4 = stoi(aux3);
            avioes* aux = adicionaAvioes(filaRetirada, nomeVoo, modelo, origem, destino, aux2, aux4);
            filaRetirada = adicionaAviaoFilaChegada2(filaRetirada, aux);
            i++;
        }
    } else {
        cout << "Erro ao abrir o arquivo para ler os dados dos avioes em chegada." << endl;
    }
    ficheiro.close();
}

/**
 * Função que lê o ficheiro passageirosChegada.txt, passageirosPista.txt e passageirosPartida.txt
 * @param nome2 - nome do ficheiro
 * @param filaRetirada - fila de avioes
 */
void leFicheiroP(string nome2, avioes*& filaRetirada){
    string numBilhete;
    string primeiroNome;
    string ultimoNome;
    string nacionalidade;
    string nomeVoo;
    string linha;
    string nomeFicheiro2 = nome2; //PassageirosChegada
    ifstream ficheiro(nomeFicheiro2);
    if (ficheiro.is_open()) {
        avioes* aux2 = filaRetirada;
        while(aux2 != nullptr) {
            int i= 0;
            while (i<aux2->capacidade){
                getline(ficheiro, numBilhete, '|');
                getline(ficheiro, primeiroNome, '|');
                getline(ficheiro, ultimoNome, '|');
                getline(ficheiro, nacionalidade, '|');
                getline(ficheiro, nomeVoo, '|');
                passageiros *aux = adicionaPassageiro(nullptr, numBilhete, primeiroNome, ultimoNome, nacionalidade);
                if (nomeVoo == aux2->nomeVoo) {
                    adicionaPassageiroAviao2(aux2, aux);
                }
            i++;
            }
            aux2 = aux2->next;
        }

    } else {
        cout << "Erro ao abrir o arquivo para ler os dados dos avioes em chegada." << endl;
    }
    ficheiro.close();
}



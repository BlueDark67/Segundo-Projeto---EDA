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
void GuardaDadosAeroporto( avioes *&filaChegada, avioes *& filaPista, avioes *& filaPartida){
    int tamanhoC = tamanhoFilas(filaChegada);
    int tamanhoP = tamanhoFilas(filaPista);
    int tamanhoPa = tamanhoFilas(filaPartida);

    ofstream arquivoChegada("avioesChegada.txt");
    ofstream arquivoPassageirosChegada("passageirosChegada.txt");
    if (arquivoChegada.is_open()) {
        for (int i = 0; i < tamanhoC; i++) {
            if (filaChegada->next == nullptr) {
                arquivoChegada << filaChegada->nomeVoo << "|" << filaChegada->modelo << "|" << filaChegada->origem<< "|"
                               << filaChegada->destino << "|" << filaChegada->capacidade << "|"<< filaChegada->qtdPassageiros << "|";
            } else {
            arquivoChegada << filaChegada->nomeVoo << "|" << filaChegada->modelo << "|" << filaChegada->origem << "|"
                           << filaChegada->destino << "|" << filaChegada->capacidade << "|"<< filaChegada->qtdPassageiros << "|\n";
            }
            if(arquivoPassageirosChegada.is_open()){
                for (int j = 0; j < filaChegada->qtdPassageiros; j++){
                    if(filaChegada->next == nullptr && filaChegada->passageiroHead->next == nullptr) {
                        arquivoPassageirosChegada << filaChegada->passageiroHead->numBilhete << "|" << filaChegada->passageiroHead->primeiroNome <<"|"
                                                  << filaChegada->passageiroHead->ultimoNome << "|" << filaChegada->passageiroHead->nacionalidade;
                    }else {
                        arquivoPassageirosChegada << filaChegada->passageiroHead->numBilhete << "|"<< filaChegada->passageiroHead->primeiroNome <<"|"
                                                  << filaChegada->passageiroHead->ultimoNome << "|" << filaChegada->passageiroHead->nacionalidade << "|\n";
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
                arquivoPista << filaPista->nomeVoo << "|" << filaPista->modelo << "|" << filaPista->origem << "|"
                             << filaPista->destino << "|" << filaPista->capacidade << "|" << filaPista->qtdPassageiros << "|";
            }else {
                arquivoPista << filaPista->nomeVoo << "|" << filaPista->modelo << "|" << filaPista->origem << "|"
                             << filaPista->destino << "|" << filaPista->capacidade << "|" << filaPista->qtdPassageiros<< "|\n";
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
                arquivoPartida << filaPartida->nomeVoo << "|" << filaPartida->modelo << "|" << filaPartida->origem << "|"
                               << filaPartida->destino << "|" << filaPartida->capacidade << "|" << filaPartida->qtdPassageiros << "|";
            }else {
                arquivoPartida << filaPartida->nomeVoo << "|" << filaPartida->modelo << "|" << filaPartida->origem<< "|"
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

avioes* leFicheiroChegada(string nome1, string nome2){
    avioes* aviaoRetiradaoTXT = new avioes;
    avioes* filaRetirada = nullptr;
    string nomeVoo;
    string modelo;
    string origem;
    string destino;
    string numBilhete;
    string primeiroNome;
    string ultimoNome;
    string nacionalidade;
    string nomeFicheiro1 = nome1; //AvioesChegada
    string nomeFicheiro2 = nome2; //PassageirosChegada
    ifstream ficheiro(nomeFicheiro1);
    ifstream ficheiro2(nomeFicheiro2);
    if(ficheiro.is_open() && ficheiro2.is_open()){
        int i = 0;
        while (i<contarLinhas(nomeFicheiro1)) {
            getline(ficheiro, nomeVoo, '|');
            aviaoRetiradaoTXT->nomeVoo = nomeVoo;
            getline(ficheiro, modelo, '|');
            aviaoRetiradaoTXT->modelo = modelo;
            getline(ficheiro, origem, '|');
            aviaoRetiradaoTXT->origem = origem;
            getline(ficheiro, destino, '|');
            aviaoRetiradaoTXT->destino = destino;
            string aux1;
            getline(ficheiro, aux1, '|');
            int aux2 = stoi(aux1);
            aviaoRetiradaoTXT->capacidade = aux2;
            string aux3;
            getline(ficheiro, aux3, '|');
            int aux4 = stoi(aux3);
            aviaoRetiradaoTXT->qtdPassageiros = aux4;
                for (int j = 0; j < aviaoRetiradaoTXT->qtdPassageiros; j++) {
                    passageiros *passageiroRetirado = nullptr;
                    getline(ficheiro2, numBilhete, '|');
                    getline(ficheiro2, primeiroNome, '|');
                    getline(ficheiro2, ultimoNome, '|');
                    getline(ficheiro2, nacionalidade, '|');
                    passageiroRetirado->numBilhete = numBilhete;
                    passageiroRetirado->primeiroNome = primeiroNome;
                    passageiroRetirado->ultimoNome = ultimoNome;
                    passageiroRetirado->nacionalidade = nacionalidade;
                    passageiroRetirado->next = nullptr;
                    adicionaPassageiroFila(aviaoRetiradaoTXT->passageiroHead, passageiroRetirado);
                }
                aviaoRetiradaoTXT->next = nullptr;
                adicionaAviaoFilaChegada(filaRetirada, aviaoRetiradaoTXT);
                i++;
        }

        } else {
            cout << "Erro ao abrir o arquivo para ler os dados dos avioes em chegada." << endl;
        }
        ficheiro.close();
        ficheiro2.close();
        return filaRetirada;
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
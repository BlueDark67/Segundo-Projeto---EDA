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
            arquivoChegada << filaChegada->nomeVoo << "|"<< filaChegada->modelo << "|" << filaChegada->origem << "|"
                           << filaChegada->destino << "|" << filaChegada->capacidade << "|" << filaChegada->qtdPassageiros <<"|\n";
            if(arquivoPassageirosChegada.is_open()){
                for (int j = 0; j < filaChegada->qtdPassageiros; j++) {
                    arquivoPassageirosChegada << filaChegada->passageiroHead->numBilhete << "|"<< filaChegada->passageiroHead->primeiroNome <<
                                              "|" << filaChegada->passageiroHead->ultimoNome << "|"<< filaChegada->passageiroHead->nacionalidade<< "|" << endl;
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
            arquivoPista << filaPista->nomeVoo << "|"<< filaPista->modelo << "|" << filaPista->origem << "|"
                           << filaPista->destino << "|" << filaPista->capacidade << "|" << filaPista->qtdPassageiros << endl;
            if(arquivoPassageirosPista.is_open()){
                for (int j = 0; j < filaPista->qtdPassageiros; j++) {
                    arquivoPassageirosPista << filaPista->passageiroHead->numBilhete << "|"<< filaPista->passageiroHead->primeiroNome <<
                                            "|" << filaPista->passageiroHead->ultimoNome << "|"<< filaPista->passageiroHead->nacionalidade << endl;
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
            arquivoPartida << filaPartida->nomeVoo << "|"<< filaPartida->modelo << "|" << filaPartida->origem << "|"
                           << filaPartida->destino << "|" << filaPartida->capacidade << "|" << filaPartida->qtdPassageiros << endl;
            if(arquivoPassageirosPartida.is_open()){
                for (int j = 0; j < filaPartida->qtdPassageiros; j++) {
                    arquivoPassageirosPartida << filaPartida->passageiroHead->numBilhete <<", "<<filaPartida->passageiroHead->primeiroNome
                                                <<"|" << filaPartida->passageiroHead->ultimoNome << "|"<< filaPartida->passageiroHead->nacionalidade << endl;
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
    string nomeFicheiro1 = nome1; //AvioesChegada
    string nomeFicheiro2 = nome2; //PassageirosChegada
    ifstream ficheiro(nomeFicheiro1);
    ifstream ficheiro2(nomeFicheiro2);
    if(ficheiro.is_open()) {
        int i = 0;
        if (i < contarLinhas(nomeFicheiro1)) {
            while (getline(ficheiro, nomeVoo, '|')) {
                aviaoRetiradaoTXT->nomeVoo = nomeVoo;
                getline(ficheiro, modelo, '|');
                aviaoRetiradaoTXT->modelo = modelo;
                getline(ficheiro, origem, '|');
                aviaoRetiradaoTXT->origem = origem;
                getline(ficheiro, destino, '|');
                aviaoRetiradaoTXT->destino = destino;
                string aux; //Pois getline nao consegue usar int diretamente
                string aux1;
                getline(ficheiro, aux, '|');
                int aux2 = stoi(aux);
                cout << aux2 << endl;
                aviaoRetiradaoTXT->capacidade = aux2;
                getline(ficheiro, aux1, '|');
                int aux3 = stoi(aux1);
                cout << aux3 << endl;
                aviaoRetiradaoTXT->qtdPassageiros = aux3;
                aviaoRetiradaoTXT->next = nullptr;

                if (ficheiro2.is_open()) {
                    for (int j = 0; j < aviaoRetiradaoTXT->qtdPassageiros; j++) {
                        getline(ficheiro2, numBilhete, '|');
                        getline(ficheiro2, primeiroNome, '|');
                        getline(ficheiro2, ultimoNome, '|');
                        getline(ficheiro2, nacionalidade, '|');
                        aviaoRetiradaoTXT->passageiroHead = adicionaPassageiro(aviaoRetiradaoTXT->passageiroHead,
                                                                               numBilhete, primeiroNome, ultimoNome,
                                                                               nacionalidade);
                    }
                } else {
                    cout << "Erro ao abrir o arquivo para ler os dados dos passageiros dos avioes em chegada." << endl;
                }
                i++;
            }
        }
        } else {
            cout << "Erro ao abrir o arquivo para ler os dados dos avioes em chegada." << endl;
        }
        ficheiro.close();
        return aviaoRetiradaoTXT;
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
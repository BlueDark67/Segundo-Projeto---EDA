
#include <iostream>
#include "aeroporto.h"
#include "aviao.h"
#include "passageiros.h"
#include <ctime>

using namespace std;

/*
 * Grupo 13: Membro 1 - 2124623; Membro 2 -2109923; Membro 3 - 2099223; Membro 4 -2144323;
 */

/**
 * Função principal
 * @param argc - número de argumentos
 * @param argv - argumentos
 * @return - 0
 */
int main(int argc, char const* argv[]) {
    srand(time(0));
    string resposta;
    bool emergenciaAeroporto = false;
    int ciclos;
    avioes *filaChegada = nullptr;
    avioes *filaPista = nullptr;
    avioes *filaPartida = nullptr;
    nodo* raiz = nullptr;
    noNacionalidade* listaNacionalidades = criaListaNacionalide(nullptr,raiz);

    if(argc==1) {
        for (int i = 0; i < 10; i++) {
            avioes *novoAviaoChegada = criaAvioes();
            adicionaPassageiroAviao(novoAviaoChegada);
            filaChegada = adicionaAviaoFilaChegada(filaChegada, novoAviaoChegada);
        }
    }else{
        string nomeFAC = argv[1];
        string nomeFAP = argv[2];
        string nomeFAPA = argv[3];
        string nomeFPC = argv[4];
        string nomeFPP = argv[5];
        string nomeFPPA = argv[6];
        carregarDadosAeroporto(filaChegada, filaPista, filaPartida, nomeFAC,nomeFAP,nomeFAPA,nomeFPC,nomeFPP,nomeFPPA);
    }

    apresentaInfoTodosAvioes(filaChegada);
    apresentaMenuAeroporto();
    do {
        cin >> resposta;
        if (resposta == "e" || resposta == "E") {// Se a resposta for g
            string resposta2;
            apresentaMenuEmergencia();
            do {
                cin >> resposta2;
                if(resposta2 == "1"){
                    moverAviaoEmergenciaParaPista(filaChegada, filaPista,filaPartida);
                    break;
                }else if(resposta2 == "2") {
                    string cilcosEmergencia;
                    do {
                        cout << "Quer fechar o aeroporto durante quantos ciclos?" << endl;
                        cin >> cilcosEmergencia;
                        if(isNumber(cilcosEmergencia)) {
                            ciclos = stoi(cilcosEmergencia);
                            if (ciclos > 0 && ciclos <= 5) {
                                cout << "Aeroporto fechado durante " << ciclos << " ciclos" << endl;
                                emergenciaAeroporto = true;
                                apresentaMenuAeroporto();
                                break;
                            } else {
                                cout << "Numero de ciclos invalido" << endl;
                                cout << "O aeroporto so pode ser fechado durante 1 a 5 ciclos" << endl;
                            }
                        }else{
                            cout <<"Opcao invalida por favor insira um numero." << endl;
                        }
                    } while(ciclos <= 0 || ciclos > 5);
                    break;
                }else if(resposta2 == "0"){
                    apresentaMenuAeroporto();
                }

            } while (resposta2!= "0");
        } else if (resposta == "s" || resposta == "S") {// Se a resposta for s
            if( emergenciaAeroporto == true){
                if(emergenciaAeroporto == true && ciclos > 0){
                    cout << "Aeroporto fechado durante " << ciclos << "ciclos" << endl;
                    avioes *novoAviaoChegada2 = criaAvioes();
                    adicionaPassageiroAviao(novoAviaoChegada2);
                    filaChegada = adicionaAviaoFilaChegada(filaChegada, novoAviaoChegada2);
                    ciclos--;
                }
                if(ciclos == 0){
                    emergenciaAeroporto = false;
                }
            } else {
                simularCiclo(filaChegada, filaPista ,filaPartida, listaNacionalidades);
            }
        } else if (resposta == "o" || resposta == "O") { // Se a resposta for O
            string resposta3;
            apresentaMenuOpcoes();
            do {
                cin >> resposta3;
                if (resposta3 == "1") {
                    mostrarPassageiros(filaPista);
                    cout << endl;
                    apresentaMenuAeroporto();
                    break;
                } else if (resposta3 == "2") {
                    mostrarPassageirosOrdemAlfabetica(filaPista);
                    break;
                } else if (resposta3 == "3") {
                    noNacionalidade *aux = listaNacionalidades;
                    while (aux != nullptr) {
                        cout << "Nacionalidade: " << *(aux->nacionalidade) << endl;
                        imprimeArvore(aux->raiz, 0);
                        aux = aux->next;
                    }
                    break;
                } else if (resposta3 == "4") {
                    pesquisarPassageiro(filaChegada, filaPartida);
                    break;
                } else if (resposta3 == "5") {
                    editarNacionalidadePassageiro(filaChegada);
                    break;
                }
            }while (resposta3 != "0");

        } else if (resposta == "g" || resposta == "G") {
            GuardaDadosAeroporto(filaChegada, filaPista, filaPartida);

        }else if(resposta == "i" || resposta == "I"){
            cout << "Inverteu a prioridade dos avioes em pista" << endl;
            invertePrioridade(filaPista);
            cout << endl;
            cout << "----------------------------" << endl;
            cout << "------Avioes em Pista-------" << endl;
            cout << "----------------------------" << endl;
            apresentaInfoTodosAvioes(filaPista);
        }else{
            cout << "Escolheu a opcao sair." << endl;
        }

    }while (resposta != "0");// Enquanto a resposta for diferente de 0

    delete filaChegada;
    delete filaPista;
    delete filaPartida;
    return 0;
}

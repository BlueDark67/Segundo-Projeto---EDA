
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
    bool emergenciaAviao = false;
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
    cout << "Escolha uma opcao: \n";
    cout << "(e)mergencia (o)pcoes (g)ravar (s)proximo ciclo\n";
    do {

        cin >> resposta;
        if (resposta == "e" || resposta == "E") {// Se a resposta for g
            string resposta2;
            cout << "Menu Emergencia" << endl;
            cout << "1 - Aviao com emergencia" << endl;
            cout << "2 - Fechar Aeroporto" << endl;
            do {
                cin >> resposta2;
                if(resposta2 == "1"){
                    emergenciaAviao = true;
                    break;
                }
                if(resposta2 == "2") {
                    cout << "Quer fechar o aeroporto durante quantos ciclos?" << endl;
                    cin >> ciclos;
                    cout << "Aeoporto fechado durante " << ciclos << " ciclos" << endl;
                    emergenciaAeroporto = true;
                    break;
                }
            } while (resposta2 != "1" || resposta2 != "2");
        } else if (resposta == "s" || resposta == "S") {// Se a resposta for s
            if(emergenciaAviao == true || emergenciaAeroporto == true){
                if(emergenciaAviao == true){
                    cout << "Aviao com emergencia" << endl;
                    emergenciaAviao = false;
                }
                if(emergenciaAeroporto == true && ciclos > 0){
                    cout << "Aeroporto fechado durante " << ciclos << "ciclos" << endl;
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
            cout << "Menu Opcoes" << endl;
            cout << "1 - Mostrar todos os passageiros em pista" << endl;
            cout << "2 - Mostrar passageiros por ordem alfabetica" << endl;
            cout << "3 - Mostra arvore de passageiros por nacionalidade" << endl;
            cout << "4 - Pesquisar passageiro" << endl;
            cout << "5 - Editar a nacionalidade de um passageiro" << endl;
            cout << "0 - Sair" << endl;
            do {
                cin >> resposta3;
                if (resposta3 == "1") {
                    break;
                } else if (resposta3 == "2") {
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
                    break;
                } else if (resposta3 == "5") {
                    break;
                }
            }while (resposta3 != "0");

        } else if (resposta == "g" || resposta == "G") {
            GuardaDadosAeroporto(filaChegada,filaPista,filaPartida);
        }else{
            cout << "Escolheu a opcao sair." << endl;
        }

    }while (resposta != "0");// Enquanto a resposta for diferente de 0

    delete filaChegada;
    delete filaPista;
    delete filaPartida;
    return 0;
}


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
    noNacionalidade* listaNacionalidades = criaListaNacionalidades();
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
    cout << "Escolha um: \n";
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
            cout << "(e)mergencia (o)pcoes (g)ravar (s)proximo ciclo\n";
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
                simularCiclo(filaChegada, filaPista ,filaPartida);
            }
        } else if (resposta == "o" || resposta == "O") { // Se a resposta for O
            testeArvore(filaPista);
            //alterar a lista ligada para ser a dos que foi retirado do txt
            //Só estrageiros (Portugues nao entra)
            //corrigir as arvores para integrar todos os avioes da fila pista
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

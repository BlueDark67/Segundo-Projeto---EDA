
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
    bool emergencia = false;

    avioes *filaChegada = nullptr;
    avioes *filaPista = nullptr;
    avioes *filaPartida = nullptr;

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
            emergencia = true;
        } else if (resposta == "s" || resposta == "S") {// Se a resposta for s
            if(emergencia == true){
                cout << "Aviso de emergencia" << endl;
                emergencia = false;
            } else {
                simularCiclo(filaChegada, filaPista ,filaPartida);
            }
        } else if (resposta == "o" || resposta == "O") { // Se a resposta for O
            testeArvore(filaPista);

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

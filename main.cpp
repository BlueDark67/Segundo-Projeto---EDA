#include <iostream>
#include "aeroporto.h"
#include "aviao.h"
#include "passageiros.h"
#include <ctime>

using namespace std;

int main(int argc, char const* argv[]) {
    srand(time(0));
    string resposta;
    cout << "Escolha uma opcao: \n";
    cout << "(e)mergencia (o)pcoes (g)ravar \n";
    //codigo de apresentação dos aviões em chegada/pista/partida
    avioes * filaChegada = nullptr;
    avioes * filaPista = nullptr;
    avioes * filaPartida = nullptr;
    for (int i = 0; i < 10; i++) {
       avioes* novoAviaoChegada = criaAvioes();
       adicionaPassageiroAviao(novoAviaoChegada);
       filaChegada = adicionaAviaoFilaChegada(filaChegada, novoAviaoChegada);
    }
    apresentaInfoTodosAvioes(filaChegada);

    do {
        cin >> resposta;
        if (resposta == "e" || resposta == "E") {// Se a resposta for g

        } else if (resposta == "s" || resposta == "S") {// Se a resposta for s
            simularCiclo(filaChegada, filaPista);
        } else if (resposta == "o" || resposta == "O") { // Se a resposta for O
            if(argc == 1) {
                cout << "Nao foram passados argumentos." << endl;
            }else{
                string fChegada = argv[1];
                avioes* aviao2 = leFicheiroChegada(fChegada);
                apresentaInfoTodosAvioes(aviao2);
            }

        } else if (resposta == "g" || resposta == "G") {
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
        }else{
            cout << "Escolheu a opcao sair." << endl;
        }

    }while (resposta != "0");// Enquanto a resposta for diferente de 0
    return 0;
}
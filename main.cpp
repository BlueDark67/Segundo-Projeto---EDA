#include <iostream>
#include "aeroporto.h"
#include "aviao.h"
#include "passageiros.h"
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    string resposta;
    cout << "Escolha uma opcao: \n";
    cout << "(e)mergencia (o)pcoes (g)ravar \n";
    //codigo de apresentação dos aviões em chegada/pista/partida
    avioes * filaChegada = nullptr;
    avioes * filaPista = nullptr;
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
            if (tamanhoFilas(filaChegada) <10){
                cout << "Erro - Nao existem 10 aviões em fila de chegada" << endl;
            }else{
                simularCiclo(filaChegada, filaPista);
            }

        } else if (resposta == "o" || resposta == "O") { // Se a resposta for O

        } else if (resposta == "g" || resposta == "G") {

        }else{
            cout << "Escolheu a opcao sair." << endl;
        }

    }while (resposta != "0");// Enquanto a resposta for diferente de 0


    return 0;
}
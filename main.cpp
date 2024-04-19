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
    avioes * novoAviaoChegada = nullptr;
    for (int i = 0; i < 10; i++) {
        novoAviaoChegada = criaAvioes();
        //passar o codigo que mete na lista para aqui
    }
    criaEApresenta(novoAviaoChegada);

    do {
        cin >> resposta;
        if (resposta == "e" || resposta == "E") {// Se a resposta for g

        } else if (resposta == "s" || resposta == "S") {// Se a resposta for s

        } else if (resposta == "o" || resposta == "O") { // Se a resposta for O

        } else if (resposta == "g" || resposta == "G") {

        }else{
            cout << "Escolheu a opcao sair." << endl;
        }

    }while (resposta != "0");// Enquanto a resposta for diferente de 0


    return 0;
}
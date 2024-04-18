#include <iostream>
#include "aeroporto.h"
#include "aviao.h"
#include "passageiros.h"
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    srand(time(0));

    Node* tail = nullptr;

    for (int i = 0; i < 5; i++) {
        // Cria um avião
        avioes* novoAviao = criaAvioes();

        // Verifica se o avião foi criado corretamente
        if (novoAviao == nullptr) {
            cout << "Erro: O avião não foi criado corretamente." << endl;
            return 1;
        }

        // Adiciona passageiros ao avião
        for (int j = 0; j < novoAviao->qtdPassageiros; j++) {
            adicionaPassageiroAviao(novoAviao);
        }

        // Adiciona o avião à fila
        tail = filaChegada(tail, novoAviao);
    }

    // Agora você pode acessar os aviões na ordem em que foram criados
    Node* head = tail;
    while (head != nullptr) {
        avioes* aviao = head->aviao;
        cout << "Avião: " << aviao->nomeVoo << "Qtd Passageiros: "<< aviao->qtdPassageiros << endl;

        // Imprime os passageiros do avião
        passageiros* passageiroHead = aviao->passageiroHead;
        while (passageiroHead != nullptr) {
            cout << "Passageiro: " << passageiroHead->primeiroNome << " " << passageiroHead->ultimoNome << endl;
            passageiroHead = passageiroHead->next;
        }

        head = head->next;
        delete aviao;
    }


    return 0;
}

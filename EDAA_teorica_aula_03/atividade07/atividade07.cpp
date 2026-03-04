// Atividade 7: Calculadora Simples
//Simula uma calculadora para soma, subtração, multiplicação e divisão utilizando o comando

#include <iostream>
using namespace std;

int main() {
    float val1, val2;
    int escolha;

    cout << "Digite o primeiro valor: ";
    cin >> val1;
    cout << "Digite o segundo valor: ";
    cin >> val2;

    cout << "--- Menu de Operacoes ---" << endl;
    cout << "1. Soma" << endl;
    cout << "2. Subtracao" << endl;
    cout << "3. Multiplicacao" << endl;
    cout << "4. Divisao" << endl;
    cout << "Escolha uma opcao (1-4): ";
    cin >> escolha;

    switch (escolha) {
        case 1:
            cout << "Resultado: " << val1 + val2 << endl;
            break;
        case 2:
            cout << "Resultado: " << val1 - val2 << endl;
            break;
        case 3:
            cout << "Resultado: " << val1 * val2 << endl;
            break;
        case 4:
            if (val2 != 0) {
                cout << "Resultado: " << val1 / val2 << endl;
            } else {
                cout << "Erro: Divisao por zero!" << endl;
            }
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
    }

    return 0;
}
/*Atividade 3: Múltiplo de 5
Lê um inteiro e indica com uma mensagem se é ou não múltiplo de 5.*/

#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Digite um numero inteiro: ";
    cin >> numero;

    if (numero % 5 == 0) {
        cout << "O numero informado e multiplo de 5." << endl;
    } else {
        cout << "O numero informado nao e multiplo de 5." << endl;
    }

    return 0;
}
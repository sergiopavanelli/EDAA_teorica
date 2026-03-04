// Atividade 10: Quadrado e Raiz
// Usa a biblioteca <cmath> para ler um número real e, se positivo, calcular seu quadrado e sua raiz quadrada através de funções.

#include <iostream>
#include <cmath> // Biblioteca necessaria para pow() e sqrt()
using namespace std;

int main() {
    float numero;

    cout << "Digite um numero real: ";
    cin >> numero;

    if (numero >= 0) {
        float quadrado = pow(numero, 2);
        float raiz = sqrt(numero);

        cout << "Numero ao quadrado: " << quadrado << endl;
        cout << "Raiz quadrada: " << raiz << endl;
    } else {
        cout << "O numero digitado nao e positivo." << endl;
    }

    return 0;
}
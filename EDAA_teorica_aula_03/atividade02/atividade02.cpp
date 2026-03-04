#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Digite um numero inteiro: ";
    cin >> numero;

    // Se o resto da divisão por 2 for 0, é par. Caso contrário, é ímpar.
    int resultado = numero % 2; 
    
    // Imprime 0 para par e 1 para ímpar (o próprio resto já faz isso para números positivos)
    if (resultado == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}
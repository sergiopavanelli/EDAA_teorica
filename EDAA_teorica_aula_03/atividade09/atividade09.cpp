// Atividade 9: Ordenação de Valores
// Lê I, A, B e C. Ordena de forma crescente, decrescente ou com o maior no meio, avisando caso o I não seja 1, 2 ou 3.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int I;
    double A, B, C;

    cout << "Digite o valor de I (inteiro e positivo): ";
    cin >> I;

    cout << "Digite os valores reais de A, B e C: ";
    cin >> A >> B >> C;

    // Coloca em um array e ordena de forma crescente para facilitar a lógica
    double valores[3] = {A, B, C};
    sort(valores, valores + 3);

    if (I == 1) {
        cout << "Ordem crescente: " << valores[0] << ", " << valores[1] << ", " << valores[2] << endl;
    } 
    else if (I == 2) {
        cout << "Ordem decrescente: " << valores[2] << ", " << valores[1] << ", " << valores[0] << endl;
    } 
    else if (I == 3) {
        cout << "Maior valor entre os outros dois: " << valores[0] << ", " << valores[2] << ", " << valores[1] << endl;
    } 
    else {
        cout << "Valor de I invalido. O algoritmo aceita apenas 1, 2 ou 3." << endl;
    }

    return 0;
}

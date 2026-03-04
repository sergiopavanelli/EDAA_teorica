// Recebe dois inteiros e inverte os valores entre as variáveis. O exemplo de saída reflete a troca de $A=10$ e $B=20$ para $A=20$ e $B=10$.

#include <iostream>
using namespace std;

int main() {
    int A, B, temp;

    cout << "Digite o valor de A: ";
    cin >> A;
    cout << "Digite o valor de B: ";
    cin >> B;

    // Inversão
    temp = A;
    A = B;
    B = temp;

    cout << "Saida: A=" << A << ", B=" << B << endl;

    return 0;
}
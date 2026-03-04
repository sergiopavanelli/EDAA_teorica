// Atividade 1: Carteira de Motorista
//Este código utiliza uma constante e um operador relacional para verificar se a idade permite tirar a carteira.

#include <iostream>
using namespace std;

int main() {
    const int IDADE_MINIMA = 18;
    int idade;

    cout << "Digite sua idade: ";
    cin >> idade;

    if (idade >= IDADE_MINIMA) {
        cout << "Voce ja pode tirar a carteira de motorista." << endl;
    } else {
        cout << "Voce ainda nao pode tirar a carteira de motorista." << endl;
    }

    return 0;
}
// Atividade 6: Conversão de TemperaturaConverte graus Celsius para Fahrenheit utilizando a fórmula $F = C * (9.0/5.0) + 32.0$. 
// Também converte para Kelvin baseado na relação matemática $C = K + 273$ fornecida no material.

#include <iostream>
using namespace std;

int main() {
    float C, F, K;

    cout << "Digite a temperatura em graus Celsius: ";
    cin >> C;

    F = C * (9.0 / 5.0) + 32.0;
    
    // Matematicamente, se C = K + 273, então K = C - 273. 
    // Porém, fisicamente K = C + 273. Adotei a soma (K = C + 273) por ser o padrão de conversão.
    K = C + 273.0; 

    cout << "Temperatura em Fahrenheit: " << F << endl;
    cout << "Temperatura em Kelvin: " << K << endl;

    return 0;
}
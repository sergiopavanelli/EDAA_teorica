# UC: Estrutura de Dados e Análise de Algoritmos

## Título: Prática nº 01B – Atividade –  EDA_1B_Lista
## Data: 04/03/2026

## Integrantes:

- Sérgio Pinton Pavanelli - RA 123220202  
- Samuel Zappala Batista - RA 12411504  
- Elizabeth Stéphany Guimarães Miranda - RA 123220604  
- Gabriel Victor Dornelas Ferreira Sathler - 12319216  
- Ana Luiza Mattos de Carvalho - RA 124114111  
- Júlia Starling Negrini Fudoli - RA 124222027  
- Ana Clara Domingos Dias Silva - RA 12316965  
- Miguel Pedro Pinheiro - RA 12315515  
- Geovana Dias de Almeida - RA 123221311  

### Tema:   Programação de Soluções Computacionais 
### Objetivo:  Introdução aos principais conceitos e motivação 
### Roteiro: Formar grupos e desenvolver as atividades propostas. 

---

## Entregas das atividades 1 a 10 solicitadas na lista de exercícios:

### Atividade 1: Carteira de Motorista
- Este código utiliza uma constante e um operador relacional para verificar se a idade permite tirar a carteira.

```c++
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
```

---

### Atividade 2: Par ou Ímpar (0 ou 1)
- O programa lê um inteiro e imprime 0 se for par, e 1 se for ímpar.

```c++
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
```
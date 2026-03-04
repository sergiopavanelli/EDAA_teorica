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

---

### Atividade 3: Múltiplo de 5
- O programa lê um inteiro e imprime se ele é múltiplo de 5 ou não.

```c++
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
```
---

### Atividade 4: Exibir Nota
- O programa exibe exatamente o texto solicitado pelo enunciado na saída.

```c++
#include <iostream>
using namespace std;

int main() {
    // O programa apenas mostra a nota conforme especificado
    cout << "(Nota=7,5)" << endl;
    return 0;
}
```

---

### Atividade 5: Inversão de Variáveis
- O programa recebe dois inteiros e inverte os valores entre as variáveis. O exemplo de saída reflete a troca de $A=10$ e $B=20$ para $A=20$ e $B=10$.

```c++
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
```

---

### Atividade 6: Conversão de Temperatura
- Converte graus Celsius para Fahrenheit utilizando a fórmula $F = C * (9.0/5.0) + 32.0$. Também converte para Kelvin baseado na relação matemática $C = K + 273$ fornecida no material.

```c++
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
```

### Atividade 7: Calculadora Simples
- Simula uma calculadora para soma, subtração, multiplicação e divisão utilizando o comando

```c++
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
```

---

### Atividade 8: Preço por Condição de Pagamento
- Calcula o valor final de um produto usando switch com base nas 4 condições de pagamento da tabela.

```c++
#include <iostream>
using namespace std;

int main() {
    float precoEtiqueta, valorFinal;
    int condicao;

    cout << "Digite o preco normal de etiqueta: R$ ";
    cin >> precoEtiqueta;

    cout << "--- Condicao de Pagamento ---" << endl;
    cout << "1 - A vista em dinheiro/cheque (10% desconto)" << endl;
    cout << "2 - A vista no cartao de credito (5% desconto)" << endl;
    cout << "3 - Em 2x (preco normal)" << endl;
    cout << "4 - Em 3x (preco normal + 10% juros)" << endl;
    cout << "Escolha a condicao (1-4): ";
    cin >> condicao;

    switch (condicao) {
        case 1:
            valorFinal = precoEtiqueta - (precoEtiqueta * 0.10);
            cout << "Valor a pagar: R$ " << valorFinal << endl;
            break;
        case 2:
            valorFinal = precoEtiqueta - (precoEtiqueta * 0.05);
            cout << "Valor a pagar: R$ " << valorFinal << endl;
            break;
        case 3:
            valorFinal = precoEtiqueta;
            cout << "Valor a pagar: 2 parcelas de R$ " << valorFinal / 2.0 << " (Total: R$ " << valorFinal << ")" << endl;
            break;
        case 4:
            valorFinal = precoEtiqueta + (precoEtiqueta * 0.10);
            cout << "Valor a pagar: 3 parcelas de R$ " << valorFinal / 3.0 << " (Total: R$ " << valorFinal << ")" << endl;
            break;
        default:
            cout << "Condicao de pagamento invalida!" << endl;
            break;
    }

    return 0;
}
```

---

### Atividade 9: Ordenação de Valores
- Lê I, A, B e C. Ordena de forma crescente, decrescente ou com o maior no meio, avisando caso o I não seja 1, 2 ou 3.

```c++
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
```

---

### Atividade 10: Quadrado e Raiz
- Usa a biblioteca <cmath> para ler um número real e, se positivo, calcular seu quadrado e sua raiz quadrada através de funções.

```c++
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
```

# UC: Estruturas de Dados e Análise de Algoritmos

## Título: Prática nº 01C – Atividade – EDA_1C_Lista
## Data: 18/03/2026

## Integrantes:

- Sérgio Pinton Pavanelli - RA 123220202  (*líder: sergiopavanelli@gmail.com*)
- Samuel Zappala Batista - RA 12411504
- Elizabeth Stéphany Guimarães Miranda - RA 123220604
- Gabriel Victor Dornelas Ferreira Sathler - 12319216
- Ana Luiza Mattos de Carvalho - RA 124114111
- Júlia Starling Negrini Fudoli - RA 124222027
- Ana Clara Domingos Dias Silva - RA 12316965
- Miguel Pedro Pinheiro - RA 12315515
- Geovana Dias de Almeida - RA 123221311

### Tema: Programação de Soluções Computacionais
### Objetivo: Introdução aos principais conceitos e motivação
### Roteiro: Formar grupos e desenvolver as atividades propostas.

---

## Entregas das atividades 1.1 a 1.5 solicitadas na lista de exercícios:

### Atividade 1.1: Custo de Construção
- Lê o comprimento e a largura de um terreno retangular, calcula a área e multiplica pelo custo de R$ 850,00 por m² para obter o valor total da construção.

```c++
#include <iostream>
using namespace std;

int main() {
    float comprimento, largura, area, custo;
    const float CUSTO_M2 = 850.0;

    cout << "Digite o comprimento do terreno (em metros): ";
    cin >> comprimento;
    cout << "Digite a largura do terreno (em metros): ";
    cin >> largura;

    area = comprimento * largura;
    custo = area * CUSTO_M2;

    cout << "A construcao custara R$ " << custo << endl;

    return 0;
}
```

---

### Atividade 1.2: Área do Quadrado
- Solicita ao usuário o valor do lado de um quadrado e calcula sua área pela fórmula $A = lado \times lado$.

```c++
#include <iostream>
using namespace std;

int main() {
    float lado, area;

    cout << "Digite o valor do lado do quadrado: ";
    cin >> lado;

    area = lado * lado;

    cout << "A area do quadrado e: " << area << endl;

    return 0;
}
```

---

### Atividade 1.3: Equação do Segundo Grau
- Lê os coeficientes $a$, $b$ e $c$ de uma equação do segundo grau ($ax^2 + bx + c = 0$) e calcula as raízes usando a fórmula de Bhaskara. O programa trata os três casos possíveis: dois valores reais distintos ($\Delta > 0$), uma raiz real dupla ($\Delta = 0$) e nenhuma raiz real ($\Delta < 0$).

```c++
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c, delta, x1, x2;

    cout << "Equacao do segundo grau: ax^2 + bx + c = 0" << endl;
    cout << "Digite o coeficiente a: ";
    cin >> a;
    cout << "Digite o coeficiente b: ";
    cin >> b;
    cout << "Digite o coeficiente c: ";
    cin >> c;

    delta = pow(b, 2) - 4 * a * c;

    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Delta = " << delta << endl;
        cout << "Duas raizes reais distintas:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        cout << "Delta = " << delta << endl;
        cout << "Uma raiz real dupla:" << endl;
        cout << "x = " << x1 << endl;
    } else {
        cout << "Delta = " << delta << endl;
        cout << "Nao existem raizes reais para esta equacao." << endl;
    }

    return 0;
}
```

---

### Atividade 1.4: Jogo Verdadeiro ou Falso
- Apresenta três afirmações ao usuário, que deve responder 1 para Verdadeiro ou 2 para Falso. Ao final, o programa exibe o gabarito e o total de acertos.

```c++
#include <iostream>
using namespace std;

int main() {
    int resp1, resp2, resp3;
    int acertos = 0;

    cout << "=== Jogo: Verdadeiro ou Falso ===" << endl;
    cout << "(Digite 1 para Verdadeiro ou 2 para Falso)" << endl << endl;

    cout << "Afirmacao 1: A linguagem C++ foi criada por Bjarne Stroustrup." << endl;
    cout << "Sua resposta: ";
    cin >> resp1;

    cout << endl;
    cout << "Afirmacao 2: O numero PI vale exatamente 3,14." << endl;
    cout << "Sua resposta: ";
    cin >> resp2;

    cout << endl;
    cout << "Afirmacao 3: Um byte possui 8 bits." << endl;
    cout << "Sua resposta: ";
    cin >> resp3;

    // Gabarito: 1=Verdadeiro, 2=Falso
    // Afirmacao 1: Verdadeiro (1)
    // Afirmacao 2: Falso     (2) - PI e irracional, nao exatamente 3,14
    // Afirmacao 3: Verdadeiro (1)

    cout << endl << "=== Gabarito ===" << endl;
    cout << "Afirmacao 1 - Correto: VERDADEIRO";
    if (resp1 == 1) { cout << " | Voce acertou!" << endl; acertos++; }
    else            { cout << " | Voce errou."  << endl; }

    cout << "Afirmacao 2 - Correto: FALSO";
    if (resp2 == 2) { cout << " | Voce acertou!" << endl; acertos++; }
    else            { cout << " | Voce errou."  << endl; }

    cout << "Afirmacao 3 - Correto: VERDADEIRO";
    if (resp3 == 1) { cout << " | Voce acertou!" << endl; acertos++; }
    else            { cout << " | Voce errou."  << endl; }

    cout << endl << "Total de acertos: " << acertos << " de 3" << endl;

    return 0;
}
```

---

### Atividade 1.5: Desconto na Compra de 3 Produtos
- Lê o preço de três produtos, calcula o total sem desconto, aplica o desconto de 20% e exibe o valor do desconto e o valor final a ser pago.

```c++
#include <iostream>
using namespace std;

int main() {
    float preco1, preco2, preco3;
    float totalSemDesconto, desconto, totalComDesconto;
    const float PERCENTUAL_DESCONTO = 0.20;

    cout << "Digite o preco do produto 1: R$ ";
    cin >> preco1;
    cout << "Digite o preco do produto 2: R$ ";
    cin >> preco2;
    cout << "Digite o preco do produto 3: R$ ";
    cin >> preco3;

    totalSemDesconto = preco1 + preco2 + preco3;
    desconto = totalSemDesconto * PERCENTUAL_DESCONTO;
    totalComDesconto = totalSemDesconto - desconto;

    cout << endl;
    cout << "Total sem desconto: R$ " << totalSemDesconto << endl;
    cout << "Desconto (20%):     R$ " << desconto << endl;
    cout << "Total a pagar:      R$ " << totalComDesconto << endl;

    return 0;
}
```

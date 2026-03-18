# UC: Estruturas de Dados e Análise de Algoritmos

## Título: Prática nº 01D – Atividade – EDA_1D - Lista
## Data: 24/03/2026

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

## Entregas das atividades 1.1 a 1.10 solicitadas na lista de exercícios:

### Atividade 1.1: Sucessor e Antecessor
- Lê um número inteiro e exibe seu sucessor (n+1) e seu antecessor (n-1) com lógica sequencial.

```c++
#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    cout << "Sucessor: " << numero + 1 << endl;
    cout << "Antecessor: " << numero - 1 << endl;

    return 0;
}
```

---

### Atividade 1.2: Hipotenusa
- Lê os comprimentos do cateto oposto e do cateto adjacente e calcula a hipotenusa usando a fórmula $H = \sqrt{a^2 + b^2}$, por meio das funções `pow()` e `sqrt()` da biblioteca `<cmath>`.

```c++
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double catetoOposto, catetoAdjacente, hipotenusa;

    cout << "Digite o comprimento do cateto oposto: ";
    cin >> catetoOposto;
    cout << "Digite o comprimento do cateto adjacente: ";
    cin >> catetoAdjacente;

    hipotenusa = sqrt(pow(catetoOposto, 2) + pow(catetoAdjacente, 2));

    cout << "Comprimento da hipotenusa: " << hipotenusa << endl;

    return 0;
}
```

---

### Atividade 1.3: Idade de Eleitor
- Declara uma variável inteira para a idade e verifica se é maior ou igual a 16 anos para determinar se a pessoa possui idade para ser eleitora no Brasil.

```c++
#include <iostream>
using namespace std;

int main() {
    int idade;

    cout << "Digite a sua idade: ";
    cin >> idade;

    if (idade >= 16) {
        cout << "Possui idade para ser eleitor no Brasil." << endl;
    } else {
        cout << "Nao possui idade para ser eleitor no Brasil." << endl;
    }

    return 0;
}
```

---

### Atividade 1.4: Par, Ímpar ou Negativo
- Recebe um número inteiro e, usando estruturas de decisão, verifica: se for negativo, informa que é negativo; caso contrário, verifica se é par ou ímpar pelo resto da divisão por 2.

```c++
#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    if (numero < 0) {
        cout << "O numero e negativo." << endl;
    } else if (numero % 2 == 0) {
        cout << "O numero e par." << endl;
    } else {
        cout << "O numero e impar." << endl;
    }

    return 0;
}
```

---

### Atividade 1.5: Multa por Velocidade
- Lê a velocidade de um carro. Se ultrapassar 80 km/h, calcula e exibe a multa de R$ 7,00 por cada km acima do limite.

```c++
#include <iostream>
using namespace std;

int main() {
    float velocidade;

    cout << "Digite a velocidade do carro (km/h): ";
    cin >> velocidade;

    if (velocidade > 80) {
        float excesso = velocidade - 80;
        float multa = excesso * 7.0;
        cout << "Voce foi multado!" << endl;
        cout << "Excesso: " << excesso << " km/h" << endl;
        cout << "Valor da multa: R$ " << multa << endl;
    } else {
        cout << "Velocidade dentro do limite permitido." << endl;
    }

    return 0;
}
```

---

### Atividade 1.6: Preço de Passagem
- Pergunta a distância da viagem em km e calcula o preço da passagem: R$ 0,50 por km para viagens de até 200 km, ou R$ 0,45 por km para viagens mais longas.

```c++
#include <iostream>
using namespace std;

int main() {
    float distancia, preco;

    cout << "Digite a distancia da viagem em km: ";
    cin >> distancia;

    if (distancia <= 200) {
        preco = distancia * 0.50;
    } else {
        preco = distancia * 0.45;
    }

    cout << "Preco da passagem: R$ " << preco << endl;

    return 0;
}
```

---

### Atividade 1.7: Aumento de Salário
- Lê o salário de um funcionário e calcula o aumento: 10% para salários superiores a R$ 1.250,00, ou R$ 15,00 fixos para salários inferiores ou iguais a esse valor.

```c++
#include <iostream>
using namespace std;

int main() {
    float salario, aumento, novoSalario;

    cout << "Digite o salario do funcionario: R$ ";
    cin >> salario;

    if (salario > 1250.0) {
        aumento = salario * 0.10;
    } else {
        aumento = 15.0;
    }

    novoSalario = salario + aumento;

    cout << "Valor do aumento: R$ " << aumento << endl;
    cout << "Novo salario: R$ " << novoSalario << endl;

    return 0;
}
```

---

### Atividade 1.8: Verificação de Triângulo
- Lê o comprimento de três retas e verifica se elas podem formar um triângulo. A condição necessária é que a soma de quaisquer dois lados seja maior que o terceiro lado (desigualdade triangular).

```c++
#include <iostream>
using namespace std;

int main() {
    float a, b, c;

    cout << "Digite o comprimento da primeira reta: ";
    cin >> a;
    cout << "Digite o comprimento da segunda reta: ";
    cin >> b;
    cout << "Digite o comprimento da terceira reta: ";
    cin >> c;

    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        cout << "As tres retas PODEM formar um triangulo." << endl;
    } else {
        cout << "As tres retas NAO podem formar um triangulo." << endl;
    }

    return 0;
}
```

---

### Atividade 1.9: Jogo de Adivinhação
- O computador "pensa" em um número inteiro entre 0 e 5 utilizando geração aleatória com `srand(time(NULL))` e `rand() % 6`. O usuário tenta adivinhar e o programa informa se venceu ou perdeu.

```c++
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
    int numero, chute;

    srand(time(NULL));
    numero = rand() % 6; // gera número entre 0 e 5

    cout << "=== Jogo de Adivinhacao ===" << endl;
    cout << "Tente adivinhar o numero entre 0 e 5: ";
    cin >> chute;

    if (chute == numero) {
        cout << "Parabens! Voce venceu! O numero era " << numero << "." << endl;
    } else {
        cout << "Voce perdeu! O numero era " << numero << "." << endl;
    }

    return 0;
}
```

---

### Atividade 1.10: Tipo de Polígono
- Lê a quantidade de lados de um polígono regular e exibe o ângulo (360 / quantidade de lados) e o tipo do polígono conforme a tabela: 3 = Triângulo, 4 = Quadrado, 5 = Pentágono, 6 = Hexágono, demais = Polígono Desconhecido.

```c++
#include <iostream>
using namespace std;

int main() {
    int lados;
    float angulo;

    cout << "Digite a quantidade de lados do poligono: ";
    cin >> lados;

    angulo = 360.0 / lados;

    cout << "Angulo necessario: " << angulo << " graus" << endl;

    switch (lados) {
        case 3:
            cout << "Tipo do poligono: Triangulo" << endl;
            break;
        case 4:
            cout << "Tipo do poligono: Quadrado" << endl;
            break;
        case 5:
            cout << "Tipo do poligono: Pentagono" << endl;
            break;
        case 6:
            cout << "Tipo do poligono: Hexagono" << endl;
            break;
        default:
            cout << "Tipo do poligono: Poligono Desconhecido" << endl;
            break;
    }

    return 0;
}
```

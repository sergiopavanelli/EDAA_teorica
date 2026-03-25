# UC: Estruturas de Dados e Análise de Algoritmos

## Título: Prática nº 01E – Atividade – EDA_1E - P3 - Lista
## Data: 25/03/2026

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

### Tema: Estruturas de Dados
### Objetivo: Estruturas de Repetição
### Roteiro: Formar grupos e desenvolver as atividades propostas.

---

## Entregas das atividades 1.1 a 1.11 solicitadas na lista de exercícios:

### Atividade 1.1: Números no Intervalo entre Dois Inteiros
- Lê dois números inteiros e gera todos os números inteiros compreendidos no intervalo entre eles, apresentando os resultados na tela.

```c++
#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "Digite o primeiro numero inteiro: ";
    cin >> num1;
    cout << "Digite o segundo numero inteiro: ";
    cin >> num2;

    int inicio, fim;
    if (num1 < num2) {
        inicio = num1;
        fim = num2;
    } else {
        inicio = num2;
        fim = num1;
    }

    cout << "Numeros no intervalo de " << inicio << " a " << fim << ":" << endl;
    for (int i = inicio; i <= fim; i++) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
```

---

### Atividade 1.2: Gerador de Tabuada
- Lê um número inteiro entre 1 e 10 informado pelo usuário e exibe a tabuada completa desse número, no formato `N x i = resultado`.

```c++
#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Digite um numero inteiro entre 1 e 10: ";
    cin >> numero;

    cout << "Tabuada de " << numero << ":" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << numero << " X " << i << " = " << numero * i << endl;
    }

    return 0;
}
```

---

### Atividade 1.3: Tabuada com FOR, WHILE e DO-WHILE
- Lê um número inteiro e exibe sua tabuada utilizando três estruturas de repetição distintas: FOR, WHILE e DO-WHILE.

```c++
#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    // Versao com FOR
    cout << "\n=== Tabuada com FOR ===" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << numero << " X " << i << " = " << numero * i << endl;
    }

    // Versao com WHILE
    cout << "\n=== Tabuada com WHILE ===" << endl;
    int i = 1;
    while (i <= 10) {
        cout << numero << " X " << i << " = " << numero * i << endl;
        i++;
    }

    // Versao com DO-WHILE
    cout << "\n=== Tabuada com DO-WHILE ===" << endl;
    i = 1;
    do {
        cout << numero << " X " << i << " = " << numero * i << endl;
        i++;
    } while (i <= 10);

    return 0;
}
```

---

### Atividade 1.4: Menu com Validação de Entrada
- Implementa um menu onde o usuário deve selecionar 1 ou 0. Caso um número diferente seja inserido, o programa solicita uma nova opção até que a entrada seja válida.

```c++
#include <iostream>
using namespace std;

int main() {
    int opcao;

    do {
        cout << "=== MENU ===" << endl;
        cout << "[1] - Opcao 1" << endl;
        cout << "[0] - Sair" << endl;
        cout << "Escolha uma opcao (0 ou 1): ";
        cin >> opcao;

        if (opcao != 0 && opcao != 1) {
            cout << "Opcao invalida! Tente novamente.\n" << endl;
        }
    } while (opcao != 0 && opcao != 1);

    if (opcao == 1) {
        cout << "Voce selecionou a Opcao 1." << endl;
    } else {
        cout << "Voce escolheu Sair. Encerrando o programa." << endl;
    }

    return 0;
}
```

---

### Atividade 1.5: Soma e Média de Números Reais
- Lê números reais maiores que zero. Quando o usuário insere zero, o programa exibe a quantidade de números digitados, a soma e a média.

```c++
#include <iostream>
using namespace std;

int main() {
    float numero, soma = 0;
    int quantidade = 0;

    cout << "Digite numeros reais maiores que zero (0 para encerrar):" << endl;

    do {
        cout << "Numero: ";
        cin >> numero;

        if (numero > 0) {
            soma += numero;
            quantidade++;
        } else if (numero < 0) {
            cout << "Valor invalido! Digite apenas numeros maiores que zero." << endl;
        }
    } while (numero != 0);

    if (quantidade > 0) {
        float media = soma / quantidade;
        cout << "\n=== Resultados ===" << endl;
        cout << "Quantidade de numeros digitados: " << quantidade << endl;
        cout << "Soma: " << soma << endl;
        cout << "Media: " << media << endl;
    } else {
        cout << "Nenhum numero valido foi digitado." << endl;
    }

    return 0;
}
```

---

### Atividade 1.6: Conversão de FOR para WHILE - Maior e Menor Número
- Converte o programa fornecido em C (com laço `for`) para utilizar a lógica `while`, mantendo a funcionalidade de encontrar o maior e o menor dentre 10 números inteiros informados pelo usuário.

**Programa original (com FOR):**
```c
#include<stdio.h>
int main()
{
    int numero, guarda_maior, guarda_menor;
    int i;
    printf("Entre com o 1o numero inteiro: ");
    scanf("%i", &numero);
    guarda_maior=numero;
    guarda_menor=numero;
    for(i=1; i<10; i++)
    {
        printf("\nEntre com o %do numero inteiro: ",i+1);
        scanf("%i", &numero);
        if(numero>guarda_maior)
            guarda_maior=numero;
        else
            if(numero<guarda_menor)
                guarda_menor=numero;
    }
    printf("\nO menor numero entrado e: %d", guarda_menor);
    printf("\nO maior numero entrado e: %d", guarda_maior);
    return 0;
}
```

**Programa convertido (com WHILE):**
```c++
#include <iostream>
using namespace std;

int main() {
    int numero, guarda_maior, guarda_menor;
    int i;

    cout << "Entre com o 1o numero inteiro: ";
    cin >> numero;

    guarda_maior = numero;
    guarda_menor = numero;

    i = 1;
    while (i < 10) {
        cout << "Entre com o " << i + 1 << "o numero inteiro: ";
        cin >> numero;

        if (numero > guarda_maior)
            guarda_maior = numero;
        else if (numero < guarda_menor)
            guarda_menor = numero;

        i++;
    }

    cout << "\nO menor numero entrado e: " << guarda_menor << endl;
    cout << "O maior numero entrado e: " << guarda_maior << endl;

    return 0;
}
```

---

### Atividade 1.7: Média e Maior Nota de uma Turma
- Lê o nome e a nota final de 10 alunos utilizando uma estrutura de repetição contável (`for`). Ao final, imprime a média das notas e o nome do aluno com a maior nota.

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome, nomeMaiorNota;
    float nota, somaNotas = 0, maiorNota = -1;

    for (int i = 0; i < 10; i++) {
        cout << "Aluno " << i + 1 << ":" << endl;
        cout << "  Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "  Nota final: ";
        cin >> nota;

        somaNotas += nota;

        if (nota > maiorNota) {
            maiorNota = nota;
            nomeMaiorNota = nome;
        }
    }

    float media = somaNotas / 10;

    cout << "\n=== Resultados ===" << endl;
    cout << "Media das notas da turma: " << media << endl;
    cout << "Aluno com maior nota: " << nomeMaiorNota << " (nota: " << maiorNota << ")" << endl;

    return 0;
}
```

---

### Atividade 1.8: Conversão de WHILE para DO-WHILE - Idade Média (Busca Ativa)
- Converte o programa fornecido (que calcula a idade média de um grupo de pessoas usando `while`) para utilizar a estrutura `do-while`. A entrada é finalizada quando o usuário digita -1.

**Programa convertido (com DO-WHILE):**
```c++
#include <iostream>
using namespace std;

int main() {
    int soma, quantidade, idade;
    float media;

    soma = 0;
    quantidade = 0;

    do {
        cout << "Idade da pessoa " << quantidade + 1 << " (tecle -1 se quiser encerrar): ";
        cin >> idade;

        if (idade >= 0) {
            soma = soma + idade;
            quantidade = quantidade + 1;
        }
    } while (idade != -1);

    if (quantidade > 0) {
        media = (float)soma / quantidade;
        cout << "A media de idade das " << quantidade << " pessoas eh: " << media << endl;
    } else {
        cout << "Nenhum dado foi informado." << endl;
    }

    return 0;
}
```

---

### Atividade 1.9: Divisores de um Número
- Lê um número inteiro e apresenta todos os seus divisores (valores cujo resto da divisão é igual a zero).

```c++
#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    cout << "Divisores de " << numero << ": " << endl;
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
```

---

### Atividade 1.10: Média de Notas de Alunos
- Lê a quantidade de alunos e suas respectivas notas da primeira prova, calculando e imprimindo a média.

**a) Com validação de nota (0 <= nota <= 10):**
```c++
#include <iostream>
using namespace std;

int main() {
    int n;
    float nota, soma = 0;

    cout << "Digite a quantidade de alunos: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        do {
            cout << "Nota do aluno " << i + 1 << " (0 a 10): ";
            cin >> nota;
            if (nota < 0 || nota > 10) {
                cout << "Nota invalida! Digite um valor entre 0 e 10." << endl;
            }
        } while (nota < 0 || nota > 10);

        soma += nota;
    }

    if (n > 0) {
        float media = soma / n;
        cout << "\nMedia das notas: " << media << endl;
    } else {
        cout << "Nenhum aluno informado." << endl;
    }

    return 0;
}
```

**b) Número de alunos desconhecido (nota negativa como critério de parada):**
```c++
#include <iostream>
using namespace std;

int main() {
    float nota, soma = 0;
    int quantidade = 0;

    cout << "Digite as notas dos alunos (nota negativa para encerrar):" << endl;

    while (true) {
        cout << "Nota do aluno " << quantidade + 1 << ": ";
        cin >> nota;

        if (nota < 0) {
            break;
        }

        if (nota > 10) {
            cout << "Nota invalida! Digite um valor entre 0 e 10." << endl;
            continue;
        }

        soma += nota;
        quantidade++;
    }

    if (quantidade > 0) {
        float media = soma / quantidade;
        cout << "\nQuantidade de alunos: " << quantidade << endl;
        cout << "Media das notas: " << media << endl;
    } else {
        cout << "Nenhuma nota foi informada." << endl;
    }

    return 0;
}
```

---

### Atividade 1.11: Cadastro de Produtos (Busca Ativa)
- Lê o código, nome e preço de produtos utilizando uma estrutura `while` para a leitura de vários produtos (código -1 encerra) e `do-while` para garantir que os preços sejam maiores que zero.

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    int codigo;
    string nome;
    float preco;

    cout << "=== Cadastro de Produtos ===" << endl;
    cout << "Digite o codigo do produto (-1 para encerrar): ";
    cin >> codigo;

    while (codigo != -1) {
        cout << "Nome do produto: ";
        cin.ignore();
        getline(cin, nome);

        do {
            cout << "Preco do produto: R$ ";
            cin >> preco;
            if (preco <= 0) {
                cout << "Preco invalido! Digite um valor maior que zero." << endl;
            }
        } while (preco <= 0);

        cout << "\n--- Dados do Produto ---" << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Nome: " << nome << endl;
        cout << "Preco: R$ " << preco << endl;
        cout << "------------------------\n" << endl;

        cout << "Digite o codigo do produto (-1 para encerrar): ";
        cin >> codigo;
    }

    cout << "Programa encerrado." << endl;

    return 0;
}
```

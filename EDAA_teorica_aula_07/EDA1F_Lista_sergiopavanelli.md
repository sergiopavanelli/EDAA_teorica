# UC: Estruturas de Dados e Análise de Algoritmos

## Título: Prática nº 01F – Atividade – EDA1F_Lista - Vetores
## Data: 08/04/2026

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
### Objetivo: Estruturas de vetores
### Roteiro: Formar grupos e desenvolver as atividades propostas.

---

## Entregas das atividades 1 a 20 solicitadas na lista de exercícios:

### Atividade 1: Operações com Vetor A
- Declara vetor `A[6] = {1, 0, 5, -2, -5, 7}`, calcula e exibe a soma de `A[0]+A[1]+A[5]`, modifica `A[4] = 100` e exibe todos os elementos.

```c++
#include <iostream>
using namespace std;

int main() {
    int A[6] = {1, 0, 5, -2, -5, 7};
    int soma;

    soma = A[0] + A[1] + A[5];
    cout << "Soma de A[0] + A[1] + A[5] = " << soma << endl;

    A[4] = 100;

    cout << "\nValores do vetor A:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "A[" << i << "] = " << A[i] << endl;
    }

    return 0;
}
```

---

### Atividade 2: Leitura e Exibição de 6 Inteiros
- Lê 6 valores inteiros fornecidos pelo usuário e os exibe na tela.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[6];

    cout << "Digite 6 valores inteiros:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    cout << "\nValores lidos:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "v[" << i << "] = " << v[i] << endl;
    }

    return 0;
}
```

---

### Atividade 3: Quadrado das Componentes de Vetor Real
- Lê 10 números reais em vetor `A`, calcula o quadrado de cada elemento armazenando em vetor `B`, e imprime ambos os vetores.

```c++
#include <iostream>
using namespace std;

int main() {
    float A[10], B[10];

    cout << "Digite 10 numeros reais:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
        B[i] = A[i] * A[i];
    }

    cout << "\nVetor A (original):" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "A[" << i << "] = " << A[i] << endl;
    }

    cout << "\nVetor B (quadrado):" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "B[" << i << "] = " << B[i] << endl;
    }

    return 0;
}
```

---

### Atividade 4: Soma de Dois Elementos por Posição
- Lê vetor de 8 posições e dois índices X e Y fornecidos pelo usuário, e exibe a soma dos valores nas posições informadas.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[8];
    int x, y;

    cout << "Digite os 8 valores do vetor:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    cout << "\nDigite a posicao X (0 a 7): ";
    cin >> x;
    cout << "Digite a posicao Y (0 a 7): ";
    cin >> y;

    cout << "\nv[" << x << "] = " << v[x] << endl;
    cout << "v[" << y << "] = " << v[y] << endl;
    cout << "Soma v[" << x << "] + v[" << y << "] = " << v[x] + v[y] << endl;

    return 0;
}
```

---

### Atividade 5: Contagem de Valores Pares
- Lê vetor de 10 posições e conta e exibe quantos elementos são pares.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[10];
    int contPares = 0;

    cout << "Digite 10 valores inteiros:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    for (int i = 0; i < 10; i++) {
        if (v[i] % 2 == 0) {
            contPares++;
        }
    }

    cout << "\nQuantidade de valores pares: " << contPares << endl;

    return 0;
}
```

---

### Atividade 6: Maior e Menor Elemento
- Lê vetor com 10 posições fornecido pelo usuário e imprime o maior e o menor elemento.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[10];

    cout << "Digite 10 valores inteiros:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    int maior = v[0], menor = v[0];
    for (int i = 1; i < 10; i++) {
        if (v[i] > maior) maior = v[i];
        if (v[i] < menor) menor = v[i];
    }

    cout << "\nMaior elemento: " << maior << endl;
    cout << "Menor elemento: " << menor << endl;

    return 0;
}
```

---

### Atividade 7: Maior Elemento e sua Posição
- Lê 10 inteiros, imprime o vetor completo, o maior elemento e o índice em que ele se encontra.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[10];

    cout << "Digite 10 valores inteiros:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    int maior = v[0], posMaior = 0;
    for (int i = 1; i < 10; i++) {
        if (v[i] > maior) {
            maior = v[i];
            posMaior = i;
        }
    }

    cout << "\nVetor: ";
    for (int i = 0; i < 10; i++) {
        cout << v[i];
        if (i < 9) cout << ", ";
    }
    cout << endl;

    cout << "Maior elemento: " << maior << endl;
    cout << "Posicao: " << posMaior << endl;

    return 0;
}
```

---

### Atividade 8: Exibição na Ordem Inversa
- Lê 6 valores inteiros e os exibe na tela na ordem inversa à leitura.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[6];

    cout << "Digite 6 valores inteiros:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    cout << "\nValores na ordem inversa:" << endl;
    for (int i = 5; i >= 0; i--) {
        cout << v[i] << endl;
    }

    return 0;
}
```

---

### Atividade 9: Leitura de Pares na Ordem Inversa
- Lê 6 valores inteiros pares (rejeita ímpares) e os exibe na ordem inversa.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[6];
    int valor;

    cout << "Digite 6 valores inteiros PARES:" << endl;
    for (int i = 0; i < 6; i++) {
        do {
            cout << "v[" << i << "]: ";
            cin >> valor;
            if (valor % 2 != 0) {
                cout << "Valor invalido! Digite um numero par." << endl;
            }
        } while (valor % 2 != 0);
        v[i] = valor;
    }

    cout << "\nValores na ordem inversa:" << endl;
    for (int i = 5; i >= 0; i--) {
        cout << v[i] << endl;
    }

    return 0;
}
```

---

### Atividade 10: Média das Notas de 15 Alunos
- Lê as notas de 15 alunos, armazena em vetor, calcula e imprime a média geral.

```c++
#include <iostream>
using namespace std;

int main() {
    float notas[15];
    float soma = 0.0f;

    cout << "Digite as notas dos 15 alunos:" << endl;
    for (int i = 0; i < 15; i++) {
        cout << "Aluno " << i + 1 << ": ";
        cin >> notas[i];
        soma += notas[i];
    }

    float media = soma / 15.0f;
    cout << "\nMedia geral da turma: " << media << endl;

    return 0;
}
```

---

### Atividade 11: Negativos e Soma dos Positivos
- Preenche vetor com 10 números reais, calcula e exibe a quantidade de números negativos e a soma dos números positivos.

```c++
#include <iostream>
using namespace std;

int main() {
    float v[10];
    int contNegativos = 0;
    float somaPositivos = 0.0f;

    cout << "Digite 10 numeros reais:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    for (int i = 0; i < 10; i++) {
        if (v[i] < 0) {
            contNegativos++;
        } else if (v[i] > 0) {
            somaPositivos += v[i];
        }
    }

    cout << "\nQuantidade de numeros negativos: " << contNegativos << endl;
    cout << "Soma dos numeros positivos: " << somaPositivos << endl;

    return 0;
}
```

---

### Atividade 12: Maior, Menor e Média de 5 Valores
- Lê 5 valores, exibe todos os valores lidos juntamente com o maior, o menor e a média.

```c++
#include <iostream>
using namespace std;

int main() {
    float v[5];
    float soma = 0.0f;

    cout << "Digite 5 valores:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
        soma += v[i];
    }

    float maior = v[0], menor = v[0];
    for (int i = 1; i < 5; i++) {
        if (v[i] > maior) maior = v[i];
        if (v[i] < menor) menor = v[i];
    }

    cout << "\nValores lidos: ";
    for (int i = 0; i < 5; i++) {
        cout << v[i];
        if (i < 4) cout << ", ";
    }
    cout << endl;

    cout << "Maior: " << maior << endl;
    cout << "Menor: " << menor << endl;
    cout << "Media: " << soma / 5.0f << endl;

    return 0;
}
```

---

### Atividade 13: Posição do Maior e do Menor
- Lê 5 valores e exibe as posições (índices) onde se encontram o maior e o menor valor.

```c++
#include <iostream>
using namespace std;

int main() {
    float v[5];

    cout << "Digite 5 valores:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    int posMaior = 0, posMenor = 0;
    for (int i = 1; i < 5; i++) {
        if (v[i] > v[posMaior]) posMaior = i;
        if (v[i] < v[posMenor]) posMenor = i;
    }

    cout << "\nMaior valor: " << v[posMaior] << " na posicao " << posMaior << endl;
    cout << "Menor valor: " << v[posMenor] << " na posicao " << posMenor << endl;

    return 0;
}
```

---

### Atividade 14: Verificação de Valores Iguais
- Lê vetor de 10 posições e verifica se existem valores repetidos, exibindo na tela os valores duplicados encontrados.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[10];

    cout << "Digite 10 valores inteiros:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    cout << "\nValores repetidos encontrados:" << endl;
    bool encontrou = false;
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (v[i] == v[j]) {
                cout << v[i] << " (posicoes " << i << " e " << j << ")" << endl;
                encontrou = true;
            }
        }
    }

    if (!encontrou) {
        cout << "Nenhum valor repetido." << endl;
    }

    return 0;
}
```

---

### Atividade 15: Eliminação de Repetidos
- Lê vetor com 20 inteiros e escreve os elementos do vetor sem valores repetidos.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[20];
    int semRepetidos[20];
    int cont = 0;

    cout << "Digite 20 valores inteiros:" << endl;
    for (int i = 0; i < 20; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    for (int i = 0; i < 20; i++) {
        bool repetido = false;
        for (int j = 0; j < cont; j++) {
            if (v[i] == semRepetidos[j]) {
                repetido = true;
                break;
            }
        }
        if (!repetido) {
            semRepetidos[cont++] = v[i];
        }
    }

    cout << "\nVetor sem repetidos:" << endl;
    for (int i = 0; i < cont; i++) {
        cout << semRepetidos[i];
        if (i < cont - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
```

---

### Atividade 16: Exibição por Código de Controle
- Lê vetor de 5 números reais e um código: 0 encerra, 1 exibe em ordem direta, 2 exibe em ordem inversa; outros códigos exibem mensagem de código inválido.

```c++
#include <iostream>
using namespace std;

int main() {
    float v[5];
    int codigo;

    cout << "Digite 5 numeros reais:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    do {
        cout << "\nCodigo (0=sair | 1=ordem direta | 2=ordem inversa): ";
        cin >> codigo;

        if (codigo == 0) {
            cout << "Programa encerrado." << endl;
        } else if (codigo == 1) {
            cout << "Ordem direta: ";
            for (int i = 0; i < 5; i++) {
                cout << v[i];
                if (i < 4) cout << ", ";
            }
            cout << endl;
        } else if (codigo == 2) {
            cout << "Ordem inversa: ";
            for (int i = 4; i >= 0; i--) {
                cout << v[i];
                if (i > 0) cout << ", ";
            }
            cout << endl;
        } else {
            cout << "Codigo invalido!" << endl;
        }
    } while (codigo != 0);

    return 0;
}
```

---

### Atividade 17: Substituição de Negativos por Zero
- Lê vetor de 10 posições e atribui valor 0 para todos os elementos que possuírem valores negativos, exibindo o vetor resultante.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[10];

    cout << "Digite 10 valores inteiros:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    for (int i = 0; i < 10; i++) {
        if (v[i] < 0) {
            v[i] = 0;
        }
    }

    cout << "\nVetor apos substituicao dos negativos por 0:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "v[" << i << "] = " << v[i] << endl;
    }

    return 0;
}
```

---

### Atividade 18: Múltiplos de X no Vetor
- Lê vetor de 10 números e um valor X, conta os múltiplos de X existentes no vetor e os exibe na tela.

```c++
#include <iostream>
using namespace std;

int main() {
    int v[10];
    int x, cont = 0;

    cout << "Digite 10 valores inteiros:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "v[" << i << "]: ";
        cin >> v[i];
    }

    cout << "Digite o valor de X: ";
    cin >> x;

    cout << "\nMultiplos de " << x << " no vetor:" << endl;
    for (int i = 0; i < 10; i++) {
        if (x != 0 && v[i] % x == 0) {
            cout << v[i] << " (posicao " << i << ")" << endl;
            cont++;
        }
    }

    cout << "Total de multiplos de " << x << ": " << cont << endl;

    return 0;
}
```

---

### Atividade 19: Intersecção de Dois Vetores
- Lê dois vetores de 10 elementos e cria um terceiro vetor com a intersecção (elementos presentes em ambos), sem repetidos.

```c++
#include <iostream>
using namespace std;

int main() {
    int a[10], b[10];
    int intersec[10];
    int cont = 0;

    cout << "Digite os 10 valores do vetor A:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "A[" << i << "]: ";
        cin >> a[i];
    }

    cout << "\nDigite os 10 valores do vetor B:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "B[" << i << "]: ";
        cin >> b[i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i] == b[j]) {
                bool jaInserido = false;
                for (int k = 0; k < cont; k++) {
                    if (intersec[k] == a[i]) {
                        jaInserido = true;
                        break;
                    }
                }
                if (!jaInserido) {
                    intersec[cont++] = a[i];
                }
                break;
            }
        }
    }

    cout << "\nInterseccao dos vetores A e B:" << endl;
    if (cont == 0) {
        cout << "Nenhum elemento em comum." << endl;
    } else {
        for (int i = 0; i < cont; i++) {
            cout << intersec[i];
            if (i < cont - 1) cout << ", ";
        }
        cout << endl;
    }

    return 0;
}
```

---

### Atividade 20: União de Dois Vetores
- Lê dois vetores de 10 elementos e cria um terceiro vetor com a união (todos os elementos dos dois vetores), sem repetidos.

```c++
#include <iostream>
using namespace std;

int main() {
    int a[10], b[10];
    int uniao[20];
    int cont = 0;

    cout << "Digite os 10 valores do vetor A:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "A[" << i << "]: ";
        cin >> a[i];
    }

    cout << "\nDigite os 10 valores do vetor B:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "B[" << i << "]: ";
        cin >> b[i];
    }

    for (int i = 0; i < 10; i++) {
        bool jaInserido = false;
        for (int k = 0; k < cont; k++) {
            if (uniao[k] == a[i]) {
                jaInserido = true;
                break;
            }
        }
        if (!jaInserido) {
            uniao[cont++] = a[i];
        }
    }

    for (int i = 0; i < 10; i++) {
        bool jaInserido = false;
        for (int k = 0; k < cont; k++) {
            if (uniao[k] == b[i]) {
                jaInserido = true;
                break;
            }
        }
        if (!jaInserido) {
            uniao[cont++] = b[i];
        }
    }

    cout << "\nUniao dos vetores A e B:" << endl;
    for (int i = 0; i < cont; i++) {
        cout << uniao[i];
        if (i < cont - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
```

---

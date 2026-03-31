# UC: Estruturas de Dados e Análise de Algoritmos

## Título: Prática nº Revisão – Atividade – EDA_Revisão
## Data: 31/03/2026

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

### Tema: Estruturas Condicionais e Repetição – C++
### Objetivo: Revisão dos principais conceitos de lógica de programação
### Roteiro: Formar grupos e desenvolver as atividades propostas.

---

## Entregas das atividades 1 a 4 solicitadas nas atividades em sala:

### Atividade 1: Calculadora de IMC
- Lê peso e altura do usuário, calcula o IMC (`IMC = PESO / ALTURA²`) e classifica o resultado utilizando estruturas condicionais `if/else if`.

```c++
#include <iostream>
using namespace std;

int main() {
    float peso, altura, imc;

    cout << "=== Calculadora de IMC ===" << endl;
    cout << "Digite seu peso (kg): ";
    cin >> peso;
    cout << "Digite sua altura (m): ";
    cin >> altura;

    imc = peso / (altura * altura);

    cout << "\nSeu IMC: " << imc << endl;

    if (imc < 18.5) {
        cout << "Classificacao: Abaixo do peso" << endl;
    } else if (imc < 25.0) {
        cout << "Classificacao: Peso Normal" << endl;
    } else if (imc < 30.0) {
        cout << "Classificacao: Sobre Peso" << endl;
    } else if (imc < 40.0) {
        cout << "Classificacao: Obeso" << endl;
    } else {
        cout << "Classificacao: Obeso morbido" << endl;
    }

    return 0;
}
```

---

### Atividade 2: Plano de Saúde por Idade
- Lê a idade do usuário e exibe o valor da mensalidade do plano de saúde correspondente, utilizando estruturas condicionais `if/else if`.

```c++
#include <iostream>
using namespace std;

int main() {
    int idade;

    cout << "=== Plano de Saude ===" << endl;
    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "\nValor da mensalidade: ";

    if (idade <= 10) {
        cout << "R$ 30,00" << endl;
    } else if (idade <= 29) {
        cout << "R$ 60,00" << endl;
    } else if (idade <= 45) {
        cout << "R$ 120,00" << endl;
    } else if (idade <= 59) {
        cout << "R$ 150,00" << endl;
    } else if (idade <= 65) {
        cout << "R$ 250,00" << endl;
    } else {
        cout << "R$ 400,00" << endl;
    }

    return 0;
}
```

---

### Atividade 3: Eleição para o Senado
- Lê votos em loop `while` (1, 2 ou 3 para candidatos; 0 para branco; 4 para nulo; -1 para encerrar). Conta os votos de cada candidato, brancos, nulos e total. Determina e exibe o vencedor com percentuais.

```c++
#include <iostream>
using namespace std;

int main() {
    int voto;
    int votos1 = 0, votos2 = 0, votos3 = 0;
    int brancos = 0, nulos = 0, total = 0;

    cout << "=== Eleicao para o Senado ===" << endl;
    cout << "Opcoes: 1, 2 ou 3 (candidatos) | 0 (branco) | 4 (nulo) | -1 (encerrar)" << endl;

    cout << "\nDigite o voto: ";
    cin >> voto;

    while (voto != -1) {
        if (voto == 1) {
            votos1++;
            total++;
        } else if (voto == 2) {
            votos2++;
            total++;
        } else if (voto == 3) {
            votos3++;
            total++;
        } else if (voto == 0) {
            brancos++;
            total++;
        } else if (voto == 4) {
            nulos++;
            total++;
        }

        cout << "Digite o voto: ";
        cin >> voto;
    }

    cout << "\n========================================" << endl;
    cout << "           RESULTADO DA ELEICAO" << endl;
    cout << "========================================" << endl;
    cout << "Total de votos: " << total << endl;
    cout << "Candidato 1:    " << votos1 << " votos" << endl;
    cout << "Candidato 2:    " << votos2 << " votos" << endl;
    cout << "Candidato 3:    " << votos3 << " votos" << endl;
    cout << "Brancos:        " << brancos << " votos" << endl;
    cout << "Nulos:          " << nulos << " votos" << endl;

    cout << "\nVencedor: ";
    if (votos1 > votos2 && votos1 > votos3) {
        cout << "Candidato 1" << endl;
    } else if (votos2 > votos1 && votos2 > votos3) {
        cout << "Candidato 2" << endl;
    } else {
        cout << "Candidato 3" << endl;
    }
    cout << "========================================" << endl;

    return 0;
}
```

---

### Atividade 4: Imposto de Renda
- Lê CPF em loop `while` (0 encerra), número de dependentes e renda anual. Calcula a renda líquida descontando R$300 por dependente e aplica a alíquota correspondente para determinar o imposto devido.

```c++
#include <iostream>
using namespace std;

int main() {
    long long cpf;
    int dependentes;
    float rendaAnual, rendaLiquida, imposto;

    cout << "=== Calculo de Imposto de Renda ===" << endl;
    cout << "Digite o CPF (0 para encerrar): ";
    cin >> cpf;

    while (cpf != 0) {
        cout << "Numero de dependentes: ";
        cin >> dependentes;
        cout << "Renda anual (R$): ";
        cin >> rendaAnual;

        rendaLiquida = rendaAnual - (dependentes * 300.0f);

        if (rendaLiquida <= 12000.0f) {
            imposto = 0.0f;
            cout << "\nSituacao: Isento de Imposto de Renda" << endl;
        } else if (rendaLiquida <= 25000.0f) {
            imposto = rendaLiquida * 0.12f;
            cout << "\nAliquota aplicada: 12%" << endl;
            cout << "Imposto devido: R$ " << imposto << endl;
        } else {
            imposto = rendaLiquida * 0.275f;
            cout << "\nAliquota aplicada: 27,5%" << endl;
            cout << "Imposto devido: R$ " << imposto << endl;
        }

        cout << "----------------------------------------" << endl;
        cout << "Digite o CPF (0 para encerrar): ";
        cin >> cpf;
    }

    cout << "\nPrograma encerrado." << endl;

    return 0;
}
```

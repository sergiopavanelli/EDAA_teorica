# UC: Estruturas de Dados e Análise de Algoritmos

## Título: Prática nº 01E – Atividade – EDA_1E – P3 - SALA
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

### Tema: Estruturas de Repetição – C++
### Objetivo: Introdução aos principais conceitos e motivação
### Roteiro: Formar grupos e desenvolver as atividades propostas.

---

## Entregas das atividades 1 a 5 solicitadas nas atividades em sala:

### Atividade 1: Estrutura Hora
- Cria uma estrutura `Hora` com os campos hora, minuto e segundo. Lê os valores do usuário e imprime os dados armazenados na tela.

```c++
#include <iostream>
using namespace std;

struct Hora {
    int hora;
    int minuto;
    int segundo;
};

int main() {
    Hora h;

    cout << "=== Cadastro de Hora ===" << endl;
    cout << "Digite a hora: ";
    cin >> h.hora;
    cout << "Digite o minuto: ";
    cin >> h.minuto;
    cout << "Digite o segundo: ";
    cin >> h.segundo;

    cout << "\n=== Hora Armazenada ===" << endl;
    cout << h.hora << ":" << h.minuto << ":" << h.segundo << endl;

    return 0;
}
```

---

### Atividade 2: Estrutura Endereço
- Cria uma estrutura `Endereco` com os campos nome da rua, número, cidade, estado e CEP. Lê os valores do usuário e imprime os dados na tela.

```c++
#include <iostream>
#include <string>
using namespace std;

struct Endereco {
    string rua;
    int numero;
    string cidade;
    string estado;
    string cep;
};

int main() {
    Endereco end;

    cout << "=== Cadastro de Endereco ===" << endl;
    cout << "Nome da rua: ";
    getline(cin, end.rua);
    cout << "Numero: ";
    cin >> end.numero;
    cin.ignore();
    cout << "Cidade: ";
    getline(cin, end.cidade);
    cout << "Estado: ";
    getline(cin, end.estado);
    cout << "CEP: ";
    getline(cin, end.cep);

    cout << "\n=== Endereco Armazenado ===" << endl;
    cout << "Rua: " << end.rua << ", " << end.numero << endl;
    cout << "Cidade: " << end.cidade << " - " << end.estado << endl;
    cout << "CEP: " << end.cep << endl;

    return 0;
}
```

---

### Atividade 3: Estrutura Pessoa (com Data e Endereço)
- Cria uma estrutura `Pessoa` com os campos nome, sexo, peso, data de nascimento e endereço. Reutiliza a estrutura `Endereco` da atividade anterior e cria uma nova estrutura `Data` para a data de nascimento.

```c++
#include <iostream>
#include <string>
using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Endereco {
    string rua;
    int numero;
    string cidade;
    string estado;
    string cep;
};

struct Pessoa {
    string nome;
    char sexo;
    float peso;
    Data nascimento;
    Endereco endereco;
};

int main() {
    Pessoa p;

    cout << "=== Cadastro de Pessoa ===" << endl;
    cout << "Nome: ";
    getline(cin, p.nome);
    cout << "Sexo (M/F): ";
    cin >> p.sexo;
    cout << "Peso (kg): ";
    cin >> p.peso;

    cout << "\n--- Data de Nascimento ---" << endl;
    cout << "Dia: ";
    cin >> p.nascimento.dia;
    cout << "Mes: ";
    cin >> p.nascimento.mes;
    cout << "Ano: ";
    cin >> p.nascimento.ano;

    cin.ignore();
    cout << "\n--- Endereco ---" << endl;
    cout << "Nome da rua: ";
    getline(cin, p.endereco.rua);
    cout << "Numero: ";
    cin >> p.endereco.numero;
    cin.ignore();
    cout << "Cidade: ";
    getline(cin, p.endereco.cidade);
    cout << "Estado: ";
    getline(cin, p.endereco.estado);
    cout << "CEP: ";
    getline(cin, p.endereco.cep);

    cout << "\n=== Dados da Pessoa ===" << endl;
    cout << "Nome: " << p.nome << endl;
    cout << "Sexo: " << p.sexo << endl;
    cout << "Peso: " << p.peso << " kg" << endl;
    cout << "Data de Nascimento: " << p.nascimento.dia << "/"
         << p.nascimento.mes << "/" << p.nascimento.ano << endl;
    cout << "Endereco: " << p.endereco.rua << ", " << p.endereco.numero << endl;
    cout << "Cidade: " << p.endereco.cidade << " - " << p.endereco.estado << endl;
    cout << "CEP: " << p.endereco.cep << endl;

    return 0;
}
```

---

### Atividade 4: Cadastro de Computadores
- Cria uma estrutura `Computador` com marca, ano de fabricação e peso. Realiza o cadastro de 3 computadores e imprime as informações de cada um na tela.

```c++
#include <iostream>
#include <string>
using namespace std;

struct Computador {
    string marca;
    int anoFabricacao;
    float peso;
};

int main() {
    Computador computadores[3];

    // Cadastro dos 3 computadores
    for (int i = 0; i < 3; i++) {
        cout << "=== Computador " << i + 1 << " ===" << endl;
        cout << "Marca: ";
        cin.ignore();
        getline(cin, computadores[i].marca);
        cout << "Ano de fabricacao: ";
        cin >> computadores[i].anoFabricacao;
        cout << "Peso (kg): ";
        cin >> computadores[i].peso;
        cout << endl;
    }

    // Impressao dos dados
    cout << "\n=== Computadores Cadastrados ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nComputador " << i + 1 << ":" << endl;
        cout << "  Marca: " << computadores[i].marca << endl;
        cout << "  Ano de fabricacao: " << computadores[i].anoFabricacao << endl;
        cout << "  Peso: " << computadores[i].peso << " kg" << endl;
    }

    return 0;
}
```

---

### Atividade 5: Cadastro de Alunos com Análise de Notas (Busca Ativa)
- Cria uma estrutura representando alunos com matrícula, nome e três notas de provas. Cadastra 5 alunos e realiza as seguintes análises: maior nota da primeira prova, maior e menor média geral, e situação de aprovação (média >= 6).

```c++
#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    string matricula;
    string nome;
    float nota1;
    float nota2;
    float nota3;
};

int main() {
    Aluno alunos[5];
    float medias[5];

    // a) Entrada de dados de 5 alunos
    for (int i = 0; i < 5; i++) {
        cout << "=== Aluno " << i + 1 << " ===" << endl;
        cout << "Matricula: ";
        cin.ignore();
        getline(cin, alunos[i].matricula);
        cout << "Nome: ";
        getline(cin, alunos[i].nome);
        cout << "Nota da 1a prova: ";
        cin >> alunos[i].nota1;
        cout << "Nota da 2a prova: ";
        cin >> alunos[i].nota2;
        cout << "Nota da 3a prova: ";
        cin >> alunos[i].nota3;
        cout << endl;

        medias[i] = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0;
    }

    // b) Aluno com maior nota da primeira prova
    int idxMaiorNota1 = 0;
    for (int i = 1; i < 5; i++) {
        if (alunos[i].nota1 > alunos[idxMaiorNota1].nota1) {
            idxMaiorNota1 = i;
        }
    }

    // c) Aluno com maior media geral
    int idxMaiorMedia = 0;
    for (int i = 1; i < 5; i++) {
        if (medias[i] > medias[idxMaiorMedia]) {
            idxMaiorMedia = i;
        }
    }

    // d) Aluno com menor media geral
    int idxMenorMedia = 0;
    for (int i = 1; i < 5; i++) {
        if (medias[i] < medias[idxMenorMedia]) {
            idxMenorMedia = i;
        }
    }

    // Impressao dos resultados
    cout << "\n========================================" << endl;
    cout << "           RESULTADOS" << endl;
    cout << "========================================" << endl;

    cout << "\nb) Aluno com maior nota na 1a prova:" << endl;
    cout << "   " << alunos[idxMaiorNota1].nome
         << " (Nota: " << alunos[idxMaiorNota1].nota1 << ")" << endl;

    cout << "\nc) Aluno com maior media geral:" << endl;
    cout << "   " << alunos[idxMaiorMedia].nome
         << " (Media: " << medias[idxMaiorMedia] << ")" << endl;

    cout << "\nd) Aluno com menor media geral:" << endl;
    cout << "   " << alunos[idxMenorMedia].nome
         << " (Media: " << medias[idxMenorMedia] << ")" << endl;

    // e) Situacao de cada aluno
    cout << "\ne) Situacao dos alunos (media >= 6 para aprovacao):" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "   " << alunos[i].nome
             << " - Media: " << medias[i];
        if (medias[i] >= 6.0) {
            cout << " -> APROVADO" << endl;
        } else {
            cout << " -> REPROVADO" << endl;
        }
    }
    cout << "========================================" << endl;

    return 0;
}
```

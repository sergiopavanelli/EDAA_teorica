# 🎯 Simulado A2 (Objetiva): Leitura de Código e Pegadinhas Clássicas

**Foco:** Preparação para a Avaliação A2 (Questões de Múltipla Escolha)  
**Objetivo:** Treinar o olhar para armadilhas comuns em testes de mesa, análise assintótica e comportamento de estruturas de dados.  

---

## 🛑 Instruções
Leia atentamente o código ou o cenário proposto. Tente escolher a alternativa correta antes de ler a resolução (Gabarito Comentado) logo abaixo de cada questão.

---

### Questão 01: A Armadilha do Loop Duplo (Complexidade)
Analise o pseudo-código abaixo:

    n = tamanho(vetor)
    Para i de 1 ate n:
        j = 1
        Enquanto j < n:
            imprimir(vetor[i] + vetor[j])
            j = j * 2

Qual é a complexidade de tempo no pior caso na notação Big-O?
* a) O(n^2)
* b) O(n)
* c) O(n log n)
* d) O(log n)
* e) O(2^n)

**Gabarito Comentado: Alternativa C**
*Pegadinha Clássica:* É tentador ver um loop dentro do outro e marcar `O(n^2)`. Porém, observe o incremento do loop interno: `j = j * 2`. Como a variável `j` dobra de valor a cada iteração, ela atinge o limite `n` muito rápido, em tempo logarítmico. O loop externo roda `n` vezes e o interno roda `log n` vezes. Multiplicando ambos, temos `O(n log n)`.

---

### Questão 02: O Vazamento da Lista Encadeada (Ponteiros)
Considere uma Lista Simplesmente Encadeada e o seguinte pseudo-código para tentar remover o primeiro elemento (o nó `Cabeca` ou `Head`):

    Funcao RemoverInicio(Cabeca):
        Se Cabeca == NULO: retornar
        NoTemporario = Cabeca
        Cabeca = Cabeca.proximo
        // Fim da funcao

Em linguagens sem Coletor de Lixo automático (como C e C++), qual o principal erro lógico e de engenharia deste código?
* a) Ele gera um erro de compilação por atribuição inválida.
* b) Ele entra em loop infinito.
* c) Ele causa um Memory Leak (Vazamento de Memória).
* d) Ele remove o segundo elemento em vez do primeiro.

**Gabarito Comentado: Alternativa C**
*Pegadinha Clássica:* O ponteiro `Cabeca` foi atualizado com sucesso para o segundo elemento, logo, para a lógica da lista, o primeiro item "sumiu". Contudo, o espaço na memória (`NoTemporario`) nunca foi desalocado usando o comando `free()` ou `delete`. Esse pedaço de memória fica "preso" para sempre (Memory Leak), o que pode travar o sistema com o tempo.

---

### Questão 03: Árvore Binária de Busca - Inserção Cega
Dada uma Árvore Binária de Busca (BST) vazia, os seguintes números são inseridos EXATAMENTE nesta ordem: `10, 20, 30, 40, 50`. 
Qual será a complexidade teórica para buscar o número 50 logo em seguida?
* a) O(1)
* b) O(log n)
* c) O(n)
* d) O(n log n)

**Gabarito Comentado: Alternativa C**
*Pegadinha Clássica:* Sabemos que a busca em uma BST é, idealmente, `O(log n)`. Porém, como os números inseridos estão todos em ordem crescente, eles serão adicionados todos à direita do nó anterior. A árvore não criará galhos para a esquerda; ela se degenerará em uma "linha reta" (uma lista encadeada disfarçada de árvore). Para achar o 50, o algoritmo terá que passar por todos os `n` nós anteriores. A resposta correta é `O(n)`. Para evitar isso, usamos Árvores AVL (balanceadas).

---

### Questão 04: Estado Oculto da Pilha
Considere uma Pilha P inicialmente vazia. Uma string `T-E-N-E-T` é lida caractere por caractere. 
- Se a letra for uma vogal, fazemos um `Push` dela na Pilha P. 
- Se a letra for uma consoante, fazemos um `Pop` na Pilha P (se não estiver vazia) e ignoramos a consoante lida.
Ao final da leitura da palavra, qual é o estado da Pilha P (do topo para a base)?
* a) T, N, T
* b) E, E
* c) T, E, N, E, T
* d) A Pilha termina vazia.

**Gabarito Comentado: Alternativa D**
*Pegadinha Clássica:* Teste de mesa mental.
1. 'T' (Consoante): Pilha vazia, Pop ignorado. Pilha: `[]`
2. 'E' (Vogal): Push('E'). Pilha: `['E']`
3. 'N' (Consoante): Pop(). Remove 'E'. Pilha: `[]`
4. 'E' (Vogal): Push('E'). Pilha: `['E']`
5. 'T' (Consoante): Pop(). Remove 'E'. Pilha: `[]`
O estado final é uma pilha vazia.

---

### Questão 05: Fila Circular e Módulo Matemática
Em uma implementação de Fila Circular usando um vetor de 5 posições (índices de 0 a 4), os ponteiros `Inicio` e `Fim` estão ambos apontando para o índice 4. A Fila contém apenas 1 elemento no momento.
Se fizermos a operação `Enqueue("Z")` (inserir no final), qual será o novo valor aritmético do ponteiro `Fim`?
* a) 5
* b) 0
* c) 4
* d) Ocorrerá um erro de Overflow, pois 4 é o último índice.

**Gabarito Comentado: Alternativa B**
*Pegadinha Clássica:* Em uma Fila Circular, não esbarramos na "parede" do vetor se o começo estiver vazio. O cálculo do próximo índice é feito pela fórmula `Fim = (Fim + 1) % Tamanho`. Ou seja, `(4 + 1) % 5 = 5 % 5 = 0`. O ponteiro `Fim` "dá a volta" e aponta para o índice 0.

---

### Questão 06: Grafos - A Aresta Perdida
Um grafo possui 5 vértices. Sua Matriz de Adjacência é composta apenas por 0s e 1s. Ao somar TODOS os números presentes dentro dessa Matriz, o resultado foi 12. 
Se o grafo não for direcionado (uma rua de mão dupla), quantas Arestas existem de fato nesse grafo?
* a) 12 arestas
* b) 24 arestas
* c) 6 arestas
* d) 5 arestas

**Gabarito Comentado: Alternativa C**
*Pegadinha Clássica:* Em uma Matriz de Adjacência de um grafo *não-direcionado*, as conexões são simétricas. Se o vértice A se conecta com o vértice B, haverá um `1` na posição (A,B) e outro `1` espelhado na posição (B,A). Portanto, a soma total dos números na matriz (12) representa o dobro do número real de arestas. Dividindo por 2, descobrimos que existem 6 arestas.

---

### Questão 07: Recursão Assassina
Considere a seguinte função recursiva:

    Funcao Calcule(n):
        Se n == 0: 
            retorna 1
        Retorna n + Calcule(n - 2)

O que acontecerá se você fizer a chamada `Calcule(5)`?
* a) Retornará 9.
* b) Retornará 10.
* c) Retornará 1.
* d) Ocorrerá um Stack Overflow (estouro de pilha).

**Gabarito Comentado: Alternativa D**
*Pegadinha Clássica:* Falha na Condição de Parada (Caso Base). A chamada começa com `n=5`. As subtrações serão `5 -> 3 -> 1 -> -1 -> -3...` Como o código pula de 2 em 2, ele "pula" a condição de parada `n == 0` e continuará rodando para os números negativos infinitamente, até esgotar a memória da Pilha de Chamadas do sistema operacional.
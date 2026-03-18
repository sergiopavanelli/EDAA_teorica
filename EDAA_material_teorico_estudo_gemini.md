# 📚 Guia Teórico Completo: Estruturas de Dados e Análise de Algoritmos

**Carga Horária:** 160h | **Semestre:** 2026/1
**Objetivo da Disciplina:** Capacitar o estudante a projetar, implementar e analisar o desempenho de estruturas de dados e algoritmos complexos, escolhendo a solução computacional mais eficiente para cada classe de problema.

---

## 🧮 Módulo 1: Fundamentos Matemáticos e Lógicos

A base de qualquer algoritmo eficiente reside na matemática discreta e na lógica estruturada. Sem elas, é impossível calcular a complexidade ou otimizar instruções em nível de máquina.

### 1.1 Sistemas Numéricos e Escovação de Bits
Computadores operam em transistores (ligado/desligado). Compreender a base numérica é vital para otimização de memória.
* **Binário (Base 2):** Representado por 0s e 1s. Operações de deslocamento de bits (Bitwise Shift) são extremamente rápidas. Deslocar os bits de um número para a esquerda (Left Shift `<<`) multiplica o valor por 2 em uma única instrução de CPU. Deslocar para a direita (Right Shift `>>`) divide por 2.
* **Hexadecimal (Base 16):** Agrupa 4 bits (um *nibble*) em um único caractere (0-9, A-F). Essencial para depuração de memória (ex: analisar ponteiros nulos ou falhas de segmentação) pois torna endereços binários longos legíveis para humanos.

### 1.2 Lógica Booleana e Operadores Bit a Bit (Bitwise)
Além dos operadores lógicos tradicionais usados em condicionais, a manipulação bit a bit permite algoritmos ultrarrápidos (como em Criptografia e Tabelas Hash):
* **AND (`&`):** Retorna 1 se ambos os bits forem 1. Usado para "mascarar" bits indesejados.
* **OR (`|`):** Retorna 1 se pelo menos um for 1. Usado para "ligar" flags específicas.
* **XOR (`^`):** Retorna 1 se os bits forem diferentes. Propriedade mágica: `A ^ A = 0` e `A ^ 0 = A`. Muito usado para encontrar elementos únicos em arrays sem usar memória extra.

### 1.3 Prova por Indução Matemática
A indução é a ferramenta matemática usada para provar a corretude de algoritmos recursivos e calcular somatórias de loops. Funciona como o "efeito dominó":
1. **Caso Base:** Provamos que a propriedade é verdadeira para o menor valor possível (ex: n = 1).
2. **Hipótese Indutiva:** Assumimos que é verdadeira para um valor arbitrário `k`.
3. **Passo Indutivo:** Usando a matemática, provamos que, se é verdade para `k`, obrigatoriamente tem que ser verdade para `k + 1`. Se provarmos isso, está provado para todos os números.

---

## ⏱️ Módulo 2: Análise de Desempenho e Notação Assintótica

Como julgar se um algoritmo é eficiente? Não podemos medir em segundos, pois um PC gamer rodaria mais rápido que um celular antigo. Medimos em **número de operações em função do tamanho da entrada (n)**.

### 2.1 O Espectro Assintótico (Big-O, Omega, Theta)
* **Big-O (O):** Representa o **Pior Caso** (Limite Superior). É o que mais importa. Se o algoritmo rodar nas piores condições possíveis, quão ruim ele pode ser?
* **Big-Omega (Ω):** Representa o **Melhor Caso** (Limite Inferior). Se os dados já vierem perfeitos (ex: ordenar uma lista que já está ordenada).
* **Big-Theta (Θ):** Ocorre quando o melhor e o pior caso têm a mesma taxa de crescimento (Limite Restrito). 

### 2.2 Classes de Complexidade de Tempo (Do Melhor ao Pior)
1. **O(1) - Constante:** O tempo é o mesmo seja para 10 ou 10 milhões de itens. (Ex: Acessar array por índice, inserção em Tabela Hash perfeita).
2. **O(log n) - Logarítmico:** O algoritmo descarta metade dos dados a cada iteração. Crescimento lentíssimo, altamente desejável. (Ex: Busca Binária, Busca em Árvore AVL).
3. **O(n) - Linear:** O tempo cresce em proporção 1:1 com os dados. (Ex: Busca sequencial em lista não ordenada).
4. **O(n log n) - Linearítmico:** O limite ótimo para algoritmos de ordenação baseados em comparação. (Ex: Merge Sort, Quick Sort).
5. **O(n^2) - Quadrático:** Um loop dentro do outro. O desempenho degrada rapidamente. (Ex: Bubble Sort, Insertion Sort).
6. **O(2^n) - Exponencial:** Força bruta que tenta todas as combinações. Inviável para entradas maiores que 40. (Ex: Quebra de senhas burra, Fibonacci recursivo sem otimização).

### 2.3 Problemas P vs NP
* **Classe P:** Problemas que podem ser **resolvidos** em tempo polinomial (rápido).
* **Classe NP:** Problemas cujas soluções podem ser **verificadas** em tempo polinomial, mas não sabemos se podem ser resolvidas rápido.
* **NP-Completo:** O núcleo duro da computação. Se você achar um algoritmo classe P para um problema NP-Completo (ex: Caixeiro Viajante, Problema da Mochila), você prova que P = NP e ganha 1 milhão de dólares do Instituto Clay.

---

## 📦 Módulo 3: Tipos Abstratos de Dados (TAD) e Estruturas Lineares

Um TAD é um modelo matemático. Ele diz "uma Pilha deve empilhar e desempilhar". A Estrutura de Dados é como escrevemos isso no código (usando Arrays ou Ponteiros).

### 3.1 Arrays vs Listas Encadeadas (O Grande Dilema)
* **Arrays (Alocação Sequencial):** * *Memória:* O sistema operacional reserva um bloco único de memória.
  * *Vantagem:* Localidade de cache (a CPU lê tudo super rápido) e acesso O(1).
  * *Desvantagem:* Tamanho fixo. Inserir no meio custa O(n) porque exige deslocar todos os vizinhos para o lado.
* **Listas Encadeadas (Alocação Dinâmica):**
  * *Memória:* Cada item (Nó) fica em um lugar aleatório da memória, guardando um ponteiro (endereço) para o próximo.
  * *Vantagem:* Cresce infinitamente. Inserir no meio custa O(1) se você já tiver o ponteiro daquele local.
  * *Desvantagem:* Acesso lento O(n). Para chegar no elemento 50, tem que passar pelos 49 anteriores. Gasta mais memória (por causa dos ponteiros).

### 3.2 Pilhas (Stacks) e Suas Aplicações
* **Conceito:** LIFO (Last-In, First-Out). O último elemento empilhado é o único que pode ser removido.
* **Operações:** `Push` (Inserir no topo) e `Pop` (Remover do topo). Ambas O(1).
* **Mecânica Real:** A pilha de chamadas (Call Stack) do seu processador usa essa estrutura. Toda vez que uma função chama outra, o estado atual é feito um "Push" na memória. Se a recursão for infinita, ocorre o famoso erro *Stack Overflow* (estouro da pilha).

### 3.3 Filas (Queues)
* **Conceito:** FIFO (First-In, First-Out). O primeiro a chegar é o primeiro a ser atendido.
* **Variações Avançadas:**
  * **Fila Circular:** Conecta o último elemento de volta ao primeiro (usando Arrays) para não desperdiçar espaço de memória quando itens são removidos do início.
  * **Deque (Double-Ended Queue):** Permite inserir e remover tanto pelo início quanto pelo fim.

---

## 🌳 Módulo 4: Estruturas Não-Lineares Hierárquicas

Quando dados chegam a milhões de registros, arrays e listas quebram. Precisamos de árvores para dividir o espaço de busca.

### 4.1 Árvores Binárias de Busca (BST)
* **Anatomia:** Cada Nó tem, no máximo, dois ponteiros (Esquerda e Direita).
* **A Regra de Ouro:** Tudo na sub-árvore esquerda deve ser MENOR que o pai. Tudo na sub-árvore direita deve ser MAIOR.
* **O Problema da Degeneração:** Se você inserir números já em ordem (1, 2, 3, 4, 5), a árvore vira uma linha reta para a direita. A busca que deveria ser O(log n) vira O(n).

### 4.2 Árvores Balanceadas (AVL e Árvore-B)
Para evitar a degeneração, criaram-se árvores que se auto-regulam.
* **Árvore AVL:** O algoritmo calcula a diferença de altura entre o lado esquerdo e direito. Se a diferença passar de 1, ele executa "Rotações" (movendo os nós para cima e para baixo) para reequilibrar a estrutura perfeitamente.
* **Árvore B (B-Trees):** Estruturas massivas onde cada nó pode ter múltiplos filhos e armazenar vários valores ao mesmo tempo. É a estrutura base de **Sistemas de Arquivos (NTFS, ext4)** e **Bancos de Dados Relacionais (MySQL, PostgreSQL)**, pois minimiza a quantidade de leituras no disco rígido.

### 4.3 Heaps (Árvores de Prioridade)
* Diferente da BST, a regra aqui é vertical: No **Max-Heap**, o nó Pai tem que ser obrigatoriamente maior que seus filhos. Não importa a relação esquerda/direita.
* Garante que o maior valor do sistema esteja sempre na raiz, acessível em tempo O(1).
* **Aplicações:** Algoritmo de roteamento de redes, agendador de tarefas do Sistema Operacional.

---

## 🔑 Módulo 5: Tabelas Hash (Dicionários/Mapas)

O objetivo da Tabela Hash é encontrar qualquer dado instantaneamente, com complexidade O(1).

* **A Função Hash:** Uma fórmula matemática que recebe uma Chave (ex: "Maria") e cospe um número inteiro (ex: 42). Esse número é usado como o índice do array onde os dados da Maria serão guardados.
* **O Problema da Colisão:** E se a função calcular o número 42 para "Maria" e também para "João"? Isso é uma colisão.
* **Resoluções de Colisão:**
  1. **Encadeamento (Chaining):** No índice 42, criamos uma Lista Encadeada. Guardamos Maria e João lá. Na hora de buscar, vamos no índice 42 e procuramos na listinha.
  2. **Sondagem Linear:** Se o 42 está ocupado, o algoritmo tenta o 43. Se estiver ocupado, tenta o 44. (Gera blocos aglomerados de memória).
* **Fator de Carga e Rehashing:** Se a tabela encher demais (ex: 70% de ocupação), as colisões disparam e o desempenho cai para O(n). O sistema pausa, cria um array com o dobro do tamanho e recalcula o Hash de todo mundo (*Rehashing*).

---

## 🕸️ Módulo 6: Teoria dos Grafos

Grafos são redes matemáticas compostas por **Vértices** (Nós) conectados por **Arestas** (Linhas).

### 6.1 Representação na Memória
* **Matriz de Adjacência:** Uma matriz bidimensional V x V. Excelente para ver rapidamente se A conecta com B (O(1)). Mas desperdiça muita memória (O(V^2)) se o grafo for "esparso" (poucas conexões).
* **Lista de Adjacência:** Cada vértice tem uma lista dos seus vizinhos. Economiza muita memória e é o padrão da indústria para mapas e redes sociais.

### 6.2 Travessia de Grafos (Buscas)
* **Busca em Profundidade (DFS):** Usa Pilha (ou Recursão). Explora um caminho até o fim (beco sem saída) antes de voltar. Usado para detectar ciclos ou resolver labirintos.
* **Busca em Largura (BFS):** Usa Fila. Explora todos os vizinhos diretos, depois os vizinhos dos vizinhos. Garante encontrar o caminho mais curto em grafos sem "pesos" nas arestas.

### 6.3 Algoritmos Clássicos de Otimização
* **Caminho Mínimo (Dijkstra):** Encontra a rota mais barata em um grafo ponderado (com pesos positivos). Base do Google Maps. Usa uma Fila de Prioridade (Min-Heap) para escolher sempre o próximo passo mais barato.
* **Árvores Geradoras Mínimas (Kruskal e Prim):** Remove arestas redundantes de uma rede até que todos os pontos estejam conectados pelo menor custo global possível. (Ex: Planejar a fiação elétrica de um bairro).

---

## 🧠 Módulo 7: Paradigmas de Projeto (Estratégias de Solução)

Como arquitetar algoritmos para problemas complexos?

### 7.1 Divisão e Conquista
Quebra o problema iterativamente pela metade até chegar a um problema trivial (ex: um array de 1 elemento). Resolve esse problema e depois combina as respostas. 
* **Exemplo - Merge Sort:** Divide um array de 8 elementos em dois de 4, quatro de 2, oito de 1. Depois junta (merge) as metades organizando os valores. Tem complexidade O(n log n) rigorosamente estável.

### 7.2 Programação Dinâmica (Dynamic Programming - DP)
Resolve problemas que têm "Subproblemas Sobrepostos".
* Ao calcular a sequência de Fibonacci recursivamente, o computador calcula o valor de Fib(3) dezenas de vezes.
* **Solução DP (Memoization):** Toda vez que calcular algo novo, guarde o resultado em um Array ou Hash. Se precisar de novo, puxe da memória em O(1) em vez de recalcular. Transforma um tempo O(2^n) terrível em O(n) rápido.

### 7.3 Algoritmos Gulosos (Greedy Algorithms)
A cada passo, toma a decisão que parece ser a melhor localmente, torcendo para que isso leve à melhor solução global. 
* **Vantagem:** Muito rápidos.
* **Desvantagem:** Nem sempre acham a solução perfeita.
* **Exemplo - Troco de Moedas:** Se você precisa dar 85 centavos de troco, o algoritmo guloso sempre pegará a maior moeda possível primeiro (50, depois 25, depois 10).

### 7.4 Heurísticas e Meta-Heurísticas
Usadas quando esbarramos na barreira dos problemas NP-Completos e não podemos esperar bilhões de anos pela solução perfeita.
* Algoritmos Genéticos, Simulated Annealing e Colônia de Formigas. Eles "chutam" soluções iniciais e vão refinando e misturando as melhores iterativamente, entregando uma resposta "ótima na medida do possível" em poucos minutos.

---

## 📌 Sistema de Avaliação (Lembrete)
* **A1 (30 pts):** Prova Discursiva. Foco em explicar os conceitos teóricos detalhados acima (Expressão e domínio técnico).
* **A2 (30 pts):** Prova Objetiva. Foco em testes de mesa, interpretação de código e análise de complexidade.
* **A3 (40 pts):** Projeto Prático. Onde você vai colocar a mão no código para implementar essas estruturas (geralmente em C, C++, Java ou Python).
* *Aprovação:* Mínimo de 70 pontos somados + 75% de presença (se presencial).
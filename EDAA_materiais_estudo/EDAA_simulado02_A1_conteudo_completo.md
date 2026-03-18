# 📝 Simulado A1 (Discursiva) - Parte 02: Cobertura Completa da Ementa

Este simulado testa o domínio dos módulos avançados da disciplina: Matemática Computacional, Complexidade, Árvores, Grafos, Hash e Paradigmas de Algoritmos.

---

## 1. Fundamentos Matemáticos: Sistemas e Lógica
**Enunciado:** A computação em baixo nível exige o domínio de bases numéricas e lógica booleana.
* **a)** Explique por que o sistema Hexadecimal é amplamente utilizado na computação, mesmo o processador operando apenas em Binário.
* **b)** Considere a operação lógica `XOR` (Ou Exclusivo) entre dois bits. Qual é a propriedade matemática que torna o `XOR` extremamente útil para encontrar elementos únicos em um array sem usar espaço extra de memória?

**Proposta de Resolução:**
* **a)** O Hexadecimal (base 16) é usado por ser uma forma extremamente compacta e legível de representar números binários longos. Exatamente 4 bits (um *nibble*) correspondem a exatamente 1 dígito hexadecimal (0-F). Isso facilita a vida dos programadores ao ler endereços de memória, cores e instruções de máquina, reduzindo erros de leitura.
* **b)** A propriedade fundamental do `XOR` (`^`) é que um número submetido ao `XOR` por ele mesmo resulta em zero ($A \oplus A = 0$), e um número submetido ao `XOR` por zero resulta nele mesmo ($A \oplus 0 = A$). Além disso, a ordem não importa. Portanto, se fizermos o `XOR` de todos os elementos de um array onde todos os números aparecem em pares, exceto um, os pares se anularão (virando 0), e o resultado final da operação será exatamente o elemento único que sobrou.

---

### 2. Indução Matemática e Recursão
**Enunciado:** Existe uma ligação direta entre a técnica de Prova por Indução Matemática e a construção de Algoritmos Recursivos.
* **a)** Quais são os dois passos fundamentais de uma prova por indução matemática?
* **b)** Como esses dois passos se traduzem na estrutura obrigatória de uma função recursiva?

**Proposta de Resolução:**
* **a)** Os dois passos são: 1) **Caso Base:** Provar que a afirmação é verdadeira para o primeiro elemento (geralmente $n = 0$ ou $n = 1$). 2) **Passo Indutivo:** Assumir que é verdadeira para um número arbitrário $k$ (Hipótese de Indução) e, com base nisso, provar que obrigatoriamente é verdadeira para $k + 1$.
* **b)** Na programação, isso se traduz perfeitamente: O "Caso Base" da indução torna-se a **Condição de Parada** da recursão (o momento em que a função para de chamar a si mesma e retorna um valor fixo, evitando o *Stack Overflow*). O "Passo Indutivo" torna-se a **Chamada Recursiva**, onde a função chama a si mesma com um subproblema menor ($n - 1$), assumindo que a chamada menor fará o trabalho corretamente.

---

### 3. Análise Assintótica (Notação Big-O)
**Enunciado:** Avalie o desempenho teórico de algoritmos usando a notação Big-O.
* **a)** Dado um algoritmo que possui dois loops `for` independentes (um após o outro) iterando $n$ vezes, e outro algoritmo com dois loops `for` aninhados (um dentro do outro) iterando $n$ vezes. Quais são as complexidades de tempo de cada um?
* **b)** Por que a constante é ignorada na notação Big-O (ex: $O(2n)$ vira $O(n)$)?

**Proposta de Resolução:**
* **a)** O algoritmo com loops independentes tem complexidade $O(n + n)$, que simplifica para **$O(n)$** (Linear). O algoritmo com loops aninhados executa o loop interno $n$ vezes para cada iteração do loop externo, resultando em complexidade **$O(n^2)$** (Quadrática).
* **b)** A notação Big-O analisa a *taxa de crescimento* do algoritmo quando a entrada $n$ tende ao infinito. Para valores massivos de $n$, termos constantes ou coeficientes multiplicativos tornam-se insignificantes na curva de crescimento em comparação com a ordem de grandeza dominante (a potência de $n$).

---

### 4. Algoritmos de Ordenação e Busca
**Enunciado:** Compare abordagens de manipulação de vetores.
* **a)** Qual é a precondição absoluta para que a Busca Binária possa ser aplicada em um array? Qual a sua complexidade de pior caso?
* **b)** Explique por que o algoritmo de ordenação *Merge Sort* é preferível ao *Bubble Sort* para grandes volumes de dados.

**Proposta de Resolução:**
* **a)** A precondição é que o array esteja **previamente ordenado**. Sua complexidade de pior caso é **$O(\log n)$**, pois o algoritmo divide o espaço de busca pela metade a cada iteração.
* **b)** O *Bubble Sort* compara e troca elementos adjacentes repetidamente, possuindo complexidade de pior e médio caso de $O(n^2)$, o que é catastrófico para arrays muito grandes. O *Merge Sort* utiliza o paradigma Divisão e Conquista, quebrando o array pela metade repetidamente e depois mesclando de forma ordenada. Ele garante uma complexidade matemática rígida de **$O(n \log n)$** no pior caso, tornando-o infinitamente mais rápido e escalável para grandes massas de dados.

---

### 5. Tabelas Hash
**Enunciado:** Tabelas Hash visam buscas em tempo $O(1)$.
* **a)** O que é uma "colisão" em uma Tabela Hash?
* **b)** Diferencie a técnica de tratamento de colisão por "Encadeamento" (Chaining) da técnica de "Sondagem Linear" (Linear Probing).

**Proposta de Resolução:**
* **a)** Uma colisão ocorre quando a Função Hash calcula o mesmo índice (endereço) de memória para duas chaves diferentes (ex: "Ana" e "Bia" geram o mesmo índice 5).
* **b)** No **Encadeamento**, cada posição do vetor da Hash não guarda o dado diretamente, mas sim um ponteiro para uma Lista Encadeada. Se houver colisão, o novo dado é apenas adicionado ao final dessa lista. Na **Sondagem Linear** (Endereçamento Aberto), todos os dados ficam no próprio vetor principal. Se o índice 5 já estiver ocupado, o algoritmo examina o próximo índice sequencialmente (6, 7, 8...) até encontrar um slot vazio para inserir o dado.

---

### 6. Árvores Binárias vs. Heaps
**Enunciado:** Embora sejam desenhadas da mesma forma, Árvores Binárias de Busca (BST) e Heaps têm propósitos distintos.
* **a)** Qual é a regra de organização estrutural de uma Árvore Binária de Busca?
* **b)** Qual é a regra de organização de um Max-Heap e para qual aplicação principal ele é usado?

**Proposta de Resolução:**
* **a)** Na BST, a regra é horizontal (relacional entre irmãos): Para qualquer nó pai, todos os valores na sua sub-árvore **esquerda** devem ser estritamente menores que ele, e todos os valores na sub-árvore **direita** devem ser maiores.
* **b)** No Max-Heap, a regra é vertical (hierárquica): O valor de **qualquer nó pai deve ser maior ou igual** ao valor de seus filhos (não importa qual filho seja maior entre si). A principal aplicação do Max-Heap é a implementação de **Filas de Prioridade**, garantindo que o maior/mais importante elemento seja sempre acessado e removido em tempo $O(1)$ na raiz.

---

### 7. Estruturas em Grafos
**Enunciado:** Grafos modelam redes complexas.
* **a)** No contexto de alocação de memória, quando é mais vantajoso usar uma Matriz de Adjacência e quando é melhor usar uma Lista de Adjacência?
* **b)** Qual estrutura de dados auxiliar é utilizada para gerenciar a fronteira de exploração do algoritmo de Busca em Largura (BFS)?

**Proposta de Resolução:**
* **a)** A **Matriz de Adjacência** é vantajosa para grafos "densos" (onde quase todos os vértices se conectam a todos), pois permite verificar a existência de uma aresta em tempo $O(1)$. No entanto, gasta memória $O(V^2)$. A **Lista de Adjacência** é melhor para grafos "esparsos" (poucas conexões, como redes sociais), pois aloca memória proporcional apenas ao número de arestas reais, economizando espaço drasticamente.
* **b)** A Busca em Largura (BFS) utiliza uma **Fila (Queue)**. Isso garante que todos os vértices que estão a uma distância $k$ do início sejam visitados antes de qualquer vértice a uma distância $k+1$, obedecendo ao princípio FIFO (primeiro a entrar, primeiro a sair).

---

### 8. Algoritmos em Grafos (Otimização)
**Enunciado:** Explique os casos de uso dos algoritmos clássicos de grafos.
* **a)** Qual é o objetivo do Algoritmo de Dijkstra e qual é a restrição sobre os pesos das arestas para que ele funcione corretamente?
* **b)** Explique o que é uma Árvore Geradora Mínima (MST) gerada por algoritmos como Kruskal ou Prim.

**Proposta de Resolução:**
* **a)** O Algoritmo de Dijkstra serve para encontrar o **caminho de custo mínimo** a partir de um vértice de origem para todos os outros vértices do grafo. A restrição fundamental é que o grafo **não pode conter arestas com pesos negativos**, pois o algoritmo é guloso e pressupõe que, uma vez que o caminho mais curto para um nó é encontrado, adicionar mais arestas só aumentará o custo total.
* **b)** Uma Árvore Geradora Mínima (MST) é um subgrafo que conecta **todos** os vértices de um grafo conexo e não-direcionado, sem formar nenhum ciclo, e cuja **soma dos pesos das arestas é a menor possível**. É amplamente usada em problemas de design de redes (telecomunicações, estradas, fiação elétrica).

---

### 9. Paradigmas de Projeto de Algoritmos
**Enunciado:** Compare Programação Dinâmica e Algoritmos Gulosos.
* **a)** Qual a principal característica matemática de um problema que nos permite aplicar a Programação Dinâmica de forma eficaz?
* **b)** Por que um Algoritmo Guloso nem sempre produz a solução ótima global?

**Proposta de Resolução:**
* **a)** A característica principal é a presença de **Subproblemas Sobrepostos**. Ou seja, a solução recursiva ingênua calcularia a mesma coisa diversas vezes (como na sequência de Fibonacci). A Programação Dinâmica salva esses resultados intermediários em uma tabela (técnica de *Memoization*), garantindo que cada subproblema seja calculado apenas uma vez.
* **b)** O Algoritmo Guloso toma a decisão que parece ser a melhor localmente, no exato momento da escolha, sem projetar os cenários futuros. Em problemas complexos, essa miopia pode levar a um caminho onde uma "economia" imediata force um "gasto" enorme mais à frente, resultando em uma solução subótima global.

---

### 10. Teoria da Computação e Classes de Complexidade
**Enunciado:** O limite do que pode ser resolvido por computadores.
* **a)** Qual a diferença conceitual entre um problema da Classe P e um problema da Classe NP?
* **b)** O Problema do Caixeiro Viajante é um clássico problema NP-Completo. Na prática, o que os engenheiros de software fazem hoje quando precisam resolver um problema NP-Completo para o qual não existe solução rápida conhecida?

**Proposta de Resolução:**
* **a)** Problemas da **Classe P** podem ser **resolvidos** eficientemente (em tempo polinomial) por um computador determinístico. Problemas da **Classe NP** são aqueles em que, se alguém fornecer uma resposta pronta, o computador consegue **verificar** se a resposta está certa rapidamente (em tempo polinomial), mas não se sabe se é possível *encontrar* essa resposta rapidamente partindo do zero.
* **b)** Como os problemas NP-Completos (como o Caixeiro Viajante para muitas cidades) exigiriam força bruta com complexidade fatorial $O(n!)$, demorando milênios para processar, os engenheiros desistem de encontrar a solução *perfeita*. Em vez disso, utilizam **Heurísticas e Algoritmos de Aproximação** (como algoritmos genéticos ou *simulated annealing*), que encontram uma solução "boa o suficiente" e muito próxima do ideal em um tempo aceitável (segundos ou minutos).
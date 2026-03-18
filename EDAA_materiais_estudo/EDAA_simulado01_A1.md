# 📝 Simulado A1 (Discursiva): Pilhas vs Filas e Estruturas Lineares

Este simulado contém 10 tipologias clássicas de questões discursivas de nível universitário. Use as resoluções como gabarito de estudo.

---

## 1. Questão Conceitual e Comparativa
**Enunciado:** Explique a diferença fundamental entre as políticas de acesso de uma Pilha (Stack) e de uma Fila (Queue). Para cada estrutura, cite um exemplo clássico de aplicação no mundo real ou na computação.

**Proposta de Resolução:**
A diferença fundamental reside na ordem em que os elementos são inseridos e removidos. 
* A **Pilha** obedece à política **LIFO** (*Last-In, First-Out*), onde o último elemento adicionado é obrigatoriamente o primeiro a ser removido. As operações (Push e Pop) ocorrem em apenas uma extremidade (o Topo). *Exemplo de aplicação:* O mecanismo de "Desfazer" (Ctrl+Z) de editores de texto ou a Pilha de Chamadas (Call Stack) de funções no processador.
* A **Fila** obedece à política **FIFO** (*First-In, First-Out*), onde o primeiro elemento adicionado é o primeiro a ser removido. A inserção ocorre no final (Rear/Tail) e a remoção ocorre no início (Front/Head). *Exemplo de aplicação:* Um *spooler* de impressão, onde os documentos são impressos na exata ordem em que foram solicitados, ou filas de requisições em servidores web.

---

### 2. Questão de Teste de Mesa (Rastreamento de Estado)
**Enunciado:** Considere uma Pilha $P$ e uma Fila $F$, ambas inicialmente vazias. Execute a seguinte sequência de operações exata. Após o término, diga qual elemento está no Topo da Pilha e qual elemento está no Início da Fila.
1. `P.push(10)`
2. `P.push(20)`
3. `F.enqueue( P.pop() )`
4. `F.enqueue(30)`
5. `P.push( F.dequeue() )`
6. `P.push(40)`
7. `F.enqueue( P.pop() )`

**Proposta de Resolução:**
Vamos rastrear o estado de cada estrutura passo a passo:
1. `P.push(10)` $\rightarrow$ Pilha: `[10]` | Fila: `[]`
2. `P.push(20)` $\rightarrow$ Pilha: `[10, 20]` (Topo é 20) | Fila: `[]`
3. `F.enqueue( P.pop() )` $\rightarrow$ Remove 20 da Pilha e insere na Fila. Pilha: `[10]` | Fila: `[20]`
4. `F.enqueue(30)` $\rightarrow$ Pilha: `[10]` | Fila: `[20, 30]`
5. `P.push( F.dequeue() )` $\rightarrow$ Remove 20 da Fila e insere na Pilha. Pilha: `[10, 20]` | Fila: `[30]`
6. `P.push(40)` $\rightarrow$ Pilha: `[10, 20, 40]` | Fila: `[30]`
7. `F.enqueue( P.pop() )` $\rightarrow$ Remove 40 da Pilha e insere na Fila. Pilha: `[10, 20]` | Fila: `[30, 40]`

**Resposta Final:** O elemento no Topo da Pilha é **20**. O elemento no Início da Fila é **30**.

---

### 3. Questão de Design e Engenharia (Duas Pilhas = Uma Fila)
**Enunciado:** Em uma entrevista técnica, pedem para você implementar uma estrutura de Fila (com operações `enqueue` e `dequeue`) utilizando estritamente **duas Pilhas** (`P1` e `P2`). Descreva a lógica de como você implementaria as operações de inserção e remoção para garantir o comportamento FIFO.

**Proposta de Resolução:**
Para simular uma Fila com duas Pilhas, usamos `P1` para entrada de dados e `P2` para saída.
* **Enqueue (Inserir):** Sempre realizamos um simples `Push` na `P1`. Complexidade $O(1)$.
* **Dequeue (Remover):** Como a Pilha inverte a ordem, precisamos desinverter. Se `P2` estiver vazia, fazemos um `Pop` de todos os elementos de `P1` e damos um `Push` de cada um em `P2`. Isso inverte a ordem de LIFO para FIFO. O elemento a ser removido agora estará perfeitamente no topo de `P2` (sendo o mais antigo inserido). Fazemos um `Pop` de `P2` e o retornamos.
* *Nota de desempenho:* Embora o pior caso do `Dequeue` seja $O(n)$ (quando transfere de P1 para P2), o custo "amortizado" ao longo de várias operações permanece $O(1)$.

---

### 4. Questão de Análise de Complexidade (Arrays vs Ponteiros)
**Enunciado:** Discuta as diferenças de complexidade de tempo $O(n)$ e uso de memória ao implementar uma **Fila** utilizando um Vetor (Array contíguo) tradicional versus uma Lista Simplesmente Encadeada (com ponteiros de início e fim). 

**Proposta de Resolução:**
* **Fila com Array Tradicional:**
    * *Inserção (Enqueue):* $O(1)$, basta adicionar no próximo índice livre.
    * *Remoção (Dequeue):* $O(n)$ no pior caso. Se removermos o índice 0, todos os outros $n$ elementos precisam ser movidos uma casa para a esquerda para preencher o buraco, o que é ineficiente. (Exceto se usarmos um Array Circular).
    * *Memória:* Tamanho fixo. Pode desperdiçar memória se alocado a mais, ou dar erro de limite (*Overflow*) se encher.
* **Fila com Lista Encadeada:**
    * *Inserção (Enqueue):* $O(1)$, basta alocar um novo Nó e fazer o ponteiro `Fim` apontar para ele.
    * *Remoção (Dequeue):* $O(1)$, basta atualizar o ponteiro `Inicio` para apontar para `Inicio.proximo` e desalocar o nó antigo.
    * *Memória:* Dinâmica, cresce conforme a necessidade. Porém, gasta mais bytes por elemento devido ao armazenamento do ponteiro para o próximo nó.

---

### 5. Questão de Estruturas Otimizadas (Fila Circular)
**Enunciado:** Explique o problema da "Falsa Falta de Espaço" que ocorre na implementação estática de uma Fila (usando vetores). Como a abordagem lógica da "Fila Circular" resolve este problema matematicamente?

**Proposta de Resolução:**
O problema da *Falsa Falta de Espaço* ocorre em Filas alocadas em vetores simples quando inserimos e removemos elementos sucessivamente. O ponteiro de "Início" e "Fim" caminham para o final do vetor. Chegará um momento em que o ponteiro "Fim" alcançará o limite máximo do vetor, impedindo novas inserções, mesmo que o início do vetor (índices 0, 1, 2...) esteja totalmente vazio devido às remoções anteriores.
A **Fila Circular** resolve isso interligando o fim do vetor ao seu início. Matematicamente, isso é feito usando o operador de módulo (resto da divisão): `Fim = (Fim + 1) % Tamanho_Maximo`. Assim, se o `Tamanho_Maximo` for 10, ao tentar avançar o ponteiro `Fim` do índice 9, o cálculo `(9 + 1) % 10` resulta em `0`, fazendo o ponteiro "dar a volta" e reaproveitar os espaços vazios do começo em tempo $O(1)$.

---

### 6. Questão de Casos Limites (Tratamento de Exceções)
**Enunciado:** Defina os conceitos de *Overflow* e *Underflow* no contexto de Pilhas limitadas por memória estática. O que acontece se essas condições não forem tratadas em código de produção?

**Proposta de Resolução:**
* **Overflow (Transbordamento):** Ocorre quando tenta-se executar um `Push` em uma Pilha que já atingiu a sua capacidade máxima de elementos. Se não for tratado, o programa tentará escrever em uma área de memória não autorizada, causando sobreposição de dados essenciais ou um *Segmentation Fault* (travamento fatal do programa).
* **Underflow (Sub-fluxo):** Ocorre quando tenta-se executar um `Pop` ou tentar acessar o `Topo` de uma Pilha que está completamente vazia. Sem tratamento, a lógica acessará "lixo de memória" ou causará um erro de ponteiro nulo, retornando valores imprevisíveis ao usuário ou derrubando a aplicação. Um código robusto sempre verifica `if (!isEmpty())` antes de remover.

---

### 7. Questão de Arquitetura de Software (Cenário Inadequado)
**Enunciado:** Um engenheiro de software júnior propôs usar uma estrutura de Pilha para armazenar as transações bancárias pendentes de clientes que aguardam aprovação no servidor. Discorra sobre as implicações funcionais (e éticas) dessa escolha arquitetural.

**Proposta de Resolução:**
A escolha é arquiteturalmente desastrosa e eticamente questionável em um sistema financeiro. Como a Pilha segue a regra LIFO (Último a Entrar, Primeiro a Sair), os clientes que fizeram as transações *mais recentemente* seriam aprovados primeiro. 
Um cliente que fez a transação logo cedo (ficando no fundo da pilha) sofreria de um problema grave conhecido na computação como **Inanição (Starvation)**. Enquanto novos pedidos continuarem chegando e sendo empilhados, o pedido antigo nunca será processado, contrariando a expectativa básica de justiça temporal em sistemas de atendimento. A estrutura correta para garantir justiça (ordem de chegada) é, sem dúvida, a **Fila (FIFO)**.

---

### 8. Questão Teórica: O Sistema Operacional e a Recursão
**Enunciado:** Por que algoritmos recursivos estão intimamente ligados ao conceito de Pilhas? Explique o funcionamento da "Pilha de Execução" (Call Stack).

**Proposta de Resolução:**
Toda recursão depende de uma Pilha em nível de Sistema Operacional (a *Call Stack*) para funcionar. Quando uma função chama a si mesma, a execução atual precisa ser "pausada". O Sistema Operacional empilha (Push) o estado atual dessa função (suas variáveis locais e a linha de código onde parou) na Call Stack e inicia a nova execução no topo.
Isso se repete até que a condição de parada (Caso Base) seja atingida. A partir daí, o sistema começa a desempilhar (Pop), retomando a execução de onde parou e multiplicando ou somando os retornos de baixo para cima. É por isso que uma recursão sem condição de parada causa o erro *Stack Overflow* (estouro da pilha de chamadas).

---

### 9. Questão de Desempenho e Aplicação Múltipla
**Enunciado:** O aplicativo do seu banco exibe o seu extrato de forma que a transação mais recente apareça no topo da tela. Porém, para processar as transações na central, elas precisam ser executadas na ordem em que ocorreram. Como você pode conciliar esses dois requisitos lógicos?

**Proposta de Resolução:**
O sistema backend deve receber as transações em uma **Fila (FIFO)** para garantir o processamento correto e justo (ordem temporal de acontecimento). Quando a transação é processada e consolidada no banco de dados do cliente, a Interface de Usuário (Front-end) pode recuperar essas informações e exibi-las empilhadas em uma **Pilha (LIFO)**. Assim, ao carregar os dados na tela do celular, as transações mais recentes darão um "Push" por cima das mais antigas, resultando na exibição cronológica inversa (do evento mais novo para o mais velho) que o usuário espera ler.

---

### 10. Questão de Extensão de Estrutura (O Deque)
**Enunciado:** Defina a estrutura de dados *Deque* (Double-Ended Queue). Cite em qual cenário essa estrutura híbrida supera as limitações exclusivas de uma Pilha ou de uma Fila tradicional.

**Proposta de Resolução:**
Um **Deque** é uma "Fila de Duas Pontas", uma estrutura linear que permite inserções e remoções genéricas em **ambas as extremidades** (tanto no Início quanto no Fim), todas em complexidade de tempo $O(1)$. 
Ele supera a Pilha e a Fila em cenários onde precisamos de flexibilidade total sem sacrificar desempenho. Um cenário clássico é o histórico de abas recentes de um navegador: usamos o Deque como Pilha para o comportamento de "voltar página" (LIFO), mas precisamos da característica de Fila no final da estrutura para apagar automaticamente o histórico mais antigo quando o limite máximo de abas armazenadas é atingido, algo que uma Pilha tradicional não consegue fazer eficientemente na base (fundo da pilha).
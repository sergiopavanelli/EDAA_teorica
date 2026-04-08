# 📚 Guia de Estudo — Aula 06: TADs Lineares

> **Para quem é este guia?** Cada exercício é explicado com: o *problema*, a *ideia central*, o *passo a passo* do algoritmo, as *armadilhas comuns* e a *análise de complexidade detalhada*.

---

## 🗂️ Índice

| Grupo | Exercícios |
|-------|-----------|
| [🧱 Grupo 1 — Vec e Operações Básicas](#-grupo-1--vec-e-operações-básicas) | 1 a 4 |
| [📚 Grupo 2 — Pilha (Stack)](#-grupo-2--pilha-stack) | 5 a 9 |
| [🚶 Grupo 3 — Fila (Queue)](#-grupo-3--fila-queue) | 10 a 13 |
| [↔️ Grupo 4 — Deque](#️-grupo-4--deque-double-ended-queue) | 14 a 16 |
| [🧠 Grupo 5 — Reflexão e Análise](#-grupo-5--reflexão-e-análise) | 17 a 20 |

---

## 🧱 Grupo 1 — Vec e Operações Básicas

---

### 🔁 Exercício 1 — Inversão com Vec

**🎯 Problema:** Inverter um vetor sem usar `.reverse()` ou índices — apenas operações de pilha.

**💡 Ideia central:** Um `Vec` em Rust se comporta como uma pilha quando usamos apenas `push` e `pop`. `pop()` retira o *último* elemento. Se fizermos `pop` de tudo e `push` em outro vetor, a ordem é invertida automaticamente.

**🪜 Passo a passo:**
```
original = [1, 2, 3, 4, 5]
              topo da pilha ↑

pop() → 5   → invertido = [5]
pop() → 4   → invertido = [5, 4]
pop() → 3   → invertido = [5, 4, 3]
pop() → 2   → invertido = [5, 4, 3, 2]
pop() → 1   → invertido = [5, 4, 3, 2, 1]
original = []
```

**✅ Por que funciona?** O elemento que entrou *por último* sai *primeiro* (LIFO). Ao mover todos os elementos de uma pilha para outra, a ordem é espelhada.

**📊 Análise de complexidade:**
- Cada `pop()` é **O(1) amortizado** — o vetor não precisa deslocar elementos, só decrementa o tamanho.
- Cada `push()` é **O(1) amortizado** — pode haver realocação ocasional, mas é diluída.
- São **n pops + n pushes** → **O(n) tempo**.
- Usamos um vetor extra de tamanho n → **O(n) espaço**.

**⚠️ Armadilha comum:** Usar `remove(0)` ao invés de `pop()`. `remove(0)` remove o *primeiro* elemento e desloca todos os demais para a esquerda — isso é **O(n)** por chamada, resultando em **O(n²)** total.

---

### 📊 Exercício 2 — Contador de Ocorrências

**🎯 Problema:** Contar quantas vezes cada letra aparece em uma string, ignorando espaços.

**💡 Ideia central:** Usar um `HashMap<char, u32>` como tabela de frequências. Para cada caractere (exceto espaço), incrementamos o contador correspondente.

**🪜 Passo a passo:**
```
frase = "estrutura de dados"

Iteração:
  'e' → contagem['e'] = 1
  's' → contagem['s'] = 1
  't' → contagem['t'] = 1
  'r' → contagem['r'] = 1
  'u' → contagem['u'] = 1
  't' → contagem['t'] = 2
  'u' → contagem['u'] = 2
  'r' → contagem['r'] = 2
  'a' → contagem['a'] = 1
  ' ' → IGNORADO
  ...
```

**🔑 O que é `.entry().or_insert(0)`?**
É a forma idiomática em Rust de: "se a chave não existe, insira 0; depois retorne uma referência mutável ao valor":
```rust
*contagem.entry(*x).or_insert(0) += 1;
// Se 'a' não existe: insere 0, depois incrementa → 1
// Se 'a' já existe: retorna referência ao valor atual, incrementa
```

**📊 Análise de complexidade:**
- Iterar sobre n caracteres: **O(n)**
- Cada operação de hash: **O(1) amortizado**
- Total: **O(n) tempo · O(k) espaço** (k = letras distintas, no máximo 26)

---

### 🗑️ Exercício 3 — Remoção Condicional (sem `.retain()`)

**🎯 Problema:** Remover todos os números pares de um vetor.

**💡 Ideia central:** Criar um novo vetor coletando apenas os ímpares. Isso é mais eficiente do que remover in-place.

**❌ Por que não remover in-place com `remove(i)`?**

Considere `[1, 2, 3, 4, 5]`:
- Removemos índice 1 (valor 2) → todos os elementos da direita deslocam: **O(n)** por remoção.
- Com n/2 remoções: **O(n) × O(n/2) = O(n²)** total.

**✅ Abordagem O(n) com novo Vec:**
```
v = [1, 2, 3, 4, 5, 6, 7, 8]

  1 % 2 != 0 → true  → push(1)
  2 % 2 != 0 → false → ignora
  3 % 2 != 0 → true  → push(3)
  ...

resultado = [1, 3, 5, 7]
```

**⚖️ Trade-off:** Ganha em tempo (O(n) vs O(n²)), mas usa memória extra O(n).

> 💬 `.retain()` faz a mesma coisa internamente em O(n) sem alocar memória extra. O enunciado pede para não usá-lo — a resolução manual com novo Vec é a alternativa mais clara.

---

### 🔀 Exercício 4 — Mescla Ordenada

**🎯 Problema:** Dado dois vetores já ordenados, produzir um único vetor ordenado com todos os elementos.

**Versão simples — extend + sort — O((n+m) log(n+m)):**
```rust
resultado.extend_from_slice(a); // copia a — O(n)
resultado.extend_from_slice(b); // copia b — O(m)
resultado.sort();               // O((n+m) log(n+m))
```

**✅ Versão eficiente — mescla manual — O(n+m):**

Dois ponteiros, um em cada vetor, sempre pegando o menor:

```
a = [1, 3, 5, 7]     i = 0
b = [2, 4, 6, 8]     j = 0

① a[0]=1 ≤ b[0]=2 → push(1), i=1
② a[1]=3 > b[0]=2 → push(2), j=1
③ a[1]=3 ≤ b[1]=4 → push(3), i=2
④ a[2]=5 > b[1]=4 → push(4), j=2
⑤ a[2]=5 ≤ b[2]=6 → push(5), i=3
⑥ a[3]=7 > b[2]=6 → push(6), j=3
⑦ a[3]=7 ≤ b[3]=8 → push(7), i=4 → a acabou!
   Restante de b: push(8)

resultado = [1, 2, 3, 4, 5, 6, 7, 8] ✓
```

**📊 Por que é O(n+m)?** Em cada passo avançamos exatamente um ponteiro. Total de passos ≤ n+m.

---

## 📚 Grupo 2 — Pilha (Stack)

---

### 🧮 Exercício 5 — Calculadora RPN

**🎯 O que é RPN (Notação Polonesa Reversa)?**

Na notação RPN (pós-fixa), o operador vem *depois* dos operandos — elimina parênteses:

| Notação | Expressão |
|---------|-----------|
| Infix (comum) | `(3 + 4) * 2` |
| RPN (pós-fixa) | `3 4 + 2 *` |

**🪜 Algoritmo com pilha:**
```
Tokens: ["3", "4", "+", "2", "*"]

"3"  → número → push(3)         pilha: [3]
"4"  → número → push(4)         pilha: [3, 4]
"+"  → operador:
         b = pop() = 4
         a = pop() = 3
         push(3 + 4 = 7)        pilha: [7]
"2"  → número → push(2)         pilha: [7, 2]
"*"  → operador:
         b = pop() = 2
         a = pop() = 7
         push(7 * 2 = 14)       pilha: [14]

Resultado: pop() = 14 ✓
```

**⚠️ Atenção à ordem do pop:** Para `-` e `/` a ordem importa:
- 1º `pop()` → operando **b** (direito)
- 2º `pop()` → operando **a** (esquerdo)
- Resultado: `a op b`

**📊 Complexidade:** Cada token processado uma vez com O(1) → **O(n) total**.

---

### 🌐 Exercício 6 — Histórico de Navegação

**🎯 Problema:** Implementar botões voltar/avançar de um navegador.

**🏗️ Estrutura:** Duas pilhas + página atual:
```
historico_back   [google, rust-lang]  ← topo = página anterior
atual            "doc.rust-lang.org"
historico_forward []                  ← topo = próxima página
```

**🔄 Operação `visitar(url)`:**
```
Antes:  back=[google], atual=rust-lang, forward=[]
        ↓ visitando "doc.rust-lang"
1. atual → push em back
2. forward.clear()   ← nova navegação invalida o avanço!
3. atual = "doc.rust-lang"
Depois: back=[google, rust-lang], atual=doc.rust-lang, forward=[]
```

**⬅️ Operação `voltar()`:**
```
Antes:  back=[google, rust-lang], atual=doc.rust-lang, forward=[]
1. anterior = back.pop() → "rust-lang"
2. atual → forward.push()
3. atual = "rust-lang"
Depois: back=[google], atual=rust-lang, forward=[doc.rust-lang]
```

**➡️ Operação `avancar()`:** Simétrica — inverte os papéis de back e forward.

**📊 Complexidade:** Todas as operações **O(1)** — push/pop em Vec.

---

### ↩️ Exercício 7 — Desfazer/Refazer (Undo/Redo)

**🎯 Problema:** Implementar Ctrl+Z e Ctrl+Y para um editor de texto.

**🏗️ Estrutura:** `pilha_undo` guarda estados anteriores; `pilha_redo` guarda estados desfeitos.

**🔑 Invariante importante:** Toda nova ação (`digitar`) deve **limpar `pilha_redo`**. Isso evita o paradoxo de refazer algo sobrescrito por uma ação diferente.

**🪜 Passo a passo:**
```
digitar("Olá")       undo=[""],          atual="Olá",       redo=[]
digitar(", mundo")   undo=["", "Olá"],   atual="Olá, mundo",redo=[]
desfazer()           undo=[""],          atual="Olá",       redo=["Olá, mundo"]
refazer()            undo=["", "Olá"],   atual="Olá, mundo",redo=[]
```

> 💡 O estado salvo é sempre o estado *antes* da ação, não depois.

**📊 Complexidade:** O(1) amortizado para todas as operações (o `.clone()` é O(tamanho do texto), não O(n operações)).

---

### 🔍 Exercício 8 — Símbolos Balanceados

**🎯 Problema:** Verificar se parênteses/colchetes/chaves estão corretamente aninhados e fechados.

**🪜 Algoritmo:**
- Abertura `(`, `[`, `{` → **empilha**
- Fechamento `)`, `]`, `}` → **desempilha e verifica** se o topo corresponde
- No final → **pilha deve estar vazia**

**✅ Trace de `{[()]}`:**
```
'{' → push('{')      pilha: ['{']
'[' → push('[')      pilha: ['{', '[']
'(' → push('(')      pilha: ['{', '[', '(']
')' → pop()='(' == '(' → OK    pilha: ['{', '[']
']' → pop()='[' == '[' → OK    pilha: ['{']
'}' → pop()='{' == '{' → OK    pilha: []
Pilha vazia → ✅ BALANCEADO
```

**❌ Trace de `([)]`:**
```
'(' → push('(')      pilha: ['(']
'[' → push('[')      pilha: ['(', '[']
')' → pop()='[' ≠ '(' → ❌ INVÁLIDO
```

**⚠️ Casos de falha:**
1. Fechamento sem abertura → `pop()` retorna `None`
2. Tipo errado → `pop()` retorna símbolo diferente
3. Abertura sem fechamento → pilha não vazia ao final

**📊 Complexidade:** Um passe, operações O(1) → **O(n) tempo · O(n) espaço**.

---

### 🏆 Exercício 9 — Pilha com Mínimo (StackMin)

**🎯 Problema:** Pilha com `min()` em **O(1)** — sem percorrer todos os elementos.

**💡 Ideia:** Manter uma segunda pilha (`mins`) cujo topo é sempre o *mínimo atual*.

**📐 Invariante:** `mins[i]` = mínimo de todos os elementos em `data[0..=i]`.

**🪜 Trace:**
```
push(5)  data=[5]       mins=[5]       → min=5
push(3)  data=[5,3]     mins=[5,3]     → min=min(5,3)=3
push(7)  data=[5,3,7]   mins=[5,3,3]   → min=min(3,7)=3
push(2)  data=[5,3,7,2] mins=[5,3,3,2] → min=min(3,2)=2

min() → mins.last() = 2 ✓

pop()  data=[5,3,7]  mins=[5,3,3] → min()=3 ✓
pop()  data=[5,3]    mins=[5,3]   → min()=3 ✓
pop()  data=[5]      mins=[5]     → min()=5 ✓
```

**🔑 Por que funciona o pop?** Ao remover um elemento, removemos também seu mínimo correspondente de `mins`. O novo topo de `mins` é automaticamente o mínimo dos elementos restantes — porque foi calculado assim no push.

**📊 Complexidade:** O dobro de memória, mas todas as operações **O(1)**.

---

## 🚶 Grupo 3 — Fila (Queue)

---

### 🏦 Exercício 10 — Simulador de Fila de Banco

**🎯 Problema:** Simular atendimento de clientes com um único atendente, calculando o tempo de espera.

**🏗️ Lógica do simulador:**
- `tempo_atual` = relógio do atendente
- Se atendente livre e cliente ainda não chegou → `tempo_atual = chegada` (atendente espera)
- `espera = tempo_atual - chegada`
- Após atender: `tempo_atual += duracao`

**🪜 Trace dos primeiros clientes:**
```
Clientes: [(t=0, d=4), (t=2, d=3), (t=5, d=5)]

Cliente 1:  chegou=0, tempo_atual=0
  espera = 0 - 0 = 0 min
  tempo_atual após = 0 + 4 = 4

Cliente 2:  chegou=2, tempo_atual=4
  espera = 4 - 2 = 2 min  ← chegou em t=2, atendido em t=4
  tempo_atual após = 4 + 3 = 7

Cliente 3:  chegou=5, tempo_atual=7
  espera = 7 - 5 = 2 min
  tempo_atual após = 7 + 5 = 12
```

**💡 Atendente ocioso:** Se `tempo_atual < chegada`, o atendente esperou — `tempo_atual = chegada`.

---

### 🖨️ Exercício 11 — Impressora Compartilhada

**🎯 Problema:** Processar trabalhos de impressão em ordem de chegada (FIFO).

**❓ Por que Fila e não Pilha?** A impressora deve processar o trabalho que chegou *primeiro*, não o último.

**⚠️ Por que não usar `Vec` como fila?**

| Operação | Vec | VecDeque |
|----------|-----|----------|
| Enfileirar (final) | O(1) amort. | O(1) amort. |
| Desenfileirar (início) | **O(n)** ← desloca tudo! | **O(1)** ← buffer circular |

Com 1000 jobs: `Vec::remove(0)` → **O(n²)**. `VecDeque::pop_front()` → **O(n)**.

---

### 📡 Exercício 12 — Buffer Circular com Overwrite

**🎯 Problema:** Buffer de capacidade fixa que descarta a mensagem *mais antiga* ao ficar cheio.

**🔄 Comportamento (capacidade=3):**
```
enqueue("msg1") → [msg1]
enqueue("msg2") → [msg1, msg2]
enqueue("msg3") → [msg1, msg2, msg3] ← cheio!
enqueue("msg4") → ⚠️ pop_front() descarta "msg1"
                   [msg2, msg3, msg4]
```

**🏭 Aplicação real:** Logs de sistema, streams de eventos em tempo real — dados antigos perdem relevância e não vale bloquear o produtor.

**📊 Complexidade:** `pop_front()` e `push_back()` são ambas **O(1)** → buffer totalmente eficiente.

---

### 🎖️ Exercício 13 — Fila de Prioridade Manual

**🎯 Problema:** Fila onde o elemento de *maior prioridade* sai primeiro.

**🪜 Trace:**
```
enqueue("normal A",   prioridade=1)  → dados: [(A,1)]
enqueue("urgente",    prioridade=3)  → dados: [(A,1), (urgente,3)]
enqueue("normal B",   prioridade=1)  → dados: [(A,1), (urgente,3), (B,1)]
enqueue("importante", prioridade=2)  → dados: [(A,1), (urgente,3), (B,1), (imp,2)]

dequeue() → busca máximo: prioridade 3 → remove "urgente"
dequeue() → busca máximo: prioridade 2 → remove "importante"
dequeue() → busca máximo: prioridade 1 → remove "normal A" (mais antigo)
dequeue() → remove "normal B"

Saída: urgente → importante → normal A → normal B ✓
```

**📊 Complexidade:**
| Operação | Esta implementação | BinaryHeap (ideal) |
|----------|-------------------|-------------------|
| enqueue | O(1) | O(log n) |
| dequeue | **O(n)** busca linear | **O(log n)** |
| n operações | **O(n²)** | **O(n log n)** |

**💡 Use `BinaryHeap` de Rust em produção!** A versão manual é apenas didática.

---

## ↔️ Grupo 4 — Deque (Double-Ended Queue)

---

### 🔤 Exercício 14 — Palíndromo com Deque

**🎯 Problema:** Verificar se uma string é palíndromo usando um Deque.

**💡 Por que Deque?** Um palíndromo se lê igual de frente para trás. Comparamos o primeiro e o último caractere simultaneamente, removendo das duas pontas.

**🪜 Trace:**
```
"racecar" → deque: ['r','a','c','e','c','a','r']

pop_front='r', pop_back='r'  → iguais ✓
pop_front='a', pop_back='a'  → iguais ✓
pop_front='c', pop_back='c'  → iguais ✓
sobrou ['e'] → len ≤ 1 → ✅ PALÍNDROMO

"hello" → deque: ['h','e','l','l','o']
pop_front='h', pop_back='o'  → diferentes ❌ NÃO É PALÍNDROMO
```

**🧹 Pré-processamento:** Filtra espaços e converte para minúsculo. Permite verificar: `"A man a plan a canal Panama"` → palíndromo ✅

**📊 Complexidade:** n/2 comparações com O(1) cada → **O(n) tempo · O(n) espaço**.

---

### 🪟 Exercício 15 — Janela Deslizante Máxima

**🎯 Problema:** Dado vetor e tamanho k, encontrar o máximo em cada janela de k elementos consecutivos.

**Exemplo:** `v=[1,3,-1,-3,5,3,6,7]`, k=3
```
Janelas:  [1,3,-1] [3,-1,-3] [-1,-3,5] [-3,5,3] [5,3,6] [3,6,7]
Máximos:      3        3          5         5       6       7
Resultado: [3, 3, 5, 5, 6, 7]
```

**⚠️ Abordagem ingênua O(n·k):** Para cada janela, percorrer k elementos → inaceitável.

**✅ Abordagem com Deque monotônico O(n):**

O Deque armazena *índices* e mantém: os valores correspondentes são **sempre decrescentes** (frente→fundo). O topo (front) é sempre o índice do máximo da janela atual.

```
i=0, v[0]=1:  deque=[] → push_back(0)          deque=[0]  (valores:[1])
i=1, v[1]=3:  v[0]=1 ≤ 3 → pop_back; push(1)  deque=[1]  (valores:[3])
              i+1=2 < k=3 → sem resultado
i=2, v[2]=-1: v[1]=3 > -1 → só push_back(2)   deque=[1,2] (valores:[3,-1])
              i+1=3 ≥ k → resultado.push(v[front=1]=3)  → [3]
i=3, v[3]=-3: v[2]=-1 > -3 → push_back(3)     deque=[1,2,3]
              resultado.push(v[1]=3)            → [3,3]
i=4, v[4]=5:  front=1, 1+3=4 ≤ 4 → pop_front!  deque=[2,3]
              v[3]=-3 ≤ 5 → pop_back; v[2]=-1 ≤ 5 → pop_back
              push_back(4)                       deque=[4] (valores:[5])
              resultado.push(v[4]=5)             → [3,3,5]
...
```

**🔑 Chave:** Um índice com valor menor que o atual nunca pode ser máximo enquanto o atual estiver na janela — pode ser descartado imediatamente.

**📊 Por que O(n)?** Cada índice entra uma vez (`push_back`) e sai uma vez (`pop_front` ou `pop_back`). Total de operações ≤ 2n → **O(n)**.

---

### ⚡ Exercício 16 — Fila de Tarefas com Prioridade de Frente

**🎯 Problema:** Fila de tarefas onde urgentes entram na frente e normais no final.

**💡 Por que Deque?** Precisamos inserir em *ambas* as pontas:

| Operação | Posição | Complexidade |
|----------|---------|-------------|
| Normal | `push_back` | O(1) |
| Urgente | `push_front` | O(1) |
| Processar | `pop_front` | O(1) |

**🪜 Trace:**
```
adicionar_normal("build")     deque: [build]
adicionar_normal("testes")    deque: [build, testes]
adicionar_urgente("bug")      deque: [bug, build, testes]
adicionar_urgente("hotfix")   deque: [hotfix, bug, build, testes]

processar() → "hotfix"
processar() → "bug"
processar() → "build"
processar() → "testes"
```

---

## 🧠 Grupo 5 — Reflexão e Análise

---

### ⚡ Exercício 17 — Comparação de Desempenho

**🎯 Objetivo:** Demonstrar empiricamente a diferença entre estruturas para uso como fila.

| Estrutura | enqueue | dequeue | Total (n ops) | Por quê? |
|-----------|---------|---------|---------------|---------|
| `Vec` com `remove(0)` | O(1) | ❌ **O(n)** | ❌ **O(n²)** | Desloca todos os elementos à esquerda |
| `VecDeque` | O(1) | ✅ **O(1)** | ✅ **O(n)** | Buffer circular — só move ponteiros |
| `FilaCircularArray` | O(1) | ✅ **O(1)** | ✅ **O(n)** | Aritmética de módulo |

**🔄 Como funciona o buffer circular:**
```
buf = [_, _, _, _, _]  cap=5  head=0  tail=0

enqueue(A): buf[0]=A, tail=1          → [A,_,_,_,_]
enqueue(B): buf[1]=B, tail=2          → [A,B,_,_,_]
dequeue():  val=buf[head=0]=A, head=1  → [_,B,_,_,_]
enqueue(C): buf[2]=C, tail=3
enqueue(D): buf[3]=D, tail=4
enqueue(E): buf[4]=E, tail=(4+1)%5=0 ← girou!
enqueue(F): buf[0]=F, tail=1  ← sobrescreve posição liberada!
```

**💡 O `% cap` faz o índice "circular"** — ao atingir o final, volta ao início sem mover nenhum elemento.

---

### 🤔 Exercício 18 — Quando Usar Qual TAD?

| Cenário | TAD | Raciocínio |
|---------|-----|-----------|
| **(a)** Ctrl+Z (Desfazer) | 📚 **Pilha** | A última ação é desfeita primeiro → LIFO perfeito |
| **(b)** Pedidos de restaurante | 🚶 **Fila** | Primeiro a chegar é primeiro atendido → FIFO |
| **(c)** Tags HTML bem formadas | 📚 **Pilha** | Tag mais recente deve fechar primeiro → LIFO |
| **(d)** BFS em diretório | 🚶 **Fila** | Explora nível a nível → enfileira vizinhos → FIFO |
| **(e)** Palíndromo de palavras | ↔️ **Deque** | Compara extremos em O(1) → precisa das duas pontas |

**🔑 Regra de ouro:**
- Precisa do **mais recente**? → **Pilha** (LIFO)
- Precisa do **mais antigo**? → **Fila** (FIFO)
- Precisa dos **dois extremos**? → **Deque**

---

### 📦 Exercício 19 — Fila com Iteração em Lotes

**🎯 Problema:** Processar uma fila em grupos de tamanho fixo.

**🪜 Trace (tamanho_lote=3):**
```
fila = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

Lote 1: pop_front × 3 → [1, 2, 3]      fila: [4..10]
Lote 2: pop_front × 3 → [4, 5, 6]      fila: [7..10]
Lote 3: pop_front × 3 → [7, 8, 9]      fila: [10]
Lote 4: pop_front × 1 → [10]           fila: vazia
```

**⚠️ Detalhe:** O laço interno usa `match fila.pop_front() { None => break }` para lidar corretamente com o último lote incompleto.

**🏭 Aplicação real:** Envio em batch de emails, processamento de eventos em grupos, pipelines de dados.

**📊 Complexidade:** Cada elemento processado uma vez → **O(n) total**.

---

### 🔄 Exercício 20 — Mini-projeto: Round Robin

**🎯 O que é Round Robin?** Algoritmo de escalonamento de processos de sistemas operacionais. Cada processo recebe um "quantum" de CPU. Se não terminar, volta para o fim da fila.

**✅ Características:**
- **Justo:** todos os processos recebem tempo de CPU ciclicamente
- **Preemptivo:** processo interrompido ao usar seu quantum
- **Implementado com Fila** (FIFO)

**🪜 Trace com quantum=3:**
```
Fila inicial: [P1(8), P2(4), P3(9), P4(5)]

t=0:  P1 executa 3s → restante=5 → volta ao fim    fila: [P2,P3,P4,P1(5)]
t=3:  P2 executa 3s → restante=1 → volta ao fim    fila: [P3,P4,P1,P2(1)]
t=6:  P3 executa 3s → restante=6 → volta ao fim    fila: [P4,P1,P2,P3(6)]
t=9:  P4 executa 3s → restante=2 → volta ao fim    fila: [P1,P2,P3,P4(2)]
t=12: P1 executa 3s → restante=2 → volta ao fim    fila: [P2,P3,P4,P1(2)]
t=15: P2 executa 1s → restante=0 → ✅ CONCLUÍDO   t=16
t=16: P3 executa 3s → restante=3 → volta          fila: [P4,P1,P3(3)]
t=19: P4 executa 2s → restante=0 → ✅ CONCLUÍDO   t=21
t=21: P1 executa 2s → restante=0 → ✅ CONCLUÍDO   t=23
t=23: P3 executa 3s → restante=0 → ✅ CONCLUÍDO   t=26
```

**❓ Por que Fila e não Pilha?** FIFO garante que todos os processos rodem ciclicamente. Com Pilha (LIFO), o processo mais recente sempre rodaria primeiro → starvation dos demais.

**📊 Complexidade:** **O(n · ⌈t_max/Q⌉)** — n processos, cada um executa no máximo `ceil(burst_time / quantum)` rodadas.

---

## 📋 Resumo dos TADs

### 📐 Vec — Array Dinâmico

| Operação | Complexidade | Notas |
|----------|-------------|-------|
| `push` (final) | O(1) amort. | Pode realocar |
| `pop` (final) | O(1) | |
| `insert(i, x)` | **O(n)** | Desloca à direita |
| `remove(i)` | **O(n)** | Desloca à esquerda |
| `get(i)` | O(1) | Acesso direto |

✅ **Use quando:** Acesso por índice O(1) e modificações predominantemente no final.

---

### 📚 Pilha (Stack via Vec)

| Operação | Complexidade |
|----------|-------------|
| `push` | O(1) amort. |
| `pop` | O(1) |
| `peek` | O(1) |

🔑 **Princípio:** LIFO — Last In, First Out.

✅ **Use quando:** Precisa de "memória" da última ação — desfazer, histórico, aninhamento, RPN.

---

### 🚶 Fila (Queue via VecDeque)

| Operação | Complexidade |
|----------|-------------|
| `push_back` | O(1) amort. |
| `pop_front` | O(1) |
| `peek_front` | O(1) |

🔑 **Princípio:** FIFO — First In, First Out.

✅ **Use quando:** Processamento em ordem de chegada — atendimento, BFS, impressora, buffer.

---

### ↔️ Deque (VecDeque)

| Operação | Complexidade |
|----------|-------------|
| `push_front` | O(1) amort. |
| `push_back` | O(1) amort. |
| `pop_front` | O(1) |
| `pop_back` | O(1) |

🔑 **Princípio:** Pilha + Fila — inserção e remoção em ambas as pontas.

✅ **Use quando:** Operações nos dois extremos — palíndromo, janela deslizante, prioridade de frente.

---

## 📊 Tabela de Complexidades — Visão Geral

| # | Exercício | ⏱️ Tempo | 💾 Espaço | 🏗️ TAD |
|---|-----------|--------|--------|--------|
| 1 | Inversão | O(n) | O(n) | Vec como Pilha |
| 2 | Contador de letras | O(n) | O(k) | Vec + HashMap |
| 3 | Remoção condicional | O(n) | O(n) | Vec |
| 4 | Mescla ordenada (manual) | O(n+m) | O(n+m) | Vec + 2 ponteiros |
| 5 | Calculadora RPN | O(n) | O(n) | Pilha |
| 6 | Histórico de navegação | O(1)/op | O(n) | 2 Pilhas |
| 7 | Desfazer/Refazer | O(1) amort. | O(n) | 2 Pilhas sincronizadas |
| 8 | Símbolos balanceados | O(n) | O(n) | Pilha |
| 9 | StackMin | O(1)/op | O(n) | 2 Pilhas sincronizadas |
| 10 | Simulador fila banco | O(n) | O(n) | Fila (VecDeque) |
| 11 | Impressora | O(n) | O(n) | Fila (VecDeque) |
| 12 | Buffer circular | O(1)/op | O(cap) | Fila com limite |
| 13 | Fila prioridade manual | enq O(1) · deq O(n) | O(n) | VecDeque + busca linear |
| 14 | Palíndromo | O(n) | O(n) | Deque |
| 15 | Janela deslizante máxima | O(n) | O(k) | Deque monotônico |
| 16 | Fila frente/fundo | O(1)/op | O(n) | Deque |
| 17 | Benchmark | — | — | Vec vs VecDeque vs Circular |
| 18 | Quando usar qual TAD | — | — | Análise conceitual |
| 19 | Processamento em lotes | O(n) | O(lote) | Fila (VecDeque) |
| 20 | Round Robin | O(n·⌈t/Q⌉) | O(n) | Fila (VecDeque) |

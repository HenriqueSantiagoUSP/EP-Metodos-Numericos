# EP — Métodos Numéricos

Exercício-Programa (EP) da disciplina de **Cálculo Numérico** do 3º semestre da **Universidade de São Paulo (USP)**.

O projeto é desenvolvido de forma incremental: a cada semana é proposta uma **tarefa** contendo funções de álgebra linear a serem implementadas e testadas. Ao final de todas as tarefas, as funções são integradas no programa principal (`src/ep.c`) para resolver o desafio proposto pela disciplina.

---

## Estrutura do Repositório

```
ep/
├── CMakeLists.txt          # Configuração do build (CMake)
├── README.md
├── include/                # Headers das funções
│   ├── ep_tarefa1.h        # Declarações — Tarefa 1
│   ├── ep_tarefa2.h        # Declarações — Tarefa 2
│   └── random.h            # Utilitários de geração aleatória
├── src/                    # Implementações
│   ├── ep.c                # Programa principal (desafio final)
│   ├── ep_tarefa1.c        # Implementação — Tarefa 1
│   ├── ep_tarefa2.c        # Implementação — Tarefa 2
│   └── random.c            # Geração aleatória de vetores e matrizes
├── tests/                  # Testes
│   ├── test_ep_tarefa1.c   # Testes — Tarefa 1
│   └── test_ep_tarefa2.c   # Testes — Tarefa 2
└── build/                  # Diretório de build (gerado pelo CMake)
```

---

## Funções Implementadas

### Tarefa 1 — Operações Básicas de Álgebra Linear

| Função | Descrição |
|---|---|
| `imprimir_matriz(M, N, A, nome)` | Imprime uma matriz M×N formatada |
| `imprimir_vetor(M, v, nome)` | Imprime um vetor de tamanho M |
| `produto_interno(M, u, v)` | Calcula o produto interno ⟨u, v⟩ |
| `norma(M, v)` | Calcula a norma euclidiana ‖v‖ |

### Tarefa 2 — Operações com Colunas e Multiplicação por Transposta

| Função | Descrição |
|---|---|
| `extrair_coluna(M, N, j, A, v)` | Extrai a coluna *j* da matriz A para o vetor v |
| `copiar_coluna(M, N, j, A, B)` | Copia a coluna *j* da matriz A para a matriz B |
| `multiplicacao_transposta_vetor(M, N, A, x, y)` | Calcula y = Aᵀ · x |

### Utilitários (`random.h`)

| Função | Descrição |
|---|---|
| `init_rand()` | Inicializa a semente do gerador aleatório |
| `rand_range(min, max)` | Gera um número aleatório no intervalo [min, max] |
| `gera_rand_vet(N, min, max)` | Gera um vetor de N elementos aleatórios |
| `gera_rand_matrix(M, N, min, max)` | Gera uma matriz M×N com elementos aleatórios |

---

## Dependências

| Dependência | Versão mínima | Descrição |
|---|---|---|
| **GCC** | 4.9+ | Compilador C com suporte a C99 (VLAs) |
| **CMake** | 3.10+ | Sistema de build |
| **Make** | — | Ferramenta de automação de build |
| **libm** | — | Biblioteca matemática padrão (linkada automaticamente) |


## Como Compilar

1. **Navegue até o diretório do projeto:**

```bash
cd /caminho/para/ep
```

2. **Crie e entre no diretório de build:**

```bash
mkdir -p build && cd build
```

3. **Gere os arquivos de build com o CMake:**

```bash
cmake ..
```

4. **Compile o projeto:**

```bash
make
```

Isso gerará três executáveis dentro de `build/`:

| Executável | Descrição |
|---|---|
| `ep` | Programa principal do EP |
| `test_ep_tarefa1` | Testes das funções da Tarefa 1 |
| `test_ep_tarefa2` | Testes das funções da Tarefa 2 |

---

## Como Executar

Após a compilação, a partir do diretório `build/`:

```bash
# Programa principal
./ep

# Testes da Tarefa 1
./test_ep_tarefa1

# Testes da Tarefa 2
./test_ep_tarefa2
```

Os testes utilizam dados gerados aleatoriamente para validar cada função, imprimindo os resultados na saída padrão para verificação manual.

---

## Padrão do Código

- **Linguagem:** C (padrão C99)
- **Build system:** CMake ≥ 3.10
- As funções fazem uso de **VLAs** (*Variable Length Arrays*), um recurso do C99
- A biblioteca matemática (`-lm`) é linkada para uso da função `sqrt()`

# EP — Métodos Numéricos

Exercício-Programa (EP) da disciplina de **Cálculo Numérico** do 3º semestre da **Universidade de São Paulo (USP)**.

O projeto é desenvolvido de forma incremental: a cada semana é proposta uma **tarefa** contendo funções de álgebra linear a serem implementadas e testadas. Na tarefa final (Tarefa 5), todas as funções são integradas para resolver o **desafio de posicionamento GPS por mínimos quadrados**, determinando a localização de um receptor na superfície terrestre a partir de dados de satélites.

---

## Estrutura do Repositório

```
ep/
├── CMakeLists.txt          # Configuração do build (CMake)
├── README.md
├── include/                # Headers das funções
│   ├── ep_tarefa1.h        # Declarações — Tarefa 1
│   ├── ep_tarefa2.h        # Declarações — Tarefa 2
│   ├── ep_tarefa3.h        # Declarações — Tarefa 3
│   ├── ep_tarefa4.h        # Declarações — Tarefa 4
│   ├── ep_tarefa5.h        # Declarações — Tarefa 5
│   └── random.h            # Utilitários de geração aleatória
├── src/                    # Implementações
│   ├── ep_tarefa1.c        # Implementação — Tarefa 1
│   ├── ep_tarefa2.c        # Implementação — Tarefa 2
│   ├── ep_tarefa3.c        # Implementação — Tarefa 3
│   ├── ep_tarefa4.c        # Implementação — Tarefa 4
│   ├── ep_tarefa5.c        # Implementação — Tarefa 5
│   └── random.c            # Geração aleatória de vetores e matrizes
├── tests/                  # Testes
│   ├── test_ep_tarefa1.c   # Testes — Tarefa 1
│   ├── test_ep_tarefa2.c   # Testes — Tarefa 2
│   ├── test_ep_tarefa3.c   # Testes — Tarefa 3
│   ├── test_ep_tarefa4.c   # Testes — Tarefa 4
│   └── test_ep_tarefa5.c   # Desafio final — Posicionamento GPS
├── resources/              # Dados de entrada
│   ├── input_gps_0.txt     # Coordenadas dos satélites (arquivo 0)
│   ├── input_gps_1.txt     # Coordenadas dos satélites (arquivo 1)
│   ├── input_gps_2.txt     # Coordenadas dos satélites (arquivo 2)
│   └── input_gps_3.txt     # Coordenadas dos satélites (arquivo 3)
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

### Tarefa 3 — Resolução de Sistemas Triangulares

| Função | Descrição |
|---|---|
| `resolver_sistema_triangular_superior(N, R, b, x)` | Resolve o sistema linear Rx = b por retrossubstituição, onde R é triangular superior |

### Tarefa 4 — Fatoração QR (Gram-Schmidt)

| Função | Descrição |
|---|---|
| `gram_schmidt(M, N, A, Q, R)` | Fatora a matriz A = QR via processo de Gram-Schmidt, onde Q tem colunas ortonormais e R é triangular superior |
| `multiplicar_QR(M, N, Q, R, resultado)` | Multiplica Q · R para verificação da fatoração (resultado ≈ A) |

### Tarefa 5 — Desafio Final: Posicionamento GPS

| Função | Descrição |
|---|---|
| `ler_dados(nusp, M, N, A)` | Lê o arquivo de coordenadas dos satélites GPS (selecionado por `nusp % 4`) |
| `geo_cords(x, lat, lon)` | Converte coordenadas cartesianas (x, y, z) em latitude e longitude (graus) |
| `multiplicar_matriz(M, N, J, A, B, ret)` | Multiplica duas matrizes: ret = A · B |
| `soma_matriz(op, M, N, A, B, ret)` | Soma (`SUM`) ou subtrai (`DIFF`) duas matrizes: ret = A ± B |

### Utilitários (`random.h`)

| Função | Descrição |
|---|---|
| `init_rand()` | Inicializa a semente do gerador aleatório |
| `rand_range(min, max)` | Gera um número aleatório no intervalo [min, max] |
| `gera_rand_vet(N, min, max)` | Gera um vetor de N elementos aleatórios |
| `gera_rand_matrix(M, N, min, max)` | Gera uma matriz M×N com elementos aleatórios |
| `gera_rand_mat_triangular(N, min, max)` | Gera uma matriz triangular superior N×N com elementos aleatórios |

---

## Dependências

| Dependência | Versão mínima | Plataforma | Descrição |
|---|---|---|---|
| **GCC** | 4.9+ | Linux / Windows (MinGW/MSYS2) | Compilador C com suporte a C99 (VLAs) |
| **MSVC** | 2019+ | Windows | Alternativa ao GCC no Windows (via Visual Studio) |
| **CMake** | 3.10+ | Linux / Windows | Sistema de build |
| **Make** | — | Linux / Windows (MSYS2) | Ferramenta de automação de build |
| **Ninja** | 1.10+ | Linux / Windows | Gerador alternativo, mais rápido que Make |
| **libm** | — | Linux | Biblioteca matemática padrão (linkada automaticamente) |

> **Windows:** no Windows, `libm` é parte do runtime C padrão e não precisa ser linkada separadamente.

---

## Como Compilar

### Linux

1. **Navegue até o diretório do projeto:**

```bash
cd /caminho/para/ep
```

2. **Crie e entre no diretório de build:**

```bash
mkdir -p build && cd build
```

3. **Gere os arquivos de build e compile:**

**Com Make (padrão):**
```bash
cmake ..
make
```

**Com Ninja:**
```bash
cmake -G Ninja ..
ninja
```

---

### Windows

No Windows, há duas abordagens principais:

#### Opção A — MSYS2 / MinGW-w64 (recomendado para ambiente Unix-like)

1. Instale o [MSYS2](https://www.msys2.org/) e, no terminal MSYS2, instale as dependências:

```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-make mingw-w64-x86_64-ninja
```

2. Navegue até o diretório do projeto e compile:

**Com Make:**
```bash
mkdir -p build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
```

**Com Ninja:**
```bash
mkdir -p build
cd build
cmake -G Ninja ..
ninja
```

#### Opção B — Visual Studio (MSVC)

1. Instale o [Visual Studio](https://visualstudio.microsoft.com/) com o componente **"Desenvolvimento para desktop com C++"** e o [CMake](https://cmake.org/download/).

2. Abra o **Developer Command Prompt** do Visual Studio e navegue até o projeto.

3. Compile:

**Com MSBuild (padrão do Visual Studio):**
```cmd
mkdir build
cd build
cmake ..
cmake --build .
```

**Com Ninja:**
```cmd
mkdir build
cd build
cmake -G Ninja ..
ninja
```

> **Nota:** o padrão C99 com VLAs é suportado pelo GCC/MinGW. No MSVC, o suporte a VLAs não é garantido — caso encontre erros de compilação, utilize a Opção A (MSYS2/MinGW).

---

## Executáveis Gerados

Após a compilação, os seguintes executáveis são gerados dentro de `build/`:

| Executável | Descrição |
|---|---|
| `test_ep_tarefa1` / `test_ep_tarefa1.exe` | Testes das funções da Tarefa 1 |
| `test_ep_tarefa2` / `test_ep_tarefa2.exe` | Testes das funções da Tarefa 2 |
| `test_ep_tarefa3` / `test_ep_tarefa3.exe` | Testes das funções da Tarefa 3 |
| `test_ep_tarefa4` / `test_ep_tarefa4.exe` | Testes das funções da Tarefa 4 |
| `test_ep_tarefa5` / `test_ep_tarefa5.exe` | **Desafio final** — Posicionamento GPS por mínimos quadrados |

---

## Como Executar

Após a compilação, a partir do diretório `build/`:

**Linux:**
```bash
# Testes individuais das tarefas
./test_ep_tarefa1
./test_ep_tarefa2
./test_ep_tarefa3
./test_ep_tarefa4

# Desafio final — Posicionamento GPS
./test_ep_tarefa5
```

**Windows:**
```cmd
test_ep_tarefa1.exe
test_ep_tarefa2.exe
test_ep_tarefa3.exe
test_ep_tarefa4.exe

REM Desafio final — Posicionamento GPS
test_ep_tarefa5.exe
```

Os testes das tarefas 1–4 utilizam dados gerados aleatoriamente para validar cada função, imprimindo os resultados na saída padrão para verificação manual.

O teste da **Tarefa 5** (`test_ep_tarefa5`) executa o desafio completo do EP:
1. Lê os dados dos satélites GPS a partir de `resources/`
2. Constrói o sistema sobredeterminado Ax = b
3. Resolve por mínimos quadrados via fatoração QR (Gram-Schmidt)
4. Calcula o raio terrestre para validação
5. Analisa os resíduos lineares e não-lineares
6. Determina o erro de sincronia do relógio (T = w/c)
7. Converte as coordenadas para latitude/longitude e identifica o estádio

---

## Padrão do Código

- **Linguagem:** C (padrão C99)
- **Build system:** CMake ≥ 3.10
- As funções fazem uso de **VLAs** (*Variable Length Arrays*), um recurso do C99
- A biblioteca matemática (`-lm`) é linkada no Linux; no Windows com MSVC ela é incluída automaticamente
- O caminho dos arquivos de entrada (`resources/`) é definido em tempo de compilação via `RESOURCES_DIR`
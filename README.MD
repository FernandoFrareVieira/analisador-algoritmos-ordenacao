# 📊 Analisador de Desempenho de Algoritmos de Ordenação em C

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)

## 📖 Sobre o Projeto

Este projeto é uma ferramenta desenvolvida em linguagem C para analisar e comparar o desempenho de alguns dos algoritmos de ordenação mais conhecidos. O programa gera um array de tamanho customizável com valores aleatórios e executa cada algoritmo de ordenação sobre o mesmo array desordenado, medindo o tempo de execução de cada um dos algoritmos.

O principal objetivo é demonstrar visualmente as diferenças de eficiência teóricas (expressas pela notação Big O) em um cenário prático.

## ✨ Funcionalidades

- **Implementação de Múltiplos Algoritmos:** Inclui algoritmos com complexidades de $O(n^2)$, $O(n \log n)$ e $O(n+k)$.
- **Análise de Desempenho:** Mede o tempo que cada algoritmo leva para ordenar o conjunto de dados.
- **Entrada do Usuário:** Permite que o usuário defina o tamanho do array a ser testado.
- **Comparação Justa:** Garante que todos os algoritmos sejam testados sob as mesmas condições, utilizando uma cópia idêntica do array desordenado original.

## 🚀 Algoritmos Implementados

| Algoritmo | Complexidade (Médio) | Complexidade (Pior Caso) | Espaço |
| :--- | :---: | :---: | :---: |
| **Bubble Sort** | $O(n^2)$ | $O(n^2)$ | $O(1)$ |
| **Selection Sort** | $O(n^2)$ | $O(n^2)$ | $O(1)$ |
| **Insertion Sort** | $O(n^2)$ | $O(n^2)$ | $O(1)$ |
| **Quick Sort** | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ |
| **Merge Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ |
| **Counting Sort** | $O(n+k)$ | $O(n+k)$ | $O(k)$ |

*Onde `n` é o número de elementos e `k` é o intervalo dos valores.*

## ⚙️ Como Executar

Para compilar e executar este projeto, você precisará de um compilador C, como o GCC.

1.  **Clone o repositório:**
    ```bash
    git clone https://github.com/FernandoFrareVieira/analisador-algoritmos-ordenacao.git
    cd analisador-algoritmos-ordenacao
    ```

2.  **Compile o arquivo:**
    ```bash
    gcc -o analisador main.c sorting.c
    ```
    *Se você separar os arquivos como sugerido abaixo, o comando será: `gcc -o analisador main.c sorting.c -WAll`*

3.  **Execute o programa:**
    ```bash
    ./analisador
    ```
    O programa solicitará que você digite o tamanho do array para o teste.

## 📈 Resultados de Desempenho

Os testes abaixo foram executados para ordenar um array de **50.000 elementos** com valores aleatórios.

| Algoritmo | Tempo de Execução (s) |
| :--- | :---: |
| Bubble Sort | 13.531000 |
| Selection Sort | 3.659000 |
| Insertion Sort | 2.156000 |
| Quick Sort | 0.007000 |
| Merge Sort | 0.031000 |
| Counting Sort | 0.001000 |

### Análise dos Resultados

Os resultados demonstram claramente a superioridade dos algoritmos mais eficientes:

-   Os algoritmos de complexidade quadrática ($O(n^2)$), como Bubble Sort, Selection Sort e Insertion Sort, são significativamente mais lentos e se tornam inviáveis para conjuntos de dados maiores.
-   Quick Sort e Merge Sort, com complexidade $O(n \log n)$, apresentam um desempenho ordens de magnitude melhor, sendo excelentes para casos de uso gerais.
-   O Counting Sort, um algoritmo não baseado em comparações, mostra-se o mais rápido de todos. Isso se deve à sua complexidade linear ($O(n+k)$), que é extremamente eficiente quando o intervalo de valores (`k`) não é muito maior que o número de elementos do vetor senndo ordenado.
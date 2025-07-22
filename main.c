#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"

#define MAX_VALOR 10000

void gerar_array_aleatorio(int *A, int n) {
    int i;
    for(i = 0; i < n; i++) {
        A[i] = rand() % (MAX_VALOR + 1);
    }
}

void copiar_array(int *origem, int *destino, int n) {
    int i;
    for(i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int n;
    
    srand(time(NULL)); 

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int *A = (int*)malloc(n * sizeof(int));
    int *A_copy = (int*)malloc(n * sizeof(int));
    int *O = (int*)malloc(n * sizeof(int));

    if(A == NULL || A_copy == NULL || O == NULL) {
        printf("Erro: Falha ao alocar memoria.\n");
        
        free(A);
        free(A_copy);
        free(O);
        return 1;
    }

    gerar_array_aleatorio(A, n);
    
    printf("\nIniciando testes com um array de %d elementos...\n", n);
    printf("--------------------------------------------------\n");
    printf("| Algoritmo          | Tempo de execucao (s)   |\n");
    printf("--------------------------------------------------\n");

    clock_t inicio, fim;
    double tempo_gasto;

    // --- Teste 1: Bubble Sort ---
    copiar_array(A, A_copy, n);
    inicio = clock();
    bubble(A_copy, n);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("| Bubble Sort        | %-23.6f |\n", tempo_gasto);

    // --- Teste 2: Selection Sort ---
    copiar_array(A, A_copy, n);
    inicio = clock();
    selection(A_copy, n);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("| Selection Sort     | %-23.6f |\n", tempo_gasto);

    // --- Teste 3: Insertion Sort ---
    copiar_array(A, A_copy, n);
    inicio = clock();
    insertion(A_copy, n);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("| Insertion Sort     | %-23.6f |\n", tempo_gasto);
    
    // --- Teste 4: Quick Sort ---
    copiar_array(A, A_copy, n);
    inicio = clock();
    quick_sort(A_copy, 0, n - 1);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("| Quick Sort         | %-23.6f |\n", tempo_gasto);

    // --- Teste 5: Merge Sort ---
    copiar_array(A, A_copy, n);
    inicio = clock();
    merge_sort(A_copy, 0, n - 1, O);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("| Merge Sort         | %-23.6f |\n", tempo_gasto);
    
    // --- Teste 6: Counting Sort ---
    copiar_array(A, A_copy, n);
    inicio = clock();
    counting_sort(A_copy, n, MAX_VALOR);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("| Counting Sort      | %-23.6f |\n", tempo_gasto);

    printf("--------------------------------------------------\n");

    free(A);
    free(A_copy);
    free(O);
    
    return 0;
}
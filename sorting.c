#include <stdio.h>
#include <stdlib.h>

void swap(int *A, int pos1, int pos2) {
    int aux = A[pos1];
    A[pos1] = A[pos2];
    A[pos2] = aux;
}

void bubble(int *A, int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - 1; j++) {
            if(A[j] > A[j+1]) 
                swap(A, j, j + 1);
        }
    }
}

void selection(int *A, int n) {
    int i, j, m;
    for(i = 0; i < n - 1; i++) {
        m = i;
        for(j = i + 1; j < n; j++) {
            if(A[j] < A[m])
                m = j;
        }
        swap(A, i, m);
    }   
}

void insertion(int *A, int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while( (j >= 0) && (key < A[j]) ) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int partition(int *A, int left, int right) {
    int p = A[right];
    int i = left - 1;
    int j;
    for(j = left; j < right; j++) {
        if(A[j] <= p) {
            i++;
            swap(A, i, j);
        }
    }
    swap(A, i + 1, right);
    return (i + 1);
}

void quick_sort(int *A, int left, int right) {
    if(left < right) {
        int p = partition(A, left, right);
        quick_sort(A, left, p - 1);
        quick_sort(A, p + 1, right);
    }
}

void merge(int *A, int left, int m, int right, int *O) {
    int i = left, j = m + 1, k = left;
    while( (i <= m) && (j <= right) ) {
        if(A[i] < A[j])
            O[k++] = A[i++];
        else
            O[k++] = A[j++];
    }
    while( i <= m) O[k++] = A[i++];
    while(j <= right) O[k++] = A[j++];
    for(i = left; i <= right; i++) A[i] = O[i];
}

void merge_sort(int *A, int left, int right, int *O) {
    if(left < right) {
        int m = left + (right - left) / 2;
        merge_sort(A, left, m, O);
        merge_sort(A, m + 1, right, O);
        merge(A, left, m, right, O);
    }
}

void counting_sort(int *A, int n, int k) {
    int i;
    int *T = (int*)malloc(n * sizeof(int));
    int *C = (int*)malloc((k + 1) * sizeof(int));
    if (T == NULL || C == NULL) {
        printf("Erro de alocacao no counting_sort\n");
        free(T);
        free(C);
        return;
    }
    for(i = 0; i <= k; i++) C[i] = 0;
    for(i = 0; i < n; i++) C[A[i]]++;
    for(i = 1; i <= k; i++) C[i] = C[i] + C[i - 1];
    for(i = n - 1; i >= 0; i--) {
        T[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    for(i = 0; i < n; i++) A[i] = T[i];
    free(T);
    free(C);
}
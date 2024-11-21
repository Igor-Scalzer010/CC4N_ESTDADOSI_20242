/**
 * @file QuickSort.c
 * @brief Implementação do algoritmo de ordenação QuickSort em C.
 * 
 * Este arquivo contém a implementação do algoritmo de ordenação QuickSort,
 * incluindo funções auxiliares para troca de elementos, particionamento do array,
 * e impressão do array ordenado.
 */

/**
 * @brief Troca os valores de duas variáveis inteiras.
 * 
 * @param a Ponteiro para o primeiro inteiro.
 * @param b Ponteiro para o segundo inteiro.
 */
void swap(int *a, int *b);

/**
 * @brief Particiona o array em torno de um pivô e retorna o índice do pivô.
 * 
 * @param arr Ponteiro para o array a ser particionado.
 * @param low Índice inicial do subarray.
 * @param high Índice final do subarray.
 * @return int Índice do pivô após a partição.
 */
int partition(int *arr, int low, int high);

/**
 * @brief Implementa o algoritmo de ordenação QuickSort.
 * 
 * @param arr Ponteiro para o array a ser ordenado.
 * @param low Índice inicial do subarray a ser ordenado.
 * @param high Índice final do subarray a ser ordenado.
 */
void quicksort(int *arr, int low, int high);

/**
 * @brief Imprime os elementos de um array.
 * 
 * @param arr Ponteiro para o array a ser impresso.
 * @param size Tamanho do array.
 */
void printArray(int *arr, int size);

/**
 * @brief Função principal que executa o algoritmo QuickSort em um array de exemplo.
 * 
 * Inicializa um array de inteiros, calcula seu tamanho, chama a função quicksort
 * para ordenar o array e imprime o array ordenado.
 * 
 * @return int Código de status da execução (0 para sucesso).
 */
int main();
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
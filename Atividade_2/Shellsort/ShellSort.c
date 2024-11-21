/**
 * @file ShellSort.c
 * @brief Implementação do algoritmo Shell Sort em C utilizando ponteiros.
 * 
 * Este arquivo contém a implementação do algoritmo de ordenação Shell Sort,
 * que é uma generalização do algoritmo de inserção direta. O Shell Sort
 * melhora a eficiência do algoritmo de inserção direta ao permitir trocas
 * de elementos que estão distantes uns dos outros.
 * 
 * Funções:
 * - shellSort: Função que realiza a ordenação de um array utilizando o algoritmo Shell Sort.
 * - printArray: Função que imprime os elementos de um array.
 * 
 * Variáveis:
 * - arr: Array de inteiros a ser ordenado.
 * - n: Tamanho do array.
 */

#include <stdio.h>

/**
 * @brief Função que realiza a ordenação de um array utilizando o algoritmo Shell Sort.
 * 
 * @param arr Ponteiro para o array de inteiros a ser ordenado.
 * @param n Tamanho do array.
 * 
 * A função shellSort utiliza um intervalo (gap) que é reduzido pela metade a cada iteração.
 * Para cada intervalo, a função realiza uma ordenação por inserção direta nos elementos
 * que estão separados pelo intervalo atual.
 */
void shellSort(int *arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = *(arr + i);
            int j;
            for (j = i; j >= gap && *(arr + j - gap) > temp; j -= gap) {
                *(arr + j) = *(arr + j - gap);
            }
            *(arr + j) = temp;
        }
    }
}

/**
 * @brief Função que imprime os elementos de um array.
 * 
 * @param arr Ponteiro para o array de inteiros a ser impresso.
 * @param n Tamanho do array.
 * 
 * A função printArray percorre todos os elementos do array e os imprime
 * na saída padrão, separados por um espaço. Após imprimir todos os elementos,
 * a função imprime uma nova linha.
 */
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

/**
 * @brief Função principal que demonstra o uso do algoritmo Shell Sort.
 * 
 * A função main inicializa um array de inteiros, imprime o array antes da ordenação,
 * chama a função shellSort para ordenar o array e, em seguida, imprime o array após
 * a ordenação.
 * 
 * @return Retorna 0 para indicar que o programa foi executado com sucesso.
 */
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Array after sorting:\n");
    printArray(arr, n);

    return 0;
}
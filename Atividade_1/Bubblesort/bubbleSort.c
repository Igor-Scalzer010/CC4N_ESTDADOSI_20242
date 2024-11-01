/**
 * @file bubblesort.c
 * @brief Implementação do algoritmo de ordenação Bubble Sort e funções auxiliares.
 *
 * Este arquivo contém a implementação do algoritmo de ordenação Bubble Sort,
 * uma função para imprimir o array e a função principal que inicializa e ordena
 * um array de números aleatórios.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Ordena um array de inteiros usando o algoritmo Bubble Sort.
 *
 * Esta função recebe um array de inteiros e seu tamanho, e ordena os elementos
 * do array em ordem crescente usando o algoritmo Bubble Sort.
 *
 * @param array Ponteiro para o array de inteiros a ser ordenado.
 * @param tamanho Tamanho do array.
 */
void bubbleSort(int *array, int tamanho);

/**
 * @brief Imprime os elementos de um array de inteiros.
 *
 * Esta função recebe um array de inteiros e seu tamanho, e imprime cada elemento
 * do array no formato "array[i] = valor".
 *
 * @param array Ponteiro para o array de inteiros a ser impresso.
 * @param tamanho Tamanho do array.
 */
void printArray(int *array, int tamanho);

/**
 * @brief Função principal que inicializa e ordena um array de números aleatórios.
 *
 * Esta função inicializa um array de 50 inteiros com números aleatórios entre 0 e 99,
 * ordena o array usando a função bubbleSort e imprime o array ordenado.
 *
 * @return Retorna 0 se a execução for bem-sucedida.
 */
int main();
void bubbleSort(int *array, int tamanho) {
    int i, continua;
    do
    {
        continua = 0;
        for(i = 0; i < tamanho -1; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                continua = 1;
            }
        }
        tamanho--;
    } while (continua != 0);    
    
}

void printArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

int main() {
    int arr[50];
    int tamanho = sizeof(arr) / sizeof(arr[0]);


    // Incializa o gerador de números aleatórios
    srand(time(NULL));

    // Preenche o array com números aleatórios
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 100;
    }

    bubbleSort(arr, tamanho);

    printf("Array ordenado: \n");
    printArray(arr, tamanho);
    return 0;
}
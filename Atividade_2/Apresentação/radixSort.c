/**
 * @file radixSort.c
 * @brief Implementação do algoritmo de ordenação Radix Sort em C.
 * 
 * Este arquivo contém a implementação do algoritmo Radix Sort, que é um algoritmo de ordenação não-comparativo.
 * Ele ordena os números inteiros processando os dígitos individuais. A implementação inclui funções auxiliares
 * para encontrar o maior número no array, realizar a ordenação por contagem em uma posição específica e imprimir o array.
 * 
 * @author Igor Scalzer Ratti
 * @date 31/10/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Encontra o maior elemento em um array.
 * 
 * Esta função percorre o array para encontrar o maior elemento.
 * 
 * @param arr O array de inteiros.
 * @param tamanho O tamanho do array.
 * @return O maior elemento do array.
 */
int encontrarMaior(int arr[], int tamanho);

/**
 * @brief Realiza a ordenação por contagem em uma posição específica.
 * 
 * Esta função realiza a ordenação por contagem (Counting Sort) com base no dígito especificado pela posição.
 * 
 * @param arr O array de inteiros a ser ordenado.
 * @param tamanho O tamanho do array.
 * @param posicao A posição do dígito a ser usado para a ordenação.
 */
void countingSort(int arr[], int tamanho, int posicao);

/**
 * @brief Realiza a ordenação Radix Sort em um array.
 * 
 * Esta função implementa o algoritmo Radix Sort, que ordena o array processando os dígitos individuais.
 * 
 * @param arr O array de inteiros a ser ordenado.
 * @param tamanho O tamanho do array.
 */
void radixSort(int arr[], int tamanho);

/**
 * @brief Imprime os elementos de um array.
 * 
 * Esta função imprime os elementos do array separados por espaços.
 * 
 * @param arr O array de inteiros a ser impresso.
 * @param tamanho O tamanho do array.
 */
void printArray(int arr[], int tamanho);

/**
 * @brief Função principal.
 * 
 * Esta função inicializa um array com números aleatórios, imprime o array original, ordena o array usando Radix Sort
 * e imprime o array ordenado.
 * 
 * @return 0 se a execução for bem-sucedida.
 */
int main();


int encontrarMaior(int arr[], int tamanho) {
    int maior = arr[0];
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }
    return maior;
}

void countingSort(int arr[], int tamanho, int posicao) {
    int* output = (int*)malloc(tamanho * sizeof(int)); // Array temporário de saída para armazenar os resultados da ordenação
    int count[10] = {0}; // Array de contagem para armazenar a ocorrencia de cada dígito (0-9)

    for (int i = 0; i < tamanho; i++) {
        int index = (arr[i] / posicao) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        int index = (arr[i] / posicao) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < tamanho; i++) {
        arr[i] = output[i];
    }

    free(output);
}

void radixSort(int arr[], int tamanho) {
    int maior = encontrarMaior(arr, tamanho);

    for (int posicao = 1; maior / posicao > 0; posicao *= 10) {
        countingSort(arr, tamanho, posicao);
    }
}

void printArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[50];
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // Inicializar o gerador de números aleatórios
    srand(time(NULL));
    
    // Preencher o array com números aleatórios
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 100;
    }
    printf("Array original: ");
    printArray(arr, tamanho);

    radixSort(arr, tamanho);

    printf("Array ordenado: ");
    printArray(arr, tamanho);

    return 0;
}

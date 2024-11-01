/**
 * @file insertionSort.c
 * @brief Implementação do algoritmo de ordenação Insertion Sort.
 *
 * Este arquivo contém a implementação do algoritmo de ordenação Insertion Sort,
 * bem como funções auxiliares para imprimir o array e preencher o array com 
 * números aleatórios.
 * 
 * @author Igor Scalzer Ratti
 * @date 31/10/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Ordena um array de inteiros usando o algoritmo Insertion Sort.
 *
 * Esta função recebe um array de inteiros e seu tamanho, e ordena o array
 * em ordem crescente usando o algoritmo Insertion Sort.
 *
 * @param arr O array de inteiros a ser ordenado.
 * @param n O tamanho do array.
 */
void insertionsort(int arr[], int n);

/**
 * @brief Imprime os elementos de um array de inteiros.
 *
 * Esta função recebe um array de inteiros e seu tamanho, e imprime os elementos
 * do array separados por espaços.
 *
 * @param arr O array de inteiros a ser impresso.
 * @param n O tamanho do array.
 */
void printArray(int arr[], int n);

/**
 * @brief Função principal que executa o programa.
 *
 * Esta função inicializa um array de inteiros com números aleatórios, 
 * ordena o array usando a função insertionsort e imprime o array ordenado.
 *
 * @return Retorna 0 se o programa for executado com sucesso.
 */
int main();

void insertionsort(int arr[], int n) {
    int i, temp, j;
    // Percorre o array a partir do segundo elemento
    for (i = 1; i < n; i++) {
        temp = arr[i]; // Armazena o valor atual
        j = i - 1;
        // Move os elementos do array que são maiores que temp para uma posição à frente
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; // Insere o valor armazenado na posição correta
    }
}

void printArray(int arr[], int n) {
    // Percorre o array e imprime cada elemento
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Imprime uma nova linha após todos os elementos
}

int main() {
    int arr[50];
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Preenche o array com números aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Ordena o array usando Insertion Sort
    insertionsort(arr, n);
    
    // Imprime o array ordenado
    printArray(arr, n);
    
    return 0;
}
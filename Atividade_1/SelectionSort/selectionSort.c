/**
 * @file selectionSort.c
 * @brief Implementação do algoritmo de ordenação Selection Sort.
 * 
 * Este arquivo contém a implementação do algoritmo de ordenação Selection Sort,
 * que ordena um array de inteiros em ordem crescente. Além disso, inclui uma 
 * função para imprimir o array e uma função principal que inicializa um array 
 * com números aleatórios, ordena-o e imprime o resultado.
 * 
 * @author Igor Scalzer Ratti
 * @date 31/10/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Ordena um array de inteiros usando o algoritmo Selection Sort.
 * 
 * Esta função percorre o array, encontra o menor elemento e o coloca na 
 * posição correta, repetindo o processo para cada posição do array até que 
 * todo o array esteja ordenado.
 * 
 * @param arr O array de inteiros a ser ordenado.
 * @param n O tamanho do array.
 */
void selectionSort(int arr[], int n);

/**
 * @brief Imprime os elementos de um array de inteiros.
 * 
 * Esta função percorre o array e imprime cada elemento no formato 
 * "Array[i] = valor".
 * 
 * @param arr O array de inteiros a ser impresso.
 * @param n O tamanho do array.
 */
void printArray(int arr[], int n);

/**
 * @brief Função principal que inicializa um array com números aleatórios, 
 * ordena-o usando Selection Sort e imprime o array ordenado.
 * 
 * A função principal inicializa o gerador de números aleatórios, preenche um 
 * array com números aleatórios, chama a função de ordenação e imprime o array 
 * ordenado.
 * 
 * @return Retorna 0 para indicar que o programa terminou corretamente.
 */
int main();

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    // Percorre o array até o penúltimo elemento
    for (i = 0; i < n-1; i++) {
        // Assume que o menor elemento é o atual
        minIndex = i;

        // Encontra o menor elemento no restante do array
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Troca o menor elemento encontrado com o elemento atual
        if (i != minIndex) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    // Percorre o array e imprime cada elemento
    for(int i = 0; i < n; i++) {
        printf("Array[%d] = %d\n", i, arr[i]);
    }
}

int main() {
    int arr[50];
    int n = sizeof(arr)/sizeof(arr[0]);

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Preenche o array com números aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Ordena o array usando Selection Sort
    selectionSort(arr, n);
    
    // Imprime o array ordenado
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
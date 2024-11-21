/**
 * @file MergeSort.c
 * @brief Implementação do algoritmo Merge Sort em C.
 *
 * Este arquivo contém a implementação do algoritmo Merge Sort, que é um 
 * algoritmo de ordenação por divisão e conquista. O algoritmo divide 
 * recursivamente o array em duas metades, ordena cada metade e depois 
 * mescla as metades ordenadas para produzir o array final ordenado.
 *
 * As principais funções neste arquivo são:
 * - merge: Mescla dois subarrays ordenados em um único array ordenado.
 * - mergeSort: Divide recursivamente o array em duas metades, ordena cada metade e as mescla.
 * - main: Demonstra o uso da função mergeSort.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Mescla dois subarrays ordenados em um único array ordenado.
 *
 * Esta função recebe um array e dois índices, left e right, que definem a 
 * faixa do array a ser mesclada. Também recebe um índice mid, que divide a 
 * faixa em dois subarrays. A função mescla esses dois subarrays ordenados 
 * em um único array ordenado.
 *
 * @param arr O array a ser ordenado.
 * @param left O índice inicial da faixa a ser mesclada.
 * @param mid O índice do meio que divide a faixa em dois subarrays.
 * @param right O índice final da faixa a ser mesclada.
 */
void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1; ///< Número de elementos no subarray esquerdo.
    int n2 = right - mid;    ///< Número de elementos no subarray direito.

    int *L = (int *)malloc(n1 * sizeof(int)); ///< Array temporário para o subarray esquerdo.
    int *R = (int *)malloc(n2 * sizeof(int)); ///< Array temporário para o subarray direito.

    // Copia os dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left; ///< Índices iniciais para os subarrays e o array mesclado.

    // Mescla os arrays temporários de volta em arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L); ///< Libera a memória alocada para o subarray esquerdo.
    free(R); ///< Libera a memória alocada para o subarray direito.
}

/**
 * @brief Divide recursivamente o array em duas metades, ordena cada metade e as mescla.
 *
 * Esta função recebe um array e dois índices, left e right, que definem a 
 * faixa do array a ser ordenada. Ela divide recursivamente o array em duas metades, 
 * ordena cada metade e depois mescla as metades ordenadas usando a função merge.
 *
 * @param arr O array a ser ordenado.
 * @param left O índice inicial da faixa a ser ordenada.
 * @param right O índice final da faixa a ser ordenada.
 */
void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; ///< Índice do meio para dividir o array em duas metades.

        mergeSort(arr, left, mid);     ///< Ordena recursivamente a primeira metade.
        mergeSort(arr, mid + 1, right); ///< Ordena recursivamente a segunda metade.

        merge(arr, left, mid, right); ///< Mescla as metades ordenadas.
    }
}

/**
 * @brief Função principal para demonstrar o uso da função mergeSort.
 *
 * Esta função inicializa um array, imprime o array original, ordena o array 
 * usando a função mergeSort e depois imprime o array ordenado.
 *
 * @return int Retorna 0 após a execução bem-sucedida.
 */
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; ///< Array a ser ordenado.
    int arr_size = sizeof(arr) / sizeof(arr[0]); ///< Tamanho do array.

    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, arr_size - 1); ///< Ordena o array usando mergeSort.

    printf("\nSorted array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
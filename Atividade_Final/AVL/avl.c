#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore AVL
typedef struct No {
    int chave;
    struct No *esquerda;
    struct No *direita;
    int altura;
} No;

// Função para obter a altura de um nó
int altura(No *N) {
    if (N == NULL)
        return 0;
    return N->altura;
}

// Função para obter o máximo entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó
No* novoNo(int chave) {
    No* no = (No*)malloc(sizeof(No));
    no->chave = chave;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1; // Novo nó é inicialmente adicionado na folha
    return(no);
}

// Função para rotacionar à direita a subárvore com raiz y
No *rotacaoDireita(No *y) {
    No *x = y->esquerda;
    No *T2 = x->direita;

    // Realiza a rotação
    x->direita = y;
    y->esquerda = T2;

    // Atualiza as alturas
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    // Retorna a nova raiz
    return x;
}

// Função para rotacionar à esquerda a subárvore com raiz x
No *rotacaoEsquerda(No *x) {
    No *y = x->direita;
    No *T2 = y->esquerda;

    // Realiza a rotação
    y->esquerda = x;
    x->direita = T2;

    // Atualiza as alturas
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    // Retorna a nova raiz
    return y;
}

// Função para obter o fator de balanceamento de um nó
int obterBalanceamento(No *N) {
    if (N == NULL)
        return 0;
    return altura(N->esquerda) - altura(N->direita);
}

// Função para inserir um nó na árvore AVL
No* inserir(No* no, int chave) {
    // 1. Realiza a inserção normal na árvore binária de busca
    if (no == NULL)
        return(novoNo(chave));

    if (chave < no->chave)
        no->esquerda = inserir(no->esquerda, chave);
    else if (chave > no->chave)
        no->direita = inserir(no->direita, chave);
    else // Chaves iguais não são permitidas na árvore AVL
        return no;

    // 2. Atualiza a altura deste nó ancestral
    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    // 3. Obtém o fator de balanceamento deste nó ancestral para verificar se este nó se tornou desbalanceado
    int balanceamento = obterBalanceamento(no);

    // Se este nó se tornou desbalanceado, então existem 4 casos

    // Caso Esquerda Esquerda
    if (balanceamento > 1 && chave < no->esquerda->chave)
        return rotacaoDireita(no);

    // Caso Direita Direita
    if (balanceamento < -1 && chave > no->direita->chave)
        return rotacaoEsquerda(no);

    // Caso Esquerda Direita
    if (balanceamento > 1 && chave > no->esquerda->chave) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    // Caso Direita Esquerda
    if (balanceamento < -1 && chave < no->direita->chave) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    // Retorna o ponteiro do nó (inalterado)
    return no;
}

// Função para imprimir a árvore AVL
void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Função principal
int main() {
    No *raiz = NULL;

    // Insere nós na árvore AVL
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 25);

    // Imprime a árvore AVL
    printf("Percurso em pré-ordem da árvore AVL construída é \n");
    preOrdem(raiz);

    return 0;
}
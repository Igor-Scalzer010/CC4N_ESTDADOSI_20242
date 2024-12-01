#include <stdio.h>
#include <stdlib.h>

/**
 * @file bst.c
 * @brief Implementação de uma Árvore Binária de Busca (BST) em C.
 * 
 * Este arquivo contém a implementação das funções para criar, inserir, buscar e
 * realizar a travessia em ordem (in-order traversal) em uma árvore binária de busca.
 */

/**
 * @struct Node
 * @brief Estrutura do nó da árvore binária de busca (BST).
 * 
 * @var Node::data
 * Valor inteiro armazenado no nó.
 * @var Node::left
 * Ponteiro para o nó filho à esquerda.
 * @var Node::right
 * Ponteiro para o nó filho à direita.
 */

/**
 * @brief Cria um novo nó com o valor fornecido.
 * 
 * @param data Valor inteiro a ser armazenado no novo nó.
 * @return Ponteiro para o novo nó criado.
 */
struct Node* createNode(int data);

/**
 * @brief Insere um novo nó na árvore binária de busca (BST).
 * 
 * @param root Ponteiro para a raiz da árvore.
 * @param data Valor inteiro a ser inserido na árvore.
 * @return Ponteiro para a raiz da árvore após a inserção.
 */
struct Node* insert(struct Node* root, int data);

/**
 * @brief Realiza a busca de um valor na árvore binária de busca (BST).
 * 
 * @param root Ponteiro para a raiz da árvore.
 * @param data Valor inteiro a ser buscado na árvore.
 * @return Ponteiro para o nó encontrado ou NULL se o valor não for encontrado.
 */
struct Node* search(struct Node* root, int data);

/**
 * @brief Realiza a travessia em ordem (in-order traversal) da árvore binária de busca (BST).
 * 
 * @param root Ponteiro para a raiz da árvore.
 */
void inorderTraversal(struct Node* root);

/**
 * @brief Função principal que demonstra a criação, inserção, busca e travessia em ordem na BST.
 * 
 * @return Código de saída do programa.
 */
int main();

// Estrutura do nó da árvore binária de busca (BST)
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo nó na BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Função para realizar a busca na BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Função para realizar a travessia em ordem (in-order traversal)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Função principal
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    int key = 40;
    if (search(root, key) != NULL) {
        printf("Node %d found in the BST.\n", key);
    } else {
        printf("Node %d not found in the BST.\n", key);
    }

    return 0;
}
/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                 Estrutura de Dados          */
/*                                                                        */
/*                         Camille Guillen                               */
/*                  Objetivo: Manipulando Lista Ligada           */
/*                                                                        */
/*                                                        Data:02/04/2024 */
/*------------------------------------------------------------------------*/ 
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista ligada
struct Node {
    int data;
    struct Node* next;
};

// Declaração da lista ligada global
struct Node* head = NULL;

// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no final da lista
void insertNode(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Função para obter um nó com base no índice (posição) na lista
struct Node* getNode(int index) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (count == index) {
            return temp;
        }
        count++;
        temp = temp->next;
    }
    return NULL; // Se o índice estiver fora do intervalo
}

// Função para excluir um nó com base no valor
void deleteNode(int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // Verifica se o nó a ser excluído é o primeiro
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }

    // Procura pelo nó a ser excluído
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Se o nó não estiver presente na lista
    if (temp == NULL) {
        printf("O elemento %d não está presente na lista.\n", value);
        return;
    }

    // Desvincula o nó a ser excluído da lista
    prev->next = temp->next;
    free(temp);
}

// Função para liberar toda a lista
void freeList() {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Função para listar todos os elementos da lista
void listAllNodes() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("Elementos da lista:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int opcao, elemento;

    do {
        printf("\nEscolha uma opção:\n");
        printf("0 - Sair\n");
        printf("1 - Incluir\n");
        printf("2 - Consultar\n");
        printf("3 - Deletar\n");
        printf("4 - Listar todos\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Programa encerrado.\n");
                break;
            case 1:
                printf("Digite o elemento a incluir: ");
                scanf("%d", &elemento);
                insertNode(elemento);
                break;
            case 2:
                printf("Digite o índice do elemento a consultar: ");
                scanf("%d", &elemento);
                if (getNode(elemento) != NULL)
                    printf("Elemento encontrado: %d\n", getNode(elemento)->data);
                else
                    printf("Índice fora do intervalo.\n");
                break;
            case 3:
                printf("Digite o elemento a deletar: ");
                scanf("%d", &elemento);
                deleteNode(elemento);
                break;
            case 4:
                listAllNodes();
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    // Liberar memória alocada para a lista
    freeList();

    return 0;
}

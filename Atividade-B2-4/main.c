/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                 Estrutura de Dados        */
/*                                                                        */
/*                           Camille Guillen                              */
/*                Objetivo: Implementação de Filas - Hospital             */
/*                                                                        */
/*                                                        Data:02/05/2024 */
/*------------------------------------------------------------------------*/ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Definição da estrutura de paciente
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char priority; // 'N' para normal, 'P' para prioritário, 'U' para urgente
    char reason[100];
} Patient;

// Definição do nó da fila
typedef struct Node {
    Patient patient;
    struct Node* next;
} Node;

// Definição da fila
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Função para inicializar a fila
void initializeQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Função para adicionar paciente à fila
void enqueue(Queue* queue, Patient patient) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->patient = patient;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Função para remover e obter o próximo paciente da fila
Patient dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = queue->front;
    Patient patient = temp->patient;

    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return patient;
}

// Função para visualizar a fila
void displayQueue(Queue* queue, char priority) {
    Node* current = queue->front;

    printf("Fila %s:\n", (priority == 'N') ? "Normal" : ((priority == 'P') ? "Prioritária" : "Urgente"));

    while (current != NULL) {
        if (current->patient.priority == priority) {
            printf("Nome: %s, Idade: %d, Motivo: %s\n", current->patient.name, current->patient.age, current->patient.reason);
        }
        current = current->next;
    }
    printf("\n");
}

// Função para adicionar um paciente à fila com base nas informações fornecidas pelo usuário
void addPatient(Queue* normalQueue, Queue* prioritaryQueue, Queue* urgentQueue) {
    Patient newPatient;
    printf("\nPara casos prioritários, digite: \n > - Gestantes \n > - Idosos (60 anos ou mais) \n > - Problemas Graves\n");
    printf("\nDigite o nome do paciente: ");
    scanf("%s", newPatient.name);
    printf("\nDigite a idade do paciente: ");
    scanf("%d", &newPatient.age);
    printf("\nDigite o motivo da consulta: ");
    scanf(" %[^\n]s", newPatient.reason);

    printf("\nDigite a prioridade do paciente ('N' para normal, 'P' para prioritário, 'U' para urgente): ");
 
    scanf(" %c", &newPatient.priority);

    if (newPatient.priority == 'P') {
        // Verificar se o paciente atende aos critérios para ser incluído na fila prioritária
        if (strcmp(newPatient.reason, "Problemas Graves") == 0 || newPatient.age >= 60 || strcmp(newPatient.reason, "Gestante") == 0) {
            enqueue(prioritaryQueue, newPatient);
            printf("Paciente adicionado à fila prioritária com sucesso.\n");
        } else {
            printf("Este paciente não atende aos critérios para ser incluído na fila prioritária.\n");
            enqueue(normalQueue, newPatient);
            printf("Paciente adicionado à fila normal.\n");
        }
    } else {
        switch (newPatient.priority) {
            case 'N':
                enqueue(normalQueue, newPatient);
                break;
            case 'U':
                enqueue(urgentQueue, newPatient);
                break;
            default:
                printf("Prioridade inválida. O paciente não será adicionado à fila.\n");
        }
    }
}

// Função para atender pacientes com base na prioridade
void servePatients(Queue* normalQueue, Queue* prioritaryQueue, Queue* urgentQueue) {
    printf("\nAtendendo pacientes...\n");

    if (!isEmpty(urgentQueue)) {
        Patient urgentPatient = dequeue(urgentQueue);
        printf("\nAtendendo paciente urgente: %s, idade %d, motivo: %s\n", urgentPatient.name, urgentPatient.age, urgentPatient.reason);
    } else if (!isEmpty(prioritaryQueue)) {
        Patient prioritaryPatient = dequeue(prioritaryQueue);
        printf("\nAtendendo paciente prioritário: %s, idade %d, motivo: %s\n", prioritaryPatient.name, prioritaryPatient.age, prioritaryPatient.reason);
    } else if (!isEmpty(normalQueue)) {
        Patient normalPatient = dequeue(normalQueue);
        printf("\nAtendendo paciente normal: %s, idade %d, motivo: %s\n", normalPatient.name, normalPatient.age, normalPatient.reason);
    } else {
        printf("\nNão há pacientes para atender.\n");
    }
}

// Função para remover pacientes após atendimento
void removePatient(Queue* queue) {
    if (!isEmpty(queue)) {
        dequeue(queue);
        printf("Paciente removido da fila após o atendimento.\n");
    } else {
        printf("Não há pacientes na fila para remover.\n");
    }
}

// Função para exibir o menu de opções
void displayMenu() {
    printf("\n\nMenu:\n");
    printf("1. Adicionar paciente à fila\n");
    printf("2. Atender pacientes\n");
    printf("3. Remover paciente da fila após o atendimento\n");
    printf("4. Visualizar fila de pacientes\n");
    printf("5. Sair\n");
    printf("\nEscolha uma opção: ");
}

int main() {
    Queue normalQueue, prioritaryQueue, urgentQueue;
    initializeQueue(&normalQueue);
    initializeQueue(&prioritaryQueue);
    initializeQueue(&urgentQueue);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(&normalQueue, &prioritaryQueue, &urgentQueue);
                break;
            case 2:
                servePatients(&normalQueue, &prioritaryQueue, &urgentQueue);
                break;
            case 3:
                removePatient(&normalQueue);
                removePatient(&prioritaryQueue);
                removePatient(&urgentQueue);
                break;
            case 4:
                displayQueue(&normalQueue, 'N');
                displayQueue(&prioritaryQueue, 'P');
                displayQueue(&urgentQueue, 'U');
                break;
            case 5:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida. Por favor, escolha outra opção.\n");
        }
    } while (choice != 5);

    return 0;
}

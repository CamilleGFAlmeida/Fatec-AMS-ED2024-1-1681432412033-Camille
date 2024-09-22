# Análise Assintótica dos Algoritmos de Busca

Este repositório contém a implementação e análise de três algoritmos de busca em C e gráficos gerados em Python para ilustrar o comportamento de tempo de execução de cada algoritmo.

## Algoritmos Implementados

### 1. Busca Linear

A busca linear percorre uma lista de elementos um por um até encontrar o item desejado ou até o final da lista.

**Código fonte: `busca_linear.c`**
```c
#include <stdio.h>

int busca_linear(int arr[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == chave) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chave = 5;
    int resultado = busca_linear(arr, n, chave);
    printf("Resultado: %d\n", resultado);
    return 0;
}


#include <stdio.h>

int busca_linear_ordem(int arr[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == chave) {
            return i;
        }
        if (arr[i] > chave) {
            return -1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chave = 5;
    int resultado = busca_linear_ordem(arr, n, chave);
    printf("Resultado: %d\n", resultado);
    return 0;
}


#include <stdio.h>

int busca_binaria(int arr[], int n, int chave) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        if (arr[meio] == chave) {
            return meio;
        }
        if (arr[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chave = 5;
    int resultado = busca_binaria(arr, n, chave);
    printf("Resultado: %d\n", resultado);
    return 0;
}



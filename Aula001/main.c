#include <stdio.h>

// Função para ordenar o array em ordem crescente
void ordenar(int array[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numeroInteiros[5] = {42, 105, 10, 50, 1};
    int i;

    // Ordenando os números
    ordenar(numeroInteiros, 5);

    // Mostrando os números ordenados
    printf("Numeros em ordem crescente:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", numeroInteiros[i]);
    }
    printf("\n");

    return 0;
}

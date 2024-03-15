#include <stdio.h>

// Função para encontrar o maior elemento do array
float encontrarMaior(float *array, int tamanho) {
    float maior = *array;
    for (int i = 1; i < tamanho; i++) {
        if (*(array + i) > maior) {
            maior = *(array + i);
        }
    }
    return maior;
}

// Função para calcular a soma de todos os elementos do array
float calcularSoma(float *array, int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += *(array + i);
    }
    return soma;
}

// Função para imprimir todos os elementos do array
void imprimirArray(float *array, int tamanho) {
    printf("Array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", *(array + i));
    }
    printf("\n");
}

// Função para modificar todos os elementos do array multiplicando-os por um valor específico
void modificarArray(float *array, int tamanho, float multiplicador) {
    for (int i = 0; i < tamanho; i++) {
        *(array + i) *= multiplicador;
    }
}

int main() {
    float notas[5];
    printf("Digite as 5 notas:\n");
    for (int i = 0; i < 5; i++) {
        do {
            printf("Nota %d: ", i + 1);
            scanf("%f", &notas[i]);
            if (notas[i] < 0) {
                printf("Valor negativo não é aceito. Por favor, digite novamente.\n");
            }
        } while (notas[i] < 0);
    }

    // Ordenar as notas em ordem ascendente (Bubble Sort)
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (notas[j] > notas[j + 1]) {
                float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }

    // Programa 1 - Encontrar o maior elemento
    float maior = encontrarMaior(notas, 5);
    printf("Maior elemento: %.2f\n", maior);

    // Programa 2 - Calcular a soma de todos os elementos
    float soma = calcularSoma(notas, 5);
    printf("Soma dos elementos: %.2f\n", soma);

    // Programa 3 - Imprimir o array
    imprimirArray(notas, 5);

    // Programa 4 - Modificar todos os elementos multiplicando por um valor específico
    float multiplicador;
    do {
        printf("Digite o valor pelo qual deseja multiplicar os elementos: ");
        scanf("%f", &multiplicador);
        if (multiplicador < 0) {
            printf("Valor negativo não é aceito. Por favor, digite novamente.\n");
        }
    } while (multiplicador < 0);
    modificarArray(notas, 5, multiplicador);
    printf("Array modificado: ");
    imprimirArray(notas, 5);

    return 0;
}

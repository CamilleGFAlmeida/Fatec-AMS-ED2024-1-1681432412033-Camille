#include <stdio.h>

// Forma de Função 

// Função para somar dois números
int somar(int a, int b) {
    return a + b;
}

int main() {
    // Declaração das variáveis
    int num1, num2, resultado;

    // Entrada de dados
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    // Somando os números usando a função
    resultado = somar(num1, num2);

    // Mostrando o resultado
    printf("A soma de %d e %d é: %d\n", num1, num2, resultado);

    return 0;
}

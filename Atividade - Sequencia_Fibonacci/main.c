#include <stdio.h>

int main() {
    int n = 10; // Número de termos desejados
    int fib[n]; // Array para armazenar os termos da sequência

    // Inicializa os dois primeiros termos da sequência de Fibonacci
    fib[0] = 0;
    fib[1] = 1;

    // Calcula os próximos termos
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Imprime os termos da sequência
    printf("Sequência de Fibonacci com %d termos:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}

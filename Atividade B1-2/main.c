#include <stdio.h>

// Função para aplicar o desconto ao preço do produto
void aplicarDesconto(float *preco, float desconto) {
    *preco = *preco * (1 - desconto / 100); // Aplica o desconto ao preço
}

int main() {
    float preco, desconto;

    // Solicita ao usuário que insira o preço do produto
    printf("Insira o preco do produto: ");
    scanf("%f", &preco);

    // Solicita ao usuário que insira o desconto a ser aplicado
    printf("Insira o desconto a ser aplicado (em porcentagem): ");
    scanf("%f", &desconto);

    // Exibe o preço original
    printf("Preco original: R$%.2f\n", preco);

    // Aplica o desconto usando a função
    aplicarDesconto(&preco, desconto);

    // Exibe o desconto aplicado e o preço final
    printf("Desconto aplicado: %.2f%%\n", desconto);
    printf("Preco final: R$%.2f\n", preco);

    return 0;
}

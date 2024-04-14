/* -------------------------------------------------------*
 * FATEC-São Caetano do Sul            Estrutura de Dados *
 *               Avaliação N1 - Parte I                   *
 *     Objetivo: Controlar Estoque de produtos            *
 *                                                        *
 *       Autores: Camille Guillen / Thiago Gerbi          *
 *                  Data:02/04/2024                       *
 *--------------------------------------------------------*
 */


#include <stdio.h>
#include "cadastrar.h"
#include "buscar.h"
#include "baixa.h"

int main() {
    Produto *estoque = criaLista();
    int opcao;
    int id, quantidade;
    char nome[50];
    double preco;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar produto\n");
        printf("2. Buscar produto\n");
        printf("3. Baixar produto\n");
        printf("4. Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                printf("Digite o nome do produto: ");
                scanf("%s", nome);
                printf("Digite a quantidade do produto: ");
                scanf("%d", &quantidade);
                printf("Digite o valor do produto: ");
                scanf("%lf", &preco);
                estoque = insereProduto(estoque, id, nome, preco, quantidade);
                break;
            case 2:
                printf("Digite o ID do produto a ser buscado: ");
                scanf("%d", &id);
                Produto *produto = buscarProduto(estoque, id);
                if (produto != NULL) {
                    printf("Produto encontrado:\n");
                    printf("ID: %d\n", produto->id);
                    printf("Nome: %s\n", produto->nome);
                    printf("Quantidade em estoque: %d\n", produto->quantidade);
                    printf("Preço: %.2f\n", produto->preco);
                } else {
                    printf("Produto com ID %d não encontrado\n", id);
                }
                break;
            case 3:
                printf("Digite o ID do produto a ser baixado: ");
                scanf("%d", &id);
                printf("Digite a quantidade a ser baixada: ");
                scanf("%d", &quantidade);
                baixarProduto(estoque, id, quantidade);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Por favor, escolha outra opcao.\n");
                break;
        }
    } while (opcao != 4);

    // Liberar memória alocada para o estoque
    Produto *atual = estoque;
    while (atual != NULL) {
        Produto *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define STACK_SIZE 100

// Definição da estrutura da pilha
typedef struct {
    double items[STACK_SIZE];
    int top;
} Stack;

// Funções auxiliares para manipulação da pilha
void push(Stack *s, double value) {
    if (s->top == STACK_SIZE - 1) {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

double pop(Stack *s) {
    if (s->top == -1) {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Função para calcular o resultado da expressão RPN
double calculateRPN(char *rpn) {
    Stack s;
    s.top = -1;

    while (*rpn != '\0') {
        if (isdigit(*rpn) || (*rpn == '-' && isdigit(*(rpn + 1)))) {
            push(&s, atof(rpn));
            while (isdigit(*rpn) || *rpn == '.') rpn++;
        } else if (*rpn == '+' || *rpn == '-' || *rpn == '*' || *rpn == '/') {
            double op2 = pop(&s);
            double op1 = pop(&s);
            switch (*rpn) {
                case '+':
                    push(&s, op1 + op2);
                    break;
                case '-':
                    push(&s, op1 - op2);
                    break;
                case '*':
                    push(&s, op1 * op2);
                    break;
                case '/':
                    push(&s, op1 / op2);
                    break;
            }
            rpn++;
        } else {
            rpn++;
        }
        while (*rpn == ' ') rpn++;  // Ignorar espaços em branco
    }

    return pop(&s);
}

int main() {
    char rpn[STACK_SIZE];
    printf("Digite a expressão RPN: ");
    fgets(rpn, STACK_SIZE, stdin);

    // Calcula o resultado da expressão RPN
    double result = calculateRPN(rpn);
    printf("Resultado: %.2f\n", result);

    return 0;
}

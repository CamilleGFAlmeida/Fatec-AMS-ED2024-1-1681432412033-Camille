# Análise de Desempenho de Algoritmos - Proposta de Solução Computacional

## Integrantes Dupla 1
- Camille Almeida
- Thiago Gerbi

## Integrantes Dupla 2 
- Felipe Lins 
- Lucas Vilas Boas 

### Curso: ADS - Análise e Desenvolvimento de Sistemas
### Disciplina: Estrutura de Dados
### Data: [## - ## - ####]

## Descrição do Negócio

O problema proposto envolve a implementação de uma solução computacional para um cenário em que é necessário processar uma série de dados e realizar cálculos complexos de forma eficiente. O objetivo é criar um algoritmo que seja capaz de executar operações repetitivas (loops) e também resolver subproblemas de forma recursiva, proporcionando uma análise de desempenho detalhada de sua eficiência.

### Cenário

Suponhamos que estamos desenvolvendo um sistema para gerenciar a distribuição de recursos em uma rede de computadores. O sistema deve calcular a quantidade de dados que cada nó da rede pode processar em um determinado período de tempo, levando em consideração fatores como largura de banda, capacidade de processamento e latência de rede.

Para isso, a solução deve:
- Iterar sobre um conjunto de nós e calcular a carga de trabalho de cada nó;
- Realizar simulações para ajustar a alocação de recursos;
- Usar recursividade para quebrar problemas maiores em subproblemas menores e facilitar o balanceamento de carga.

## Macro Solução

A solução computacional será composta por um programa que contém três pontos de laço de repetição e um ponto de recursividade.

### Laços de Repetição

1. **Laço de For**: Para percorrer cada nó da rede e calcular a carga de trabalho.
   - Código exemplo:
   ```python
   for node in network_nodes:
       process_node_load(node)

2. **Laço de While**: Para realizar simulações até que a alocação de recursos atinja um equilíbrio.
   - Código exemplo:
   ```python
    while not balanced:
    simulate_load_distribution()

3. **Laço de For**: Para monitorar o tempo de processamento de cada nó e verificar se está dentro dos limites aceitáveis.
   - Código exemplo:
   ```python
    for node in network_nodes:
    check_processing_time(node)

4. **Ponto de Recursividade**: A recursividade será utilizada para resolver o problema do balanceamento de carga entre os nós da rede, dividindo o problema em subproblemas menores, até que seja possível resolver individualmente cada um.
   - Código exemplo:
   ```python
    def balance_resources(node_list):
    if len(node_list) == 1:
        return node_list[0].load
    else:
        mid = len(node_list) // 2
        left_load = balance_resources(node_list[:mid])
        right_load = balance_resources(node_list[mid:])
        return combine_loads(left_load, right_load)

---

## 4. Ferramentas e Linguagens Utilizadas

- Linguagem de Programação: Python

Python será utilizado devido à sua versatilidade e suporte para algoritmos eficientes, além de bibliotecas prontas para análise de desempenho, como timeit para medir tempo de execução.

- Plataforma de Controle de Versão: GitHub

O GitHub será utilizado para o versionamento e compartilhamento do código, permitindo a colaboração entre os integrantes da equipe.

- Bibliotecas:

**timeit** para análise de desempenho dos loops e da recursividade. 
<br>
**matplotlib (opcional)** para visualização gráfica do desempenho dos algoritmos.

- Ferramenta de Benchmarking:

O algoritmo será testado com diferentes entradas para comparar o tempo de execução e a eficiência dos laços de repetição e da recursividade.



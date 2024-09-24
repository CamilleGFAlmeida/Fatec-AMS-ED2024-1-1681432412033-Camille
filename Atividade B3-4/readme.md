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

A loja online está enfrentando desafios para gerenciar e analisar o grande volume de dados de vendas que processa diariamente. A necessidade é de um sistema que possa organizar as transações, facilitar a geração de relatórios e realizar análises detalhadas para ajudar na tomada de decisões estratégicas.

- Os principais requisitos do sistema incluem:

1. **Gerenciamento de Vendas**: Organizar e armazenar todas as transações de vendas, incluindo informações como o produto, cliente, quantidade e valor total.
2. **Relatórios de Desempenho**: Permitir a geração de relatórios detalhados que mostrem produtos mais vendidos, receita gerada em períodos específicos e clientes recorrentes.
3. **Análise de Períodos de Venda**: Realizar comparações entre diferentes períodos para identificar quais estratégias de vendas foram mais eficazes.
##
Além disso, o sistema utilizará benchmarking para comparar a eficiência de diferentes implementações de algoritmos.

## Macro Solução

Para atender a essas necessidades, o sistema será implementado utilizando três laços de repetição e um ponto de recursividade. Abaixo, detalhamos os componentes principais da solução.

### Entrada de Dados
O sistema receberá e armazenará dados em três principais estruturas:

- Vendas: Um conjunto de transações, cada uma contendo dados como o produto vendido, o cliente, a quantidade e o valor da venda.
- Produtos: Lista de produtos, com nome, categoria e preço de cada item.
- Clientes: Registro de clientes, incluindo suas informações básicas e histórico de compras.
  ##
  
### Laços de Repetição

1. **Laço 1 (For)**: Será utilizado para percorrer a lista de transações de vendas e somar o total de vendas por produto. Isso será usado para criar relatórios sobre os produtos mais vendidos.
   - Código exemplo:
   ```java
   for (Venda venda : listaVendas) {
    Produto produto = venda.getProduto();
    int quantidade = venda.getQuantidade();
    totalVendasPorProduto.put(produto, totalVendasPorProduto.getOrDefault(produto, 0) + quantidade);

2. **Laço 2 (While)**: Um laço contínuo para agregar as vendas durante o período de análise. O laço funcionará até que todos os dados de vendas sejam processados.
   - Código exemplo:
   ```java

3. **Laço 3 (For)**: Um laço contínuo que realiza o relatório de vendas. 
   - Código exemplo:
    ```java 
     public Map<Cliente, Integer> clientesFrequentes() {
        Map<Cliente, Integer> clientesFrequentes = new HashMap<>();
        for (Venda venda : listaVendas) {  // Laço 3 (For)
            Cliente cliente = venda.getCliente();
            clientesFrequentes.put(cliente, clientesFrequentes.getOrDefault(cliente, 0) + venda.getQuantidade());
        }
        return clientesFrequentes;
    }

3. **Ponto de Recursividade**: A recursividade será aplicada para a análise de desempenho de vendas em períodos diferentes. Por exemplo, o sistema fará comparações entre as vendas de diferentes semanas, dividindo recursivamente os períodos de tempo para encontrar o melhor desempenho (maior volume de vendas ou maior lucro).
   - Código exemplo:
   ```python
    public double comparaVendas(List<Venda> vendas, int inicio, int fim) {
    if (inicio == fim) {
        return vendas.get(inicio).getValorTotal();
    }
    int meio = (inicio + fim) / 2;
    double totalEsquerda = comparaVendas(vendas, inicio, meio);
    double totalDireita = comparaVendas(vendas, meio + 1, fim);
    return totalEsquerda + totalDireita;

A solução computacional será composta por um programa que contém três pontos de laço de repetição e um ponto de recursividade.

---

## 4. Ferramentas e Linguagens Utilizadas

- Linguagem de Programação: Java 

A escolha de Java se deve à sua robustez, escalabilidade e capacidade de lidar com grandes volumes de dados, além de sua eficiência ao utilizar laços de repetição e recursividade.

###

- Bibliotecas:

1. **Java Collections Framework (List, Map)**: Para armazenar e manipular os dados de vendas, produtos e clientes.
<br>

2. **System.nanoTime() e System.currentTimeMillis()**: Para medir o tempo de execução e realizar benchmarking de diferentes implementações de algoritmos.
<br>

3. **JFreeChart**: Para gerar gráficos que mostram visualmente os dados de vendas, como produtos mais vendidos ou desempenho de vendas ao longo do tempo.
<br>

4. **JUnit**: Para a execução de testes de desempenho e validação das funcionalidades implementadas.

###
- Plataforma de Controle de Versão: GitHub

O GitHub será utilizado para o versionamento e compartilhamento do código, permitindo a colaboração entre os integrantes da equipe.

### 
- Ferramenta de Benchmarking:

Este sistema para gerenciamento e análise de dados de vendas será uma solução robusta e eficiente para lidar com grandes volumes de transações, identificando padrões de compra e oferecendo insights valiosos para a loja online. A combinação de laços de repetição e recursividade permitirá que o sistema processe os dados de forma otimizada, enquanto o benchmarking garantirá que o desempenho seja constantemente monitorado e melhorado.
O algoritmo será testado com diferentes entradas para comparar o tempo de execução e a eficiência dos laços de repetição e da recursividade.



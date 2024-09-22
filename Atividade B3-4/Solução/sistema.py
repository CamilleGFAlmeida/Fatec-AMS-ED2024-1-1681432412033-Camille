import random
import timeit

# Simulação de um nó da rede
class NetworkNode:
    def __init__(self, id, processing_power):
        self.id = id
        self.processing_power = processing_power
        self.load = 0  # Carga de trabalho que o nó está processando (inicialmente 0)

# Função para simular o processamento de um nó
def process_node_load(node):
    node.load = random.randint(50, 200)  # Simulando a carga de trabalho de cada nó (em MB)
    print(f"Nó {node.id}: Carga de trabalho atribuída: {node.load} MB")

# Função para simular o balanceamento de carga da rede até atingir um estado estável
def simulate_load_distribution(nodes):
    balanced = False
    iteration = 0
    max_iterations = 10  # Limite de iterações para evitar laços infinitos
    while not balanced and iteration < max_iterations:
        iteration += 1
        print(f"\nSimulação de balanceamento - Iteração {iteration}")
        
        # Simulação do balanceamento ajustando a carga de cada nó
        for node in nodes:
            adjustment = random.randint(-10, 10)  # Simula o ajuste da carga
            node.load += adjustment
            node.load = max(0, node.load)  # Garante que a carga não seja negativa
            print(f"Nó {node.id}: Ajustando a carga para {node.load} MB")
        
        # Critério de parada: quando a variação entre os nós for pequena o suficiente
        max_load = max([node.load for node in nodes])
        min_load = min([node.load for node in nodes])
        print(f"Maior carga: {max_load} MB, Menor carga: {min_load} MB")
        
        if max_load - min_load <= 20:  # Critério de balanceamento
            balanced = True
            print("Carga balanceada entre os nós.")
        elif iteration == max_iterations:
            print("Limite máximo de iterações atingido, balanceamento não totalmente concluído.")

# Função recursiva para balancear os recursos entre nós
def balance_resources(node_list):
    if len(node_list) == 1:
        return node_list[0].load
    else:
        mid = len(node_list) // 2
        left_load = balance_resources(node_list[:mid])  # Recursão à esquerda
        right_load = balance_resources(node_list[mid:])  # Recursão à direita
        return (left_load + right_load) // 2  # Combina as cargas

# Função para verificar o tempo de processamento de cada nó
def check_processing_time(node):
    # Simulando tempo de processamento com base na carga
    time_to_process = node.load / node.processing_power
    print(f"Nó {node.id}: Tempo de processamento esperado: {time_to_process:.2f} segundos")
    return time_to_process

# Função principal
def main():
    # Criando uma lista de nós da rede
    network_nodes = [NetworkNode(id=i, processing_power=random.randint(1, 5)) for i in range(5)]
    
    # 1º laço de repetição: atribuir carga de trabalho a cada nó
    print("\nAtribuindo cargas de trabalho aos nós...")
    for node in network_nodes:
        process_node_load(node)
    
    # 2º laço de repetição: simular a distribuição de carga até balancear
    simulate_load_distribution(network_nodes)
    
    # Recursividade: balancear recursos entre os nós
    print("\nRecursividade para balancear os recursos:")
    balanced_load = balance_resources(network_nodes)
    print(f"Carga média balanceada entre os nós: {balanced_load} MB")
    
    # 3º laço de repetição: verificar tempo de processamento para cada nó
    print("\nVerificando tempos de processamento...")
    for node in network_nodes:
        check_processing_time(node)

# Medindo o tempo de execução de todo o processo
execution_time = timeit.timeit(main, number=1)
print(f"\nTempo total de execução do programa: {execution_time:.4f} segundos")

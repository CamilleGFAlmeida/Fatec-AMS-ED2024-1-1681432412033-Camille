import matplotlib.pyplot as plt
import networkx as nx
import time

# Definindo a classe do nó da árvore binária
class No:
    def __init__(self, dado):
        self.dado = dado
        self.esquerda = None
        self.direita = None

class ArvoreBinaria:
    def __init__(self):
        self.raiz = None
        self.G = nx.DiGraph()  # Grafo para visualização
        print("Estrutura de árvore binária criada.\n")

    # Função para criar um novo nó
    def criar_no(self, dado):
        print(f"Nó criado na memória com valor {dado}\n")
        return No(dado)

    # Inserção de um nó na árvore
    def inserir(self, dado):
        if self.raiz is None:
            self.raiz = self.criar_no(dado)
        else:
            self._inserir_rec(self.raiz, dado)
        self.visualizar_arvore(f"Árvore após inserir {dado}")

    def _inserir_rec(self, no, dado):
        if dado < no.dado:
            if no.esquerda is None:
                no.esquerda = self.criar_no(dado)
                print(f"Nó {dado} inserido à esquerda de {no.dado}")
            else:
                self._inserir_rec(no.esquerda, dado)
        elif dado > no.dado:
            if no.direita is None:
                no.direita = self.criar_no(dado)
                print(f"Nó {dado} inserido à direita de {no.dado}")
            else:
                self._inserir_rec(no.direita, dado)

    # Busca de um nó na árvore
    def buscar(self, dado):
        print(f"Buscando o nó com valor {dado}...\n")
        encontrado = self._buscar_rec(self.raiz, dado)
        if encontrado:
            print(f"Nó {dado} encontrado na árvore.\n")
        else:
            print(f"Nó {dado} não encontrado na árvore.\n")
        return encontrado

    def _buscar_rec(self, no, dado):
        if no is None:
            return False
        if no.dado == dado:
            return True
        elif dado < no.dado:
            return self._buscar_rec(no.esquerda, dado)
        else:
            return self._buscar_rec(no.direita, dado)

    # Remoção de um nó da árvore
    def remover(self, dado):
        print(f"Removendo o nó com valor {dado}...\n")
        self.raiz = self._remover_rec(self.raiz, dado)
        self.visualizar_arvore(f"Árvore após remoção de {dado}")

    def _remover_rec(self, no, dado):
        if no is None:
            return no
        if dado < no.dado:
            no.esquerda = self._remover_rec(no.esquerda, dado)
        elif dado > no.dado:
            no.direita = self._remover_rec(no.direita, dado)
        else:
            if no.esquerda is None:
                return no.direita
            elif no.direita is None:
                return no.esquerda
            temp = self._encontrar_minimo(no.direita)
            no.dado = temp.dado
            no.direita = self._remover_rec(no.direita, temp.dado)
        return no

    def _encontrar_minimo(self, no):
        while no.esquerda is not None:
            no = no.esquerda
        return no

    # Visualização da árvore com NetworkX e Matplotlib
    def visualizar_arvore(self, titulo=""):
        plt.clf()  # Limpa a figura em vez de criar uma nova
        self.G.clear()
        self._adicionar_nos(self.raiz)
        pos = self._get_pos(self.raiz, x=0, y=0, dx=1)
        nx.draw(self.G, pos, with_labels=True, arrows=False, node_size=800, node_color="skyblue", font_size=10)
        plt.title(titulo)
        plt.pause(0.5)  # Pausa mais curta para uma transição mais rápida

    def _adicionar_nos(self, no):
        if no is not None:
            self.G.add_node(no.dado)
            if no.esquerda:
                self.G.add_edge(no.dado, no.esquerda.dado)
                self._adicionar_nos(no.esquerda)
            if no.direita:
                self.G.add_edge(no.dado, no.direita.dado)
                self._adicionar_nos(no.direita)

    def _get_pos(self, no, x, y, dx):
        if no is None:
            return {}
        pos = {no.dado: (x, y)}
        if no.esquerda:
            pos.update(self._get_pos(no.esquerda, x - dx, y - 1, dx / 2))
        if no.direita:
            pos.update(self._get_pos(no.direita, x + dx, y - 1, dx / 2))
        return pos

# Função principal para executar o passo a passo
def executar_passos():
    plt.ion()  # Modo interativo
    arvore = ArvoreBinaria()
    
    # Passo 1: Criação da estrutura
    time.sleep(0.5)

    # Passo 2 e 3: Inserindo nós na árvore
    valores_inserir = [8, 3, 10, 1, 6, 14, 4, 7, 13]
    for valor in valores_inserir:
        arvore.inserir(valor)
        time.sleep(0.5)

    # Passo 4: Remover o nó com valor 10
    arvore.remover(10)
    time.sleep(0.5)

    # Passo 5: Buscar o nó com valor 6
    arvore.buscar(6)
    time.sleep(0.5)

    # Passo 6: Imprimir árvore final
    arvore.visualizar_arvore("Estrutura final da árvore")
    plt.ioff()  # Desativa o modo interativo
    plt.show()

# Executa os passos
executar_passos()

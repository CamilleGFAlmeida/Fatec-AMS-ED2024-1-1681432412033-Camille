/*// ------------------------------------ //
// Projeto B3-4                           //
//                                        //
// Autores: Camille Almeida, Thiago Gerbi,
 * Lucas Vilas Boas e Felipe Lins         //
 */
// Instituição: Fatec Antonio Russo        //
// Professor: Carlos Veríssimo             //
// Paradigma: Análise do Algoritmo         //
// Data: 01/10/2024                       //
// ------------------------------------ // */


package Vendas;

public class Venda {
    private Produto produto;
    private Cliente cliente;
    private int quantidade;
    private double valorTotal;

    public Venda(Produto produto, Cliente cliente, int quantidade) {
        this.produto = produto;
        this.cliente = cliente;
        this.quantidade = quantidade;
        this.valorTotal = quantidade * produto.getPreco();
    }

    public Produto getProduto() {
        return produto;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public double getValorTotal() {
        return valorTotal;
    }

    @Override
    public String toString() {
        return cliente.getNome() + " comprou " + quantidade + "x " + produto.getNome() + " por " + valorTotal;
    }
}



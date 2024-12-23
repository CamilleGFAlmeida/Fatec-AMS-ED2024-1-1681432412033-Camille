<<<<<<< HEAD
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

=======
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

>>>>>>> 370d8abc5e14bc16155f6fe4c42ffe57ff540498

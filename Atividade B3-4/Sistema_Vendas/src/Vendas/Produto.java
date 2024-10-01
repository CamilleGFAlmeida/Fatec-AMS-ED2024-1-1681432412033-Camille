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

public class Produto {
    private String nome;
    private String categoria;
    private double preco;

    public Produto(String nome, String categoria, double preco) {
        this.nome = nome;
        this.categoria = categoria;
        this.preco = preco;
    }

    public String getNome() {
        return nome;
    }

    public String getCategoria() {
        return categoria;
    }

    public double getPreco() {
        return preco;
    }

    @Override
    public String toString() {
        return nome + " - " + categoria + " - " + preco;
    }
}



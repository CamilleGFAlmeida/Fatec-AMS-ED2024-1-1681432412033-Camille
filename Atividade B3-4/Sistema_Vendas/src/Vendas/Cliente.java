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

public class Cliente {
    private String nome;
    private String email;

    public Cliente(String nome, String email) {
        this.nome = nome;
        this.email = email;
    }

    public String getNome() {
        return nome;
    }

    public String getEmail() {
        return email;
    }

    @Override
    public String toString() {
        return nome + " - " + email;
    }
}



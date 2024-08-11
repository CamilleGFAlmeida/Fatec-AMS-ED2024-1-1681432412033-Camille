/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                 Estrutura de Dados        */
/*                                                                        */
/*                           Camille Guillen                              */
/*         Objetivo: Calculo tempo de execução Insertion Sort             */            
/*                                                                        */
/*                                                       Data: 11/08/2024 */
/*------------------------------------------------------------------------*/


#include <stdio.h>


for j <- 2 to length[A]                // C1 * (n - 1)
    do key <- A[j]                     // C2 * (n - 1)
    // Insert A[j] into the sorted 
    // sequence A[1.. j - 1]
    i <- j - 1                         // C3 * (n - 1)
    while i > 0 and A[i] > key         // C4 * Sum(Tj)
        do A[i + 1] <- A[i]            // C5 * Sum(Tj)
        i <- i - 1                     // C6 * Sum(Tj)
    A[i + 1] <- key                    // C7 * (n - 1)


// modo 2: 

for j <- 2 to length[A]           // t (atribuição) + tn (lógica)
    do key <- A[j]                // 2tn (1 atribuição + 1 acesso)

// Insert A[j] into the sorted 
//sequence A[1.. j - 1]     
    i <- j - 1                    // 2tn (1 atribuição + 1 aritmética)
    
while i > 0                       // tn (lógica) 
    and A[i] > key               // tn (1 lógica + 1 acesso para A[i]) 
         do A[i + 1] <- A [i]   // tn (1 atribuição + 1 acesso para A[i]) 
             i <- i - 1        // 2tn (1 aritmética)        
    A[i + 1] <- key           // 2tn (atribuição + aritmética) 


//Acessos + Atribuições + Aritmética:
//t + 3n + 4tn + 4tn² + 5tn² + 2tn = 9tn² + 9tn + t



    
/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: entender o método de ordenação   *
* bubble sort                                            *
* Data - 14/05/2025                                      * 
* Autor: Ruan Victor e Caio Fuschillo                    *
*--------------------------------------------------------*/


#include <stdio.h>

// Função para preencher o vetor com valores informados pelo usuário
void preencherVet(int *vet, int tam){
    printf("\nPREENCHA UM VETOR COM 10 POSICOES\n");

    for (int i = 0; i < tam; i++){
        printf("DIGITE O %do VALOR: ", i + 1);
        scanf("%d", (vet + i)); // Lê o valor e armazena na posição i do vetor
    }
}

// Função que ordena o vetor com o algoritmo Bubble Sort
int bubbleSort(int *vet, int tam) {
    int aux, i;
    int troca;     // variavel que evita loops desnecessarios
    int *ptr;      // Ponteiro para percorrer o vetor

    do {
        troca = 0;
        for (ptr = vet; ptr < vet + tam - 1; ptr++) {
            // Compara o valor atual com o próximo
            if (*ptr > *(ptr + 1)) {
                // Troca os valores usando variável auxiliar
                aux = *(ptr + 1);
                *(ptr + 1) = *ptr;
                *ptr = aux;
                troca = 1; 
            }
        }
        tam--; 
    } while (troca); // Continua enquanto houver trocas
}

// Função que imprime os valores do vetor
void imprimir(int *vet, int tam) {
    printf("\nORDENACAO POR BUBBLE SORT\n");
    for (int i = 0; i < tam; i++) {
        printf("vetor[%d] = %d\n", i, *(vet + i)); 
    }
}

// Função principal
int main() {
    int vetor[10];
    int tam = sizeof(vetor) / sizeof(vetor[0]);

    preencherVet(vetor, tam);    
    bubbleSort(vetor, tam);      
    imprimir(vetor, tam);       

    return 0;
}

/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: entender o método de ordenação   *
* insertion sort                                         *
* Data - 14/05/2025                                      * 
* Autor: Ruan Victor e Caio Fuschillo                    *
*--------------------------------------------------------*/

#include <stdio.h>

// Função para preencher o vetor com valores fornecidos pelo usuário
void preencherVet(int *vet, int tam){
    printf("\nPREENCHA UM VETOR COM 10 POSICOES\n");

    for (int i = 0; i < tam; i++) {
        // Solicita ao usuário que digite um valor e armazena no vetor usando ponteiro
        printf("DIGITE O %do VALOR: ", i + 1);
        scanf("%d", (vet + i));
    }
}

// Função que ordena o vetor usando o algoritmo Insertion Sort
void insertionSort(int *vet, int tam) {
    for (int i = 1; i < tam; i++) {
        int *ptr = vet + i;  // Ponteiro para o endereço atual
        int aux = *ptr;      // Armazena o valor atual
        int *j = ptr - 1;    // Ponteiro para o endereço anterior

        // Move elementos maiores que 'aux' uma posição à frente
        while (j >= vet && *j > aux) {
            *(j + 1) = *j;   // Desloca o valor para frente
            j--;             // Move o ponteiro uma posição para trás
        }

        // Insere o valor de 'aux' na posição correta
        *(j + 1) = aux;
    }
}

// Função para imprimir o vetor ordenado
void imprimir(int *vet, int tam) {
    printf("\nORDENACAO POR INSERTION SORT\n");
    for (int i = 0; i < tam; i++) {
        printf("vetor[%d] = %d\n", i, *(vet + i));
    }
}

int main() {
    int vetor[10]; 
    int tam = sizeof(vetor) / sizeof(vetor[0]); // Calcula o tamanho do vetor

    preencherVet(vetor, tam);  
    insertionSort(vetor, tam);  
    imprimir(vetor, tam);      
    
    return 0; 
}

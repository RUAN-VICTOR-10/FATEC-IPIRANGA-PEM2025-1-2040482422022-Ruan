#include <stdio.h>


void preencherVet(int *vet, int tam){
    printf("\nPREENCHA UM VETOR COM 10 POSICOES\n");

    for (int i=0; i< tam; i++){
        printf("DIGITE O %do VALOR: ", i+1);
        scanf("%d", (vet + i));
    }
}
// Função que ordena um vetor utilizando o método insertion sort com ponteiros
void insertionSort(int *vet, int tam) {
    for (int i = 1; i < tam; i++) {
        int *ptr = vet + i;  // vet + i refere-se ao endereco
        int aux = *ptr;
        int *j = ptr - 1;

        while (j >= vet && *j > aux) {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = aux;
    }
}

void imprimir(int *vet, int tam) {
    printf("\nORDENACAO POR INSERTION SORT\n");
    for (int i = 0; i < tam; i++) {
        printf("vetor[%d] = %d\n", i, *(vet + i));
    }
}

int main() {
    int vetor[10]; 
    int tam = sizeof(vetor) / sizeof(vetor[0]);

    preencherVet(vetor, tam);
    insertionSort(vetor, tam);
    imprimir(vetor, tam);
    
    return 0;
}

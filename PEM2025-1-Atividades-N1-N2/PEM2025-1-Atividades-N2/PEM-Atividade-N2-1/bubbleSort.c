#include <stdio.h>

void preencherVet(int *vet, int tam){
    printf("\nPREENCHA UM VETOR COM 10 POSICOES\n");

    for (int i=0; i< tam; i++){
        printf("DIGITE O %do VALOR: ", i+1);
        scanf("%d", (vet + i));
    }
}
// *vet e vet[] sao a mesma coisa para o compilador no parametro da funcao
int bubbleSort(int *vet, int tam) {
    int aux, i;
    int troca;
    int *ptr;

    do {
        troca = 0;
        for (ptr = vet; ptr < vet + tam - 1; ptr++) {
            if (*ptr > *(ptr + 1)) {
                aux = *(ptr + 1);
                *(ptr + 1) = *ptr;
                *ptr = aux;
                troca = 1;
            }
        }
     tam--;
    } while (troca);
}

void imprimir(int *vet, int tam) {
    printf("\nORDENACAO POR BUBBLE SORT\n");
    for (int i = 0; i < tam; i++) {
        printf("vetor[%d] = %d\n", i, *(vet+i));
    }
}

int main() {
    int vetor[10];
    int tam = sizeof(vetor) / sizeof(vetor[0]);
    
    preencherVet(vetor, tam);
    bubbleSort(vetor, tam); 
    imprimir(vetor, tam);
   
    return 0;
}

/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: organização do setor de estoque  *
* Data - 14/03/2025                                      * 
* Autor: Ruan Victor                                     *
*--------------------------------------------------------*/

#include <stdio.h> // input output
#include <string.h> // Manipulacao de strings
#include <ctype.h> // verificar caracteres

#define NUM_RUAS 3 // numero de ruas no armazem
#define NUM_GONDOLAS 10  // Cada rua tem 10 gondolas
#define MAX_LOTES 5      // Cada gondola pode ter no maximo 5 lotes
#define MAX_PRODUTO 5    // Formato para o codigo do produto: Letra + 3 digitos (A123\0)

// Funcao para validar o codigo do produto (Letra + 3 digitos)
int validar_codigo_produto(char *codigo_produto) {
    if (strlen(codigo_produto) != 4) { // se tamanho do codigo for diferente de 4. para.
        return 0;
    }
    if (!isalpha(codigo_produto[0])) { // se o primeiro valor for diferente de uma letra. para.
        return 0;
    }
    for (int i = 1; i < 4; i++) { // se no indice 1, 2 e 3 for diferente de numeros. para
        if (!isdigit(codigo_produto[i])) {
            return 0;
        }
    }
    return 1; // o codigo segue o padrao
}

// Funcao para estocar um produto dentro do limite de 5 lotes por gondola
void estocar_produto(char armazem[NUM_RUAS][NUM_GONDOLAS][MAX_LOTES][MAX_PRODUTO], char *codigo_produto) {
    for (int rua = 0; rua < NUM_RUAS; rua++) {
        for (int gondola = 0; gondola < NUM_GONDOLAS; gondola++) {
            //strcmp eh usada para comparar strings
            if (strcmp(armazem[rua][gondola][0], codigo_produto) == 0) { // se strings forem iguais...
                for (int i = 0; i < MAX_LOTES; i++) {
                    if (strlen(armazem[rua][gondola][i]) == 0) { // se a posicao da matriz estiver vazia
                        strcpy(armazem[rua][gondola][i], codigo_produto); //copia o codigo do produto para a posicao da matriz
                        printf("Lote do produto %s adicionado na Gondola %c%d.\n", codigo_produto, 'A' + rua, gondola + 1);
                        return;
                    }
                }
                //senao, a gondola esta cheia
                printf("A Gondola %c%d esta cheia para o produto %s.\n", 'A' + rua, gondola + 1, codigo_produto);
                return;
            }
        }
    }
    //se nao encontrado o produto, estacar em uma gondola vazia
    for (int rua = 0; rua < NUM_RUAS; rua++) {
        for (int gondola = 0; gondola < NUM_GONDOLAS; gondola++) {
            if (strlen(armazem[rua][gondola][0]) == 0) { // a gondola esta vazia?
                strcpy(armazem[rua][gondola][0], codigo_produto); // copia o codigo do produto
                printf("Produto %s estocado na Gondola %c%d.\n", codigo_produto, 'A' + rua, gondola + 1);
                return;
            }
        }
    }
    printf("Nao ha espaco disponivel no estoque!\n"); // nao ha espaco nas gondolas 
} 

// Funcao para retirar um produto(lote) do estoque
void retirar_produto(char armazem[NUM_RUAS][NUM_GONDOLAS][MAX_LOTES][MAX_PRODUTO], char *codigo_produto) {
    for (int rua = 0; rua < NUM_RUAS; rua++) {
        for (int gondola = 0; gondola < NUM_GONDOLAS; gondola++) {
            for (int i = 0; i < MAX_LOTES; i++) {
                if (strcmp(armazem[rua][gondola][i], codigo_produto) == 0) { // se posicao do armazem for igual ao codigo...
                    memset(armazem[rua][gondola][i], 0, sizeof(armazem[rua][gondola][i])); // todos os bytes na posicao especifica da matriz armazem sera substituido por 0
                    printf("Lote do produto %s retirado da Gondola %c%d.\n", codigo_produto, 'A' + rua, gondola + 1);
                    return;
                }
            }
        }
    }
    printf("Produto %s nao encontrado no estoque!\n", codigo_produto);
}

// Funcao para mostrar o status do estoque
void mostrar_estoque(char armazem[NUM_RUAS][NUM_GONDOLAS][MAX_LOTES][MAX_PRODUTO]) {
    printf("\nStatus do estoque:\n");
    for (int i = 0; i < NUM_RUAS; i++) {
        printf("Rua %c:\n", 'A' + i);
        for (int j = 0; j < NUM_GONDOLAS; j++) {
            int quantidade_lotes = 0;
            for (int k = 0; k < MAX_LOTES; k++) {
                if (strlen(armazem[i][j][k]) > 0) {
                    quantidade_lotes++;
                }
            }
            printf("  Gondola %d: %d lote(s) ocupado(s)\n", j + 1, quantidade_lotes);
        }
    }
}

int main() {
    char armazem[NUM_RUAS][NUM_GONDOLAS][MAX_LOTES][MAX_PRODUTO] = {{{{0}}}}; // inicializa a estrutura do armazem
    int opcao; // armazena a escolha do usuario
    char codigo_produto[MAX_PRODUTO]; // codigo do produto possui 5 campos

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Estocar um produto\n");
        printf("2 - Retirar um produto\n");
        printf("3 - Mostrar o status do estoque\n");
        printf("4 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) { //bloco de decisao
            case 1: // se codigo estiver errado. exibir menssagem de erro. senao estocar produto
                printf("Digite o codigo do produto (ex: S123): ");
                scanf("%s", codigo_produto);
                if (!validar_codigo_produto(codigo_produto)) { 
                    printf("Codigo invalido! O codigo deve seguir o formato Letra + 3 digitos.\n");
                } else {
                    estocar_produto(armazem, codigo_produto);
                }
                break;

            case 2: // retirar produto do armazem
                printf("Digite o codigo do produto: ");
                scanf("%s", codigo_produto);
                retirar_produto(armazem, codigo_produto);
                break;

            case 3: // exibir status do estoque
                mostrar_estoque(armazem);
                break;

            case 4: // sair do programa
                printf("Saindo do programa...\n");
                return 0;

            default: // garante que seja possuivel somente 4 opcoes
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
}

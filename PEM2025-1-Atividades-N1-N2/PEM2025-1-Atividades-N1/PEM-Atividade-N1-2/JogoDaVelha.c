/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Aula 3-Jogo da Velha             *
* Data - 28/02/2025                                      * 
* Autor: Ruan Victor                                     *
*--------------------------------------------------------*/

#include <stdio.h>

#define TAM 3  // Tamanho do tabuleiro 3 linhas e 3 colunas

//funcao que exibe o tabuleiro
void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAM - 1) printf("|");
        }
        printf("\n");
        if (i < TAM - 1) printf("---+---+---\n");
    }
}
//funcao para a verificacao de vencedores
int verificarVencedor(char tabuleiro[TAM][TAM], char jogador) {
    
    // Verificando se um dos jogadores venceu a linha
    for (int i = 0; i < TAM; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1;  // Linha vencida
        }
    }
    
    // Verificando se um dos jogadores venceu a coluna
    for (int i = 0; i < TAM; i++) {
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {
            return 1;  // Coluna vencida
        }
    }
    
    // Verificando se um dos jogadores venceu a diagonal
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1;  // Diagonal principal vencida
    }

    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1;  // Diagonal secundária vencida
    }
    //nao ha  linhas, colunas ou diagonais vencidas
    return 0;  
}

int main() {
    char tabuleiro[TAM][TAM] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};  //  tabuleiro inicia vazio
    int linha, coluna, jogada = 1;  // Jogada 1 começa com o jogador 1
    int vencedor = 0;
    int movimentos = 0;  // Contador de movimentos
    char jogador_atual;

    // Enquanto nao haver vencedor e movimentos for menor que 9
    while (!vencedor && movimentos < TAM * TAM) {
        exibirTabuleiro(tabuleiro);  // Exibe o tabuleiro com as jogadas atuais


        // Determina qual jogador está jogando
        if (jogada % 2 != 0) {
            jogador_atual = 'X';  // Jogador 1 
        } else {
            jogador_atual = 'O';  // Jogador 2 
        }

        // Exibe a vez do jogador atual
        printf("Eh a vez do jogador %c\n", jogador_atual);

        printf("Escolha a linha (1 a 3): ");
        scanf("%d", &linha);
        printf("Escolha a coluna (1 a 3): ");
        scanf("%d", &coluna);

        linha--;  // tira uma unidade da linha, pois o usuario digitará de 1 à 3
        coluna--;  // tira uma unidade da coluna, pois o usuario digitará de 1 à 3

        // Verifica se a posição escolhida esta vazia
        if (tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogador_atual;  // Marca a jogada no tabuleiro

            // Verifica se houve vencedor após a jogada
            if (verificarVencedor(tabuleiro, jogador_atual)) {
                exibirTabuleiro(tabuleiro);  // Exibe o tabuleiro final
                printf("O jogador %c venceu!\n", jogador_atual);
                vencedor = 1;  // Define que houve um vencedor
            } else { // senao, incrementa um movimento e uma jogada
                movimentos++;  
                jogada++;   
            }
        } else {  //se o tabuleiro nao estiver vazio, eh enviado uma menssagem
            printf("A posicao ja esta ocupada! Tente novamente.\n");
        }
    }

    // Se o jogo terminou em empate
    if (!vencedor) {
        printf("EMPATE!\n");
    }

    return 0;
}



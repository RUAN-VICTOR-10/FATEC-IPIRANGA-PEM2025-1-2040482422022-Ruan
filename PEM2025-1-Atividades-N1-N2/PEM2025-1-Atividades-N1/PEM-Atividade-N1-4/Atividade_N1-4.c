/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: explorar e exibir uma arvore de  *
* diretório com recursividade                            *
* Data - 27/03/2025                                      * 
* Autor: Ruan Victor                                     *
*--------------------------------------------------------*/

#include <stdio.h>          // Biblioteca para entrada e saída padrão (printf)
#include <stdlib.h>         // Biblioteca para funções de alocação dinâmica de memória (malloc, free), controle de processo, etc.
#include <dirent.h>         // Biblioteca para manipulação de diretórios (opendir, readdir, closedir)
#include <sys/types.h>      // Biblioteca para tipos de dados relacionados a sistemas de arquivos, como o tipo de dado para informações de arquivos.
#include <sys/stat.h>       // Biblioteca que define estruturas de dados para estatísticas de arquivos, como verificações de tipo de arquivo.
#include <unistd.h>         // Biblioteca que fornece funções para manipulação do sistema operacional (por exemplo, para obter informações sobre arquivos).
#include <string.h>         // Biblioteca para manipulação de strings (como strlen, strcspn).

// Função que exibe o nome de um arquivo ou diretório com indentação baseada no nível de profundidade.
void exibirNome(const char *nomeArquivo, int nivel) {
    // Laço para imprimir a indentação de acordo com o nível de profundidade no diretório
    for (int i = 0; i < nivel; i++) {
        printf("    ");  // espaços por nível de profundidade para representar visualmente a hierarquia
    }
    printf("%s\n", nomeArquivo);  // Exibe o nome do arquivo ou diretório
}

// Função que verifica se o caminho fornecido é um diretório ou não.
int ehDiretorio(const char *caminho) {
    struct stat informacoesArquivo;  // Estrutura que irá armazenar as informações sobre o arquivo/diretório
    
    // A função 'stat' retorna as informações sobre o arquivo/diretório especificado.
    if (stat(caminho, &informacoesArquivo) == 0 && S_ISDIR(informacoesArquivo.st_mode)) {
        return 1;  // Se for um diretório, retorna 1.
    }
    return 0;  // Se não for um diretório, retorna 0.
}

// Função recursiva que lista arquivos e subdiretórios a partir do caminho fornecido.
void listarDiretorio(const char *caminho, int nivel) {
    // Abre o diretório especificado
    DIR *diretorio = opendir(caminho);
    if (diretorio == NULL) {
        perror("Nao foi possivel abrir o diretorio");  // Exibe um erro caso o diretório não possa ser aberto
        return;  // Se o diretório não foi aberto, retorna para evitar processamento adicional
    }

    struct dirent *entrada;  // Ponteiro para armazenar as informações sobre cada entrada no diretório
    // Laço para ler cada entrada no diretório
    while ((entrada = readdir(diretorio)) != NULL) {
        // Ignora os diretórios "." e "..", que são referências ao diretório atual e ao diretório pai
        if (entrada->d_name[0] == '.') {
            continue;  // Pula essas entradas
        }

        // Cria o caminho completo do arquivo/diretório
        char caminhoCompleto[1024];  // Buffer para armazenar o caminho completo
        snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/%s", caminho, entrada->d_name);

        // Exibe o nome da entrada com a indentação apropriada
        exibirNome(entrada->d_name, nivel);

        // Se for um diretório, chama recursivamente para listar seus arquivos e subdiretórios
        if (ehDiretorio(caminhoCompleto)) {
            listarDiretorio(caminhoCompleto, nivel + 1);  // Chama recursivamente para subdiretórios
        }
    }

    closedir(diretorio);  // Fecha o diretório após a exploração
}

// Função principal que solicita ao usuário o caminho do diretório e inicia a exploração.
void explorarDiretorio() {
    char caminho[1024];  // Buffer para armazenar o caminho do diretório fornecido pelo usuário

    // Solicita ao usuário o caminho do diretório
    printf("Digite o caminho do diretorio: ");
    fgets(caminho, sizeof(caminho), stdin);  // Recebe o caminho do diretório via entrada padrão

    // Remove o caractere de nova linha que pode ser adicionado pelo fgets
    caminho[strcspn(caminho, "\n")] = 0;

    // Exibe o diretório inicial e começa a exploração recursiva
    printf("Estrutura de Diretorios para: %s\n", caminho);
    listarDiretorio(caminho, 0);  // Chama a função recursiva para listar os arquivos e subdiretórios
}

// Função principal que inicia a execução do programa.
int main() {
    explorarDiretorio();  // Inicia a exploração do diretório
    return 0;  
}

#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATOS 50 // Define o número máximo de candidatos que o programa pode lidar

int main() {
    char nome[30]; // Variável para armazenar os nomes dos candidatos
    float PE[4], AC[5], PP[10], EB[3]; // Arrays para armazenar as notas
    float NF[MAX_CANDIDATOS]; // Array para armazenar a nota final de cada candidato
    char candidatos[MAX_CANDIDATOS][30];  // Matriz 2D para armazenar os nomes dos candidatos
    int num_candidatos; // Variável para armazenar o número de candidatos

    // Perguntar e armazenar o número de candidatos
    printf("Digite o numero de candidatos (maximo 50): ");
    scanf("%d", &num_candidatos);

    // Bloco de decisão para não ultrapassar o limite de 50 candidatos
    if (num_candidatos > MAX_CANDIDATOS) {
        printf("Numero de alunos excede o limite permitido de %d.\n", MAX_CANDIDATOS);
        return 1;
    }

    // Entrada das informações dos alunos
    for (int i = 0; i < num_candidatos; i++) { // Loop para cada candidato
        printf("\nDigite o nome do aluno %d: ", i + 1);
        getchar(); // Para capturar o '\n' que sobra após o scanf anterior
        fgets(candidatos[i], sizeof(candidatos[i]), stdin); // Lê a string e armazena no array candidatos
        candidatos[i][strcspn(candidatos[i], "\n")] = 0;   // Remove o caractere de nova linha do final do nome

        // Entrada das notas de PE
        printf("Digite as notas de PE (4 notas):\n");
        for (int j = 0; j < 4; j++) {
            do { // Loop que lê impede notas menores que 0 e maiores que 10
                scanf("%f", &PE[j]);
                if (PE[j] < 0.0 || PE[j] > 10.0) {
                    printf("Nota invalida! Digite novamente (entre 0.0 e 10.0): ");
                }
            } while (PE[j] < 0.0 || PE[j] > 10.0); // Repete até que uma nota válida seja inserida
        }

        // Entrada das notas de AC
        printf("Digite as notas de AC (5 notas):\n");
        for (int j = 0; j < 5; j++) {
            do {
                scanf("%f", &AC[j]);
                if (AC[j] < 0.0 || AC[j] > 10.0) {
                    printf("Nota invalida! Digite novamente (entre 0.0 e 10.0): ");
                }
            } while (AC[j] < 0.0 || AC[j] > 10.0);
        }

        // Entrada das notas de PP
        printf("Digite as notas de PP (10 notas):\n");
        for (int j = 0; j < 10; j++) {
            do {
                scanf("%f", &PP[j]);
                if (PP[j] < 0.0 || PP[j] > 10.0) {
                    printf("Nota invalida! Digite novamente (entre 0.0 e 10.0): ");
                }
            } while (PP[j] < 0.0 || PP[j] > 10.0);
        }

        // Entrada das notas de EB
        printf("Digite as notas de EB (3 notas):\n");
        for (int j = 0; j < 3; j++) {
            do {
                scanf("%f", &EB[j]);
                if (EB[j] < 0.0 || EB[j] > 10.0) {
                    printf("Nota invalida! Digite novamente (entre 0.0 e 10.0): ");
                }
            } while (EB[j] < 0.0 || EB[j] > 10.0);
        }

        // Ordena as notas para PE, AC, PP e EB, removendo a maior e a menor para somar as notas restantes
        float sum_PE = 0, sum_AC = 0, sum_PP = 0, sum_EB = 0;
        
        // Ordenando PE e somando a média das notas intermediárias
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (PE[j] > PE[k]) {
                    float temp = PE[j];
                    PE[j] = PE[k];
                    PE[k] = temp;
                }
            }
        }
        sum_PE = PE[1] + PE[2]; // Ignora a menor e a maior nota

        // Ordenando AC e somando a média das notas intermediárias
        for (int j = 0; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                if (AC[j] > AC[k]) {
                    float temp = AC[j];
                    AC[j] = AC[k];
                    AC[k] = temp;
                }
            }
        }
        sum_AC = AC[1] + AC[2] + AC[3]; // Ignora a menor e a maior nota

        // Ordenando PP e somando a média das notas intermediárias
        for (int j = 0; j < 10; j++) {
            for (int k = j + 1; k < 10; k++) {
                if (PP[j] > PP[k]) {
                    float temp = PP[j];
                    PP[j] = PP[k];
                    PP[k] = temp;
                }
            }
        }
        sum_PP = PP[1] + PP[2] + PP[3] + PP[4] + PP[5] + PP[6] + PP[7] + PP[8]; // Ignora a menor e a maior nota

        // Ordenando EB e somando a média das notas intermediárias
        for (int j = 0; j < 3; j++) {
            for (int k = j + 1; k < 3; k++) {
                if (EB[j] > EB[k]) {
                    float temp = EB[j];
                    EB[j] = EB[k];
                    EB[k] = temp;
                }
            }
        }
        sum_EB = EB[1]; 

        // Calculando a nota final (NF)
        NF[i] = (sum_PE * 0.3) + (sum_AC * 0.1) + (sum_PP * 0.4) + (sum_EB * 0.2);
    }

    // Ordenando os candidatos pela nota final (NF)
    for (int i = 0; i < num_candidatos - 1; i++) {
        for (int j = i + 1; j < num_candidatos; j++) {
            if (NF[i] < NF[j]) { // Se a nota final do candidato i for menor que a do candidato j
                // Troca as notas finais
                float temp_nf = NF[i];
                NF[i] = NF[j];
                NF[j] = temp_nf;

                // Troca os nomes correspondentes as notas acima
                char temp_nome[30];
                //é usado para copiar uma string de um array para outro.
                //sintaxe - char *strcpy(char *dest, const char *scr); //dest= destino e src = a string que sera copiada
                strcpy(temp_nome, candidatos[i]);
                strcpy(candidatos[i], candidatos[j]);
                strcpy(candidatos[j], temp_nome);
            }
        }
    }

    // Exibindo os 15 melhores candidatos
    printf("\nTop 15 alunos:\n");
    for (int i = 0; i < 15 && i < num_candidatos; i++) { // Loop para os 15 melhores (ou menos, se houver menos candidatos)
        printf("%d. %s - Nota Final: %.2f\n", i + 1, candidatos[i], NF[i]); // Imprime a posição, nome e nota final
    }

    return 0; // Indica que o programa terminou com sucesso
}

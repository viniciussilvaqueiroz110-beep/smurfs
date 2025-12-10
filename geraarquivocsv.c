#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SMURFS 3
#define NAME_LEN 100

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "help") == 0) {
        printf("Desenvolvido por Rayan Lima\n");
        return 0;
    }

    char smurfs[MAX_SMURFS][NAME_LEN];
    int capturas[MAX_SMURFS];
    char buffer[128];

    for (int i = 0; i < MAX_SMURFS; i++) {
        printf("Digite o nome do Smurf %d: ", i + 1);
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            fprintf(stderr, "Erro ao ler o nome.\n");
            return 1;
        }
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline
        strncpy(smurfs[i], buffer, NAME_LEN - 1);
        smurfs[i][NAME_LEN - 1] = '\0';

        printf("Digite a quantidade de capturas do Smurf %d: ", i + 1);
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            fprintf(stderr, "Erro ao ler as capturas.\n");
            return 1;
        }
        capturas[i] = atoi(buffer);
    }

    FILE *f = fopen("smurfs.csv", "w");
    if (!f) {
        perror("Erro ao abrir smurfs.csv");
        return 1;
    }

    for (int i = 0; i < MAX_SMURFS; i++) {
        int codigo = i + 1;
        fprintf(f, "%02d,%s,%02d\n", codigo, smurfs[i], capturas[i]);
    }

    fclose(f);
    printf("Arquivo smurfs.csv gerado com sucesso!\n");

    return 0;
}
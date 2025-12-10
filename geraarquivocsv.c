#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SMURFS 3
#define NAME_LEN 100

int main()

    char smurfs[MAX_SMURFS][NAME_LEN];
    int capturas[MAX_SMURFS];
    char buffer[128];

    for (int i = 0; i < MAX_SMURFS; i++) {
        
       
        smurfs[i] = "smurf";

        capturas[i] = 1;
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

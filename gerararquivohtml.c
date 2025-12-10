#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cabecalho(FILE *f) {
    fprintf(f,
        "<!DOCTYPE html>\n"
        "<html lang=\"pt-BR\">\n"
        "<head>\n"
        "    <meta charset=\"UTF-8\">\n"
        "    <title>Smurfs Capturados</title>\n"
        "</head>\n"
        "<body>\n"
        "    <h1>Smurfs</h1>\n"
        "    <ul>\n"
    );
}

void rodape(FILE *f) {
    fprintf(f,
        "    </ul>\n"
        "    <p>Desenvolvido por Rayan Lima</p>\n"
        "</body>\n"
        "</html>\n"
    );
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "help") == 0) {
        printf("Desenvolvido por Rayan Lima\n");
        return 0;
    }

    FILE *entrada = fopen("smurfs.csv", "r");
    FILE *saida = fopen("smurfs.html", "w");

    if (!entrada) {
        perror("Erro ao abrir smurfs.csv");
        return 1;
    }
    if (!saida) {
        perror("Erro ao criar smurfs.html");
        fclose(entrada);
        return 1;
    }

    char linha[256];
    char matricula[10];
    char nome[128];
    char capturas[10];

    cabecalho(saida);

    while (fgets(linha, sizeof(linha), entrada)) {
        /* Leitura segura: %2[^,] pega até 2 caracteres antes da vírgula,
           %127[^,] pega até 127 caracteres para o nome (evita overflow),
           %2[^,\n] pega até 2 caracteres para capturas. */
        if (sscanf(linha, "%2[^,],%127[^,],%2[^,\n]", matricula, nome, capturas) >= 2) {
            fprintf(saida, "        <li>%s - %s - %s</li>\n", matricula, nome, capturas);
        }
    }

    rodape(saida);

    fclose(entrada);
    fclose(saida);

    printf("Arquivo smurfs.html gerado com sucesso!\\n");

    return 0;
}
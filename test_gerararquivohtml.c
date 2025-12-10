#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("smurfs.html", "r");
    assert(f != NULL); // O arquivo deve existir (gerado pelo programa)
    char buf[8192];
    size_t n = fread(buf, 1, sizeof(buf) - 1, f);
    buf[n] = '\0';
    fclose(f);

    /* A versão alterada do gerador de HTML usa listas (<ul>/<li>).
       Portanto testamos se existe pelo menos uma tag <li>. */
    assert(strstr(buf, "<li>") != NULL);

    printf("Teste passou: tag <li> encontrada em smurfs.html\n");
    return 0;
}


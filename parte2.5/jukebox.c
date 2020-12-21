#include <stdio.h>
#include <string.h>

char musicas[][80] = {
    "I left my heart at Harvard med school",
    "Newark, Newark - a wonderful town",
    "Dancing with a dork",
    "From here to maternity",
    "The girl from Iwo Jima"};

void procurar(char busca[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strstr(musicas[i], busca))
            printf("Musica %i: %s \n", (i + 1), musicas[i]);
    }
}

int main()
{
    char buscaInput[80];
    printf("Buscar por: ");
    // fgets(buscaInput, 80, stdin); /* fgets coloca no final do input \0 e \n se detectado */
    scanf("%79s", buscaInput);
    procurar(buscaInput);
    return 0;
}

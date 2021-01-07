#include <stdio.h>

int main(int argc, char const *argv[])
{
    char primNome[20];
    char *pointer = primNome;
    printf("Escreva seu nome: ");
    /* scanf("%s %i", primNome, &valor); */
    /* fgets(primNome, sizeof(primNome), stdin); */
    fgets(pointer, 20, stdin);
    printf("%s", primNome);
}

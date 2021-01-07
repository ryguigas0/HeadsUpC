#include <stdio.h>

void getSize(char str[]){ /* Recebe um ponteiro */
    printf("A cópia do array de caracters tem valor: %s", str); /* Valor que o ponteiro aponta */
    printf("A cópia da mensagem ocupa %lu bytes\n", sizeof(str)); /* Tamanho do ponteiro */
}

int main()
{
    char mensagem[] = "Turtles!";
    printf("Esta escrito na mensagem: %s\n", mensagem);
    printf("A mensagem ocupa %lu bytes\n", sizeof(mensagem));
    getSize(&mensagem);
    return 0;
}
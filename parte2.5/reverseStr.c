#include <stdio.h>
#include <string.h>

/* Mais louco que brainfuck isso */
void reverse(char *s)
{
    size_t len = strlen(s);
    /* Pega o tamanho da string armazenada no ponteiro s */
    /* size_t -> endereço de parâmetro é um long, mas como não tem valor explicito é unasigned */

    char *t = s + len - 1;
    /* Pega o endereço da última letra */
    /* tamanho da string + local na memória (s é ponteiro) - 1 (encaixar no index) */

    // while (t >= s) /* Enquanto t for um endereço a frente ou igual de s */
    // {
    //     printf("%c", *t); /* Escreva o caractere que o endereço do t está armazenando */
    //     t = t - 1;        /* faça t apontar para um endereço anterior*/
    // }
    for (; t >= s; t--) /* Resumindo código do while acima */
        printf("%c", *t);
    puts("");
}

int main(int argc, char const *argv[])
{
    char string[] = "JQK";
    reverse(string);
    return 0;
}

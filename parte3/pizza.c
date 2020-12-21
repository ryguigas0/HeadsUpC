#include <stdio.h>
#include <unistd.h>

int main(int argc, char *const *argv)
{
    char *delivery = ""; /* Delivery aponta para o endereço da string */
    int thick = 0;       /* thick vale 0 == false */
    char ch;             /* O caractere da flag */
    /* pega o caractere da flag a partir do que passou no getopt (-t e -d são válidos,mas -d tem parametros a mais) 
    e vê se não existe mais opções ( == -1) */
    while ((ch = getopt(argc, argv, "d:t")) != -1)
    {
        switch (ch)
        {
        case 'd':              /* Caso for -d */
            delivery = optarg; /* Faça delivery apontar para o endereço da string do parametro desse argumento*/
            break;
        case 't':       /* Caso for -t */
            thick = 1; /* 1 == true */
            break;
        default: /* Se for nenhum caso, dê erro */
            fprintf(stderr, "Unknown option: %s\n", optarg);
            return 1;
        }
    }

    /* pula os argumentos já lidos */
    argc -= optind; /* Tira do total de argumentos */
    argv += optind; /* Pula os argumentos lidos */

    if (thick) /* 1 == true e 0 == false */
        puts("Thick crust.");
    if (delivery[0]) /* 0 == false, então != 0 é true */
        printf("To be delivered %s.\n", delivery);
    puts("Ingredients: ");
    /* Pega os outros argumentos */
    for (int count = 0; count < argc; count++)
        puts(argv[count]); /* e coloca no console */

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct island
{
    char *name;
    char *opens;
    char *closes;
    struct island *next;
};

void display(struct island *start)
{
    struct island *i = start;
    for (; i != NULL; i = i->next)
        printf("The island %s is open from %s to %s\n", i->name, i->opens, i->closes);
}

struct island *create(char *name) /* recebe o ponteiro que aponta para um array char */
{
    struct island *i = malloc(sizeof(struct island));
    // i->name = name; -> pega o endereço do array de chars name
    /* Logo o que mudar nesse endereço mudaria para todos */
    i->name = strdup(name); /* Duplica o conteudo no endereço do array de chars name usando malloc e devolve um ponteiro*/
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void release(struct island *start) /* ONDE USA MALLOC PRECISA LIBERAR */
{
    struct island *next  = NULL;
    for (struct island *i = start; i != NULL; i = next)
    {
        next = i->next; /* Antes de remover, guarda o endereço do próximo endereço */
        free(i->name); /* Libera o espaço da duplicata da string */
        free(i); /* Libere o espaço que o dado ocupa */
    }
}

int main()
{
    struct island *start, *i, *next = NULL;
    char name[80];
    for (; fgets(name, 80, stdin) != NULL; i = next)
    {
        next = create(name);
        if (start == NULL)
            start = next;
        if (i != NULL)
            i->next = next;
    }
    display(start);
    release(start);
    return 0;
}

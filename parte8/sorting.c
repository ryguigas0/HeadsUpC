#include <stdlib.h>
#include <stdio.h>
int scores[] = {543, 323, 32, 554, 11, 3, 112};

// Compara dois dados baseado em um resultado (-1 e 0 -> ordem certa +1 -> troca os dados de lugar)
// Como dois dados podem ser qualquer um, devem ser um ponteiro de void e receberem cast depois
int compare_fn(const void *score_a, const void *score_b)
{
    /* const void *score_* ->  ponteiro de qualquer tipo de dado constante */
    int a = *(int *)score_a; /* (int *) -> faz um cast no ponteiro void para ponteiro int*/
    int b = *(int *)score_b; /* *(int *) -> faz o cast e pega o valor qie o ponteiro aponta*/
    return a - b;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 7; i++)
    {
        printf("scores[%i] == %i\n", i, scores[i]);
    }
    puts("SORTING");
    qsort(scores, 7, sizeof(int), compare_fn);
    for (int i = 0; i < 7; i++)
    {
        printf("scores[%i] == %i\n", i, scores[i]);
    }
    return 0;
}

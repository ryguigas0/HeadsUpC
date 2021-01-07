#include <stdio.h>

void altera(int *a)
{
    printf("Alterando valor no local: %p\n", a);
    *a += 20;
}

int main(int argc, char const *argv[])
{
    int x = 90;
    int *ptr = &x;
    printf("x vale: %i\n", x);
    printf("x esta guardado em: %p\n", &x);
    printf("ptr aponta para: %p\n", ptr);
    altera(ptr);
    printf("x vale: %i\n", x);
    return 0;
}

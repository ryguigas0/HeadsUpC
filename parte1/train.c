#include <stdio.h>

int main()
{
    int mes = 12;
    switch (mes)
    {
    case 12:
    case 1:
        printf("FERIAS!!");
    case 6:
        printf("DO MEIO DE ANO!");
        break;
    default:
        printf("nao e ferias...");
    }
    return 0;
}
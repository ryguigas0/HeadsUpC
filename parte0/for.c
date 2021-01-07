#include <stdio.h>

int main()
{
    // puts("LOOP FOR decrescente");
    // int clientes = 10;
    // for (clientes; clientes > 0; clientes--)
    // {
    //     printf("Servindo sorvete para o cliente %i \n", clientes);
    // }

    puts("LOOP FOR crescente");
    for (int tempo = 0; tempo <= 23; tempo++)
    {
        switch (tempo)
        {
        case 20:
            printf("Sao %i horas, vou dormir!\n", tempo);
            break;
        case 6:
            printf("Sao %i horas, bom dia!\n", tempo);
            break;
        case 12:
            printf("Sao %i horas, vou almocar!\n", tempo);
            break;
        default:
            printf("Sao %i horas!\n", tempo);
            break;
        }
    }

    // puts("USANDO O BREAK");
    // int x = 0;
    // while(x >= 0){
    //     printf("%i\n", x);
    //     x++;
    //     if(x == 7) break; else puts("Supimpasso");
    // }

    // puts("USANDO O CONTINUE");
    // int x = 0;
    // while(x >= 0){
    //     printf("%i\n", x);
    //     x++;
    //     if(x == 4) continue;
    //     if(x == 7) break; else puts("Supimpasso");
    // }

    return 0;
}
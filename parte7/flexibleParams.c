#include <stdio.h>
#include <stdarg.h>

enum drink
{
    MUDSLIDE,
    FUZZY_NAVEL,
    MONKEY_GLAND,
    ZOMBIE
};

double price(enum drink d)
{
    switch (d)
    {
    case MUDSLIDE:
        return 6.79;
    case FUZZY_NAVEL:
        return 5.31;
    case MONKEY_GLAND:
        return 4.82;
    case ZOMBIE:
        return 5.89;
    }
    return 0;
}

double total(int argc, ...) //O ... diz que vai ter uma lista de argumentos
{
    double total = 0;
    va_list argsl;         //Pega a lista de argumentos
    va_start(argsl, argc); //Comece um forEach
    for (int i = 0; i < argc; i++)
    {
        //Pega o próximo elemento e diz qual o tipo do elemento após esse
        enum drink bottleName = va_arg(argsl, enum drink);
        double bottlePrice = price(bottleName);
        total += bottlePrice;
    }
    va_end(argsl); //Acabe o forEach
    return total;
}

int main()
{
    printf("O preço total é de: %.2lf\n",
           total(5, MUDSLIDE, MUDSLIDE, MONKEY_GLAND,
                 MONKEY_GLAND, FUZZY_NAVEL));
}

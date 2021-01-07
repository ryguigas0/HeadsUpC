#include <stdio.h>

enum response_type
{
    DUMP,
    SECOND_CHANCE,
    MARRIAGE
};

typedef struct
{
    char *name;
    enum response_type response;
} response;

void dump(response r)
{
    printf("Dear %s,\n", r.name);
    puts("DUMPED");
}

void second_chance(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Second chance");
}

void marriage(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Marry me!");
}
// Array de functions
// O que cada valor retorna? Retorna um void
// Como eu chamo ele? Use mensages (ponteiro de array)
// O que cada function recebe? Recebe um struct response
void (*mensages[]) (response) = {dump, second_chance, marriage};

int main(int argc, char const *argv[])
{
    response r[] = {
        {"Moke", DUMP},
        {"Luis", SECOND_CHANCE},
        {"Mattew", SECOND_CHANCE},
        {"William", MARRIAGE}
    };
    for(int i = 0; i < 4; i++){
        // MUITO CÓDIGO!!
        /* switch (r[i].response)
        {
        case DUMP:
            dump(r[i]);
            break;
        case SECOND_CHANCE:
            second_chance(r[i]);
            break;
        default:
            marriage(r[i]);
            break;
        } */
        // Primeira parte -> pega a function
        // Segunda parte -> roda a function passando o argumento
        (mensages[r[i].response])(r[i]);
    }
    return 0;
}

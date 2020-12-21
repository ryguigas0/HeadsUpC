#include <stdio.h>

typedef enum
{
    NUMERO,
    KILO,
    LITRO
} unidadeMedida;

typedef union
{
    short numero;
    float volume;
    float peso;
} quantidade;

typedef struct
{
    const char *nome;
    const char *pais;
    quantidade quantidade;
    unidadeMedida medida;
} pedidoFruta;

void mostrarPedido(pedidoFruta p)
{
    printf("Esse pedido contém:\n");
    if (p.medida == NUMERO)
    {
        printf("%i", p.quantidade.numero);
    }
    else if (p.medida == KILO)
    {
        printf("%2.2f kg", p.quantidade.peso);
    }
    else
    {
        printf("%2.2f L", p.quantidade.volume);
    }
    printf(" %s(s), vindas de %s\n", p.nome, p.pais);
}

int main()
{
    pedidoFruta laranjas = {"laranja", "Brasil", .quantidade.numero = 200, NUMERO};
    pedidoFruta goiabas = {"goiaba", "México", .quantidade.peso = 55.22, KILO};
    pedidoFruta kiwis = {"kiwi", "Espanha", .quantidade.volume = 22.2, LITRO};
    mostrarPedido(laranjas);
    mostrarPedido(goiabas);
    mostrarPedido(kiwis);
    return 0;
}

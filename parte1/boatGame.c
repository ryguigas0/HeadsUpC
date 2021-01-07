#include <stdio.h>
// Não funciona porque não está acessando o endereço de memória e mudando o valor
// Na verdade está criando novas varávies com os valores dos parâmetros e mudando os valores das novas variáveis
//Ou seja, copia os valores dos parâmetros em novos endereços e altera os valores das cópias
// void irSudeste(int lon, int lat)
// {
//     lat -= 1;
//     lon += 1;
// }

// Recebe o endereço das varáveis para alterar
void irSudeste(int *lon, int *lat)
{ 
    *lat = *lat * 2; //Acessa o valor e altera
    *lon = *lon * 3;
}

int main(int argc, char const *argv[])
{
    int longitude = 22;
    int latitude = -42;
    irSudeste(&longitude, &latitude); //Pass o endereço
    printf("Position on map: [%i, %i]\n", latitude, longitude);
    return 0;
}

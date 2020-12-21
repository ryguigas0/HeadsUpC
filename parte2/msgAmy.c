#include <stdio.h>
void skip(char *msg)
{
    /* Funciona porque pega cada endereço e adiciona mais 6 */
    puts(msg + 6);
}

int main()
{
    char *msgAmy = "Don't call me";
    skip(msgAmy);
    return 0;
}

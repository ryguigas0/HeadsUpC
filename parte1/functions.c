#include <stdio.h>
int maior(int a, int b)
{
    if (a > b)
        return a;
    else if (a < b)
        return b;
    else
        return 0;
}

void mensagem(char msg[])
{
    puts(msg);
}

int main()
{
    int c = 20;
    int d = 40;
    int maiorNum = maior(c, d);
    printf("O maior numero entre %i e %i eh %i\n", c, d, maiorNum);
    mensagem("minecraft é bem legal");
    return 0;
}
#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("O tamanho de um char é: %li bits\n", sizeof(char) * 8);
    printf("O tamanho de um short é: %li bits\n", sizeof(short) * 8);
    printf("O tamanho de um int é: %li bits\n", sizeof(int) * 8);
    printf("O tamanho de um long é: %li bits\n", sizeof(long) * 8);
    printf("O tamanho de um double é: %li bits\n", sizeof(double) * 8);
    printf("O tamanho de um float é: %li bits\n", sizeof(float) * 8);
    return 0;
}

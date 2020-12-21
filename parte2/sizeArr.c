#include <stdio.h>
int main(int argc, char const *argv[])
{
    char s[] = "How big is it?";
    char *t = s;
    if(&s == s){
        printf("%p é igual a %p\n", &s, s);
    }
    if(&t != t){
        printf("%p é diferente de %c\n", &t, t);
    }
    return 0;
}

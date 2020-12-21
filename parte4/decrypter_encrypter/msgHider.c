#include <stdio.h>
#include "encript.h"

int main()
{
    char msg[80];
    while(fgets(msg, 79, stdin)){
        encriptar(msg);
        printf("%s\n", msg);
    }
    return 0;
}

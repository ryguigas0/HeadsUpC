#include "encript.h"

void encriptar(char message[])
{
    char c;
    while (*message)
    {
        *message = *message ^ 31;
        message++;
    }
}
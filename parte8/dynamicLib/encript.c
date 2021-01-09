#include "includes/encript.h"

void encrypt(char message[])
{
    char c;
    while (*message)
    {
        *message = *message ^ 127;
        message++;
    }
}
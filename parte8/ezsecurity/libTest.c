#include "checksum.h"
#include "encript.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[] = "Essa mensagem é um segredinho!";
    encrypt(s);
    printf("ENCRYPTED: %s\n", s);
    printf("CHECKSUM: %i\n", checksum(s));
    encrypt(s);
    printf("DECRYPTED: %s\n", s);
    printf("CHECKSUM: %i\n", checksum(s));
    return 0;
}

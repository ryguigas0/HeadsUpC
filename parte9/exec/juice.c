#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Litters of juice: %s\n", argv[1]);
    printf("Type of juice: %s\n", getenv("FLAVOUR"));
    return 0;
}
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3};
    int *index = arr;
    printf("arr: %i\n", *index);
    printf("arr + 1: %i\n", *(index + 1));
    printf("arr + 2: %i\n", *(index + 2));
    return 0;
}

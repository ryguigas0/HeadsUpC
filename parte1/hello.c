/*
* Comment talking about the code, licences and who wrote it
*/
#include <stdio.h>
int main()
{
    int index = 2;
    char a[5] = "Hello";
    char s[5] = {'H', 'e', 'l', 'l', 'o', '\0'};
    s[index] = 'b';
    a[index] = 'd';
    if (a[index] != s[index])
        printf("Na string, a casa %i vale %c e no array vale %c\n", index, a[index], s[index]);
    printf("if does not need curly braces\n");
    if (a[index] = 'd')
        printf("A letra na string vale d\n");

    return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
    char haystack[30] = "dysfuncional";
    char needle[30] = "fun";
    // char haystack[30];
    // char needle[30];

    // puts("Enter a word: ");
    // fgets(haystack, 30, stdin);
    // puts("Enter another word: ");
    // fgets(needle, 30, stdin);

    if (strstr(haystack, needle))
    {
        printf("there is %s in %s\n", needle, haystack);
    }
    else
    {
        printf("there is no %s in %s\n", needle, haystack);
    }

    return 0;
}

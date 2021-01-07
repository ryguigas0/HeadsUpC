#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// char * -> ponteiro de char ou string
// char * [] -> array de ponteiros de char ou array de string
char *names[] = {"Leanne Graham", "Ervin Howell", "Clementine Bauch",
                "Patricia Lebsack", "Chelsey Dietrich",
                "Mrs. Dennis Schulist", "Kurtis Weissnat", "Nicholas Runolfsdottir V",
                "Glenna Reichert", "Clementina DuBuque"};

int compareStrings(const void *a, const void *b)
{
    char **string_a = (char **)a;
    char **string_b = (char **)b;
    return strcmp(*string_a, *string_b);
}

int main()
{
    puts("UNSORTED");
    for (int i = 0; i < 10; i++)
    {
        printf("names[%i] == %s\n", i, names[i]);
    }

    puts("SORTING");
    qsort(names, 10, sizeof(char*), compareStrings);

    puts("SORTED");
    for (int i = 0; i < 10; i++)
    {
        printf("names[%i] == %s\n", i, names[i]);
    }
    return 0;
}

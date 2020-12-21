#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    char *opens;
    char *closes;
    island *next;
} island;

void display(island *start)
{
    island *i = start;
    for (; i != NULL; i = i->next)
        printf("The island %s is open from %s to %s\n", i->name, i->opens, i->closes);
}

int main()
{
    island a = {"Amity", "19:00", "19:50", NULL};
    island b = {"Craggy", "19:00", "19:50", NULL};
    island c = {"Isla Nublar", "19:50", "20:00", NULL};
    island d = {"Shutter", "19:00", "19:50", NULL};

    a.next = &b;
    b.next = &c;
    c.next = &d;

    display(&a);

    printf("\n");
    island e = {"Skull Island", "19:50", "20:00", NULL};

    c.next = &e;
    e.next = &d;

    display(&a);

    return 0;
}

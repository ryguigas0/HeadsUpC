#include <stdio.h>
#include <string.h>
void reverse(char *s) /* Explicação em reverseStr.c */
{
    size_t len = strlen(s);
    char *t = s + len - 1;
    for (; t >= s; t--)
        printf("%c", *t);
    puts("");
}

int main()
{
    /* Brainfuck 2.0 */
    /* Array de endereços de arrays de chars, que estão no local da memória de constantes */
    char *juices[] = {"dragonfruit", "waterberry", "sharonfruit",
                    "uglifruit", "rumberry", "kiwifruit", "mulberry",
                    "strawberry", "blueberry", "blackberry", "starfruit"};

    char *a;
    puts(juices[6]);
    reverse(juices[7]);

    a = juices[2]; /* a aponta para (o mesmo valor que juices[2] no momento) sharonfruit*/
    juices[2] = juices[8]; /* ponteiro [2] aponta para (o mesmo valor que o ponteiro [8] que aponta no momento) blueberry*/
    juices[8] = a; /* ponteiro [8] aponta para (o valor que o ponteiro a aponta no momento) sharonfruit */

    puts(juices[8]); /* ponteiro [8]  -> sharonfruit */
    reverse(juices[(18 + 7) / 5]); /* (18 + 17) / 5 == 25 /5 == 5, juices[5] aponta para kiwifruit, só reverter*/
    puts(juices[2]); /* [2] -> blueberry */

    reverse(juices[9]);
    juices[1] = juices[3]; /* o ponteiro [1] aponta para o valor que [3] está apontando agora*/
    puts(juices[10]);
    reverse(juices[1]);
    return 0;
}

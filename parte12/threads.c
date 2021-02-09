#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void errormsg(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void *tarefa1()
{
    for (int i = 0; i < 5; i++)
    {
        printf("tarefa1: %i\n", i);
        sleep(1);
    }
}

void *tarefa2()
{
    for (int i = 0; i < 5; i++)
    {
        printf("tarefa2: %i\n", i);
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t t1;
    pthread_t t2;

    /* pthread_create não faz o processo main esperar, então quando o main acaba, mata as threads */
    if (pthread_create(&t1, NULL, tarefa1, NULL) == -1)
        errormsg("Can't create thread 1");
    if (pthread_create(&t1, NULL, tarefa2, NULL) == -1)
        errormsg("Can't create thread 2");

    void *result;

    /* pthread_join faz o processo principal esperar as threads rodarem */
    if (pthread_join(t1, &result) == -1)
        errormsg("Can't join thread 1");
    if (pthread_join(t1, &result) == -1)
        errormsg("Can't join thread 2");

    printf("%s\n", result);

    return 0;
}

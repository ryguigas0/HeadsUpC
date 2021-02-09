#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int beers = 2000000;
pthread_mutex_t drinks_lock = PTHREAD_MUTEX_INITIALIZER;

void *drink(void *a)
{
    pthread_mutex_lock(&drinks_lock);
    for (int b = 0; b < 100000; b++)
    {
        beers -= 1;
    }
    pthread_mutex_unlock(&drinks_lock);
    printf("Beers = %i\n", beers);
    return NULL;
}

void errormsg(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char const *argv[])
{
    printf("Tem %i cervejas no armazem\n", beers);
    pthread_t threads[20];
    for (int t = 0; t < 20; t++)
    {
        if (pthread_create(&threads[t], NULL, drink, NULL) == -1)
        {
            char *err;
            sprintf(err, "Can't create thread %i", t);
            errormsg(err);
        }
    }
    void *result;
    for (int t = 0; t < 20; t++)
    {
        if (pthread_join(threads[t], &result) == -1)
        {
            char *err;
            sprintf(err, "Can't join thread %i", t);
            errormsg(err);
        }
    }
    printf("Tem %i cervejas guardadas\n", beers);
    return 0;
}

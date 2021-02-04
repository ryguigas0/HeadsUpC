#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void atuar(int sig)
{
    puts("\nSer ou não ser, eis a questão.");
    exit(1);
}
int catchSignal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int main(int argc, char const *argv[])
{
    if(catchSignal(SIGTERM, atuar) == -1){
        fprintf(stderr, "Can't handle the handler\n");
    }
    char name[30];
    printf("Enter your name: ");
    fgets(name, 30, stdin);
    printf("Hello %s\n", name);
    return 0;
}
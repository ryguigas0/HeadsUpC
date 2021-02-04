#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void errormsg(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void openurl(char *url)
{
    char launch[255];
    sprintf(launch, "librewolf %s", url);
    system(launch);
}

int main(int argc, char const *argv[])
{
    //int len = (int)sizeof(links) / sizeof(char *);
    char *vars[] = {"INPUT=input.txt", NULL};

    /* FILE *f = fopen("output.txt", "w");
    if (!f)
    {
        errormsg("Can't open output file");
    } */

    int fd[2];
    if (pipe(fd) == -1)
        errormsg("Can't create pipe");

    __pid_t pid = fork();
    if (pid == -1)
    {
        errormsg("Can't fork process");
    }

    if (!pid)
    {
        //if (dup2(fileno(f), 1) != -1){
        dup2(fd[1], 1);
        close(fd[0]);
        if (execle("./requester", "./requester", NULL, vars) == -1)
            errormsg("Can't run requester");
        //}
    }
    /* int pidStatus;
    if (waitpid(pid, &pidStatus, 0) == -1)
    {
        errormsg("Error waiting for child process");
    } */
    dup2(fd[0], 0);
    close(fd[1]);
    char line[255];
    while (fgets(line, 255, stdin))
    {
        printf("%s", line);
        if (line[0] == '\n')
            openurl(line + 1);
    }

    return 0;
}

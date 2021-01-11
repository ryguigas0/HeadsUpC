#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (!pid)
    {
        execlp("cvlc", "cvlc", "audio1.mp3", "--gain", "0.1", NULL); //Induce error for child process
    }
    else if (pid == -1)
    {
        fprintf(stderr, "Cannot create process: %s\n", strerror(errno));
    }
    else
    {
        execlp("cvlc", "cvlc", "audio.mp3", "--gain", "0.3", NULL);
    }
    return 0;
}

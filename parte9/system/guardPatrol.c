#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char *now()
{
    time_t t;
    time(&t);
    return asctime(localtime(&t));
}

int main(int argc, char const *argv[])
{
    char comment[80];
    char cmd[120];
    fgets(comment, 80, stdin);
    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());
    system(cmd);
    return 0;
}

#include <unistd.h>

int main()
{
    char *my_env[] = {"FLAVOUR=orange and passion fruit mix", NULL};
    execle("juice", "juice", "4", NULL, my_env);
    return 0;
}

#include <stdio.h>

int main()
{
    int iorgurtes = 10;
    puts("LOOP WHILE");
     while(iorgurtes > 0){
         iorgurtes -= 1;
         puts("Comi um iorgurte");
         printf("Ainda tenho %i iorgurtes\n", iorgurtes);
     }
    // return 0;
    // puts("LOOP DO WHILE");
    // do
    // {
    //     iorgurtes -= 1;
    //     puts("Comi um iorgurte");
    //     printf("Ainda tenho %i iorgurtes\n", iorgurtes);
    // } while (iorgurtes > 0);
}
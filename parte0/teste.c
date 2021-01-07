#include <stdio.h>

int main(){
    int card = 1;
    if(card > 1)
        card -= 1;
        printf("%i \n", card);
        if(card < 7)
            puts("Small card");
    else
        puts("Ace!");
    return 0;
}
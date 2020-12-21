#include <stdio.h>

int main()
{
    int x = 0;
    int y = 0;
    while (x < 5)
    {
        
        if(y < 5){
            x = x + 1;
            if(y < 3) x = x - 1;
        }
        y = y + 2;

        printf("%i%i ", x , y);
        x = x + 1;
    }
    return 0;
}

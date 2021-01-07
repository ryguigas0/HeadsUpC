#include <stdio.h>

typedef union
{
    float lemon;
    int limePieces;
} lime;

typedef struct
{
    float tequila;
    float cointreau;
    lime citrus;
} margarita;

int main()
{
    margarita m = {2.0, 1.0, {1}};
    printf("%1.1f measures of tequila, %1.1f measures of cointreau, %1.1f measures of juice\n",
           m.tequila, m.cointreau, m.citrus.lemon);
    /* printf("%1.1f measures of tequila, %1.1f measures of cointreau, %i lime pieces\n",
           m.tequila, m.cointreau, m.citrus.limePieces); */
    return 0;
}

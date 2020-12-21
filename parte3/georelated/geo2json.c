#include <stdio.h>

int main()
{
    float latitude;
    float longitude;
    char info[80];
    int started = 0;

    puts("data = [");
    /* %79[^\n] -> pega no máximo os próximos 79 caracteres e e atualiza o dado no endereço info */
    while (scanf("%f, %f, %79[^\n]", &latitude, &longitude, info) == 3)
    {
        if (latitude < -90.0 || latitude > 90.0)
        {
            fprintf(stderr, "Latitude %f is invalid!\n", latitude);
            return 2;
        }
        if (longitude < -180.0 || longitude > 180.0)
        {
            fprintf(stderr, "Longitude %f is invalid!\n", longitude);
            return 2;
        }
        if (started)
            printf("\n");
        else
            started = 1;
        printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
    }
    puts("\n]");
    return 0;
}

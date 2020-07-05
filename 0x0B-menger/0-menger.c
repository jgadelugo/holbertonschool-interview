#include "menger.h"
#include <stdlib.h>

/**
 * menger - prints a 2D menger sponge
 * @level: level of menger sponge
 * 
 */
void menger(int level)
{
    int N = pow(3, level), size, i, **layers, j;

    size = pow(N, 2);
    layers = malloc(sizeof(int) * (N + 1));

    for (i = 0; i < N; i++)
    {
        *layers = malloc(sizeof(int) * (N + 1));
        for (j = 0; j < N; j++)
        {
            layers[i][j] = 1;
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (layers[i][j])
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}

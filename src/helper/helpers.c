#include "cub3d.h"

void ft_print2d(char **str2d)
{
    int i = 0;
    while (str2d[i])
    {
        printf("%s\n", str2d[i]);
        i++;
    }
    printf("\n");
}
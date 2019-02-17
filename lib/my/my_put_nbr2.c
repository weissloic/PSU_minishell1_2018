/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** my_put_nbr
*/
#include "../../include/my.h"
#include <stdarg.h>

void my_put_nbr2(unsigned int nb)
{
    if (nb == -2147483648) {
        my_put_nbr2(-214748364);
        my_putchar('8');
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if ((nb >= 0) && (nb < 10)) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr2(nb / 10);
        my_putchar((nb % 10) + 48);
    }
}

char *my_strcat(char *dest, char *src)
{
    int i;
    int j;

    j = 0;
    i = my_strlen(dest);
    while (src[j] != '\0') {
        dest[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return (dest);
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** func_lib3.c
*/

#include "../include/func.h"
#include "../include/struct.h"

int my_getnbr(char *str)
{
    int a = 0, nb = 0;
    int neg = 1;
    while (str[a] != '\0' && (str[a] < '0' || str[a] > '9')) {
        if (str[a] == '-')
            neg = neg * (-1);
        if (a == my_strlen(str))
            return (0);
        a++;
    }
    while (str[a] != '\0' && (str[a] >= '0' && str[a] <= '9')) {
        nb = nb * 10 + str[a] - 48;
        a++;
    }
    if (nb > 2147483647 || nb < -2147483647)
        return (0);
    return (nb * neg);
}
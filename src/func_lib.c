/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** func_lib.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i += 1);
    return (i);
}

char *my_strdup(char *str)
{
    int i = 0;
    for (; str[i]; i += 1);
    char *temp = malloc(sizeof(char) * i + 1);
    for (int i = 0; str[i]; i += 1)
        temp[i] = str[i];
    temp[i] = '\0';
    return temp;
}


char *my_strdup2(char const *str)
{
    int i = 0;
    for (; str[i]; i += 1);
    char *temp = malloc(sizeof(char) * i + 1);
    for (int i = 0; str[i]; i += 1)
        temp[i] = str[i];
    temp[i] = '\0';
    return temp;
}

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
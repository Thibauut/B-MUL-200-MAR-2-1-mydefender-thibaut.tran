/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** func_lib2.c
*/

#include "../include/func.h"
#include "../include/struct.h"

char *clean_get(char *line)
{
    char *tmp = malloc(sizeof(char) * my_strlen(line) + 1);
    int j = 0, i = 0, verif = 0;
    for (; line[i] != '\0'; i += 1) {
        if (line[i] == '/')
            verif = 1;
        if (verif == 1) {
            tmp[j] = line[i];
            j += 1;
        }
    }
    return (tmp);
}

int my_strcmp2(char *s1, char *s2)
{
    int len = my_strlen(s2);
    for (int j = 0; j != len; j += 1) {
        if (s1[j] != s2[j])
            return (1);
    }
    return (0);
}

char *my_get_line(char **env, char *arg)
{
    char *line;
    int i = 0;
    for (; env[i] != 0; i += 1) {
        if (my_strcmp2(env[i], arg) == 0) {
            line = my_strdup(env[i]);
            line = clean_get(line);
        }
    }
    return (line);
}

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int i = 0;
    while (dest[a] != '\0')
        a = a + 1;
    while (src[i] != '\0') {
        dest[a + i] = src [i];
        i = i + 1;
    }
    dest[a + i] = '\0';
    return (dest);
}

char *my_itoa(int nb)
{
    int size = 0;
    char *nb_in_str = NULL;
    int tmp = nb;
    if (tmp == 0)
        size = 1;
    while (tmp > 0) {
        tmp /= 10;
        size++;
    }
    nb_in_str = malloc(sizeof(char) * (size + 1));
    nb_in_str[size] = '\0';
    while (size--) {
        nb_in_str[size] = nb % 10  + '0';
        nb /= 10;
    }
    return (nb_in_str);
}

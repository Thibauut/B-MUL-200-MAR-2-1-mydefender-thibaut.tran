/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** load_save.c
*/

#include "../include/func.h"
#include "../include/struct.h"

int open_my_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (84);
    return (fd);
}

int read_my_file(int fd, char *buffer, int size)
{
    read(fd, buffer, size);
    return (0);
}

char *file_to_str(char const *filepath)
{
    struct stat buf;
    stat(filepath, &buf);
    int size = buf.st_size;
    char *buffer = malloc(sizeof(char) * size);
    int fd = open_my_file(filepath);
    read_my_file(fd, buffer, size);
    close(fd);
    return (buffer);
}

int create_tab(char *str, char c)
{
    int i = 0, j = 0;
    for (; str[i] != 0; i += 1) {
        if (str[i] == c)
            j += 1;
    }
    return (j + 1);
}

char **word_to_tab(char *filepath, char c, int i)
{
    char *str = file_to_str(filepath);
    int j = 0, k = 0, size = create_tab(str, c);
    char **tab = malloc(sizeof(char *) * (size + 1));
    tab[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        if (str[i] == c) {
            i += 1;
            tab[j][k] = '\0';
            j += 1, k = 0;
            tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
        }
        tab[j][k] = str[i];
        i += 1, k += 1;
    }
    j += 1, tab[j] = 0;
    return (tab);
}
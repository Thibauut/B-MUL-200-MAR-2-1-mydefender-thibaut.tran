/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** save_info.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void save_info(global_s *all)
{
    FILE *fd = fopen(all->info_p->save, "w");
    char *name = my_strdup2(sfText_getString(all->info_p->name));
    char *lvl = my_itoa(all->info_p->lvl);
    char *gold = my_itoa(all->info_p->coins);
    char *tower = my_itoa(all->info_p->tower);
    char *pl_base = my_itoa(all->info_p->pl_base);
    char *base = my_itoa(all->info_p->base);
    fwrite("SAVE", sizeof(char), 4, fd);
    fwrite("\nNAME=", sizeof(char), 6, fd);
    fwrite(name, sizeof(char), my_strlen(name), fd);
    fwrite("\nLEVEL=", sizeof(char), 7, fd);
    fwrite(lvl, sizeof(char), my_strlen(lvl), fd);
    fwrite("\nGOLD=", sizeof(char), 6, fd);
    fwrite(gold, sizeof(char), my_strlen(gold), fd);
    fwrite("\nBASE=", sizeof(char), 6, fd);
    fwrite(base, sizeof(char), my_strlen(base), fd);
    fwrite("\nTOWER=", sizeof(char), 7, fd);
    fwrite(tower, sizeof(char), my_strlen(tower), fd);
    fwrite("\nPLBASE=", sizeof(char), 8, fd);
    fwrite(pl_base, sizeof(char), my_strlen(pl_base), fd);
    fclose(fd);
    return;
}
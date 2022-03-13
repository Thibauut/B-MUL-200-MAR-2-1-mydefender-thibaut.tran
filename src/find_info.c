/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** find_info.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void find_name(global_s *all)
{
    int i = 0;
    for (; all->info_p->tab[1][i] != '='; i++);
    if (all->info_p->tab[1][i + 1] == '\0')
        all->is_ask = ASKING;
    else {
        int j = 0;
        i++;
        char *res = malloc(sizeof(char) * my_strlen(all->info_p->tab[1]));
        for (; all->info_p->tab[1][i] != '\0'; i++, j++)
            res[j] = all->info_p->tab[1][i];
        all->info_p->name = create_textStocky(res, 30, sfBlack, 200, 400);
        all->is_ask = FINISH;
    }
}

player *take_info(char **av, global_s *all)
{
    player *info;
    info = malloc(sizeof(player));
    if (av[1]) {
        char *str = malloc(sizeof(char) * 18);
        str = my_strcat(str, "save/save_player");
        str = my_strcat(str, av[1]);
        info->save = my_strdup(str);
        info->tab = word_to_tab(str, '\n', 0);
    } else {
        info->save = my_strdup("save/save_guest");
        info->tab = word_to_tab("save/save_guest", '\n', 0);
    }
    info->lvl = my_getnbr(info->tab[2]);
    info->coins = my_getnbr(info->tab[3]);
    info->base = my_getnbr(info->tab[4]);
    info->tower = my_getnbr(info->tab[5]);
    info->pl_base = my_getnbr(info->tab[6]);
    return (info);
}
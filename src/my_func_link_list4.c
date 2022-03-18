/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** my_func_link_list4.c
*/

#include "../include/my.h"
#include "../include/struct.h"

sfSprite *get_spt_en(list_enemy *list, int pos)
{
    for (int i = 0; i < pos; i += 1)
        list = list->next;
    return (list->enemy.sprite);
}

list_tow_g *modif_element(list_tow_g *list, int e, v2f pos, sfpt *spt, int typ)
{
    list[e].tower.pos = pos;
    list[e].tower.sprite = spt;
    list[e].tower.type = typ;
    return (list);
}

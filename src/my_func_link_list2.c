/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** my_func_link_list.2.c
*/

#include "../include/my.h"
#include "../include/struct.h"

list_tow_g *create_cell(tow_g tower)
{
    list_tow_g *cell = malloc(sizeof(list_tow_g));
    if (cell == NULL)
        return (NULL);
    cell->tower.pos = tower.pos;
    cell->tower.sprite = tower.sprite;
    cell->tower.type = tower.type;
    cell->tower.clock = tower.clock;
    cell->tower.rect = tower.rect;
    cell->tower.bullet = tower.bullet;
    cell->tower.clock_b = tower.clock_b;
    cell->tower.target = tower.target;
    cell->next = NULL;
    return (cell);
}

sfSprite *get_element(list_tow_g *list, int pos)
{
    for (int i = 0; i < pos; i += 1)
        list = list->next;
    return (list->tower.sprite);
}

sfVector2f get_element3(list_tow_g *list, int pos)
{
    for (int i = 0; i < pos; i += 1)
        list = list->next;
    return (list->tower.pos);
}

tow_g get_element4(list_tow_g *list, int pos)
{
    for (int i = 0; i < pos; i += 1)
        list = list->next;
    return (list->tower);
}

enemy_s get_enemy(list_enemy *list, int pos)
{
    list_enemy *list1 = list;
    for (int i = 0; i < pos; i += 1)
        list1 = list1->next;
    return (list1->enemy);
}
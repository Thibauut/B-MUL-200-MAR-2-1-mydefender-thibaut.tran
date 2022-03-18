/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_func_link_list.c
*/

#include "../include/my.h"
#include "../include/struct.h"

list_enemy *create_enemy(enemy_s enemy)
{
    list_enemy *cell = malloc(sizeof(list_enemy));
    if (cell == NULL)
        return (NULL);
    cell->enemy.life = enemy.life;
    cell->enemy.clock = enemy.clock;
    cell->enemy.rect = enemy.rect;
    cell->enemy.sprite = enemy.sprite;
    cell->enemy.type =  enemy.type;
    cell->enemy.col = enemy.col;
    cell->enemy.clock_fx = enemy.clock_fx;
    cell->enemy.fx = enemy.fx;
    cell->enemy.move_b = enemy.move_b;
    cell->next = NULL;
    return (cell);
}

list_enemy *add_enemy(list_enemy *list2, enemy_s enemy, int pos)
{
    list_enemy *prev = list2;
    list_enemy *curr = list2;
    list_enemy *cell = create_enemy(enemy);
    if (list2 == NULL)
        return (cell);
    if (pos == 0) {
        cell->next = list2;
        return (cell);
    }
    for (int i = 0; i < pos; i += 1) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = cell;
    cell->next = curr;
    return (list2);
}

int list_len(list_tow_g *list)
{
    int i = 0;
    for (; list != NULL; list = list->next, i += 1);
    return (i);
}

int list_len_2(list_enemy *list)
{
    int i = 0;
    for (; list != NULL; list = list->next, i += 1);
    return (i);
}

list_tow_g *add_tower(list_tow_g *list, tow_g tower, int pos)
{
    list_tow_g *prev = list;
    list_tow_g *curr = list;
    list_tow_g *cell = create_cell(tower);
    if (list == NULL)
        return (cell);
    if (pos == 0) {
        cell->next = list;
        return (cell);
    }
    for (int i = 0; i < pos; i += 1) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = cell;
    cell->next = curr;
    return (list);
}

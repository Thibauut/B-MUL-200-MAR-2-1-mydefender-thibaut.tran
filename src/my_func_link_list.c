/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_func_link_list.c
*/

#include "../include/my.h"
#include "../include/struct.h"

// my_list2_t *create_cell2(int i)
// {
//     my_list2_t *cell = malloc(sizeof(my_list2_t));
//     if (cell == NULL)
//         return (NULL);
//     cell->i = i;
//     cell->next = NULL;
//     cell->prev = NULL;
//     return (cell);
// }


// my_list2_t *add_element2(my_list2_t *list2, int i, int pos)
// {
//     my_list2_t *prev = list2;
//     my_list2_t *curr = list2;
//     my_list2_t *cell = create_cell2(i);
//     if (list2 == NULL)
//         return (cell);
//     if (pos == 0) {
//         cell->next = list2;
//         return (cell);
//     }
//     for (int i = 0; i < pos; i += 1) {
//         prev = curr;
//         curr = curr->next;
//     }
//     prev->next = cell;
//     cell->next = curr;
//     return (list2);
// }

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
    for(; list != NULL; list = list->next, i += 1);
    return (i);
}

int list_len_2(list_enemy *list)
{
    int i = 0;
    for(; list != NULL; list = list->next, i += 1);
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

list_tow_g *modif_element(list_tow_g *list, int e, sfVector2f pos, sfSprite *spt, int type)
{
    list[e].tower.pos = pos;
    list[e].tower.sprite = spt;
    list[e].tower.type = type;
    return (list);
}

list_enemy *modif_element2(list_enemy *list, one_cl clock, int e)
{
    list[e].enemy.clock = clock;
    return (list);
}

list_enemy *free_first_element(list_enemy *list)
{
    if (list == NULL)
        return (NULL);
    list_enemy *tmp = list;
    list = tmp->next;
    return (list);
}

list_enemy *free_element_at(list_enemy *list, int pos)
{
    list_enemy *prev = list;
    list_enemy *curr = list;
    if (list == NULL)
        return (NULL);
    if (pos == 0) {
        list = free_first_element(list);
        return (list);
    }
    for (int i = 0; i < pos; i += 1) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
    return (list);
}

list_tow_g *free_first_tow(list_tow_g *list)
{
    if (list == NULL)
        return (NULL);
    list_tow_g *tmp = list;
    list = tmp->next;
    return (list);
}

list_tow_g *free_tow_at(list_tow_g *list, int pos)
{
    list_tow_g *prev = list;
    list_tow_g *curr = list;
    if (list == NULL)
        return (NULL);
    if (pos == 0) {
        list = free_first_tow(list);
        return list;
    }
    for (int i = 0; i < pos; i += 1) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
    return (list);
}
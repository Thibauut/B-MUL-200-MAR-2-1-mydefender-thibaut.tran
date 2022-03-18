/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** my_func_link_list3.c
*/

#include "../include/my.h"
#include "../include/struct.h"

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

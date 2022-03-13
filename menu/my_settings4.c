/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** my_settings4.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

void more(global_s *all)
{
    all->event = malloc(sizeof(sfEvent));
    sfRenderWindow_clear(all->wind, sfBlack);
    while (sfRenderWindow_isOpen(all->wind)) {
        move_bg(all->sprite.menu.more_bg, all->wind, &all->cl.cl_more, 2);
        move_bg(all->sprite.menu.more_bg2, all->wind, &all->cl.cl_more2, 4);
        draw_more(all);
        sfRenderWindow_display(all->wind);
        if (more_event(all) == 1)
            return;
    }
    return;
}

int more_bt(global_s *all)
{
    v2f size = {1, 1}, sizeup = {1.03, 1.03}, move = {806, 729};
    v2f pos = {810, 732};
    if (sffrc(&all->rect->more, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.menu.bt_1, move);
        sfSprite_setScale(all->sprite.menu.bt_1, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed) {
            more(all);
        }
    } else {
        sfSprite_setScale(all->sprite.menu.bt_1, size);
        sfSprite_setPosition(all->sprite.menu.bt_1, pos);
    }
    return (0);
}
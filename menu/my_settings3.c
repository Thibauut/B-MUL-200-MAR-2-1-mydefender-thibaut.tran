/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_settings3.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

void more_bt_option(global_s *all)
{
    sfVector2f size = {1, 1}, sizeup = {1.03, 1.03}, move = {807, 729}, pos = {810, 732};
    if (sfFloatRect_contains(&all->rect->option, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.menu.bt_option, move);
        sfSprite_setScale(all->sprite.menu.bt_option, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed)
            more_option(all);
    } else {
        sfSprite_setScale(all->sprite.menu.bt_option, size);
        sfSprite_setPosition(all->sprite.menu.bt_option, pos);
    }
}

void more_bt_tutorial(global_s *all)
{
    sfVector2f size = {1, 1}, sizeup = {1.03, 1.03}, move = {806, 598}, pos = {810, 600};
    if (sfFloatRect_contains(&all->rect->tutorial, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.menu.bt_tutorial, move);
        sfSprite_setScale(all->sprite.menu.bt_tutorial, sizeup);
        // if (all->event->type == sfEvtMouseButtonPressed) {
        //     sfRenderWindow_close(all->wind);
        //     all->STATUS = FINISH;
        // }
    } else {
        sfSprite_setScale(all->sprite.menu.bt_tutorial, size);
        sfSprite_setPosition(all->sprite.menu.bt_tutorial, pos);
    }
}

void more(global_s *all)
{
    all->event = malloc(sizeof(sfEvent));
    sfRenderWindow_clear(all->wind, sfBlack);
    while (sfRenderWindow_isOpen(all->wind)) {
        move_bg(all->sprite.menu.more_bg, all->wind, &all->cl.cl_more, 2);
        move_bg(all->sprite.menu.more_bg2, all->wind, &all->cl.cl_more2, 4);
        draw_more(all);
        sfRenderWindow_display(all->wind);
        while (sfRenderWindow_pollEvent(all->wind, all->event)) {
            all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
            if (all->event->type == sfEvtClosed) {
                sfRenderWindow_close(all->wind);
                all->STATUS = FINISH;
            }
            if (more_bt_close(all) == 1)
                return;
            more_bt_option(all);
            more_bt_tutorial(all);
        }
    }
    return;
}

int more_bt(global_s *all)
{
    sfVector2f size = {1, 1}, sizeup = {1.03, 1.03}, move = {806, 729}, pos = {810, 732};
    if (sfFloatRect_contains(&all->rect->more, all->pos_mouse.x, all->pos_mouse.y)) {
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
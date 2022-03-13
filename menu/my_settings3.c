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
    v2f size = {1, 1}, sizeup = {1.03, 1.03}, move = {807, 729};
    v2f pos = {810, 732};
    if (sffrc(&all->rect->option, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.menu.bt_option, move);
        sfSprite_setScale(all->sprite.menu.bt_option, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed)
            more_option(all);
    } else {
        sfSprite_setScale(all->sprite.menu.bt_option, size);
        sfSprite_setPosition(all->sprite.menu.bt_option, pos);
    }
}

int tutorial_event(global_s *all)
{
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
        if (all->event->type == sfEvtClosed) {
            sfRenderWindow_close(all->wind);
            all->STATUS = FINISH;
        }
        if (more_bt_close(all) == 1)
            return (1);
    }
    return (0);
}

void tutorial(global_s *all)
{
    all->event = malloc(sizeof(sfEvent));
    sfRenderWindow_clear(all->wind, sfBlack);
    while (sfRenderWindow_isOpen(all->wind)) {
        sfRenderWindow_drawSprite(all->wind, all->sprite.menu.tutorial, NULL);
        sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_close, NULL);
        sfRenderWindow_display(all->wind);
        if (tutorial_event(all) == 1)
            return;
    }
}

void more_bt_tutorial(global_s *all)
{
    v2f size = {1, 1}, sizeup = {1.03, 1.03}, move = {806, 598};
    v2f pos = {810, 600};
    if (sffrc(&all->rect->tutorial, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.menu.bt_tutorial, move);
        sfSprite_setScale(all->sprite.menu.bt_tutorial, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed)
            tutorial(all);
    } else {
        sfSprite_setScale(all->sprite.menu.bt_tutorial, size);
        sfSprite_setPosition(all->sprite.menu.bt_tutorial, pos);
    }
}

int more_event(global_s *all)
{
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
        if (all->event->type == sfEvtClosed) {
            sfRenderWindow_close(all->wind);
            all->STATUS = FINISH;
        }
        if (more_bt_close(all) == 1)
            return (1);
        more_bt_option(all);
        more_bt_tutorial(all);
    }
    return (0);
}
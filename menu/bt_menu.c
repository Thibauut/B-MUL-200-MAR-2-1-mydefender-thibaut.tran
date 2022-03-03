/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** bt_menu.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

void init_rect(global_s *all)
{
    all->rect = malloc(sizeof(rect));
    all->rect->more = sfSprite_getGlobalBounds(all->sprite.menu.bt_1);
    all->rect->play = sfSprite_getGlobalBounds(all->sprite.menu.bt_2);
    all->rect->close = sfSprite_getGlobalBounds(all->sprite.menu.bt_close);
    all->rect->tutorial = sfSprite_getGlobalBounds(all->sprite.menu.bt_tutorial);
    all->rect->option = sfSprite_getGlobalBounds(all->sprite.menu.bt_option);
}

int play_bt(global_s *all)
{
    sfVector2f size = {1, 1}, sizeup = {1.03, 1.03}, move = {806, 598}, pos = {810, 600};
    if (sfFloatRect_contains(&all->rect->play, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.menu.bt_2, move);
        sfSprite_setScale(all->sprite.menu.bt_2, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed) {
            all->STATUS = MAP;
            sfFloatRect rect = sfSprite_getGlobalBounds(all->sprite.menu.bt_close);
            rect.height = rect.height / 2;
            rect.width = rect.width / 2;
            sfSprite_setOrigin(all->sprite.menu.bt_close, tsvf(rect.width, rect.height));
            sfSprite_setPosition(all->sprite.menu.bt_close, tsvf(1830, 70));
            ask_name(all);
            choose_base(all);
            my_init_level(all);
        }
    } else {
        sfSprite_setScale(all->sprite.menu.bt_2, size);
        sfSprite_setPosition(all->sprite.menu.bt_2, pos);
    }
    return (0);
}

void draw_more(global_s *all)
{
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.more_bg, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.more_bg2, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.more_bg3, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_option, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_tutorial, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_close, NULL);
}

int more_bt_close(global_s *all)
{
    sfVector2f size = {1, 1}, sizeup = {1.03, 1.03}, move = {1798, 47}, pos = {1800, 50};
    if (sfFloatRect_contains(&all->rect->close, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.menu.bt_close, move);
        sfSprite_setScale(all->sprite.menu.bt_close, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed)
            return (1);
    } else {
        sfSprite_setScale(all->sprite.menu.bt_close, size);
        sfSprite_setPosition(all->sprite.menu.bt_close, pos);
    }
    return (0);
}

void draw_more_option(global_s *all)
{
    move_bg(all->sprite.menu.more_bg, all->wind, &all->cl.cl_more, 2);
    move_bg(all->sprite.menu.more_bg2, all->wind, &all->cl.cl_more2, 4);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.more_bg, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.more_bg2, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.more_bg4, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.r_option, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_close, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_left, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_right, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_left2, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_right2, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_left3, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_right3, NULL);

}
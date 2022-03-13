/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** menu_weap.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void close_weap(global_s *all)
{
    sfVector2f size = {1, 1};
    sfFloatRect rect = sfSprite_getGlobalBounds(all->sprite.menu.bt_close);
    if (all->event->type == sfEvtClosed) {
        sfRenderWindow_close(all->wind);
        all->STATUS = FINISH;
    }
    if (sfFloatRect_contains(&rect, all->pos_mouse.x, all->pos_mouse.y)) {
        if (all->event->type == sfEvtMouseButtonPressed) {
            all->STATUS = MAP;
            restart_pop(&all->pop5);
            restart_pop(&all->pop1);
        }
    }
    if (all->event->type == sfEvtKeyPressed && all->event->key.code == sfKeyEscape) {
        all->STATUS = MAP;
        restart_pop(&all->pop5);
        restart_pop(&all->pop1);
    }

}

void buy_weapons(global_s *all)
{
    sfFloatRect rect_2 = sfSprite_getGlobalBounds(all->sprite.weapons.unlock1);
    sfFloatRect rect_3 = sfSprite_getGlobalBounds(all->sprite.weapons.unlock2);
    sfFloatRect rect_4 = sfSprite_getGlobalBounds(all->sprite.weapons.unlock3);
    // sfFloatRect rect_5 = sfSprite_getGlobalBounds(all->sprite.weapons.unlock5);
    if (sfFloatRect_contains(&rect_2, all->pos_mouse.x, all->pos_mouse.y)) {
        if (is_weap_unclock(all, 2) == 0)
            can_buy_weap(all, 2);
    }
    if (sfFloatRect_contains(&rect_3, all->pos_mouse.x, all->pos_mouse.y)) {
        if (is_weap_unclock(all, 3) == 0)
            can_buy_weap(all, 3);
    }
    if (sfFloatRect_contains(&rect_4, all->pos_mouse.x, all->pos_mouse.y)) {
        if (is_weap_unclock(all, 4) == 0)
            can_buy_weap(all, 4);
    }
    // if (sfFloatRect_contains(&rect_5, all->pos_mouse.x, all->pos_mouse.y)) {
    //     if (is_weap_unclock(all, 5) == 0)
    //         can_buy_weap(all, 5);
    // }
}

void check_events_weap(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        close_weap(all);
        if (all->event->type == sfEvtMouseButtonPressed)
            buy_weapons(all);
    }
}

void refresh_clock_pop(global_s *all)
{
    all->sprite.other.cl_pop.time = sfClock_getElapsedTime(all->sprite.other.cl_pop.clock);
    all->sprite.other.cl_pop.seconds = all->sprite.other.cl_pop.time.microseconds / 1000000.0;
}

void my_weapons(global_s *all)
{
    draw_menu_weap(all);
    check_events_weap(all);
}
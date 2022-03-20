/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** menu_weap.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#define aswu2 all->sprite.weapons.unlock2

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
            if (all->sounds.active == sfTrue)
                sfSound_stop(sm1), sfSound_play(sm1);
            all->STATUS = MAP;
            restart_pop(&all->pop5);
            restart_pop(&all->pop1);
        }
    }
    if (all->event->type == sfekp && all->event->key.code == ske) {
        all->STATUS = MAP;
        restart_pop(&all->pop5);
        restart_pop(&all->pop1);
    }
}

void buy_weapons(global_s *all)
{
    sffr rect_2 = sfggb(all->sprite.weapons.unlock1), rect_3 = sfggb(aswu2);
    sffr rect_4 = sfggb(all->sprite.weapons.unlock3);
    if (sffrc(&rect_2, all->pos_mouse.x, all->pos_mouse.y)) {
        if (all->sounds.active == sfTrue)
            sfSound_stop(all->sounds.sound1), sfSound_play(all->sounds.sound1);
        if (is_weap_unclock(all, 2) == 0)
            can_buy_weap(all, 2);
    }
    if (sffrc(&rect_3, all->pos_mouse.x, all->pos_mouse.y)) {
        if (all->sounds.active == sfTrue)
            sfSound_stop(all->sounds.sound1), sfSound_play(all->sounds.sound1);
        if (is_weap_unclock(all, 3) == 0)
            can_buy_weap(all, 3);
    }
    if (sffrc(&rect_4, all->pos_mouse.x, all->pos_mouse.y)) {
        if (all->sounds.active == sfTrue)
            sfSound_stop(all->sounds.sound1), sfSound_play(all->sounds.sound1);
        if (is_weap_unclock(all, 4) == 0)
            can_buy_weap(all, 4);
    }
}

void check_events_weap(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        close_weap(all);
        if (all->event->type == sfEvtMouseButtonPressed) {
            buy_weapons(all);
        }
    }
}

void refresh_clock_pop(global_s *all)
{
    all->sprite.other.cl_pop.time = sfcget(all->sprite.other.cl_pop.clock);
    all->sprite.other.cl_pop.sec = all->sprite.other.cl_pop.tms / 1000000.0;
}

void my_weapons(global_s *all)
{
    draw_menu_weap(all);
    check_events_weap(all);
}

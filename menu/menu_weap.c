/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** menu_weap.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void draw_menu_weap(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.bg_weap, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.left_ar, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.right_ar, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_close, NULL);
    print_weap(all);
    draw_pop_up(all->sprite.weapons.unlock1 , all, &all->pop6);
    draw_pop_up(all->sprite.weapons.unlock2, all, &all->pop7);
    draw_pop_up(all->sprite.weapons.unlock3, all, &all->pop8);
    sfRenderWindow_display(all->wind);
}

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
        }
    }
    if (all->event->type == sfEvtKeyPressed && all->event->key.code == sfKeyEscape) {
        all->STATUS = MAP;
        restart_pop(&all->pop5);
    }

}

void can_buy_weap(global_s *all, int wep)
{
    sfTexture *texture;
    sfVector2f pos = {-1000, 0};
    switch (wep)
    {
    case 2:
        if (all->info_p->coins >= 800) {
            sfSprite_setPosition(all->sprite.weapons.unlock1, pos);
            texture = sfTexture_createFromFile("res/weapons/wp2.png", NULL);
            sfSprite_setTexture(all->sprite.weapons.wp2, texture, sfFalse);
            all->info_p->coins = all->info_p->coins - 800;
            all->info_p->tower = all->info_p->tower + 1000;
        }
        break;
    case 3:
        if (all->info_p->coins >= 800) {
            sfSprite_setPosition(all->sprite.weapons.unlock2, pos);
            texture = sfTexture_createFromFile("res/weapons/wp3.png", NULL);
            sfSprite_setTexture(all->sprite.weapons.wp3, texture, sfFalse);
            all->info_p->coins = all->info_p->coins - 800;
            all->info_p->tower = all->info_p->tower + 100;
        }
        break;
    case 4:
        if (all->info_p->coins >= 1000) {
            sfSprite_setPosition(all->sprite.weapons.unlock3, pos);
            texture = sfTexture_createFromFile("res/weapons/wp4.png", NULL);
            sfSprite_setTexture(all->sprite.weapons.wp4, texture, sfFalse);
            all->info_p->coins = all->info_p->coins - 1000;
            all->info_p->tower = all->info_p->tower + 10;
        }
        break;
    case 5:
        if (all->info_p->coins >= 1200) {
            texture = sfTexture_createFromFile("res/weapons/wp5.png", NULL);
            sfSprite_setTexture(all->sprite.weapons.wp5, texture, sfFalse);
            all->info_p->coins = all->info_p->coins - 1200;
            all->info_p->tower = all->info_p->tower + 1;
        }
        break;
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

void init_weapons(global_s *all)
{
    all->sprite.level.bg_weap = csS("res/menu/menu_weap/bg_weap.png", 0, 0, tsvf(1, 1));
    create_weapons(all);
    sfVector2f pos = {2000, 0};
    if (is_weap_unclock(all, 2) == 1)
        sfSprite_setPosition(all->sprite.weapons.unlock1, pos);
    if (is_weap_unclock(all, 3) == 1)
        sfSprite_setPosition(all->sprite.weapons.unlock2, pos);
    if (is_weap_unclock(all, 4) == 1)
        sfSprite_setPosition(all->sprite.weapons.unlock3, pos);
    // if (is_weap_unclock(all, 5))
    //     sfSprite_setPosition(all->sprite.weapons.unlock1, pos);
    // all->pop1 = pop_up(all, 0.5, 0.04,  all->sprite.weapons.wp1);
    // all->pop2 = pop_up(all, 0.5, 0.04,  all->sprite.weapons.wp2);
    // all->pop3 = pop_up(all, 0.5, 0.04,  all->sprite.weapons.wp3);
    // all->pop4 = pop_up(all, 0.5, 0.04,  all->sprite.weapons.wp4);
    all->pop6 = pop_up(all, 0.5, 0.04,  all->sprite.weapons.unlock1);
    all->pop7 = pop_up(all, 0.5, 0.04,  all->sprite.weapons.unlock2);
    all->pop8 = pop_up(all, 0.5, 0.04,  all->sprite.weapons.unlock3);
}

void my_weapons(global_s *all)
{
    draw_menu_weap(all);
    check_events_weap(all);
}
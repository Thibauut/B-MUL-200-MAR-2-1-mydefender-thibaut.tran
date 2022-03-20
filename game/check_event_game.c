/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** check_event_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#define en all->sprite.game.list_enemy
#define en2 all->sprite.game.list_enemy2
#define en3 all->sprite.game.list_enemy3
#define en4 all->sprite.game.list_enemy4
#define en5 all->sprite.game.list_enemy5
#define en6 all->sprite.game.list_enemy6

void super_power(global_s *all)
{
    int len_mecha = list_len_2(en), len_mecha_rev = list_len_2(en2);
    int len_jet = list_len_2(en3), len_jet_rev = list_len_2(en5);
    int len_car = list_len_2(en4), len_car_rev = list_len_2(en6);
    if (all->sprite.game.blood >= 900) {
        sfClock_restart(all->sprite.game.cl_pow.clock);
        all->sprite.game.blood -= 900, all->sprite.game.power = True;
        if (len_mecha > 1)
            free_element_at(en, len_mecha - 1);
        if (len_mecha_rev > 1)
            free_element_at(en2, len_mecha_rev - 1);
        if (len_jet > 1)
            free_element_at(en3, len_jet - 1);
        if (len_jet_rev > 1)
            free_element_at(en5, len_jet_rev - 1);
        if (len_car > 1)
            free_element_at(en4, len_car - 1);
        if (len_car_rev > 1)
            free_element_at(en6, len_car_rev - 1);
    }
}

void check_ev3(global_s *all)
{
    if (all->STATUS == MAP) {
        sfMusic_stop(all->musics.music3);
        all->i = 0;
    }
}

void check_ev2(global_s *all)
{
    if (all->sprite.game.is_bar == False) {
        if (pause_game(all) == 2) {
            all->STATUS = MAP;
            check_ev3(all);
        }
    }
    else
        all->sprite.game.is_bar = False;
}

void check_events_game(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        if (all->event->type == sfEvtClosed) {
            sfRenderWindow_close(all->wind);
            all->STATUS = FINISH;
        }
        if (sfKeyboard_isKeyPressed(sfKeyS))
            super_power(all);
        if (sfKeyboard_isKeyPressed(sfKeyH) && all->sprite.game.blood >= 1000)
            refresh_life_base(all, 10000);
        if (all->event->type == sfEvtKeyPressed
        && all->event->key.code == sfKeyEscape) {
            check_ev2(all);
        }
        if (all->event->type == sfEvtMouseButtonPressed
        && all->sprite.game.is_bar == True) {
            check_place_weap(all);
        }
    }
}

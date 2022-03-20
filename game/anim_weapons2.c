/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** anim_weapons2.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void anim_klassico(tow_g *tow, global_s *all)
{
    tow->rect.top = 0;
    tow->rect.height = 79;
    enemy_s t_bullet;
    tow->rect.width = 283;
    tow->clock.time = sfClock_getElapsedTime(tow->clock.clock);
    tow->clock.seconds = tow->clock.time.microseconds / 1000000.0;
    tow->clock_b.time = sfClock_getElapsedTime(tow->clock_b.clock);
    tow->clock_b.seconds = tow->clock_b.time.microseconds / 1000000.0;
    if (tow->clock.seconds > 0.05) {
        if (tow->pos.x < 1000) {
            if (tow->rect.left == 1132 && all->verif_l == 0)
                create_bullet_klassico(tow, t_bullet, all);
        } else {
            if (tow->rect.left == 1132 && all->verif_r == 0)
                create_bullet_klassico(tow, t_bullet, all);
        }
        tow->rect.left = tow->rect.left + 283;
        if (tow->rect.left >= 2547)
            tow->rect.left = 0;
        sfClock_restart(tow->clock.clock);
    }
    int len_bul = list_len_2(tow->bullet);
    if (len_bul >= 1) {
        if (tow->clock_b.seconds > 0.01) {
            move_bullet(tow, len_bul, all);
        }
    }
    sfSprite_setTextureRect(tow->sprite, tow->rect);
}

void anim_avocado(tow_g *tow, global_s *all)
{
    tow->rect.top = 0;
    tow->rect.height = 67;
    tow->rect.width = 177;
    enemy_s t_bullet;
    tow->clock.time = sfClock_getElapsedTime(tow->clock.clock);
    tow->clock.seconds = tow->clock.time.microseconds / 1000000.0;
    tow->clock_b.time = sfClock_getElapsedTime(tow->clock_b.clock);
    tow->clock_b.seconds = tow->clock_b.time.microseconds / 1000000.0;
    if (tow->clock.seconds > 0.045) {
        tow->rect.left = tow->rect.left + 177;
        if (tow->rect.left >= 1053) {
            tow->rect.left = 0;
            if (tow->pos.x > 1000) {
                if (all->verif_r == 0)
                    create_bullet_avocado(tow, t_bullet, all);
            } else {
                if (all->verif_l == 0)
                    create_bullet_avocado(tow, t_bullet, all);
            }
        }
        sfClock_restart(tow->clock.clock);
    }
    int len_bul = list_len_2(tow->bullet);
    if (len_bul >= 1) {
        if (tow->clock_b.seconds > 0.001)
            move_bullet(tow, len_bul, all);
    }
    sfSprite_setTextureRect(tow->sprite, tow->rect);
}

void anim_stazz(tow_g *tow, global_s *all)
{
    tow->rect.top = 0;
    tow->rect.height = 145;
    tow->rect.width = 290;
    enemy_s t_bullet;
    tow->clock.time = sfClock_getElapsedTime(tow->clock.clock);
    tow->clock.seconds = tow->clock.time.microseconds / 1000000.0;
    tow->clock_b.time = sfClock_getElapsedTime(tow->clock_b.clock);
    tow->clock_b.seconds = tow->clock_b.time.microseconds / 1000000.0;
    if (tow->clock.seconds > 0.045) {
        tow->rect.left = tow->rect.left + 290;
        if (tow->rect.left >= 2610) {
            tow->rect.left = 0;
            if (tow->pos.x > 1000) {
                if (all->verif_r == 0)
                    create_bullet_hunter(tow, t_bullet, all);
            } else {
                if (all->verif_l == 0)
                    create_bullet_hunter(tow, t_bullet, all);
            }
        }
        sfClock_restart(tow->clock.clock);
    }
    int len_bul = list_len_2(tow->bullet);
    if (len_bul >= 1) {
        if (tow->clock_b.seconds > 0.001)
            move_bullet(tow, len_bul, all);
    }
    sfSprite_setTextureRect(tow->sprite, tow->rect);
}

void anim_blaster(tow_g *tow, global_s *all)
{
    tow->rect.top = 0;
    tow->rect.height = 99;
    tow->rect.width = 246;
    enemy_s t_bullet;
    tow->clock.time = sfClock_getElapsedTime(tow->clock.clock);
    tow->clock.seconds = tow->clock.time.microseconds / 1000000.0;
    tow->clock_b.time = sfClock_getElapsedTime(tow->clock_b.clock);
    tow->clock_b.seconds = tow->clock_b.time.microseconds / 1000000.0;
    if (tow->clock.seconds > 0.01) {
        tow->rect.left = tow->rect.left + 246;
        if (tow->rect.left >= 2214) {
            tow->rect.left = 0;
            if (tow->pos.x > 1000) {
                if (all->verif_r == 0)
                    create_bullet_blaster(tow, t_bullet, all);
            } else {
                if (all->verif_l == 0)
                    create_bullet_blaster(tow, t_bullet, all);
            }
        }
        sfClock_restart(tow->clock.clock);
    }
    int len_bul = list_len_2(tow->bullet);
    if (len_bul >= 1) {
        if (tow->clock_b.seconds > 0.001)
            move_bullet(tow, len_bul, all);
    }
    sfSprite_setTextureRect(tow->sprite, tow->rect);
}

/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** anim_weapons.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void move_bullet(tow_g *tow, int len_bul)
{
    enemy_s en;
    for (int i = 0 ; i < len_bul; i++) {
        en = get_enemy(tow->bullet, i);
        if (sfSprite_getPosition(tow->sprite).x < 1000)
            sfSprite_move(en.sprite, tsvf(-10, 0));
        else {
            sfSprite_move(en.sprite, tsvf(10, 0));
        }
    }
    sfClock_restart(tow->clock_b.clock);
}

void create_bullet(tow_g *tow, enemy_s t_bullet)
{
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    if (sfSprite_getPosition(tow->sprite).x < 1000)
        t_bullet.sprite = create_spriteStocky("res/sprites/bullet1.png", pos.x - 10, pos.y + 10, tsvf(1, 1));
    else
        t_bullet.sprite = create_spriteStocky("res/sprites/bullet1.png", pos.x - 10, pos.y + 10, tsvf(-1, 1));
    tow->bullet = add_enemy(tow->bullet, t_bullet, 0);
}

void anim_klassico(tow_g *tow)
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
        tow->rect.left = tow->rect.left + 283;
        if (tow->rect.left >= 2547)
            tow->rect.left = 0;
        if (tow->rect.left == 1132)
            create_bullet(tow, t_bullet);
        sfClock_restart(tow->clock.clock);
    }
    int len_bul = list_len_2(tow->bullet);
    if (len_bul >= 1) {
        if (tow->clock_b.seconds > 0.001)
            move_bullet(tow, len_bul);
    }
    sfSprite_setTextureRect(tow->sprite, tow->rect);
}

void anim_avocado(tow_g *tow)
{
    tow->rect.top = 0;
    tow->rect.height = 67;
    tow->rect.width = 177;
    tow->clock.time = sfClock_getElapsedTime(tow->clock.clock);
    tow->clock.seconds = tow->clock.time.microseconds / 1000000.0;
    if (tow->clock.seconds > 0.045) {
        tow->rect.left = tow->rect.left + 177;
        if (tow->rect.left >= 1053)
            tow->rect.left = 0;
        sfClock_restart(tow->clock.clock);
    }
    sfSprite_setTextureRect(tow->sprite, tow->rect);
}

void anim_stazz(tow_g *tow)
{
    tow->rect.top = 0;
    tow->rect.height = 145;
    tow->rect.width = 290;
    tow->clock.time = sfClock_getElapsedTime(tow->clock.clock);
    tow->clock.seconds = tow->clock.time.microseconds / 1000000.0;
    if (tow->clock.seconds > 0.045) {
        tow->rect.left = tow->rect.left + 290;
        if (tow->rect.left >= 2610)
            tow->rect.left = 0;
        sfClock_restart(tow->clock.clock);
    }
    sfSprite_setTextureRect(tow->sprite, tow->rect);
}

void anim_blaster(tow_g *tow)
{
    tow->rect.top = 0;
    tow->rect.height = 99;
    tow->rect.width = 246;
    tow->clock.time = sfClock_getElapsedTime(tow->clock.clock);
    tow->clock.seconds = tow->clock.time.microseconds / 1000000.0;
    if (tow->clock.seconds > 0.01) {
        tow->rect.left = tow->rect.left + 246;
        if (tow->rect.left >= 2214)
            tow->rect.left = 0;
        sfClock_restart(tow->clock.clock);
    }
    sfSprite_setTextureRect(tow->sprite, tow->rect);
}
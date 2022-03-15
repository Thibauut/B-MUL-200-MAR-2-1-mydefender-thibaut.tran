/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** anim_weapons.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void move_bullet(tow_g *tow, int len_bul, global_s *all)
{
    enemy_s en;
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    if (tow->verif_shoot == 1) {
        tow->bullet = free_element_at(tow->bullet, len_bul - 1);
        len_bul = len_bul - 1;
    }
    for (int i = 0 ; i < len_bul; i++) {
        en = get_enemy(tow->bullet, i);
        if (sfSprite_getPosition(tow->sprite).x < 1000) {
            // printf("float: %f\n", en.move_b.y);
            // if (tow->type == 1 || tow->type == 4)
            sfSprite_move(en.sprite, tsvf(-10, (en.move_b.y)));
            // else
            //     sfSprite_move(en.sprite, tsvf(-10, 0));
            if (sfSprite_getPosition(en.sprite).x < 0) {
                tow->bullet = free_element_at(tow->bullet, len_bul - 1);
                len_bul -= 1;
            }
        } else {
            if (sfSprite_getPosition(en.sprite).x > 1920) {
                tow->bullet = free_element_at(tow->bullet, len_bul - 1);
                len_bul -= 1;
            }
            sfSprite_move(en.sprite, tsvf(10, 0));
        }
    }
    sfClock_restart(tow->clock_b.clock);
}

void create_bullet_klassico(tow_g *tow, enemy_s t_bullet)
{
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    t_bullet.move_b.x = -10;
    if (pos.x <= 1000) {
        t_bullet.sprite = create_spriteStocky("res/sprites/bullet1.png", pos.x - 30, pos.y + 10, tsvf(1, 1));
    } else {
        t_bullet.sprite = create_spriteStocky("res/sprites/bullet1.png", pos.x - 30, pos.y + 10, tsvf(-1, 1));
    }
    sfVector2f pos_tow = sfSprite_getPosition(t_bullet.sprite);
    float i = (pos_tow.x - tow->target.x);
    float y = (pos_tow.y - tow->target.y);
    float r = y / i;
    t_bullet.move_b.y = r;
    tow->bullet = add_enemy(tow->bullet, t_bullet, 0);
}

void create_bullet_avocado(tow_g *tow, enemy_s t_bullet)
{
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    if (sfSprite_getPosition(tow->sprite).x < 1000)
        t_bullet.sprite = create_spriteStocky("res/sprites/avocado.png", pos.x - 10, pos.y + 5, tsvf(0.7, 0.7));
    else
        t_bullet.sprite = create_spriteStocky("res/sprites/avocado.png", pos.x - 10, pos.y + 5, tsvf(-0.7, 0.7));
    sfVector2f pos_tow = sfSprite_getPosition(t_bullet.sprite);
    float i = (tow->target.x - pos_tow.x) / -10;
    float y = (tow->target.y - pos_tow.y);
    float r = y / i;
    t_bullet.move_b.y = r;
    tow->bullet = add_enemy(tow->bullet, t_bullet, 0);
    tow->bullet = add_enemy(tow->bullet, t_bullet, 0);
}

void create_bullet_hunter(tow_g *tow, enemy_s t_bullet)
{
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    if (sfSprite_getPosition(tow->sprite).x < 1000)
        t_bullet.sprite = create_spriteStocky("res/sprites/hunter.png", pos.x - 10, pos.y + 32, tsvf(1, 1));
    else
        t_bullet.sprite = create_spriteStocky("res/sprites/hunter.png", pos.x - 10, pos.y + 32, tsvf(-1, 1));
    sfVector2f pos_tow = sfSprite_getPosition(t_bullet.sprite);
    float i = (tow->target.x - pos_tow.x) / -10;
    float y = (tow->target.y - pos_tow.y);
    float r = y / i;
    // printf("type: %d distance x: %f distance y: %f target: %f move: %f\n", tow->type, i, y, tow->target.y, r);
    t_bullet.move_b.y = r;
    tow->bullet = add_enemy(tow->bullet, t_bullet, 0);
}

void create_bullet_blaster(tow_g *tow, enemy_s t_bullet)
{
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    if (sfSprite_getPosition(tow->sprite).x < 1000)
        t_bullet.sprite = create_spriteStocky("res/sprites/blaster.png", pos.x - 10, pos.y + 17, tsvf(0.7, 0.7));
    else
        t_bullet.sprite = create_spriteStocky("res/sprites/blaster.png", pos.x - 10, pos.y + 17, tsvf(-0.7, 0.7));
        sfVector2f pos_tow = sfSprite_getPosition(t_bullet.sprite);
    float i = (tow->target.x - pos_tow.x) / -10;
    float y = (tow->target.y - pos_tow.y);
    float r = y / i;
    // printf("type: %d distance x: %f distance y: %f target: %f move: %f\n", tow->type, i, y, tow->target.y, r);
    t_bullet.move_b.y = r;
    tow->bullet = add_enemy(tow->bullet, t_bullet, 0);
}

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
        if (tow->rect.left == 1132 && all->verif_l == 0)
            create_bullet_klassico(tow, t_bullet);
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
            create_bullet_avocado(tow, t_bullet);
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
            create_bullet_hunter(tow, t_bullet);
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
            if (all->verif_l == 0)
                create_bullet_blaster(tow, t_bullet);
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

/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** anim_weapons.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void move_bullet(tow_g *tow, int len_bul, global_s *all)
{
    enemy_s en;
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    for (int i = 0 ; i < len_bul; i++) {
        en = get_enemy(tow->bullet, i);
        if (sfSprite_getPosition(tow->sprite).x < 1000) {
            sfSprite_move(en.sprite, tsvf(-10, (en.move_b.y)));
            if (sfSprite_getPosition(en.sprite).x < 0) {
                tow->bullet = free_element_at(tow->bullet, len_bul - 1);
                len_bul -= 1;
            }
        } else {
            sfSprite_move(en.sprite, tsvf(10, en.move_b.y));
            if (sfSprite_getPosition(en.sprite).x > 1920) {
                tow->bullet = free_element_at(tow->bullet, len_bul - 1);
                len_bul -= 1;
            }
        }
    }
    sfClock_restart(tow->clock_b.clock);
}

void create_bullet_klassico(tow_g *tow, enemy_s t_bullet, global_s *all)
{
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    char *b1 = "res/sprites/bullet1.png";
    t_bullet.move_b.x = -10;
    int dy;
    if (pos.x <= 1000) {
        dy = -10;
        t_bullet.sprite = csS(b1, pos.x - 30, pos.y - 6, tsvf(1, 1));
    } else {
        dy = 10;
        t_bullet.sprite = csS(b1, pos.x - 30, pos.y - 6, tsvf(-1, 1));
    }
    sfVector2f pos_tow = sfSprite_getPosition(t_bullet.sprite);
    float i = (pos_tow.x - tow->target.x) / dy;
    float y = (pos_tow.y - tow->target.y);
    t_bullet.move_b.y = y / i;
    tow->bullet = add_enemy(tow->bullet, t_bullet, 0);
}

void create_bullet_avocado(tow_g *tow, enemy_s t_bullet, global_s *all)
{
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    char *b2 = "res/sprites/avocado.png";
    int dy;
    if (sfSprite_getPosition(tow->sprite).x < 1000) {
        dy = -10;
        t_bullet.sprite = csS(b2, pos.x - 10, pos.y - 10, tsvf(0.7, 0.7));
    } else {
        dy = 10;
        t_bullet.sprite = csS(b2, pos.x - 10, pos.y - 10, tsvf(-0.7, 0.7));
    }
    sfVector2f pos_tow = sfSprite_getPosition(t_bullet.sprite);
    float i = (tow->target.x - pos_tow.x) / dy;
    float y = (tow->target.y - pos_tow.y);
    float r = y / i;
    t_bullet.move_b.y = r;
    tow->bullet = add_enemy(tow->bullet, t_bullet, 0);
}

void create_bullet_hunter(tow_g *tow, enemy_s t_bullet, global_s *all)
{
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    char *b3 = "res/sprites/hunter.png";
    int dy;
    if (sfSprite_getPosition(tow->sprite).x < 1000) {
        dy = -10;
        t_bullet.sprite = csS(b3, pos.x - 10, pos.y + 10, tsvf(1, 1));
    } else {
        dy = 10;
        t_bullet.sprite = csS(b3, pos.x - 10, pos.y + 10, tsvf(-1, 1));
    }
    sfVector2f pos_tow = sfSprite_getPosition(t_bullet.sprite);
    float i = (tow->target.x - pos_tow.x) / dy;
    float y = (tow->target.y - pos_tow.y);
    float r = y / i;
    t_bullet.move_b.y = r;
    tow->bullet = add_enemy(tow->bullet, t_bullet, 0);
}

void create_bullet_blaster(tow_g *tow, enemy_s t_bullet, global_s *all)
{
    sfVector2f pos = sfSprite_getPosition(tow->sprite);
    char *b4 = "res/sprites/blaster.png";
    int dy;
    if (sfSprite_getPosition(tow->sprite).x < 1000) {
        dy = -10;
        t_bullet.sprite = csS(b4, pos.x - 10, pos.y, tsvf(0.7, 0.7));
    } else {
        dy = 10;
        t_bullet.sprite = csS(b4, pos.x - 10, pos.y, tsvf(-0.7, 0.7));
    }
    sfVector2f pos_tow = sfSprite_getPosition(t_bullet.sprite);
    float i = (tow->target.x - pos_tow.x) / dy;
    float y = (tow->target.y - pos_tow.y);
    t_bullet.move_b.y = y / i;
    tow->bullet = add_enemy(tow->bullet, t_bullet, 0);
}

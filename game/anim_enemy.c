/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** anim_enemy.c
*/

#include "../include/func.h"
#include "../include/struct.h"

int anim_e1(sfSprite *spt, one_cl *cl, int i, global_s *all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect enemy_r = sfSprite_getGlobalBounds(spt);
    sfFloatRect base_r = sfSprite_getGlobalBounds(all->sprite.game.base);
    base_r.left = base_r.left + 50;
    sfIntRect rect = {cl->pos, 100, 130, 100};
    sfBool is_rect = sfFloatRect_intersects(&enemy_r, &base_r, NULL);
    if (is_rect == sfTrue)
        rect.top = 0;
    if (en->life <= 0) {
        rect.top = 200;
        is_rect = sfTrue;
        en->col.width = 0;
        en->col.height = 0;
    }
    if (cl->seconds > 0.025) {
        if (is_rect != sfTrue) {
            sfSprite_move(spt, tsvf(3, 0));
            en->col = rect_e1(all, en->sprite);
        }
        cl->pos = cl->pos + i;
        if (cl->pos >= 2340 && is_rect != sfTrue)
            cl->pos = 0;
        if (cl->pos >= 5460 && rect.top == 200)
            return (1);
        if (cl->pos >= 2860 && rect.top == 0)
            cl->pos = 0;
        sfClock_restart(cl->clock);
    }
    sfSprite_setTextureRect(spt, rect);
    return (0);
}

int anim_e1_rev(sfSprite *spt, one_cl *cl, int i, global_s *all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect ennemy_r = sfSprite_getGlobalBounds(spt);
    sfFloatRect base_r = sfSprite_getGlobalBounds(all->sprite.game.base);
    base_r.width = base_r.width - 50;
    sfIntRect rect = {cl->pos, 100, 130, 100};
    sfBool is_rect = sfFloatRect_intersects(&ennemy_r, &base_r, NULL);
    if (is_rect == sfTrue)
        rect.top = 0;
    if (en->life <= 0) {
        rect.top = 200;
        is_rect = sfTrue;
        en->col.width = 0;
        en->col.height = 0;
    }
    if (cl->seconds > 0.025) {
        if (is_rect != sfTrue) {
            sfSprite_move(spt, tsvf(-3, 0));
            en->col = rect_e1_rev(all, en->sprite);
        }
        cl->pos = cl->pos + i;
        if (cl->pos >= 2340 && is_rect != sfTrue)
            cl->pos = 0;
        if (cl->pos >= 5460 && rect.top == 200)
            return (1);
        if (cl->pos >= 2860 && rect.top == 0)
            cl->pos = 0;
        sfClock_restart(cl->clock);
    }
    sfSprite_setTextureRect(spt, rect);
    return (0);
}

int anim_e3(sfSprite *spt, one_cl *cl, int i, global_s* all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect enemy_r = sfSprite_getGlobalBounds(spt);
    sfIntRect rect = {cl->pos, 0, 251, 255};
    sfBool is_rect = sfFalse;
    if (enemy_r.left >= 200)
        is_rect = sfTrue;
    if (is_rect == sfTrue)
        rect.top = 255;
    if (en->life <= 0) {
        rect.top = 510;
        is_rect = sfTrue;
        en->col.width = 0;
        en->col.height = 0;
    }
    if (cl->seconds > 0.02) {
        if (is_rect != sfTrue) {
            sfSprite_move(spt, tsvf(2, 0));
            en->col = rect_e3(all, en->sprite);
        }
        cl->pos = cl->pos + i;
        if (cl->pos >= 1872 && is_rect != sfTrue)
            cl->pos = 0;
        if (cl->pos >= 5522 && rect.top == 510)
            return (1);
        if (cl->pos >= 2041 && rect.top == 255)
            cl->pos = 0;
        sfClock_restart(cl->clock);
    }
    sfSprite_setTextureRect(spt, rect);
    return (0);
}

int anim_e4(sfSprite *spt, one_cl *cl, int i, global_s* all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect enemy_r = sfSprite_getGlobalBounds(spt);
    sfFloatRect base_r = sfSprite_getGlobalBounds(all->sprite.game.base);
    base_r.left = base_r.left + 50;
    sfIntRect rect = {cl->pos, 0, 343, 218};
    sfBool is_rect = sfFloatRect_intersects(&enemy_r, &base_r, NULL);
    if (is_rect == sfTrue)
        rect.top = 218;
    if (en->life <= 0) {
        rect.top = 436;
        is_rect = sfTrue;
    }
    if (cl->seconds > 0.02) {
        if (is_rect != sfTrue) {
            sfSprite_move(spt, tsvf(2, 0));
            en->col = rect_e4(all, en->sprite);
        }
        cl->pos = cl->pos + i;
        if (cl->pos >= 6174 && is_rect != sfTrue)
            cl->pos = 0;
        if (cl->pos >= 6174 && rect.top == 436)
            return (1);
        if (cl->pos >= 5831 && rect.top == 218)
            cl->pos = 0;
        sfClock_restart(cl->clock);
    }
    sfSprite_setTextureRect(spt, rect);
    return (0);
}

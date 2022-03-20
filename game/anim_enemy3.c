/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** anim_enemy3.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void check_death_e1(enemy_s *en, sfIntRect *rect, sfBool *is_rect)
{
    if (*is_rect == sfTrue)
        rect->top = 0;
    if (en->life <= 0) {
        rect->top = 200;
        *is_rect = sfTrue;
        en->col.width = 0;
        en->col.height = 0;
    }
}

void anim_clock_e1(one_cl *cl, sfBool is_rect, sfIntRect *rect)
{
    if (cl->pos >= 2340 && is_rect != sfTrue)
        cl->pos = 0;
}

void anim_clock_e11(global_s *all, one_cl *cl, sfIntRect rect, enemy_s *en)
{
    if (cl->pos >= 2860 && rect.top == 0)
        cl->pos = 0;
    if (rect.top == 0 && cl->pos == 1690)
        refresh_life_base(all, 100);
    sfClock_restart(cl->clock);
}

int anim_e1(one_cl *cl, int i, global_s *all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sffr enemy_r = sfggb(en->sprite), base_r = sfggb(all->sprite.game.base);
    base_r.left = base_r.left + 50;
    sfIntRect rect = {cl->pos, 100, 130, 100};
    sfBool is_rect = sfFloatRect_intersects(&enemy_r, &base_r, NULL);
    check_death_e1(en, &rect, &is_rect);
    if (cl->seconds > 0.025) {
        if (is_rect != sfTrue) {
            sfSprite_move(en->sprite, tsvf(3, 0));
            en->col = rect_e1(all, en->sprite);
        }
        cl->pos = cl->pos + i;
        anim_clock_e1(cl, is_rect, &rect);
        if (cl->pos >= 5460 && rect.top == 200)
            return (1);
        anim_clock_e11(all, cl, rect, en);
    }
    sfSprite_setTextureRect(en->sprite, rect);
    return (0);
}

int anim_e1_rev(one_cl *cl, int i, global_s *all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sffr ennemy_r = sfggb(en->sprite), base_r = sfggb(all->sprite.game.base);
    base_r.width = base_r.width - 50;
    sfIntRect rect = {cl->pos, 100, 130, 100};
    sfBool is_rect = sfFloatRect_intersects(&ennemy_r, &base_r, NULL);
    check_death_e1(en, &rect, &is_rect);
    if (cl->seconds > 0.025) {
        if (is_rect != sfTrue) {
            sfSprite_move(en->sprite, tsvf(-3, 0));
            en->col = rect_e1_rev(all, en->sprite);
        }
        cl->pos = cl->pos + i;
        anim_clock_e1(cl, is_rect, &rect);
        if (cl->pos >= 5460 && rect.top == 200)
            return (1);
        anim_clock_e11(all, cl, rect, en);
    }
    sfSprite_setTextureRect(en->sprite, rect);
    return (0);
}
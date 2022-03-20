/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** anim_enemy2.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#define rer rect_e4_rev
#define ssm sfSprite_move
#define sfr sfFloatRect

void anim_clock_e4(one_cl *cl, sfBool is_rect, sfIntRect *rect)
{
    if (cl->pos >= 6174 && is_rect != sfTrue)
        cl->pos = 0;
    if (cl->pos >= 6174 && rect->top == 436)
        rect->top = 654;
}

void anim_clock_e44(global_s *all, one_cl *cl, sfIntRect rect, enemy_s *en)
{
    if (cl->pos >= 5831 && rect.top == 218) {
        refresh_life_base(all, 150);
        cl->pos = 0;
    }
    if (rect.top != 218) {
        sfSprite_move(en->sprite, tsvf(2, 0));
        en->col = rect_e4(all, en->sprite);
    }
    sfClock_restart(cl->clock);
}

void check_death_e4(enemy_s *en, sfIntRect *rect, sfBool *is_rect)
{
    if (*is_rect == sfTrue)
        rect->top = 218;
    if (en->life <= 0) {
        rect->top = 436;
        *is_rect = sfTrue;
        en->col.width = 0;
        en->col.height = 0;
    }
}

int anim_e4(one_cl *cl, int i, global_s* all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect enemy_r = sfSprite_getGlobalBounds(en->sprite);
    sfFloatRect base_r = sfSprite_getGlobalBounds(all->sprite.game.base);
    base_r.left = base_r.left + 50;
    sfIntRect rect = {cl->pos, 0, 343, 218};
    sfBool is_rect = sfFloatRect_intersects(&enemy_r, &base_r, NULL);
    check_death_e4(en, &rect, &is_rect);
    if (cl->seconds > 0.03) {
        cl->pos = cl->pos + i;
        anim_clock_e4(cl, is_rect, &rect);
        if (cl->pos >= 6174 && rect.top == 654)
            return (1);
        anim_clock_e44(all, cl, rect, en);
    }
    sfSprite_setTextureRect(en->sprite, rect);
    return (0);
}

int anim_e4_rev(one_cl *cl, int i, global_s* all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfr enemy_r = sfggb(en->sprite), base_r = sfggb(all->sprite.game.base);
    base_r.left = base_r.left - 50;
    sfIntRect rect = {cl->pos, 0, 343, 218};
    sfBool is_rect = sfFloatRect_intersects(&enemy_r, &base_r, NULL);
    check_death_e4(en, &rect, &is_rect);
    if (cl->seconds > 0.03) {
        cl->pos = cl->pos + i;
        if (is_rect != sfTrue)
            ssm(en->sprite, tsvf(-2, 0)), en->col = rer(all, en->sprite);
        anim_clock_e4(cl, is_rect, &rect);
        if (cl->pos >= 6174 && rect.top == 654)
            return (1);
        if (cl->pos >= 5831 && rect.top == 218)
            refresh_life_base(all, 150), cl->pos = 0;
        sfClock_restart(cl->clock);
    }
    sfSprite_setTextureRect(en->sprite, rect);
    return (0);
}
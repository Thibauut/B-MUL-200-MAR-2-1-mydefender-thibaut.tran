/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** anim_enemy4.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void check_death_e3(enemy_s *en, sfIntRect *rect, sfBool *is_rect)
{
    if (*is_rect == sfTrue)
        rect->top = 255;
    if (en->life <= 0) {
        rect->top = 510;
        *is_rect = sfTrue;
        en->col.width = 0;
        en->col.height = 0;
    }
}

void anim_clock_e33(global_s *all, one_cl *cl, sfBool is_rect, enemy_s *en)
{
    if (cl->pos >= 1872 && is_rect != sfTrue)
        cl->pos = 0;
    if (cl->pos == 1757 && is_rect == sfTrue) {
        sfSprite_setPosition(en->bullet, tsvf(290, 620));
        refresh_life_base(all, 10);
    }
    if (is_rect == sfTrue) {
        sfSprite_move(en->bullet, tsvf(65, 0));
    }
    sfClock_restart(cl->clock);
}

void anim_move_e3(global_s *all, one_cl *cl, sfBool is_rect, enemy_s *en)
{
    if (is_rect != sfTrue) {
        sfSprite_move(en->sprite, tsvf(2, 0));
        en->col = rect_e3(all, en->sprite);
    }
}

void anim_move_e3_rev(global_s *all, one_cl *cl, sfBool is_rect, enemy_s *en)
{
    if (is_rect != sfTrue) {
        sfSprite_move(en->sprite, tsvf(-2, 0));
        en->col = rect_e3_rev(all, en->sprite);
    }
}

void anim_move_e33(global_s *all, one_cl *cl, sfIntRect *rect, enemy_s *en)
{
    if (cl->pos >= 2041 && rect->top == 255)
        cl->pos = 0;
}
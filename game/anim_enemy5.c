/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** anim_enemy5.c
*/

#include "../include/func.h"
#include "../include/struct.h"

int anim_e3(one_cl *cl, int i, global_s* all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect enemy_r = sfSprite_getGlobalBounds(en->sprite);
    sfIntRect rect = {cl->pos, 0, 251, 255};
    sfBool is_rect = sfFalse;
    if (enemy_r.left >= 200)
        is_rect = sfTrue;
    check_death_e3(en, &rect, &is_rect);
    if (cl->seconds > 0.02) {
        anim_move_e3(all, cl, is_rect, en);
        cl->pos = cl->pos + i;
        if (cl->pos >= 5522 && rect.top == 510)
            return (1);
        anim_move_e33(all, cl, &rect, en);
        anim_clock_e33(all, cl, is_rect, en);
    }
    if (is_rect == sfTrue)
        sfRenderWindow_drawSprite(all->wind, en->bullet, NULL);
    sfSprite_setTextureRect(en->sprite, rect);
    return (0);
}

int anim_e3_rev(one_cl *cl, int i, global_s* all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect enemy_r = sfSprite_getGlobalBounds(en->sprite);
    sfIntRect rect = {cl->pos, 0, 251, 255};
    sfBool is_rect = sfFalse;
    if (enemy_r.left <= 1550)
        is_rect = sfTrue;
    check_death_e3(en, &rect, &is_rect);
    if (cl->seconds > 0.02) {
        anim_move_e3_rev(all, cl, is_rect, en);
        cl->pos = cl->pos + i;
        if (cl->pos >= 5522 && rect.top == 510)
            return (1);
        anim_move_e33(all, cl, &rect, en);
        anim_clock_e33(all, cl, is_rect, en);
    }
    if (is_rect == sfTrue)
        sfRenderWindow_drawSprite(all->wind, en->bullet, NULL);
    sfSprite_setTextureRect(en->sprite, rect);
    return (0);
}
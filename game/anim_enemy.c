/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** anim_enemy.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void refresh_life_base(global_s *all, int dmg)
{
    if (dmg == 10000) {
        all->sprite.game.blood -= 1000;
        all->sprite.game.life_b = 5000;
    } else {
        all->sprite.game.life_b -= dmg;
    }
    all->life = (all->sprite.life_tmp / 183) + 1;
    all->life = (int) all->sprite.game.life_b / all->life;
    all->rect_life = create_rect(0, 0, all->life, 12);
    sfSprite_setTextureRect(all->sprite.game.life_bs, all->rect_life);
    if (all->sprite.game.life_b <= 0)
        loose_game(all);
}

int anim_e1(one_cl *cl, int i, global_s *all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect enemy_r = sfSprite_getGlobalBounds(en->sprite);
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
            sfSprite_move(en->sprite, tsvf(3, 0));
            en->col = rect_e1(all, en->sprite);
        }
        cl->pos = cl->pos + i;
        if (cl->pos >= 2340 && is_rect != sfTrue)
            cl->pos = 0;
        if (cl->pos >= 5460 && rect.top == 200)
            return (1);
        if (cl->pos >= 2860 && rect.top == 0)
            cl->pos = 0;
        if (rect.top == 0 && cl->pos == 1690)
            refresh_life_base(all, 100);
        sfClock_restart(cl->clock);
    }
    sfSprite_setTextureRect(en->sprite, rect);
    return (0);
}

int anim_e1_rev(one_cl *cl, int i, global_s *all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect ennemy_r = sfSprite_getGlobalBounds(en->sprite);
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
            sfSprite_move(en->sprite, tsvf(-3, 0));
            en->col = rect_e1_rev(all, en->sprite);
        }
        cl->pos = cl->pos + i;
        if (cl->pos >= 2340 && is_rect != sfTrue)
            cl->pos = 0;
        if (cl->pos >= 5460 && rect.top == 200)
            return (1);
        if (cl->pos >= 2860 && rect.top == 0)
            cl->pos = 0;
        if (rect.top == 0 && cl->pos == 1690)
            refresh_life_base(all, 100);
        sfClock_restart(cl->clock);
    }
    sfSprite_setTextureRect(en->sprite, rect);
    return (0);
}

int anim_e3(one_cl *cl, int i, global_s* all, enemy_s *en)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect enemy_r = sfSprite_getGlobalBounds(en->sprite);
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
            sfSprite_move(en->sprite, tsvf(2, 0));
            en->col = rect_e3(all, en->sprite);
        }
        cl->pos = cl->pos + i;
        if (cl->pos >= 1872 && is_rect != sfTrue)
            cl->pos = 0;
        if (cl->pos >= 5522 && rect.top == 510)
            return (1);
        if (cl->pos >= 2041 && rect.top == 255)
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
            sfSprite_move(en->sprite, tsvf(-2, 0));
            en->col = rect_e3_rev(all, en->sprite);
        }
        cl->pos = cl->pos + i;
        if (cl->pos >= 1872 && is_rect != sfTrue)
            cl->pos = 0;
        if (cl->pos >= 5522 && rect.top == 510)
            return (1);
        if (cl->pos >= 2041 && rect.top == 255)
            cl->pos = 0;
        if (cl->pos == 1757 && is_rect == sfTrue) {
            sfSprite_setPosition(en->bullet, tsvf(1550, 610));
            refresh_life_base(all, 10);
        }
        if (is_rect == sfTrue) {
            sfSprite_move(en->bullet, tsvf(-57, 0));
        }
        sfClock_restart(cl->clock);
    }
    if (is_rect == sfTrue)
        sfRenderWindow_drawSprite(all->wind, en->bullet, NULL);
    sfSprite_setTextureRect(en->sprite, rect);
    return (0);
}

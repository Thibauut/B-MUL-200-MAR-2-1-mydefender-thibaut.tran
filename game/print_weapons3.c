/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** print_weapons3.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

void print_weapons2(global_s *all, tow_g *tow)
{
    sfSprite_setRotation(tow->sprite, 0);
    if (tow->pos.x == 820 && tow->pos.y == 537) {
        sfSprite_setRotation(tow->sprite, -25);
        if (tow->type == 1 || tow->type == 4)
            sfssp(tow->sprite, tsvf(tow->pos.x - 100, tow->pos.y + 100));
        if (tow->type == 2)
            sfssp(tow->sprite, tsvf(tow->pos.x - 70, tow->pos.y + 100));
        if (tow->type == 3)
            sfssp(tow->sprite, tsvf(tow->pos.x - 115, tow->pos.y + 85));
    }
    if (tow->pos.x == 1175 && tow->pos.y == 537) {
        sfSprite_setRotation(tow->sprite, 25);
        if (tow->type == 1 || tow->type == 4)
            sfssp(tow->sprite, tsvf(tow->pos.x, tow->pos.y + 110));
        if (tow->type == 2)
            sfssp(tow->sprite, tsvf(tow->pos.x - 15, tow->pos.y + 100));
        if (tow->type == 3)
            sfssp(tow->sprite, tsvf(tow->pos.x + 25, tow->pos.y + 85));
    }
}

void print_weapons3(global_s *all, tow_g *tow)
{
    sfSprite_setRotation(tow->sprite, 0);
    if (tow->pos.x == 685 && tow->pos.y == 795) {
        sfSprite_setRotation(tow->sprite, 25);
        if (tow->type == 1 || tow->type == 4)
            sfssp(tow->sprite, tsvf(tow->pos.x - 90, tow->pos.y + 55));
        if (tow->type == 2)
            sfssp(tow->sprite, tsvf(tow->pos.x - 60, tow->pos.y + 70));
        if (tow->type == 3)
            sfssp(tow->sprite, tsvf(tow->pos.x - 90, tow->pos.y + 20));
    }
    if (tow->pos.x == 1305 && tow->pos.y == 795) {
        sfSprite_setRotation(tow->sprite, -25);
        if (tow->type == 1 || tow->type == 4)
            sfssp(tow->sprite, tsvf(tow->pos.x, tow->pos.y + 50));
        if (tow->type == 2)
            sfssp(tow->sprite, tsvf(tow->pos.x - 10, tow->pos.y + 70));
        if (tow->type == 3)
            sfssp(tow->sprite, tsvf(tow->pos.x, tow->pos.y + 20));
    }
}

void print_weapons4(global_s *all, tow_g *tow, sfFloatRect rect, int i)
{
    if (sfFloatRect_contains(&rect, all->pos_mouse.x, all->pos_mouse.y)) {
        sfssp(tow->sprite, tsvf(tow->pos.x - 2, tow->pos.y - 3));
        if (all->event->type == sfEvtMouseButtonPressed) {
            all->sprite.game.is_bar = True;
            all->sprite.game.wc_tower = i;
        }
    } else {
        sfssp(tow->sprite, tow->pos);
    }
}

void print_weapons5(global_s *all, tow_g *tow, int i)
{
    choose_target(all, &*tow);
    if (tow->type > 0) {
        if (tow->target.y > 650)
            print_weapons2(all, &*tow);
        else
            print_weapons3(all, &*tow);
    }
    all->sprite.game.list_tow = fta(all->sprite.game.list_tow, i);
    all->sprite.game.list_tow = addt(all->sprite.game.list_tow, *tow, i);
}

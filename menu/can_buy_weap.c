/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** can_buy_weap.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void weap2(global_s *all, sfTexture *texture, v2f pos)
{
    if (all->info_p->coins >= 800) {
        sfSprite_setPosition(all->sprite.weapons.unlock1, pos);
        texture = sfTexture_createFromFile("res/weapons/wp2.png", NULL);
        sfSprite_setTexture(all->sprite.weapons.wp2, texture, sfFalse);
        all->info_p->coins = all->info_p->coins - 800;
        all->info_p->tower = all->info_p->tower + 1000;
    }
}

void weap3(global_s *all, sfTexture *texture, v2f pos)
{
    if (all->info_p->coins >= 800) {
        sfSprite_setPosition(all->sprite.weapons.unlock2, pos);
        texture = sfTexture_createFromFile("res/weapons/wp3.png", NULL);
        sfSprite_setTexture(all->sprite.weapons.wp3, texture, sfFalse);
        all->info_p->coins = all->info_p->coins - 800;
        all->info_p->tower = all->info_p->tower + 100;
    }
}

void weap4(global_s *all, sfTexture *texture, v2f pos)
{
    if (all->info_p->coins >= 1000) {
        sfSprite_setPosition(all->sprite.weapons.unlock3, pos);
        texture = sfTexture_createFromFile("res/weapons/wp4.png", NULL);
        sfSprite_setTexture(all->sprite.weapons.wp4, texture, sfFalse);
        all->info_p->coins = all->info_p->coins - 1000;
        all->info_p->tower = all->info_p->tower + 10;
    }
}

void weap5(global_s *all, sfTexture *texture, v2f pos)
{
    if (all->info_p->coins >= 1200) {
        texture = sfTexture_createFromFile("res/weapons/wp5.png", NULL);
        sfSprite_setTexture(all->sprite.weapons.wp5, texture, sfFalse);
        all->info_p->coins = all->info_p->coins - 1200;
        all->info_p->tower = all->info_p->tower + 1;
    }
}

void can_buy_weap(global_s *all, int wep)
{
    sfTexture *texture;
    sfVector2f pos = {-1000, 0};
    switch (wep)
    {
    case 2: weap2(all, texture, pos);
        break;
    case 3: weap3(all, texture, pos);
        break;
    case 4: weap4(all, texture, pos);
        break;
    case 5: weap5(all, texture, pos);
        break;
    }
}
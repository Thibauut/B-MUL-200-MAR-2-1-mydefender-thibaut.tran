/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** add_weapons.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void is_weap_unclock_sp(global_s *all, sfSprite *sprite, char *file_unlock, int wp)
{
    sfTexture *texture = sfTexture_createFromFile(file_unlock, NULL);
    char *str = my_itoa(all->info_p->tower);
    char m = str[wp - 1];
    if (m == '1') {
        sfSprite_setTexture(sprite, texture, sfTrue);
    }
}

int is_weap_unclock(global_s *all, int wp)
{
    char *str = my_itoa(all->info_p->tower);
    char m = str[wp - 1];
    if (m == '1')
        return (1);
    return (0);
}

void create_weapons(global_s *all)
{
    sfVector2f size_1 = {0.5 , 0.5}, size_2 = {0.6 , 0.6};
    all->sprite.weapons.unlock1 = csS("res/weapons/unlock_bt.png", 710, 810, size_2);
    all->sprite.weapons.unlock2 = csS("res/weapons/unlock_bt.png", 1460, 460, size_2);
    all->sprite.weapons.unlock3 = csS("res/weapons/unlock_bt.png", 1460, 810, size_2);
    all->sprite.weapons.unlock4 = csS("res/weapons/unlock_bt.png", 0, 0, size_2);
    all->sprite.weapons.wp1 = csS("res/weapons/wp1.png", 250, 280, size_1);
    all->sprite.weapons.wp2 = csS("res/weapons/wp2_lock.png", 220, 630, size_1);
    is_weap_unclock_sp(all, all->sprite.weapons.wp2, "res/weapons/wp2.png", 2);
    all->sprite.weapons.wp3 = csS("res/weapons/wp3_lock.png", 960, 280, size_1);
    is_weap_unclock_sp(all, all->sprite.weapons.wp3, "res/weapons/wp3.png", 3);
    all->sprite.weapons.wp4 = csS("res/weapons/wp4_lock.png", 960, 630, size_1);
    is_weap_unclock_sp(all, all->sprite.weapons.wp4, "res/weapons/wp4.png", 4);
    all->sprite.weapons.wp5 = csS("res/weapons/wp5_lock.png", 0, 0, size_1);
    is_weap_unclock_sp(all, all->sprite.weapons.wp5, "res/weapons/wp5.png", 5);
}

void print_weap(global_s *all)
{
    sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.wp1, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.wp2, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.wp3, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.wp4, NULL);
    // sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.unlock1, NULL);
    // sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.unlock2, NULL);
    // sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.unlock3, NULL);
    return;
}
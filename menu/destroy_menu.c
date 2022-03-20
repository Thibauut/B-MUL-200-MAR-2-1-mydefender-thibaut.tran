/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** destroy_menu.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void destroy_menu(global_s *all)
{
    sfSprite_destroy(all->sprite.menu.bg_1);
    sfSprite_destroy(all->sprite.menu.bg_2);
    sfSprite_destroy(all->sprite.menu.bg_3);
    sfSprite_destroy(all->sprite.menu.bg_4);
    sfSprite_destroy(all->sprite.menu.bg_5);
    sfSprite_destroy(all->sprite.menu.bg_6);
    sfSprite_destroy(all->sprite.menu.bg_7);
    sfSprite_destroy(all->sprite.menu.bg_8);
    sfSprite_destroy(all->sprite.menu.bt_1);
    sfSprite_destroy(all->sprite.menu.bt_2);
}

void destroy_menu2(global_s *all)
{
    sfSprite_destroy(all->sprite.menu.bt_left2);
    sfSprite_destroy(all->sprite.menu.bt_left3);
    sfSprite_destroy(all->sprite.menu.bt_left);
    sfSprite_destroy(all->sprite.menu.bt_option);
    sfSprite_destroy(all->sprite.menu.bt_right2);
    sfSprite_destroy(all->sprite.menu.bt_right3);
    sfSprite_destroy(all->sprite.menu.bt_right);
    sfSprite_destroy(all->sprite.menu.bt_tutorial);
    sfSprite_destroy(all->sprite.menu.menu);
    sfSprite_destroy(all->sprite.menu.more_bg2);
    sfSprite_destroy(all->sprite.menu.more_bg3);
    sfSprite_destroy(all->sprite.menu.more_bg4);
    sfSprite_destroy(all->sprite.menu.more_bg);
    sfSprite_destroy(all->sprite.menu.r_option);
    sfSprite_destroy(all->sprite.menu.tutorial);
}

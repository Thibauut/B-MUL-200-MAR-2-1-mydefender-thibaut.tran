/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_place_weap.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void check_place_weap4(global_s *all, char *str)
{
    sfFloatRect rect_4 = sfSprite_getGlobalBounds(all->sprite.weapons.bt_wp4);
    if (sfFloatRect_contains(&rect_4, all->pos_mouse.x, all->pos_mouse.y) && str[3] == '1') {
        int len = all->sprite.game.wc_tower;
        tow_g tow = get_element4(all->sprite.game.list_tow, len);
        if (all->sprite.game.blood < 900 || tow.type == 4)
            return;
        tow.type = 4;
        tow.rect.left = 0;
        tow.rect.width = 246;
        all->sprite.game.is_bar = False;
        all->sprite.game.blood = all->sprite.game.blood - 900;
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, len);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, len);
    }
}

void check_place_weap3(global_s *all, char *str)
{
    sfFloatRect rect_3 = sfSprite_getGlobalBounds(all->sprite.weapons.bt_wp3);
    if (sfFloatRect_contains(&rect_3, all->pos_mouse.x, all->pos_mouse.y) && str[2] == '1') {
        int len = all->sprite.game.wc_tower;
        tow_g tow = get_element4(all->sprite.game.list_tow, len);
        if (all->sprite.game.blood < 600 || tow.type == 3)
            return;
        tow.type = 3;
        tow.rect.left = 0;
        tow.rect.width = 290;
        all->sprite.game.is_bar = False;
        all->sprite.game.blood = all->sprite.game.blood - 600;
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, len);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, len);
    }
}


void check_place_weap2(global_s *all, char *str)
{
    sfFloatRect rect_2 = sfSprite_getGlobalBounds(all->sprite.weapons.bt_wp2);
    if (sfFloatRect_contains(&rect_2, all->pos_mouse.x, all->pos_mouse.y) && str[1] == '1') {
        int len = all->sprite.game.wc_tower;
        tow_g tow = get_element4(all->sprite.game.list_tow, len);
        if (all->sprite.game.blood < 300 || tow.type == 2)
            return;
        tow.type = 2;
        tow.rect.left = 0;
        tow.rect.width = 177;
        all->sprite.game.is_bar = False;
        all->sprite.game.blood = all->sprite.game.blood - 300;
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, len);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, len);
    }
}

void check_place_weap5(global_s *all, char *str)
{
    sfFloatRect rect_5 = sfSprite_getGlobalBounds(all->sprite.weapons.bt_wp5);
    if (sfFloatRect_contains(&rect_5, all->pos_mouse.x, all->pos_mouse.y) && str[4] == '1') {
        int len = all->sprite.game.wc_tower;
        tow_g tow = get_element4(all->sprite.game.list_tow, len);
        if (all->sprite.game.blood < 1200 || tow.type == 5)
            return;
        tow.type = 5;
        all->sprite.game.is_bar = False;
        all->sprite.game.blood = all->sprite.game.blood - 1200;
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, len);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, len);
    }
}

void check_place_weap(global_s *all)
{
    list_tow_g *list_tmp = all->sprite.game.list_tow;
    sfFloatRect rect_1 = sfSprite_getGlobalBounds(all->sprite.weapons.bt_wp1);
    char *str = my_itoa(all->info_p->tower);
    if (sfFloatRect_contains(&rect_1, all->pos_mouse.x, all->pos_mouse.y)) {
        int len = all->sprite.game.wc_tower;
        tow_g tow = get_element4(all->sprite.game.list_tow, len);
        if (all->sprite.game.blood < 100 || tow.type == 1)
            return;
        tow.type = 1;
        tow.rect.left = 0;
        tow.rect.width = 283;
        all->sprite.game.is_bar = False;
        all->sprite.game.blood = all->sprite.game.blood - 100;
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, len);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, len);
    }
    check_place_weap2(all, str);
    check_place_weap3(all, str);
    check_place_weap4(all, str);
    check_place_weap5(all, str);
}

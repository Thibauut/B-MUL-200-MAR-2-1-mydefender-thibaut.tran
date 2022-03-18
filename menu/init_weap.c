/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** init_weap.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void init_weapons(global_s *all)
{
    char *bg_weap = "res/menu/menu_weap/bg_weap.png";
    all->sprite.level.bg_weap = csS(bg_weap, 0, 0, tsvf(1, 1));
    create_weapons(all);
    sfVector2f pos = {2000, 0};
    if (is_weap_unclock(all, 2) == 1)
        sfSprite_setPosition(all->sprite.weapons.unlock1, pos);
    if (is_weap_unclock(all, 3) == 1)
        sfSprite_setPosition(all->sprite.weapons.unlock2, pos);
    if (is_weap_unclock(all, 4) == 1)
        sfSprite_setPosition(all->sprite.weapons.unlock3, pos);
    all->pop6 = pop_up(all, 0.5, 0.04,  all->sprite.weapons.unlock1);
    all->pop7 = pop_up(all, 0.5, 0.04,  all->sprite.weapons.unlock2);
    all->pop8 = pop_up(all, 0.5, 0.04,  all->sprite.weapons.unlock3);
}

void draw_menu_weap(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.bg_weap, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.left_ar, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.right_ar, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_close, NULL);
    print_weap(all);
    draw_pop_up(all->sprite.weapons.unlock1 , all, &all->pop6);
    draw_pop_up(all->sprite.weapons.unlock2, all, &all->pop7);
    draw_pop_up(all->sprite.weapons.unlock3, all, &all->pop8);
    sfRenderWindow_display(all->wind);
}

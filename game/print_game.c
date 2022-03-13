/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** print_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

void is_draw_wep(sfSprite *spt, int num, global_s *all)
{
    char *str = my_itoa(all->info_p->tower);
    char c = str[num];
    if (c == '1')
        sfRenderWindow_drawSprite(all->wind, spt, NULL);
    else {
        sfVector2f vect = sfSprite_getPosition(spt);
        sfSprite_setPosition(all->sprite.weapons.unlock1, vect);
        sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.unlock1, NULL);
    }
}

void draw_bg(global_s *all)
{
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.clouds, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.brume, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.tree, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.road, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.base, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.blood_s, NULL);
}

void print_game(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.bg, NULL);
    draw_bg(all);
    sfText_setString(all->sprite.game.blood_x, my_itoa(all->sprite.game.blood));
    sfRenderWindow_drawText(all->wind, all->sprite.game.blood_x, NULL);
    if (all->sprite.game.is_bar == True) {
        sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.tower_bar, NULL);
        is_draw_wep(all->sprite.weapons.bt_wp1, 0, all);
        is_draw_wep(all->sprite.weapons.bt_wp2, 1, all);
        is_draw_wep(all->sprite.weapons.bt_wp3, 2, all);
        is_draw_wep(all->sprite.weapons.bt_wp4, 3, all);
        is_draw_wep(all->sprite.weapons.bt_wp5, 4, all);
    }
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.life_bbs, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.life_bs, NULL);
    print_weapons(all);
    enemy4(all);
    enemy(all);
    enemy2(all);
    enemy3(all);
    sfRenderWindow_display(all->wind);
}

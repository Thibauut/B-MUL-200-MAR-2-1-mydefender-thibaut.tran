/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** print_game3.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

void is_wep_draw(global_s *all)
{
    sfrwds(all->wind, all->sprite.weapons.tower_bar, NULL);
    is_draw_wep(all->sprite.weapons.bt_wp1, 0, all);
    is_draw_wep(all->sprite.weapons.bt_wp2, 1, all);
    is_draw_wep(all->sprite.weapons.bt_wp3, 2, all);
    is_draw_wep(all->sprite.weapons.bt_wp4, 3, all);
    is_draw_wep(all->sprite.weapons.bt_wp5, 4, all);
}

void print_base_selected(global_s *all)
{
    sfrwds(all->wind, all->sprite.game.bg, NULL);
    if (all->level_played < 4)
        draw_bg(all);
    if (all->level_played >= 4 && all->level_played < 7)
        draw_bg2(all);
    if (all->level_played >= 7 && all->level_played < 10)
        draw_bg3(all);
    sfrwds(all->wind, all->sprite.game.base, NULL);
    sfrwds(all->wind, all->sprite.game.blood_s, NULL);
    sfText_setString(all->sprite.game.blood_x, i_a(all->sprite.game.blood));
    sfRenderWindow_drawText(all->wind, all->sprite.game.blood_x, NULL);
}

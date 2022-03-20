/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** print_game2.c
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
        sfrwds(all->wind, all->sprite.weapons.unlock1, NULL);
    }
}

void draw_bg(global_s *all)
{
    sfrwds(all->wind, all->sprite.game.clouds, NULL);
    sfrwds(all->wind, all->sprite.game.brume, NULL);
    sfrwds(all->wind, all->sprite.game.tree, NULL);
    sfrwds(all->wind, all->sprite.game.road, NULL);
}

void draw_bg2(global_s *all)
{
    sfrwds(all->wind, all->sprite.game.bg1, NULL);
    sfrwds(all->wind, all->sprite.game.bg6, NULL);
    sfrwds(all->wind, all->sprite.game.bg5, NULL);
    sfrwds(all->wind, all->sprite.game.bg4, NULL);
    sfrwds(all->wind, all->sprite.game.bg3, NULL);
    sfrwds(all->wind, all->sprite.game.bg2, NULL);
}

void draw_bg3(global_s *all)
{
    sfrwds(all->wind, all->sprite.game.bg1_1, NULL);
    sfrwds(all->wind, all->sprite.game.bg5_2, NULL);
    sfrwds(all->wind, all->sprite.game.bg4_2, NULL);
    sfrwds(all->wind, all->sprite.game.bg3_2, NULL);
    sfrwds(all->wind, all->sprite.game.bg2_2, NULL);
}

int exit_win_bt(global_s *all)
{
    sfFloatRect rect = sfggb(all->win.exit_bt);
    v2f size = {1.5, 1.5}, sizeup = {1.53, 1.53};
    if (sfFloatRect_contains(&rect, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setScale(all->win.exit_bt, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed)
            return (1);
    } else
        sfSprite_setScale(all->loose.exit_bt, size);
    return (0);
}

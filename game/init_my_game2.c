/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** init_my_game2.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"
#define l_rs list_rev->enemy.sprite
#define l_r list_rev->enemy
#define l_ec list->enemy.clock
#define l_es list->enemy.sprite
#define ae1r anim_e1_rev
#define ae4r anim_e4_rev

void enemy(global_s *all)
{
    list_enemy *list = all->sprite.game.list_enemy;
    int len = list_len_2(list) - 1;
    sfVector2f pos_txt;
    char *txt_string;
    sfFloatRect r_prev, r_now;
    int verif = 0;
    enemy_s enemy;
    for (int i = 0; i != len; list = list->next, i++) {
        if (anim_e1(&l_ec, 130, all, &list->enemy) == 1) {
            all->sprite.game.nb_mecha -= 1;
            all->sprite.game.list_enemy = fet(all->sprite.game.list_enemy, i);
            all->sprite.game.blood += 70;
            continue;
        }
        pos_txt = sfSprite_getPosition(list->enemy.sprite);
        pos_txt.y = pos_txt.y - 30;
        pos_txt.x = pos_txt.x + 70;
        sfRenderWindow_drawSprite(all->wind, list->enemy.sprite, NULL);
        sfrdt(all->wind, pv(pos_txt.x, pos_txt.y, list), NULL);
    }
}

int enemy3_rev_anim(global_s *all, list_enemy *list)
{
    int i = 0;
    i = anim_e3_rev(&list->enemy.clock, 251, all, &list->enemy);
    anim_fx_rev(&list->enemy);
    return (i);
}

void enemy3_rev(global_s *all)
{
    list_enemy *list = all->sprite.game.list_enemy5;
    int len = list_len_2(list) - 1;
    sfVector2f pos_txt;
    enemy_s enemy;
    for (int i = 0; i != len; list = list->next, i++) {
        if (enemy3_rev_anim(all, list) == 1) {
            all->sprite.game.blood += 45;
            all->sprite.game.nb_jet -= 1;
            all->sprite.game.list_enemy5 = fet(all->sprite.game.l_e5, i);
            continue;
        }
        pos_txt = sfSprite_getPosition(list->enemy.sprite);
        pos_txt.y = pos_txt.y - 50;
        pos_txt.x = pos_txt.x + 10;
        if (list->enemy.life > 0)
            sfRenderWindow_drawSprite(all->wind, list->enemy.fx, NULL);
        sfRenderWindow_drawSprite(all->wind, list->enemy.sprite, NULL);
        sfrdt(all->wind, pv(pos_txt.x, pos_txt.y, list), NULL);
    }
}

void enemy4(global_s *all)
{
    list_enemy *list = all->sprite.game.list_enemy4;
    int len = list_len_2(list) - 1;
    sfVector2f pos_txt;
    enemy_s enemy;
    for (int i = 0; i != len; list = list->next, i++) {
        if (anim_e4(&l_ec, 343, all, &list->enemy) == 1) {
            all->sprite.game.nb_car -= 1;
            all->sprite.game.blood += 100;
            all->sprite.game.list_enemy4 = fet(all->sprite.game.l_e4, i);
            continue;
        }
        pos_txt = sfSprite_getPosition(list->enemy.sprite);
        pos_txt.y = pos_txt.y - 50;
        pos_txt.x = pos_txt.x + 10;
        sfRenderWindow_drawSprite(all->wind, list->enemy.sprite, NULL);
        sfrdt(all->wind, pv(pos_txt.x, pos_txt.y, list), NULL);
    }
}

void enemy4_rev(global_s *all)
{
    list_enemy *list = all->sprite.game.list_enemy6;
    int len = list_len_2(list) - 1;
    sfVector2f pos_txt;
    enemy_s enemy;
    for (int i = 0; i != len; list = list->next, i++) {
        if (ae4r(&l_ec, 343, all, &list->enemy) == 1) {
            all->sprite.game.nb_car -= 1;
            all->sprite.game.blood += 100;
            all->sprite.game.list_enemy6 = fet(all->sprite.game.l_e6, i);
            continue;
        }
        pos_txt = sfSprite_getPosition(list->enemy.sprite);
        pos_txt.y = pos_txt.y - 50;
        pos_txt.x = pos_txt.x - 150;
        sfRenderWindow_drawSprite(all->wind, list->enemy.sprite, NULL);
        sfrdt(all->wind, pv(pos_txt.x, pos_txt.y, list), NULL);
    }
}

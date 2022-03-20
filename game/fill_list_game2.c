/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** fill_list_game2.c
*/

#include "../include/func.h"
#include "../include/struct.h"

list_enemy *fill_enemy_4_rev(global_s *all)
{
    enemy_s enemy;
    enemy.life = 200 * all->level_played;
    int count = 1920;
    enemy.type = 0;
    char *e4 = "res/sprites/gova2_spt.png";
    for (int i = 0; i != all->sprite.game.nb_car; i++) {
        enemy.clock = create_one_clock();
        enemy.sprite = csS(e4, count, 768, tsvf(-1, 1));
        sfSprite_setTextureRect(enemy.sprite, create_rect(0, 0, 218, 343));
        count = count + 500;
        enemy.col = rect_e4_rev(all, enemy.sprite);
        all->sprite.game.l_e6 = adde(all->sprite.game.l_e6, enemy, 0);
    }
    return (all->sprite.game.list_enemy6);
}

list_enemy *fill_enemy_3_rev(global_s *all)
{
    enemy_s enemy;
    enemy.life = 50 * all->level_played;
    int count = 1920;
    enemy.type = 0;
    char *jet = "res/sprites/jet_spt.png";
    char *fx = "res/sprites/jet_fx.png";
    char *bullet = "res/sprites/bullet1.png";
    for (int i = 0; i < all->sprite.game.nb_jet; i++) {
        enemy.clock = create_one_clock();
        enemy.clock_fx = create_one_clock();
        enemy.sprite = csS(jet, count, 520, tsvf(-0.8, 0.8));
        enemy.fx = csS(fx, count - 50, 465, tsvf(-0.3, 0.3));
        enemy.bullet = csS(bullet, 1550, 620, tsvf(0.5, 0.5));
        sfSprite_setTextureRect(enemy.sprite, create_rect(0, 0, 251, 255));
        sfSprite_setTextureRect(enemy.fx, create_rect(0, 0, 180, 398));
        count = count + 500;
        enemy.col = rect_e3_rev(all, enemy.sprite);
        all->sprite.game.l_e5 = adde(all->sprite.game.list_enemy5, enemy, 0);
    }
    return (all->sprite.game.list_enemy5);
}

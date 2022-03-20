/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** init_my_game4.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"
#define parallax1_1 "res/game/parallax3/bg1.png"
#define parallax2_1 "res/game/parallax3/bg2.png"
#define parallax3_1 "res/game/parallax3/bg3.png"
#define parallax4_1 "res/game/parallax3/bg4.png"
#define parallax5_1 "res/game/parallax3/bg5.png"
#define parallax1 "res/game/parallax2/bg1.png"
#define parallax2 "res/game/parallax2/bg2.png"
#define parallax3 "res/game/parallax2/bg3.png"
#define parallax4 "res/game/parallax2/bg4.png"
#define parallax5 "res/game/parallax2/bg5.png"
#define parallax6 "res/game/parallax2/bg6.png"

void create_sprites_game5(global_s *all)
{
    all->sprite.game.bg = csS("res/game/bg_sky.png", 0, 0, tsvf(1.1, 1));
    all->sprite.game.clouds = csS("res/game/clouds.png", 0, 0, tsvf(1, 1));
    all->sprite.game.brume = csS("res/game/brume.png", 0, 0, tsvf(1, 1));
    all->sprite.game.road = csS("res/menu/6.png", 0, 535, tsvf(1, 1));
    all->sprite.game.tree = csS("res/game/cloud2.png", 0, 60, tsvf(1, 1));
    all->sprite.game.bg1 = csS(parallax1, 0, 0, tsvf(1, 1));
    all->sprite.game.bg2 = csS(parallax2, 0, 45, tsvf(1, 1));
    all->sprite.game.bg3 = csS(parallax3, 0, 0, tsvf(1, 1));
    all->sprite.game.bg4 = csS(parallax4, 0, 0, tsvf(1, 1));
    all->sprite.game.bg5 = csS(parallax5, 0, 0, tsvf(1, 1));
    all->sprite.game.bg6 = csS(parallax6, 0, 0, tsvf(1, 1));
    all->sprite.game.bg1_1 = csS(parallax1_1, 0, 0, tsvf(1, 1));
    all->sprite.game.bg2_2 = csS(parallax2_1, 0, 35, tsvf(1, 1));
    all->sprite.game.bg3_2 = csS(parallax3_1, 0, 0, tsvf(1, 1));
    all->sprite.game.bg4_2 = csS(parallax4_1, 0, 0, tsvf(1, 1));
    all->sprite.game.bg5_2 = csS(parallax5_1, 0, 0, tsvf(1, 1));
}

void create_sprites_game2(global_s *all)
{
    char *t_bar = "res/weapons/tower_bar.png";
    char *btwp1 = "res/weapons/bt_wp1.png", *btwp2 = "res/weapons/bt_wp2.png";
    char *btwp3 = "res/weapons/bt_wp3.png", *btwp4 = "res/weapons/bt_wp4.png";
    char *bt_wp5 = "res/weapons/bt_wp5.png";
    create_sprites_game5(all);
    all->sprite.weapons.tower_bar = csS(t_bar, 467, 70, tsvf(1, 1));
    all->sprite.weapons.bt_wp1 = csS(btwp1, 487, 125, tsvf(0.6, 0.6));
    all->sprite.weapons.bt_wp2 = csS(btwp2, 697, 120, tsvf(0.85, 0.85));
    all->sprite.weapons.bt_wp3 = csS(btwp3, 886, 93, tsvf(0.6, 0.6));
    all->sprite.weapons.bt_wp4 = csS(btwp4, 1095, 117, tsvf(0.65, 0.65));
    all->sprite.weapons.bt_wp5 = csS(bt_wp5, 1305, 95, tsvf(0.65, 0.65));
    create_sprites_game4(all);
    int i = (all->sprite.game.nb_mecha + all->sprite.game.nb_jet) * 2;
    int j = all->sprite.game.nb_car * 2;
    all->sprite.game.nb_enemy = i + j - 6;
    char *str = my_itoa(all->sprite.game.nb_enemy);
    all->sprite.game.nb_enemy_t = ctS(str, 60, sfWhite, tsvf(1750, 15));
    sfSprite_setOrigin(all->loose.light, tsvf(150, 150));
    sfSprite_setOrigin(all->win.light, tsvf(150, 150));
    create_sprites_game3(all);
}

void init_list(global_s *all)
{
    all->sprite.game.list_tow = NULL;
    all->sprite.game.list_enemy = NULL;
    all->sprite.game.list_enemy2 = NULL;
    all->sprite.game.list_enemy3 = NULL;
    all->sprite.game.list_enemy4 = NULL;
    all->sprite.game.list_enemy5 = NULL;
    all->sprite.game.list_enemy6 = NULL;
}

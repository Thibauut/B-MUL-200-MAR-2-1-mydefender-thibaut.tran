/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** fill_enemy.c
*/

#include "../include/func.h"
#include "../include/struct.h"

list_tow_g *fill_list_tow(global_s *all)
{
    tow_g tow;
    tow.type = 0;
    int bin_x[4], bin_y[4], place = 0;
    bin_x[0] = 685, bin_x[1] = 1305, bin_x[2] = 1175, bin_x[3] = 820;
    bin_y[0] = 795, bin_y[1] = 795, bin_y[2] = 537, bin_y[3] = 537;
    char *wp = "res/game/add_weap.png";
    tow.verif_shoot = 0;
    for (; place != all->info_p->pl_base; place += 1) {
        tow.clock = create_one_clock();
        tow.clock_b = create_one_clock();
        tow.rect.left = 0;
        tow.pos = tsvf(bin_x[place], bin_y[place]);
        tow.sprite = csS(wp, tow.pos.x, tow.pos.y, tsvf(1.2, 1.2));
        tow.rect = sfSprite_getTextureRect(tow.sprite);
        sfso(tow.sprite, tsvf(tow.rect.width, tow.rect.height / 2));
        tow.type = 0;
        tow.bullet = NULL;
        all->sprite.game.list_tow = addt(all->sprite.game.list_tow, tow, 0);
    }
    return (all->sprite.game.list_tow);
}

list_enemy *fill_enemy(global_s *all)
{
    enemy_s enemy;
    enemy.life = 100 * all->level_played;
    int count = 10;
    enemy.type = 0;
    char *spt = "res/sprites/e1_spt_2.png";
    for (int i = 0; i != all->sprite.game.nb_mecha; i++) {
        enemy.clock = create_one_clock();
        enemy.sprite = create_spriteStocky(spt, count, 780, tsvf(1.9, 1.9));
        sfSprite_setTextureRect(enemy.sprite, create_rect(100, 130, 0, 0));
        count = count - 500;
        enemy.col = rect_e1(all, enemy.sprite);
        all->sprite.game.l_e = adde(all->sprite.game.list_enemy, enemy, 0);
    }
    return (all->sprite.game.list_enemy);
}

list_enemy *fill_enemy_2(global_s *all)
{
    enemy_s enemy;
    enemy.life = 100 * all->level_played;
    int count = 1920;
    enemy.type = 0;
    char *e1 = "res/sprites/e1_spt_2.png";
    for (int i = 0; i != all->sprite.game.nb_mecha; i++) {
        enemy.clock = create_one_clock();
        enemy.sprite = create_spriteStocky(e1, count, 780, tsvf(-1.9, 1.9));
        sfSprite_setTextureRect(enemy.sprite, create_rect(100, 130, 0, 0));
        count = count + 500;
        enemy.col = rect_e1_rev(all, enemy.sprite);
        all->sprite.game.l_e2 = adde(all->sprite.game.list_enemy2, enemy, 0);
    }
    return (all->sprite.game.list_enemy2);
}

list_enemy *fill_enemy_3(global_s *all)
{
    enemy_s enemy;
    enemy.life = 50 * all->level_played;
    int count = 0;
    enemy.type = 0;
    char *jet = "res/sprites/jet_spt.png";
    char *fx = "res/sprites/jet_fx.png";
    char *bullet = "res/sprites/bullet1.png";
    for (int i = 0; i < all->sprite.game.nb_jet; i++) {
        enemy.clock = create_one_clock();
        enemy.clock_fx = create_one_clock();
        enemy.sprite = csS(jet, count, 520, tsvf(0.8, 0.8));
        enemy.fx = csS(fx, count - 50, 465, tsvf(0.3, 0.3));
        enemy.bullet = csS(bullet, 290, 620, tsvf(-0.5, -0.5));
        sfSprite_setTextureRect(enemy.sprite, create_rect(0, 0, 251, 255));
        sfSprite_setTextureRect(enemy.fx, create_rect(0, 0, 180, 398));
        count = count - 500;
        enemy.col = rect_e3(all, enemy.sprite);
        all->sprite.game.l_e3 = adde(all->sprite.game.list_enemy3, enemy, 0);
    }
    return (all->sprite.game.list_enemy3);
}

list_enemy *fill_enemy_4(global_s *all)
{
    enemy_s enemy;
    enemy.life = 200 * all->level_played;
    int count = 0;
    enemy.type = 0;
    char *e4 = "res/sprites/gova2_spt.png";
    for (int i = 0; i != all->sprite.game.nb_car; i++) {
        enemy.clock = create_one_clock();
        enemy.sprite = csS(e4, count, 768, tsvf(1, 1));
        sfSprite_setTextureRect(enemy.sprite, create_rect(0, 0, 218, 343));
        count = count - 500;
        enemy.col = rect_e4(all, enemy.sprite);
        all->sprite.game.l_e4 = adde(all->sprite.game.l_e4, enemy, 0);
    }
    return (all->sprite.game.list_enemy4);
}

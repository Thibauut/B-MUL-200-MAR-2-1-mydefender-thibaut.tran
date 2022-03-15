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
    list_tow_g *list = NULL;
    tow_g tow;
    tow.type = 0;
    int bin_x[4];
    bin_x[0] = 650;
    bin_x[1] = 1265;
    bin_x[2] = 1130;
    bin_x[3] = 780;
    int bin_y[4];
    bin_y[0] = 790;
    bin_y[1] = 790;
    bin_y[2] = 535;
    bin_y[3] = 535;
    int place = 0;
    tow.verif_shoot = 0;
    for (; place != all->info_p->pl_base; place += 1) {
        tow.clock = create_one_clock();
        tow.clock_b = create_one_clock();
        tow.rect.left = 0;
        tow.pos = tsvf(bin_x[place], bin_y[place]);
        tow.sprite = create_spriteStocky("res/game/add_weap.png", tow.pos.x, tow.pos.y, tsvf(1.2, 1.2));
        tow.rect = sfSprite_getTextureRect(tow.sprite);
        sfSprite_setOrigin(tow.sprite, tsvf(tow.rect.width / 2 , tow.rect.height / 2));
        tow.type = 0;
        tow.bullet = NULL;
        list = add_tower(list, tow, 0);
    }
    return (list);
}

list_enemy *fill_enemy(global_s *all)
{
    list_enemy *list = NULL;
    enemy_s enemy;
    enemy.life = 1000;
    int count = 10;
    enemy.type = 0;
    printf("mecha: %i ", all->sprite.game.nb_mecha - 1);
    for (int i = 0; i != all->sprite.game.nb_mecha ; i++) {
        enemy.clock = create_one_clock();
        enemy.sprite = create_spriteStocky("res/sprites/e1_spt_2.png", count, 780, tsvf(1.9, 1.9));
        sfSprite_setTextureRect(enemy.sprite, create_rect(100, 130, 0, 0));
        count = count - 500;
        enemy.col = rect_e1(all, enemy.sprite);
        list = add_enemy(list, enemy, 0);
    }
    return (list);
}

list_enemy *fill_enemy_2(global_s *all)
{
    list_enemy *list = NULL;
    enemy_s enemy;
    enemy.life = 1000;
    int count = 1920;
    enemy.type = 0;
    printf("mecha_rev: %i ", all->sprite.game.nb_mecha - 1);
    for (int i = 0; i != all->sprite.game.nb_mecha; i++) {
        enemy.clock = create_one_clock();
        enemy.sprite = create_spriteStocky("res/sprites/e1_spt_2.png", count, 780, tsvf(-1.9, 1.9));
        sfSprite_setTextureRect(enemy.sprite, create_rect(100, 130, 0, 0));
        count = count + 500;
        enemy.col = rect_e1_rev(all, enemy.sprite);
        list = add_enemy(list, enemy, 0);
    }
    return (list);
}

list_enemy *fill_enemy_3(global_s *all)
{
    list_enemy *list = NULL;
    enemy_s enemy;
    enemy.life = 300;
    int count = 0;
    enemy.type = 0;
    printf("jet: %i ", all->sprite.game.nb_jet - 1);
    for (int i = 0; i != all->sprite.game.nb_jet; i++) {
        enemy.clock = create_one_clock();
        enemy.clock_fx = create_one_clock();
        enemy.sprite = create_spriteStocky("res/sprites/jet_spt.png", count, 520, tsvf(0.8, 0.8));
        enemy.fx = create_spriteStocky("res/sprites/jet_fx.png", count - 50, 465, tsvf(0.3, 0.3));
        sfSprite_setTextureRect(enemy.sprite, create_rect(0, 0, 251, 255));
        sfSprite_setTextureRect(enemy.fx, create_rect(0, 0, 180, 398));
        count = count - 500;
        enemy.col = rect_e3(all, enemy.sprite);
        list = add_enemy(list, enemy, 0);
    }
    return (list);
}

list_enemy *fill_enemy_4(global_s *all)
{
    list_enemy *list = NULL;
    enemy_s enemy;
    enemy.life = 1000;
    int count = 0;
    enemy.type = 0;
    printf("gova: %i ", all->sprite.game.nb_car - 1);
    for (int i = 0; i != all->sprite.game.nb_car; i++) {
        enemy.clock = create_one_clock();
        enemy.sprite = create_spriteStocky("res/sprites/gova2_spt.png", count, 768, tsvf(1, 1));
        sfSprite_setTextureRect(enemy.sprite, create_rect(0, 0, 218, 343));
        count = count - 500;
        enemy.col = rect_e4(all, enemy.sprite);
        list = add_enemy(list, enemy, 0);
    }
    return (list);
}
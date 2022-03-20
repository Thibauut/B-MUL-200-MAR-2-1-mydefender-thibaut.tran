/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** collision_enemy.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void detect_mecha(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test)
{
    sfFloatRect rect_b = sfSprite_getGlobalBounds(bullet_l->sprite);
    sfFloatRect rect_e;
    enemy_s enemy;
    int len_mecha = list_len_2(all->sprite.game.list_enemy);
    for (int i = 0; i != len_mecha; i++) {
        enemy = get_enemy(all->sprite.game.list_enemy, i);
        rect_e = rect_e1(all, enemy.sprite);
        if (sfFloatRect_intersects(&rect_e, &rect_b, NULL)) {
            enemy.life = enemy.life - dmg(tow->type, all->info_p->base);
            *test += 1;
            all->sprite.game.list_enemy = fet(all->sprite.game.list_enemy, i);
            all->sprite.game.list_enemy = adde(all->sprite.game.l_e, enemy, i);
            return;
        }
    }
    detect_mecha_rev(all, bullet_l, tow, test);
}

void detect_mecha_rev(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test)
{
    sfFloatRect rect_b = sfSprite_getGlobalBounds(bullet_l->sprite);
    sfFloatRect rect_e;
    enemy_s enemy;
    int len_mecha_rev = list_len_2(all->sprite.game.list_enemy2);
    for (int i = 0; i != len_mecha_rev; i++) {
        enemy = get_enemy(all->sprite.game.list_enemy2, i);
        rect_e = rect_e1_rev(all, enemy.sprite);
        if (sfFloatRect_intersects(&rect_e, &rect_b, NULL)) {
            enemy.life = enemy.life - dmg(tow->type, all->info_p->base);
            *test += 1;
            all->sprite.game.list_enemy2 = fet(all->sprite.game.l_e2, i);
            all->sprite.game.l_e2 = adde(all->sprite.game.l_e2, enemy, i);
            return;
        }
    }
    detect_jet(all, bullet_l, tow, test);
}

void detect_jet(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test)
{
    sfFloatRect rect_b = sfSprite_getGlobalBounds(bullet_l->sprite);
    sfFloatRect rect_e;
    enemy_s enemy;
    int len_jet = list_len_2(all->sprite.game.list_enemy3);
    for (int i = 0; i != len_jet; i++) {
        enemy = get_enemy(all->sprite.game.list_enemy3, i);
        rect_e = rect_e3(all, enemy.sprite);
        if (sfFloatRect_intersects(&rect_e, &rect_b, NULL)) {
                enemy.life = enemy.life - dmg(tow->type, all->info_p->base);
                *test += 1;
                all->sprite.game.list_enemy3 = fet(all->sprite.game.l_e3, i);
                all->sprite.game.l_e3 = adde(all->sprite.game.l_e3, enemy, i);
                return;
        }
    }
    detect_car(all, bullet_l, tow, test);
}

void detect_car(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test)
{
    sfFloatRect rect_b = sfSprite_getGlobalBounds(bullet_l->sprite);
    sfFloatRect rect_e;
    enemy_s enemy;
    int len_jet = list_len_2(all->sprite.game.l_e4);
    for (int i = 0; i != len_jet; i++) {
        enemy = get_enemy(all->sprite.game.list_enemy4, i);
        rect_e = rect_e4(all, enemy.sprite);
        if (sfFloatRect_intersects(&rect_e, &rect_b, NULL)) {
            enemy.life = enemy.life - dmg(tow->type, all->info_p->base);
            *test += 1;
            all->sprite.game.list_enemy4 = fet(all->sprite.game.l_e4, i);
            all->sprite.game.l_e4 = adde(all->sprite.game.l_e4, enemy, i);
            return;
        }
    }
    detect_jet_rev(all, bullet_l, tow, test);
}

void detect_jet_rev(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test)
{
    sfFloatRect rect_b = sfSprite_getGlobalBounds(bullet_l->sprite);
    sfFloatRect rect_e;
    enemy_s enemy;
    int len_jet = list_len_2(all->sprite.game.l_e5);
    for (int i = 0; i != len_jet; i++) {
        enemy = get_enemy(all->sprite.game.list_enemy5, i);
        rect_e = rect_e3_rev(all, enemy.sprite);
        if (sfFloatRect_intersects(&rect_e, &rect_b, NULL)) {
            enemy.life = enemy.life - dmg(tow->type, all->info_p->base);
            *test += 1;
            all->sprite.game.list_enemy5 = fet(all->sprite.game.l_e5, i);
            all->sprite.game.l_e5 = adde(all->sprite.game.l_e5, enemy, i);
            return;
        }
    }
    detect_car_rev(all, bullet_l, tow, test);
}

void detect_car_rev(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test)
{
    sfFloatRect rect_b = sfSprite_getGlobalBounds(bullet_l->sprite);
    sfFloatRect rect_e;
    enemy_s enemy;
    int len_jet = list_len_2(all->sprite.game.l_e6);
    for (int i = 0; i != len_jet; i++) {
        enemy = get_enemy(all->sprite.game.list_enemy6, i);
        rect_e = rect_e4_rev(all, enemy.sprite);
        if (sfFloatRect_intersects(&rect_e, &rect_b, NULL)) {
            enemy.life = enemy.life - dmg(tow->type, all->info_p->base);
            *test += 1;
            all->sprite.game.list_enemy6 = fet(all->sprite.game.l_e6, i);
            all->sprite.game.l_e6 = adde(all->sprite.game.l_e6, enemy, i);
            return;
        }
    }
}
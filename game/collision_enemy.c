/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** collision_enemy.c
*/

#include "../include/func.h"
#include "../include/struct.h"

int collision_e1(global_s *all, list_enemy *list, int r)
{
    int verif = 0;
    int len_tow = list_len(all->sprite.game.list_tow);
    for (int i = 0, len_bul = 0; i != len_tow; i++) {
        if ((i % 2) == 0) {
            i = i + 1;
            if (i >= len_tow)
                return (0);
        }
        tow_g tow = get_element4(all->sprite.game.list_tow, i);
        len_bul = list_len_2(tow.bullet);
        if (len_bul >= 1) {
            enemy_s ene = get_enemy(all->sprite.game.list_enemy, r);
            enemy_s bull = get_enemy(tow.bullet, len_bul - 1);
            sfFloatRect rect_b = sfSprite_getGlobalBounds(bull.sprite);
            if (sfFloatRect_intersects(&ene.col, &rect_b, NULL)) {
                ene.life = ene.life - dmg(tow.type, all->info_p->base);
                all->verif_b = 1;
                all->sprite.game.list_enemy = free_element_at(all->sprite.game.list_enemy, r);
                all->sprite.game.list_enemy = add_enemy(all->sprite.game.list_enemy, ene, r);
                return (1);
            }
        }
    }
    return (0);
}

int collision_e1_rev(global_s *all, list_enemy *list, int r)
{
    int verif = 0;
    int len_tow = list_len(all->sprite.game.list_tow);
    for (int i = 0; i != len_tow; i++) {
        if ((i % 2) != 0) {
            i = i + 1;
            if (i >= len_tow)
                return (0);
        }
        tow_g tow = get_element4(all->sprite.game.list_tow, i);
        int len_bul = list_len_2(tow.bullet);
        if (len_bul >= 1) {
            enemy_s ene = get_enemy(all->sprite.game.list_enemy2, r);
            enemy_s bull = get_enemy(tow.bullet, len_bul - 1);
            sfFloatRect rect_b = sfSprite_getGlobalBounds(bull.sprite);
            if (sfFloatRect_intersects(&ene.col, &rect_b, NULL)) {
                ene.life = ene.life - dmg(tow.type, all->info_p->base);
                all->verif_b2 = 1;
                all->sprite.game.list_enemy2 = free_element_at(all->sprite.game.list_enemy2, r);
                all->sprite.game.list_enemy2 = add_enemy(all->sprite.game.list_enemy2, ene, r);
                return (1);
            }
        }
    }
    return (0);
}


int collision_e3(global_s *all, list_enemy *list, int r)
{
    int verif = 0;
    int len_tow = list_len(all->sprite.game.list_tow);
    for (int i = 0; i != len_tow; i++) {
        if ((i % 2) != 0) {
            i = i + 1;
            if (i >= len_tow)
                return (0);
        }
        tow_g tow = get_element4(all->sprite.game.list_tow, i);
        int len_bul = list_len_2(tow.bullet);
        if (len_bul >= 1) {
            enemy_s ene = get_enemy(all->sprite.game.list_enemy3, r);
            enemy_s bull = get_enemy(tow.bullet, len_bul - 1);
            sfFloatRect rect_b = sfSprite_getGlobalBounds(bull.sprite);
            if (sfFloatRect_intersects(&ene.col, &rect_b, NULL)) {
                ene.life = ene.life - dmg(tow.type, all->info_p->base);
                all->verif_b2 = 1;
                all->sprite.game.list_enemy3 = free_element_at(all->sprite.game.list_enemy3, r);
                all->sprite.game.list_enemy3 = add_enemy(all->sprite.game.list_enemy3, ene, r);
                return (1);
            }
        }
    }
    return (0);
}

int collision_e4(global_s *all, list_enemy *list, int r)
{
    int verif = 0;
    int len_tow = list_len(all->sprite.game.list_tow);
    for (int i = 0; i != len_tow; i++) {
        if ((i % 2) != 0) {
            i = i + 1;
            if (i >= len_tow)
                return (0);
        }
        tow_g tow = get_element4(all->sprite.game.list_tow, i);
        int len_bul = list_len_2(tow.bullet);
        if (len_bul >= 1) {
            enemy_s ene = get_enemy(all->sprite.game.list_enemy4, r);
            enemy_s bull = get_enemy(tow.bullet, len_bul - 1);
            sfFloatRect rect_b = sfSprite_getGlobalBounds(bull.sprite);
            if (sfFloatRect_intersects(&ene.col, &rect_b, NULL)) {
                ene.life = ene.life - dmg(tow.type, all->info_p->base);
                all->verif_b2 = 1;
                all->sprite.game.list_enemy4 = free_element_at(all->sprite.game.list_enemy4, r);
                all->sprite.game.list_enemy4 = add_enemy(all->sprite.game.list_enemy4, ene, r);
                return (1);
            }
        }
    }
    return (0);
}
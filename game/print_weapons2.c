/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** print_weapons2.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

tow_g choose_texture(global_s *all, tow_g tow)
{
    sfTexture *texture;
    if (tow.type == 0) {
        texture = sfTexture_createFromFile("res/game/add_weap.png", NULL);
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        return (tow);
    }
    sfVector2f scale = {0.45, 0.45};
    all->more = 0;
    if (sfSprite_getPosition(tow.sprite).x > 1000)
        scale.x = scale.x * (-1);
    return (choose_texture2(all, tow, texture, scale));
}

void choose_target_list(list_enemy *list, sfVector2f *pos)
{
    int len = list_len_2(list) - 1;
    sfFloatRect pos_enemy;
    for (int  i = 0; i != len; i += 1) {
        pos_enemy = get_enemy(list, i).col;
        if (pos_enemy.left > pos->x) {
            pos->x = pos_enemy.left + ((pos_enemy.width) / 2);
            pos->y = pos_enemy.top + ((pos_enemy.height) / 2);
        }
    }
}

void choose_target_list_rev(list_enemy *list, sfVector2f *pos)
{
    int len = list_len_2(list) - 1;
    sfFloatRect pos_enemy;
    for (int  i = 0; i != len; i += 1) {
        pos_enemy = get_enemy(list, i).col;
        if (pos_enemy.left < pos->x) {
            pos->x = pos_enemy.left + ((pos_enemy.width) / 2);
            pos->y = pos_enemy.top + ((pos_enemy.height) / 2);
        }
    }
}

void choose_target(global_s *all, tow_g *tow)
{
    sfVector2f pos;
    pos.x = 0;
    list_enemy *list_mecha = all->sprite.game.list_enemy;
    list_enemy *list_mecha_rev = all->sprite.game.list_enemy2;
    list_enemy *list_jet = all->sprite.game.list_enemy3;
    list_enemy *list_jet_rev = all->sprite.game.list_enemy5;
    list_enemy *list_car = all->sprite.game.list_enemy4;
    list_enemy *list_car_rev = all->sprite.game.list_enemy6;
    if (sfSprite_getPosition(tow->sprite).x <= 1000) {
        choose_target_list(list_jet, &pos);
        choose_target_list(list_mecha, &pos);
        choose_target_list(list_car, &pos);
        tow->target = pos;
        if (pos.x <= 0)
            all->verif_l = 1;
        else
            all->verif_l = 0;
    } else {
        pos.x = 1920;
        choose_target_list_rev(list_mecha_rev, &pos);
        choose_target_list_rev(list_jet_rev, &pos);
        choose_target_list_rev(list_car_rev, &pos);
        tow->target = pos;
        if (pos.x >= 1920)
            all->verif_r = 1;
        else
            all->verif_r = 0;
    }
}

void print_weapons(global_s *all)
{
    int i = 0;
    int len = list_len(all->sprite.game.list_tow);
    enemy_s bullet;
    int numt = 0;
    sfFloatRect rect;
    for (int len_bul = 0; i != len; i += 1) {
        tow_g tow = get_element4(all->sprite.game.list_tow, i);
        rect = sfSprite_getGlobalBounds(tow.sprite);
        if (sfFloatRect_contains(&rect, all->pos_mouse.x, all->pos_mouse.y)) {
            sfssp(tow.sprite, tsvf(tow.pos.x - 2, tow.pos.y - 3));
            if (all->event->type == sfEvtMouseButtonPressed) {
                all->sprite.game.is_bar = True;
                all->sprite.game.wc_tower = i;
            }
        } else {
            sfssp(tow.sprite, tow.pos);
        }
        tow = choose_texture(all, tow);
        choose_target(all, &tow);
        if (tow.type > 0) {
            if (tow.target.y > 650) {
                sfSprite_setRotation(tow.sprite, 0);
                if (tow.pos.x == 820 && tow.pos.y == 537) {
                    sfSprite_setRotation(tow.sprite, -25);
                    if (tow.type == 1 || tow.type == 4)
                        sfssp(tow.sprite, tsvf(tow.pos.x - 100, tow.pos.y + 100));
                    if (tow.type == 2)
                        sfssp(tow.sprite, tsvf(tow.pos.x - 70, tow.pos.y + 100));
                    if (tow.type == 3)
                        sfssp(tow.sprite, tsvf(tow.pos.x - 115, tow.pos.y + 85));
                }
                if (tow.pos.x == 1175 && tow.pos.y == 537) {
                    sfSprite_setRotation(tow.sprite, 25);
                    if (tow.type == 1 || tow.type == 4)
                        sfssp(tow.sprite, tsvf(tow.pos.x, tow.pos.y + 110));
                    if (tow.type == 2)
                        sfssp(tow.sprite, tsvf(tow.pos.x - 15, tow.pos.y + 100));
                    if (tow.type == 3)
                        sfssp(tow.sprite, tsvf(tow.pos.x + 25, tow.pos.y + 85));
                }
            } else {
                sfSprite_setRotation(tow.sprite, 0);
                if (tow.pos.x == 685 && tow.pos.y == 795) {
                    sfSprite_setRotation(tow.sprite, 25);
                    if (tow.type == 1 || tow.type == 4)
                        sfssp(tow.sprite, tsvf(tow.pos.x - 90, tow.pos.y + 55));
                    if (tow.type == 2)
                        sfssp(tow.sprite, tsvf(tow.pos.x - 60, tow.pos.y + 70));
                    if (tow.type == 3)
                        sfssp(tow.sprite, tsvf(tow.pos.x - 90, tow.pos.y + 20));
                }
                if (tow.pos.x == 1305 && tow.pos.y == 795) {
                    sfSprite_setRotation(tow.sprite, -25);
                    if (tow.type == 1 || tow.type == 4)
                        sfssp(tow.sprite, tsvf(tow.pos.x, tow.pos.y + 50));
                    if (tow.type == 2)
                        sfssp(tow.sprite, tsvf(tow.pos.x - 10, tow.pos.y + 70));
                    if (tow.type == 3)
                        sfssp(tow.sprite, tsvf(tow.pos.x, tow.pos.y + 20));
                }
            }
        }
        all->sprite.game.list_tow = fta(all->sprite.game.list_tow, i);
        all->sprite.game.list_tow = addt(all->sprite.game.list_tow, tow, i);
            len_bul = list_len_2(tow.bullet);
            if (len_bul >= 1)
                for (int i = 0; i < len_bul; i++) {
                    bullet = get_enemy(tow.bullet, i);
                    detect_mecha(all, &bullet, &tow, &numt);
                    if (numt > 0) {
                        tow.bullet = free_element_at(tow.bullet, i);
                        len_bul -= 1;
                        numt = 0;
                    }
                    sfRenderWindow_drawSprite(all->wind, bullet.sprite, NULL);
                }
        sfRenderWindow_drawSprite(all->wind, tow.sprite, NULL);

    }
}
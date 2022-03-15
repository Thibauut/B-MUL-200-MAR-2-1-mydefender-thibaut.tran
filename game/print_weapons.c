/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** print_weapons.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

tow_g choose_texture4(global_s *all, tow_g tow, sfTexture *texture, v2f scale)
{
    if (tow.type == 5) {
        texture = sfTexture_createFromFile("res/sprites/wp5_spt.png", NULL);
        sfIntRect rect_1;
        rect_1.left = 0;
        rect_1.top = 0;
        rect_1.width = 230;
        rect_1.height = 132;
        sfSprite_setScale(tow.sprite, tsvf(0.6, 0.6));
        sfSprite_setPosition(tow.sprite, tsvf(tow.pos.x - 50, tow.pos.y));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        sfSprite_setTextureRect(tow.sprite, rect_1);
    }
    return (tow);
}

tow_g choose_texture3(global_s *all, tow_g tow, sfTexture *texture, v2f scale)
{
    if (tow.type == 3) {
        if (sfSprite_getPosition(tow.sprite).x > 1000)
            all->more = 190;
        texture = sfTexture_createFromFile("res/sprites/wp3_spt.png", NULL);
        sfIntRect rect_1;
        sfSprite_setScale(tow.sprite, scale);
        sfssp(tow.sprite, tsvf(tow.pos.x - 60 + all->more, tow.pos.y));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        anim_stazz(&tow, all);
    }
    if (tow.type == 4) {
        if (sfSprite_getPosition(tow.sprite).x > 1000)
            all->more = 0;
        else
            all->more = 100;
        texture = sfTexture_createFromFile("res/sprites/wp4_spt.png", NULL);
        sfSprite_setScale(tow.sprite, scale);
        sfssp(tow.sprite, tsvf(tow.pos.x - all->more, tow.pos.y + 77));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        anim_blaster(&tow, all);
    }
    return (choose_texture4(all, tow, texture, scale));
}

tow_g choose_texture2(global_s *all, tow_g tow, sfTexture *texture, v2f scale)
{
    if (tow.type == 1) {
        if (sfSprite_getPosition(tow.sprite).x > 1000)
            all->more = 0;
        else
            all->more = 100;
        texture = sfTexture_createFromFile("res/sprites/wp1_spt.png", NULL);
        sfSprite_setScale(tow.sprite, scale);
        sfssp(tow.sprite, tsvf(tow.pos.x - all->more, tow.pos.y + 77));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        anim_klassico(&tow, all);
    }
    if (tow.type == 2) {
        if (sfSprite_getPosition(tow.sprite).x > 1000)
            all->more = 0;
        else
            all->more = 100;
        texture = sfTexture_createFromFile("res/sprites/wp2_spt.png", NULL);
        sfSprite_setScale(tow.sprite, scale);
        sfssp(tow.sprite, tsvf(tow.pos.x - all->more, tow.pos.y + 77));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        anim_avocado(&tow, all);
    }
    return (choose_texture3(all, tow, texture, scale));
}

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
    int len = list_len_2(list);
    sfFloatRect pos_enemy;
    for (int  i = 0; i != len; i += 1) {
        pos_enemy = get_enemy(list, i).col;
        if (pos_enemy.left > pos->x) {
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
    list_enemy *list_car = all->sprite.game.list_enemy4;
    if (sfSprite_getPosition(tow->sprite).x <= 1000) {
        choose_target_list(list_jet, &pos);
        choose_target_list(list_mecha, &pos);
        choose_target_list(list_car, &pos);
        tow->target = pos;
        if (pos.x <= 0)
            all->verif_l = 1;
        else
            all->verif_l = 0;
        // printf("enemy: %f\n", tow->target.y);
    }
    // choose_target_list(list_car, &pos);
    // choose_target_list(list_mecha, &pos);
}

void print_weapons(global_s *all)
{
    int i = 0;
    int len = list_len(all->sprite.game.list_tow);
    sfFloatRect rect;
    for (; i != len; i += 1) {
        tow_g tow = get_element4(all->sprite.game.list_tow, i);
        rect = sfSprite_getGlobalBounds(tow.sprite);
        if (sfFloatRect_contains(&rect, all->pos_mouse.x, all->pos_mouse.y)) {
            sfSprite_setPosition(tow.sprite, tsvf(tow.pos.x - 2, tow.pos.y - 3));
            if (all->event->type == sfEvtMouseButtonPressed) {
                all->sprite.game.is_bar = True;
                all->sprite.game.wc_tower = i;
            }
        } else {
            sfSprite_setPosition(tow.sprite, tsvf(tow.pos.x, tow.pos.y));
        }
        tow = choose_texture(all, tow);
        choose_target(all, &tow);
        if (tow.type > 0) {
            printf("type: %d target: %f\n", tow.type, tow.target.y);
            if (tow.target.y > 650)
                sfSprite_setRotation(tow.sprite, 0);
            else
                sfSprite_setRotation(tow.sprite, 45);
        }
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, i);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, i);
            int len_bul = list_len_2(tow.bullet);
            if (len_bul >= 1)
                for (int i = 0; i < len_bul; i++)
                    sfRenderWindow_drawSprite(all->wind, get_enemy(tow.bullet, i).sprite, NULL);
        sfRenderWindow_drawSprite(all->wind, tow.sprite, NULL);
    }
}

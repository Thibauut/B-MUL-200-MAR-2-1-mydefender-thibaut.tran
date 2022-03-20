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

void choose_texture3_3(global_s *all, tow_g tow)
{
    if (sfSprite_getPosition(tow.sprite).x > 1000)
        all->more = 0;
    else
        all->more = 100;
}

tow_g choose_texture3(global_s *all, tow_g tow, sft *texture, v2f scale)
{
    if (tow.type == 3) {
        if (sfSprite_getPosition(tow.sprite).x > 1000)
            all->more = 10;
        else
            all->more = -95;
        texture = sfTexture_createFromFile("res/sprites/wp3_spt.png", NULL);
        sfIntRect rect_1;
        sfSprite_setScale(tow.sprite, scale);
        sfssp(tow.sprite, tsvf(tow.pos.x + all->more, tow.pos.y + 49));
        sfsst(tow.sprite, texture, sfFalse), anim_stazz(&tow, all);
    }
    if (tow.type == 4) {
        choose_texture3_3(all, tow);
        texture = sfTexture_createFromFile("res/sprites/wp4_spt.png", NULL);
        sfSprite_setScale(tow.sprite, scale);
        sfssp(tow.sprite, tsvf(tow.pos.x - all->more, tow.pos.y + 77));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        anim_blaster(&tow, all);
    }
    return (choose_texture4(all, tow, texture, scale));
}

void choose_texture2_2(global_s *all, tow_g tow)
{
    if (sfSprite_getPosition(tow.sprite).x > 1000)
        all->more = 0;
    else
        all->more = 60;
}

tow_g choose_texture2(global_s *all, tow_g tow, sft *texture, v2f scale)
{
    if (tow.type == 1) {
        if (sfSprite_getPosition(tow.sprite).x > 1000)
            all->more = -20;
        else
            all->more = 100;
        texture = sfTexture_createFromFile("res/sprites/wp1_spt.png", NULL);
        sfSprite_setScale(tow.sprite, scale);
        sfssp(tow.sprite, tsvf(tow.pos.x - all->more, tow.pos.y + 77));
        sfsst(tow.sprite, texture, sfFalse), anim_klassico(&tow, all);
    }
    if (tow.type == 2) {
        choose_texture2_2(all, tow);
        texture = sfTexture_createFromFile("res/sprites/wp2_spt.png", NULL);
        sfSprite_setScale(tow.sprite, scale);
        sfssp(tow.sprite, tsvf(tow.pos.x - all->more - 10, tow.pos.y + 85));
        sfsst(tow.sprite, texture, sfFalse), anim_avocado(&tow, all);
    }
    return (choose_texture3(all, tow, texture, scale));
}

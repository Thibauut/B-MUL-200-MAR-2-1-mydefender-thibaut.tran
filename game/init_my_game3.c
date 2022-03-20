/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** init_my_game3.c
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

sfText *pv(float x, float y, list_enemy *list)
{
    char *txt_string;
    sfText *text;
    if (list->enemy.life > 0) {
        txt_string = my_strdup("PV: ");
        txt_string = my_strcat(txt_string, my_itoa(list->enemy.life));
    } else
        txt_string =  my_strdup(" ");
    text = create_textStocky(txt_string, 30, sfWhite, tsvf(x, y));
    return (text);
}

int dmg(int type, int base)
{
    int dmg = 0;
    switch (type)
    {
        case 1:
            dmg = 15;
            break;
        case 2:
            dmg = 25;
            break;
        case 3:
            dmg = 70;
            break;
        case 4:
            dmg = 30;
            break;
    }
    if (base == ATTACK)
        dmg = dmg * 1.3;
    return (dmg);
}

void anim_fx(enemy_s *enemy)
{
    enemy->clock_fx.time = sfClock_getElapsedTime(enemy->clock_fx.clock);
    enemy->clock_fx.seconds = enemy->clock_fx.time.microseconds / 1000000.0;
    sfIntRect rect = create_rect(0, enemy->clock_fx.pos, 180, 398);
    sfSprite_setTextureRect(enemy->fx, rect);
    if (enemy->clock_fx.seconds > 0.01) {
        enemy->clock_fx.pos = enemy->clock_fx.pos + 180;
        if (enemy->clock_fx.pos >= 3060)
            enemy->clock_fx.pos = 0;
        sfClock_restart(enemy->clock_fx.clock);
    }
    sfVector2f pos = sfSprite_getPosition(enemy->sprite);
    pos.y += 112;
    pos.x += 60;
    sfSprite_setPosition(enemy->fx, pos);
}

void anim_fx_rev(enemy_s *enemy)
{
    enemy->clock_fx.time = sfClock_getElapsedTime(enemy->clock_fx.clock);
    enemy->clock_fx.seconds = enemy->clock_fx.time.microseconds / 1000000.0;
    sfIntRect rect = create_rect(0, enemy->clock_fx.pos, 180, 398);
    sfSprite_setTextureRect(enemy->fx, rect);
    if (enemy->clock_fx.seconds > 0.01) {
        enemy->clock_fx.pos = enemy->clock_fx.pos + 180;
        if (enemy->clock_fx.pos >= 3060)
            enemy->clock_fx.pos = 0;
        sfClock_restart(enemy->clock_fx.clock);
    }
    sfVector2f pos = sfSprite_getPosition(enemy->sprite);
    pos.y += 112;
    pos.x -= 60;
    sfSprite_setPosition(enemy->fx, pos);
}

void enemy2(global_s *all)
{
    list_enemy *list_rev = all->sprite.game.list_enemy2;
    sfVector2f pos_txt;
    enemy_s enemy;
    int len2 = list_len_2(list_rev) - 1;
    for (int i = 0; i != len2; list_rev = list_rev->next, i++) {
        if (ae1r(&list_rev->enemy.clock, 130, all, &l_r) == 1) {
            all->sprite.game.nb_mecha_rev -= 1;
            all->sprite.game.blood += 70;
            all->sprite.game.l_e2 = fet(all->sprite.game.list_enemy2, i);
            continue;
        }
        pos_txt = sfSprite_getPosition(list_rev->enemy.sprite);
        pos_txt.y = pos_txt.y - 30;
        pos_txt.x = pos_txt.x - 150;
        sfRenderWindow_drawSprite(all->wind, list_rev->enemy.sprite, NULL);
        sfrdt(all->wind, pv(pos_txt.x, pos_txt.y, list_rev), NULL);
    }
}

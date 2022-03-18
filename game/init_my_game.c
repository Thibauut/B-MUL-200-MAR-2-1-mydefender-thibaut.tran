/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** init_my_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"
#define l_rs list_rev->enemy.sprite
#define l_r list_rev->enemy
#define l_ec list->enemy.clock
#define l_es list->enemy.sprite

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

sfText *pv(float x, float y, list_enemy *list)
{
    char *txt_string;
    sfText *text;
    if (list->enemy.life > 0) {
        txt_string = my_strdup("PV: ");
        txt_string = my_strcat(txt_string, my_itoa(list->enemy.life));
    } else
        txt_string =  my_strdup(" ");
    text = create_textStocky(txt_string, 30, sfWhite, x, y);
    return (text);
}

int dmg(int type, int base)
{
    int dmg = 0;
    switch (type)
    {
        case 1:
            dmg = 10;
            break;
        case 2:
            dmg = 20;
            break;
        case 3:
            dmg = 20;
            break;
        case 4:
            dmg = 150;
            break;
    }
    if (base == ATTACK)
        dmg = dmg * 1.3;
    return (dmg);
}

void enemy2(global_s *all)
{
    list_enemy *list_rev = all->sprite.game.list_enemy2;
    sfVector2f pos_txt;
    enemy_s enemy;
    int len2 = list_len_2(list_rev) - 1;
    for (int i = 0; i != len2; list_rev = list_rev->next, i++) {
        if (anim_e1_rev(l_rs, &list_rev->enemy.clock, 130, all, &l_r) == 1) {
            all->sprite.game.nb_mecha_rev -= 1;
            all->sprite.game.blood += 30;
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

int enemy3_anim(global_s *all, list_enemy *list)
{
    int i = 0;
    i = anim_e3(l_es, &list->enemy.clock, 251, all, &list->enemy);
    anim_fx(&list->enemy);
    return (i);
}

void enemy3(global_s *all)
{
    list_enemy *list = all->sprite.game.list_enemy3;
    int len = list_len_2(list) - 1;
    sfVector2f pos_txt;
    enemy_s enemy;
    for (int i = 0; i != len; list = list->next, i++) {
        if (enemy3_anim(all, list) == 1) {
            all->sprite.game.blood += 30;
            all->sprite.game.nb_jet -= 1;
            all->sprite.game.list_enemy3 = fet(all->sprite.game.l_e3, i);
            continue;
        }
        pos_txt = sfSprite_getPosition(list->enemy.sprite);
        pos_txt.y = pos_txt.y - 50;
        pos_txt.x = pos_txt.x + 10;
        if (list->enemy.life > 0)
            sfRenderWindow_drawSprite(all->wind, list->enemy.fx, NULL);
        sfRenderWindow_drawSprite(all->wind, list->enemy.sprite, NULL);
        sfrdt(all->wind, pv(pos_txt.x, pos_txt.y, list), NULL);
    }
}

void enemy4(global_s *all)
{
    list_enemy *list = all->sprite.game.list_enemy4;
    int len = list_len_2(list) - 1;
    sfVector2f pos_txt;
    enemy_s enemy;
    for (int i = 0; i != len; list = list->next, i++) {
        if (anim_e4(list->enemy.sprite, &l_ec, 343, all, &list->enemy) == 1) {
            all->sprite.game.nb_car -= 1;
            all->sprite.game.blood += 30;
            all->sprite.game.list_enemy4 = fet(all->sprite.game.l_e4, i);
            continue;
        }
        pos_txt = sfSprite_getPosition(list->enemy.sprite);
        pos_txt.y = pos_txt.y - 50;
        pos_txt.x = pos_txt.x + 10;
        sfRenderWindow_drawSprite(all->wind, list->enemy.sprite, NULL);
        sfrdt(all->wind, pv(pos_txt.x, pos_txt.y, list), NULL);
    }
}

void enemy(global_s *all)
{
    list_enemy *list = all->sprite.game.list_enemy;
    int len = list_len_2(list) - 1;
    sfVector2f pos_txt;
    char *txt_string;
    sfFloatRect r_prev, r_now;
    int verif = 0;
    enemy_s enemy;
    for (int i = 0; i != len; list = list->next, i++) {
        if (anim_e1(list->enemy.sprite, &l_ec, 130, all, &list->enemy) == 1) {
            all->sprite.game.nb_mecha -= 1;
            all->sprite.game.list_enemy = fet(all->sprite.game.list_enemy, i);
            all->sprite.game.blood += 30;
            continue;
        }
        pos_txt = sfSprite_getPosition(list->enemy.sprite);
        pos_txt.y = pos_txt.y - 30;
        pos_txt.x = pos_txt.x + 70;
        sfRenderWindow_drawSprite(all->wind, list->enemy.sprite, NULL);
        sfrdt(all->wind, pv(pos_txt.x, pos_txt.y, list), NULL);
    }
}

int start_api(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_setMouseCursorVisible(all->wind, sfFalse);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.load, NULL);
    sfRenderWindow_display(all->wind);
    return (0);
}

void my_init_game(global_s *all)
{
    start_api(all);
    create_sprites_game(all);
    sfRenderWindow_setFramerateLimit(all->wind, 60);
    all->sprite.game.cl = create_clock();
}

void check_events_game(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        if (all->event->type == sfEvtClosed) {
            sfRenderWindow_close(all->wind);
            all->STATUS = FINISH;
        }
        if (all->event->type == sfEvtKeyPressed
        && all->event->key.code == sfKeyEscape) {
            if (all->sprite.game.is_bar == False) {
                if (pause_game(all) == 2)
                    all->STATUS = MAP;
            }
            else
                all->sprite.game.is_bar = False;
        }
        if (all->event->type == sfEvtMouseButtonPressed
        && all->sprite.game.is_bar == True)
            check_place_weap(all);
    }
}

void my_game(global_s *all)
{
    refresh_clocks(all);
    move_clouds(all);
    print_game(all);
    check_events_game(all);
}

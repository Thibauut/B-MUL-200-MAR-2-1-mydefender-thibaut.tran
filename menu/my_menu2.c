/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_menu2.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#define A ATTACK
#define D DEFENSIVE

sfVector2f transform_vf(float x, float y)
{
    sfVector2f vector = {x, y};
    return (vector);
}

void my_init_level2(global_s *all)
{
    char *bt_weap = "res/menu/bt_weap.png";
    char *load = "res/sprites/load.png";
    all->sprite.level.bt_weap = csS(bt_weap, 1000, 875, tsvf(1, 1));
    all->pop5 = pop_up(all, 1, 0.1, all->sprite.level.bt_weap);
    all->pop1 = pop_up(all, 1, 0.1, all->sprite.level.upgrade_bt);
    all->sprite.game.load = create_spriteStocky(load, 0, 0, tsvf(1, 1));
    all->sprite.level.txt_coins = ctS(i_a(all->info_p->coins), 47, w, 200, 115);
}

void my_init_level(global_s *all)
{
    char *light = "res/menu/BrightLight.png";
    char *right_ar = "res/menu/rh_arrow.png";
    char *left_ar = "res/menu/lf_arrow.png";
    all->sprite.level.bg_lvl = csS("res/menu/bg_levels.png", 0, 0, tsvf(1, 1));
    all->verif.verif_1 = 0;
    all->sprite.level.ic_1 = csS("res/menu/lvl_av.png", 230, 400, tsvf(1, 1));
    all->sprite.level.ic_2 = csS("res/menu/lvl_lk.png", 230, 720, tsvf(1, 1));
    all->sprite.level.ic_3 = csS("res/menu/lvl_lk.png", 565, 720, tsvf(1, 1));
    all->sprite.level.ic_4 = csS("res/menu/lvl_lk.png", 565, 300, tsvf(1, 1));
    all->sprite.level.ic_5 = csS("res/menu/lvl_lk.png", 900, 300, tsvf(1, 1));
    all->sprite.level.ic_6 = csS("res/menu/lvl_lk.png", 900, 600, tsvf(1, 1));
    all->sprite.level.ic_7 = csS("res/menu/lvl_lk.png", 1100, 600, tsvf(1, 1));
    all->sprite.level.ic_8 = csS("res/menu/lvl_lk.png", 1100, 300, tsvf(1, 1));
    all->sprite.level.ic_9 = csS("res/menu/lvl_lk.png", 1400, 300, tsvf(1, 1));
    all->sprite.level.light = csS(light, 0, 0, tsvf(0.35, 0.35));
    all->sprite.level.cb = csS("res/menu/coin_bar.png", 50, 100, tsvf(2, 2));
    all->sprite.level.upgrade = csS("res/menu/upgrade.png", 1398, 493, tsvf(1.5, 1.5));
    all->sprite.level.upgrade_bt = csS("res/menu/upgrade_bt.png", 1575, 825, tsvf(1, 1));
    all->sprite.level.right_ar = csS(right_ar, 1800, 500, tsvf(1, 1));
    all->sprite.level.left_ar = csS(left_ar, 30, 500, tsvf(1, 1));
    my_init_level2(all);
}

sfSprite *choose_icon_level(sfSprite *sprite, int player_lvl, int states)
{
    if (player_lvl > states) {
        sfTexture *t_win = sftcff("res/menu/lvl_win.png", NULL);
        sfSprite_setTexture(sprite, t_win, sfTrue);
    }
    if (player_lvl < states) {
        sfTexture *t_lock = sftcff("res/menu/lvl_lk.png", NULL);
        sfSprite_setTexture(sprite, t_lock, sfTrue);
    }
    if (player_lvl == states) {
        sfTexture *t_av = sftcff("res/menu/lvl_av.png", NULL);
        sfSprite_setTexture(sprite, t_av, sfTrue);
    }
    // sfTexture_destroy(t_lock);
    // sfTexture_destroy(t_av);
    // sfTexture_destroy(t_win);
    return (sprite);
}

void info_update(global_s *all)
{
    char *atk = "res/game/atk_lvl1.png";
    char *atk2 = "res/game/atk_lvl2.png";
    char *def = "res/game/def_lvl1.png";
    char *def2 = "res/game/def_lvl2.png";
    char *pv = "res/game/health_lvl1.png";
    char *pv2 = "res/game/health_lvl2.png";
    switch (all->info_p->base)
    {
        case A: all->sprite.game.update = csS(atk, 590, 560, tsvf(0.75, 0.75));
            if (all->info_p->pl_base == 4)
                all->sprite.game.update = csS(atk2, 590, 560, tsvf(0.75, 0.75));
            break;
        case D: all->sprite.game.update = csS(def, 590, 560, tsvf(0.75, 0.75));
            if (all->info_p->pl_base == 4)
                all->sprite.game.update = csS(def2, 590, 560, tsvf(0.75, 0.75));
            break;
        case PV: all->sprite.game.update = csS(pv, 590, 560, tsvf(0.75, 0.75));
            if (all->info_p->pl_base == 4)
                all->sprite.game.update = csS(pv2, 590, 560, tsvf(0.75, 0.75));
            break;
    }
}

void draw_price_base(global_s *all)
{
    int prix = 10;
    sfText *up_base;
    switch (all->info_p->pl_base) {
        case 2:
            prix = 1000;
            up_base = create_textStocky(my_itoa(prix), 45, sfWhite, 1550, 529);
            break;
        case 4:
            prix = 5000;
            up_base = create_textStocky(my_itoa(prix), 45, sfWhite, 1550, 529);
            break;
        case 7:
            up_base = create_textStocky("MAX", 45, sfWhite, 1548, 529);

    }
    sfRenderWindow_drawText(all->wind, up_base, NULL);
}

void my_draw_levels(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.bg_lvl, NULL);
    print_light(all);
    info_update(all);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_1, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_2, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_3, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_4, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_5, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_6, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_7, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_8, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_9, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.cb, NULL);
    draw_pop_up(all->sprite.level.bt_weap, all, &all->pop5);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.bt_weap, NULL);
    sfRenderWindow_drawText(all->wind, all->sprite.level.txt_coins, NULL);
    sfText_setString(all->sprite.level.txt_coins, my_itoa(all->info_p->coins));
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.upgrade, NULL);
    if (all->info_p->pl_base != 7)
        draw_pop_up(all->sprite.level.upgrade_bt, all, &all->pop1);
    sfSprite_setScale(all->sprite.game.update, tsvf(0.3, 0.3));
    sfSprite_setPosition(all->sprite.game.update, tsvf(1425, 600));
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.update, NULL);
    draw_price_base(all);
    sfRenderWindow_display(all->wind);
}

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
    all->verif_save_menu = 0;
    char *bt_weap = "res/menu/bt_weap.png";
    char *load = "res/sprites/load.png";
    char *save_bt = "res/game/save_bt.png";
    char *exit_bt = "res/game/exit_bt.png";
    char *save_icon = "res/game/save_icon.png";
    asl.bt_weap = csS(bt_weap, 1000, 875, tsvf(1, 1));
    all->pop5 = pop_up(all, 1, 0.1, asl.bt_weap);
    all->pop1 = pop_up(all, 1, 0.1, asl.upgrade_bt);
    all->sprite.game.load = create_spriteStocky(load, 0, 0, tsvf(1, 1));
    asl.txt_coins = ctsss;
    asgpmpm = csS("res/others/pause_menu.png", 0, 0, tsvf(1, 1));
    all->sprite.game.pause_menu.exit_menu = csS(exit_bt, 830, 800, tsvf(1.5, 1.5));
    all->sprite.game.pause_menu.save_menu = csS(save_bt, 830, 650, tsvf(1.5, 1.5));
    all->sprite.game.pause_menu.save_icon_menu = csS(save_icon, 1750, 50, tsvf(0.2, 0.2));
}

void my_init_level(global_s *all)
{
    char *light = "res/menu/bright_light.png";
    char *right_ar = "res/menu/rh_arrow.png";
    char *left_ar = "res/menu/lf_arrow.png";
    asl.bg_lvl = csS("res/menu/bg_levels.png", 0, 0, tsvf(1, 1));
    all->verif.verif_1 = 0;
    asl.ic_1 = csS("res/menu/lvl_av.png", 230, 400, tsvf(1, 1));
    asl.ic_2 = csS("res/menu/lvl_lk.png", 230, 720, tsvf(1, 1));
    asl.ic_3 = csS("res/menu/lvl_lk.png", 565, 720, tsvf(1, 1));
    asl.ic_4 = csS("res/menu/lvl_lk.png", 565, 300, tsvf(1, 1));
    asl.ic_5 = csS("res/menu/lvl_lk.png", 900, 300, tsvf(1, 1));
    asl.ic_6 = csS("res/menu/lvl_lk.png", 900, 600, tsvf(1, 1));
    asl.ic_7 = csS("res/menu/lvl_lk.png", 1100, 600, tsvf(1, 1));
    asl.ic_8 = csS("res/menu/lvl_lk.png", 1100, 300, tsvf(1, 1));
    asl.ic_9 = csS("res/menu/lvl_lk.png", 1400, 300, tsvf(1, 1));
    asl.light = csS(light, 0, 0, tsvf(0.35, 0.35));
    asl.cb = csS("res/menu/coin_bar.png", 50, 100, tsvf(2, 2));
    asl.upgrade = csS("res/menu/upgrade.png", 1398, 493, tsvf(1.5, 1.5));
    asl.upgrade_bt = csS("res/menu/upgrade_bt.png", 1575, 825, t11);
    asl.right_ar = csS(right_ar, 1800, 500, t11);
    asl.left_ar = csS(left_ar, 30, 500, t11);
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
        case A: all->sprite.game.update = csS(atk, 590, 560, t07);
            if (all->info_p->pl_base == 4)
                all->sprite.game.update = csS(atk2, 590, 560, t07);
            break;
        case D: all->sprite.game.update = csS(def, 590, 560, t07);
            if (all->info_p->pl_base == 4)
                all->sprite.game.update = csS(def2, 590, 560, t07);
            break;
        case PV: all->sprite.game.update = csS(pv, 590, 560, t07);
            if (all->info_p->pl_base == 4)
                all->sprite.game.update = csS(pv2, 590, 560, t07);
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
    sfRenderWindow_drawSprite(all->wind, asl.bg_lvl, NULL);
    print_light(all);
    info_update(all);
    sfRenderWindow_drawSprite(all->wind, asl.ic_1, NULL);
    sfRenderWindow_drawSprite(all->wind, asl.ic_2, NULL);
    sfRenderWindow_drawSprite(all->wind, asl.ic_3, NULL);
    sfRenderWindow_drawSprite(all->wind, asl.ic_4, NULL);
    sfRenderWindow_drawSprite(all->wind, asl.ic_5, NULL);
    sfRenderWindow_drawSprite(all->wind, asl.ic_6, NULL);
    sfRenderWindow_drawSprite(all->wind, asl.ic_7, NULL);
    sfRenderWindow_drawSprite(all->wind, asl.ic_8, NULL);
    sfRenderWindow_drawSprite(all->wind, asl.ic_9, NULL);
    sfRenderWindow_drawSprite(all->wind, asl.cb, NULL);
    draw_pop_up(asl.bt_weap, all, &all->pop5);
    sfRenderWindow_drawSprite(all->wind, asl.bt_weap, NULL);
    sfRenderWindow_drawText(all->wind, asl.txt_coins, NULL);
    sfText_setString(asl.txt_coins, my_itoa(all->info_p->coins));
    sfRenderWindow_drawSprite(all->wind, asl.upgrade, NULL);
    if (all->info_p->pl_base != 7)
        draw_pop_up(asl.upgrade_bt, all, &all->pop1);
    sfSprite_setScale(all->sprite.game.update, tsvf(0.3, 0.3));
    sfSprite_setPosition(all->sprite.game.update, tsvf(1425, 600));
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.update, NULL);
    draw_price_base(all);
    sfRenderWindow_display(all->wind);
}

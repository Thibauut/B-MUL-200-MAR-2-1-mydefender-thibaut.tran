/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** my_menu2.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#define A ATTACK
#define D DEFENSIVE
#define my_light "res/menu/bright_light.png"

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
    asg.load = create_spriteStocky(load, 0, 0, tsvf(1, 1));
    asl.txt_coins = ctsss;
    asgpmpm = csS("res/others/pause_menu.png", 0, 0, tsvf(1, 1));
    asg.pause_menu.exit_menu = csS(exit_bt, 830, 800, tsvf(1.5, 1.5));
    asg.pause_menu.save_menu = csS(save_bt, 830, 650, tsvf(1.5, 1.5));
    asg.pause_menu.save_icon_menu = csS(save_icon, 1750, 50, tsvf(0.2, 0.2));
}

void my_init_level(global_s *all)
{
    char *light = my_light, *right_ar = "res/menu/rh_arrow.png";
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
    char *pv = "res/game/health_lvl1.png", *pv2 = "res/game/health_lvl2.png";
    switch (all->info_p->base)
    {
        case A: asg.update = csS(atk, 590, 560, t07);
            if (all->info_p->pl_base == 4)
                asg.update = csS(atk2, 590, 560, t07);
            break;
        case D: asg.update = csS(def, 590, 560, t07);
            if (all->info_p->pl_base == 4)
                asg.update = csS(def2, 590, 560, t07);
            break;
        case PV: asg.update = csS(pv, 590, 560, t07);
            if (all->info_p->pl_base == 4)
                asg.update = csS(pv2, 590, 560, t07);
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
            up_base = ctS(my_itoa(prix), 45, sfWhite, tsvf(1550, 529));
            break;
        case 4:
            prix = 5000;
            up_base = ctS(my_itoa(prix), 45, sfWhite, tsvf(1550, 529));
            break;
        case 7:
            up_base = ctS("MAX", 45, sfWhite, tsvf(1548, 529));

    }
    sfRenderWindow_drawText(all->wind, up_base, NULL);
}

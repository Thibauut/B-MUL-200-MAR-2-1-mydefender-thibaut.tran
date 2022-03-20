/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** create_spt_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"
#define A ATTACK
#define D DEFENSIVE
#define icon all->sprite.game.pause_menu.save_icon
#define resume all->sprite.game.pause_menu.resume

void init_var(global_s *all)
{
    all->verif_l = 1;
    all->verif_r = 1;
    all->sprite.game.blood = 200 * all->level_played;
    all->verif_r_bullet = 0;
    all->verif_anim = 0;
}
void create_sprites_game3(global_s *all)
{
    char *wp_lock = "res/weapons/wp_lock.png";
    char *elixir = "res/weapons/elixir.png";
    char *pause = "res/game/pause.png";
    char *r_pause = "res/game/r_pause.png";
    char *resume_bt = "res/game/resume_bt.png";
    char *save_bt = "res/game/save_bt.png";
    char *exit_bt = "res/game/exit_bt.png";
    char *save_icon = "res/game/save_icon.png";
    all->sprite.weapons.unlock1 = csS(wp_lock, 1305, 95, tsvf(0.65, 0.65));
    init_var(all);
    all->sprite.game.blood_s = csS(elixir, 5, 10, tsvf(0.25, 0.25));
    all->sprite.game.blood_x = ctS(i_a(all->sprite.game.blood), 70, w, 100, 5);
    all->sprite.game.pause_menu.pause = csS(pause, 0, 0, tsvf(1, 1));
    all->sprite.game.pause_menu.r_pause = csS(r_pause, 0, 0, tsvf(1, 1));
    resume = csS(resume_bt, 830, 500, tsvf(1.5, 1.5));
    all->sprite.game.pause_menu.save = csS(save_bt, 830, 650, tsvf(1.5, 1.5));
    all->sprite.game.pause_menu.exit = csS(exit_bt, 830, 800, tsvf(1.5, 1.5));
    icon = csS(save_icon, 1750, 50, tsvf(0.2, 0.2));
    sfRenderWindow_setMouseCursorVisible(all->wind, sfTrue);
}

void create_sprites_game4(global_s *all)
{
    char *restart = "res/others/restart_bt.png";
    char *exit = "res/others/exit_bt.png";
    char *enemy = "res/game/logo_enemy.png";
    all->loose.bg2 = csS("res/others/lose2.png", 0, 0, tsvf(1, 1));
    all->loose.bg = csS("res/others/lose.png", 0, 0, tsvf(1, 1));
    all->loose.exit_bt = csS(exit, 1070, 880, tsvf(1.5, 1.5));
    all->loose.restart_bt = csS(restart, 570, 880, tsvf(1.5, 1.5));
    all->loose.light = csS("res/others/light.png", 940, 400, tsvf(2.8, 2.8));
    all->win.bg2 = csS("res/others/win2.png", 0, 0, tsvf(1, 1));
    all->win.bg = csS("res/others/win.png", 0, 0, tsvf(1, 1));
    all->win.exit_bt = csS("res/others/exit_bt.png", 820, 860, tsvf(1.5, 1.5));
    all->win.restart_bt = csS(restart, 770, 880, tsvf(1.5, 1.5));
    all->win.light = csS("res/others/light.png", 940, 400, tsvf(2.8, 2.8));
    all->sprite.game.logo_enemy = csS(enemy, 1553, 0, tsvf(0.09, 0.09));
}

void create_sprites_game5(global_s *all)
{
    all->sprite.game.bg = csS("res/game/bg_sky.png", 0, 0, tsvf(1.1, 1));
    all->sprite.game.clouds = csS("res/game/clouds.png", 0, 0, tsvf(1, 1));
    all->sprite.game.brume = csS("res/game/brume.png", 0, 0, tsvf(1, 1));
    all->sprite.game.road = csS("res/menu/6.png", 0, 535, tsvf(1, 1));
    all->sprite.game.tree = csS("res/game/cloud2.png", 0, 60, tsvf(1, 1));
    all->sprite.game.bg1 = csS("res/game/parallax2/bg1.png", 0, 0, tsvf(1, 1));
    all->sprite.game.bg2 = csS("res/game/parallax2/bg2.png", 0, 45, tsvf(1, 1));
    all->sprite.game.bg3 = csS("res/game/parallax2/bg3.png", 0, 0, tsvf(1, 1));
    all->sprite.game.bg4 = csS("res/game/parallax2/bg4.png", 0, 0, tsvf(1, 1));
    all->sprite.game.bg5 = csS("res/game/parallax2/bg5.png", 0, 0, tsvf(1, 1));
    all->sprite.game.bg6 = csS("res/game/parallax2/bg6.png", 0, 0, tsvf(1, 1));
    all->sprite.game.bg1_1 = csS("res/game/parallax3/bg1.png", 0, 0, tsvf(1, 1));
    all->sprite.game.bg2_2 = csS("res/game/parallax3/bg2.png", 0, 35, tsvf(1, 1));
    all->sprite.game.bg3_2 = csS("res/game/parallax3/bg3.png", 0, 0, tsvf(1, 1));
    all->sprite.game.bg4_2 = csS("res/game/parallax3/bg4.png", 0, 0, tsvf(1, 1));
    all->sprite.game.bg5_2 = csS("res/game/parallax3/bg5.png", 0, 0, tsvf(1, 1));
}

void create_sprites_game2(global_s *all)
{
    char *t_bar = "res/weapons/tower_bar.png";
    char *btwp1 = "res/weapons/bt_wp1.png", *btwp2 = "res/weapons/bt_wp2.png";
    char *btwp3 = "res/weapons/bt_wp3.png", *btwp4 = "res/weapons/bt_wp4.png";
    char *bt_wp5 = "res/weapons/bt_wp5.png";
    create_sprites_game5(all);
    all->sprite.weapons.tower_bar = csS(t_bar, 467, 70, tsvf(1, 1));
    all->sprite.weapons.bt_wp1 = csS(btwp1, 487, 125, tsvf(0.6, 0.6));
    all->sprite.weapons.bt_wp2 = csS(btwp2, 697, 120, tsvf(0.85, 0.85));
    all->sprite.weapons.bt_wp3 = csS(btwp3, 886, 93, tsvf(0.6, 0.6));
    all->sprite.weapons.bt_wp4 = csS(btwp4, 1095, 117, tsvf(0.65, 0.65));
    all->sprite.weapons.bt_wp5 = csS(bt_wp5, 1305, 95, tsvf(0.65, 0.65));
    create_sprites_game4(all);
    int i = all->sprite.game.nb_mecha + all->sprite.game.nb_jet;
    int j = all->sprite.game.nb_car + all->sprite.game.nb_mecha;
    all->sprite.game.nb_enemy = i + j - 4;
    char *str = my_itoa(all->sprite.game.nb_enemy);
    all->sprite.game.nb_enemy_t = ctS(str, 60, sfWhite, 1750, 15);
    sfSprite_setOrigin(all->loose.light, tsvf(150, 150));
    sfSprite_setOrigin(all->win.light, tsvf(150, 150));
    create_sprites_game3(all);
}

void info_base(global_s *all)
{
    char *atk = "res/game/atk_lvl1.png";
    char *atk2 = "res/game/atk_lvl2.png";
    char *def = "res/game/def_lvl1.png";
    char *def2 = "res/game/def_lvl2.png";
    char *pv = "res/game/health_lvl1.png";
    char *pv2 = "res/game/health_lvl2.png";
    char *bbs = "res/sprites/bg_bar.png";
    char *bs = "res/sprites/green_bar.png";
    switch (all->info_p->base) {
        case A: all->sprite.game.base = csS(atk, 590, 560, tsvf(0.75, 0.75));
                all->sprite.game.life_b = 2000;
            if (all->info_p->pl_base == 4) {
                all->sprite.game.base = csS(atk2, 590, 560, tsvf(0.75, 0.75));
                all->sprite.game.life_b = 5000;
            }
            break;
        case D: all->sprite.game.base = csS(def, 590, 560, tsvf(0.75, 0.75));
                all->sprite.game.life_b = 2000;
            if (all->info_p->pl_base == 4) {
                all->sprite.game.base = csS(def2, 590, 560, tsvf(0.75, 0.75));
                all->sprite.game.life_b = 5000;
            }
            break;
        case PV: all->sprite.game.base = csS(pv, 590, 560, tsvf(0.75, 0.75));
                all->sprite.game.life_b = 2500;
            if (all->info_p->pl_base == 4) {
                all->sprite.game.base = csS(pv2, 590, 560, tsvf(0.75, 0.75));
                all->sprite.game.life_b = 6000;
            }
            break;
    }
    all->sprite.life_tmp = all->sprite.game.life_b;
    all->sprite.game.life_bbs = csS(bbs, 765, 300, tsvf(1.64, 2));
    all->sprite.game.life_bs = csS(bs, 775, 306, tsvf(2, 2));
    all->rect_life = create_rect(0, 0, 183, 12);
    all->life = 0;
    sfSprite_setTextureRect(all->sprite.game.life_bs, all->rect_life);
}

void init_list(global_s *all)
{
    all->sprite.game.list_tow = NULL;
    all->sprite.game.list_enemy = NULL;
    all->sprite.game.list_enemy2 = NULL;
    all->sprite.game.list_enemy3 = NULL;
    all->sprite.game.list_enemy4 = NULL;
    all->sprite.game.list_enemy5 = NULL;
    all->sprite.game.list_enemy6 = NULL;

}

void create_sprites_game(global_s *all)
{
    all->sprite.game.e1 = 0;
    info_base(all);
    all->sprite.game.cl_pow = create_one_clock();
    init_list(all);
    all->sprite.game.list_tow = fill_list_tow(all);
    all->sprite.game.list_enemy = fill_enemy(all);
    all->sprite.game.list_enemy2 = fill_enemy_2(all);
    all->sprite.game.list_enemy3 = fill_enemy_3(all);
    all->sprite.game.list_enemy4 = fill_enemy_4(all);
    all->sprite.game.list_enemy5 = fill_enemy_3_rev(all);
    all->sprite.game.list_enemy6 = fill_enemy_4_rev(all);
    all->rect_e = malloc(sizeof(rect_e));
    create_sprites_game2(all);
}

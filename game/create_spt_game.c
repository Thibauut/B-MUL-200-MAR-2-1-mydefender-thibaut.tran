/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** create_spt_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"
#define icon all->sprite.game.pause_menu.save_icon
#define resume all->sprite.game.pause_menu.resume
#define asgbx all->sprite.game.blood_x

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
    asgbx = ctS(i_a(all->sprite.game.blood), 70, w, tsvf(100, 5));
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

/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** print_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"
#define sfkp sfEvtKeyPressed
#define sfke sfKeyEscape

void draw_win(global_s *all)
{
    sfSprite_rotate(all->win.light, 0.2);
    sfRenderWindow_drawSprite(all->wind, all->win.bg2, NULL);
    sfRenderWindow_drawSprite(all->wind, all->win.light, NULL);
    sfRenderWindow_drawSprite(all->wind, all->win.bg, NULL);
    sfRenderWindow_drawSprite(all->wind, all->win.exit_bt, NULL);
    sfRenderWindow_display(all->wind);
}

int my_win(global_s *all)
{
    int verif = 0;
    all->event = malloc(sizeof(sfEvent)), all->verif_save = 0;
    while (verif != 1) {
        draw_win(all);
        while (sfRenderWindow_pollEvent(all->wind, all->event)) {
            all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
            if (all->event->type == sfEvtClosed) {
                sfRenderWindow_close(all->wind);
                all->STATUS = FINISH;
                verif = 1;
            }
            if (all->event->type == sfkp && all->event->key.code == sfke)
                return (0);
            if (exit_win_bt(all) == 1) {
                all->info_p->coins += 200, all->info_p->lvl += 1;
                all->STATUS = MAP, verif = 1;
            }
        }
    }
    return (0);
}

void win_checker(global_s *all, int nb)
{
    if (nb <= 0)
        my_win(all);
}

void print_power(global_s *all)
{
    all->sprite.game.cl_pow.time = sfcget(all->sprite.game.cl_pow.clock);
    all->sprite.game.cl_pow.sec = all->sprite.game.cl_pow.tms / 1000000.0;
    if (all->sprite.game.power == True) {
        sfSprite *atks = csS("res/others/atkspe.png", 0, 0, tsvf(2.5, 2.5));
        sfRenderWindow_drawSprite(all->wind, atks, NULL);
        if (all->sprite.game.cl_pow.seconds >= 0.1)
            all->sprite.game.power = False;
    }
}

void print_game(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    print_base_selected(all);
    if (all->sprite.game.is_bar == True)
        is_wep_draw(all);
    sfrwds(all->wind, all->sprite.game.life_bbs, NULL);
    sfrwds(all->wind, all->sprite.game.life_bs, NULL);
    print_weapons(all);
    enemy4(all), enemy4_rev(all), enemy(all), enemy2(all), enemy3(all);
    enemy3_rev(all);
    sfrwds(all->wind, all->sprite.game.logo_enemy, NULL);
    int i = all->sprite.game.nb_car + all->sprite.game.nb_mecha;
    int nb = i + all->sprite.game.nb_mecha_rev + all->sprite.game.nb_jet - 4;
    char *str = my_itoa(nb);
    sfText_setString(all->sprite.game.nb_enemy_t, str);
    win_checker(all, nb);
    sfRenderWindow_drawText(all->wind, all->sprite.game.nb_enemy_t, NULL);
    print_power(all);
    sfRenderWindow_display(all->wind);
}

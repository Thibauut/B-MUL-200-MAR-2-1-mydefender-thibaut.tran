/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** print_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

void is_draw_wep(sfSprite *spt, int num, global_s *all)
{
    char *str = my_itoa(all->info_p->tower);
    char c = str[num];
    if (c == '1')
        sfRenderWindow_drawSprite(all->wind, spt, NULL);
    else {
        sfVector2f vect = sfSprite_getPosition(spt);
        sfSprite_setPosition(all->sprite.weapons.unlock1, vect);
        sfrwds(all->wind, all->sprite.weapons.unlock1, NULL);
    }
}

void draw_bg(global_s *all)
{
    sfrwds(all->wind, all->sprite.game.clouds, NULL);
    sfrwds(all->wind, all->sprite.game.brume, NULL);
    sfrwds(all->wind, all->sprite.game.tree, NULL);
    sfrwds(all->wind, all->sprite.game.road, NULL);
    sfrwds(all->wind, all->sprite.game.base, NULL);
    sfrwds(all->wind, all->sprite.game.blood_s, NULL);
}

int exit_win_bt(global_s *all)
{
    sfFloatRect rect = sfggb(all->win.exit_bt);
    v2f size = {1.5, 1.5}, sizeup = {1.53, 1.53};
    if (sfFloatRect_contains(&rect, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setScale(all->win.exit_bt, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed)
            return (1);
    } else
        sfSprite_setScale(all->loose.exit_bt, size);
    return (0);
}

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
    all->event = malloc(sizeof(sfEvent));
    all->verif_save = 0;
    while (verif != 1) {
        draw_win(all);
        while (sfRenderWindow_pollEvent(all->wind, all->event)) {
            all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
            if (all->event->type == sfEvtClosed) {
                sfRenderWindow_close(all->wind);
                all->STATUS = FINISH;
                verif = 1;
            }
            if (all->event->type == sfEvtKeyPressed
            && all->event->key.code == sfKeyEscape)
                return (0);
            if (exit_win_bt(all) == 1) {
                all->info_p->coins += 200;
                all->info_p->lvl += 1;
                all->STATUS = MAP;
                verif = 1;
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

void print_game(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfrwds(all->wind, all->sprite.game.bg, NULL);
    draw_bg(all);
    sfText_setString(all->sprite.game.blood_x, i_a(all->sprite.game.blood));
    sfRenderWindow_drawText(all->wind, all->sprite.game.blood_x, NULL);
    if (all->sprite.game.is_bar == True) {
        sfrwds(all->wind, all->sprite.weapons.tower_bar, NULL);
        is_draw_wep(all->sprite.weapons.bt_wp1, 0, all);
        is_draw_wep(all->sprite.weapons.bt_wp2, 1, all);
        is_draw_wep(all->sprite.weapons.bt_wp3, 2, all);
        is_draw_wep(all->sprite.weapons.bt_wp4, 3, all);
        is_draw_wep(all->sprite.weapons.bt_wp5, 4, all);
    }
    sfrwds(all->wind, all->sprite.game.life_bbs, NULL);
    sfrwds(all->wind, all->sprite.game.life_bs, NULL);
    print_weapons(all);
    enemy4(all);
    enemy(all);
    enemy2(all);
    enemy3(all);
    sfrwds(all->wind, all->sprite.game.logo_enemy, NULL);
    int i = all->sprite.game.nb_car + all->sprite.game.nb_mecha;
    int nb = i + all->sprite.game.nb_mecha_rev + all->sprite.game.nb_jet - 4;
    char *str = my_itoa(nb);
    sfText_setString(all->sprite.game.nb_enemy_t, str);
    win_checker(all, nb);
    sfRenderWindow_drawText(all->wind, all->sprite.game.nb_enemy_t, NULL);
    sfRenderWindow_display(all->wind);
}

/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** loose_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"

int restart_bt(global_s *all)
{
    sfFloatRect rect = sfggb(all->loose.restart_bt);
    v2f size = {1.5, 1.5}, sizeup = {1.53, 1.53};
    if (sfFloatRect_contains(&rect, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setScale(all->loose.restart_bt, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed)
            return (1);
    } else
        sfSprite_setScale(all->loose.restart_bt, size);
    return (0);
}

int exit_bt(global_s *all)
{
    sfFloatRect rect = sfggb(all->loose.exit_bt);
    v2f size = {1.5, 1.5}, sizeup = {1.53, 1.53};
    if (sfFloatRect_contains(&rect, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setScale(all->loose.exit_bt, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed)
            return (1);
    } else
        sfSprite_setScale(all->loose.exit_bt, size);
    return (0);
}

void draw_loose_game(global_s *all)
{
    sfSprite_rotate(all->loose.light, 0.2);
    sfRenderWindow_drawSprite(all->wind, all->loose.bg2, NULL);
    sfRenderWindow_drawSprite(all->wind, all->loose.light, NULL);
    sfRenderWindow_drawSprite(all->wind, all->loose.bg, NULL);
    sfRenderWindow_drawSprite(all->wind, all->loose.restart_bt, NULL);
    sfRenderWindow_drawSprite(all->wind, all->loose.exit_bt, NULL);
    sfRenderWindow_display(all->wind);
}

void loose_game(global_s *all)
{
    int verif = 0;
    all->event = malloc(sizeof(sfEvent));
    while (verif != 1) {
        draw_loose_game(all);
        all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
        while (sfRenderWindow_pollEvent(all->wind, all->event)) {
            if (all->event->type == sfEvtClosed) {
                sfRenderWindow_close(all->wind);
                all->STATUS = FINISH;
                verif = 1;
            }
            if (restart_bt(all) == 1) {
                my_init_game(all);
                verif = 1;
            }
            if (exit_bt(all) == 1) {
                all->STATUS = MAP;
                if (all->STATUS == MAP) {
                    sfMusic_stop(all->musics.music3);
                    all->i = 0;
                }
                verif = 1;
            }
        }
    }
    return;
}

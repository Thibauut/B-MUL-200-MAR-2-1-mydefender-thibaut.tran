/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** pause_game2.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void pause_game_5(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    if (all->event->type == sfEvtClosed) {
        sfRenderWindow_close(all->wind);
        all->STATUS = FINISH;
    }
}

int pause_game(global_s *all)
{
    all->event = malloc(sizeof(sfEvent));
    init_pause_rect(all);
    all->verif_save = 0;
    while (sfRenderWindow_isOpen(all->wind)) {
        pause_draw(all);
        while (sfRenderWindow_pollEvent(all->wind, all->event)) {
            pause_game_5(all);
            if (all->event->type == sfEvtKeyPressed
            && all->event->key.code == sfKeyEscape)
                return (0);
            if (pause_resume(all) == 1)
                return (0);
            if (pause_exit(all) == 1)
                return (2);
            pause_save(all);
        }
    }
    return (0);
}

/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_menu1.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void bt_menu(global_s *all)
{
    if (all->event->type == sfEvtClosed) {
        sfRenderWindow_close(all->wind);
        all->STATUS = FINISH;
    }
    play_bt(all);
    more_bt(all);
}

void check_events(global_s *all)
{
    all->event = malloc(sizeof(sfEvent));
    init_rect(all);
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        bt_menu(all);
    }
}

void draw_sprite_menu(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    if (all->musics.active == sfTrue && all->i == 0) {
        sfMusic_stop(all->musics.music1);
        sfMusic_play(all->musics.music1);
        all->i = 1;
    }
    anim_parallax(all);
    anim_button(all);
    sfRenderWindow_display(all->wind);
}

void my_menu(global_s *all)
{
    draw_sprite_menu(all);
}

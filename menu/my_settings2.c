/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_settings2.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

int sound_bt(global_s *all)
{
    sfFloatRect rm = sfSprite_getGlobalBounds(all->sprite.menu.bt_left2);
    sfFloatRect rm2 = sfSprite_getGlobalBounds(all->sprite.menu.bt_right2);
    sfVector2i m = sfMouse_getPositionRenderWindow(all->wind);
    if(all->event->type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&rm, m.x, m.y))
            //actvier la structure des sons
            return (1);
        if (sfFloatRect_contains(&rm2, m.x, m.y))
            //desactvier la structure des sons
            return (0);
    }
    return (3);
}

int sound_checker(int m, int x)
{
    if (m == 0) {
        x = 1;
        return (x);
    }
    if (m == 1) {
        x = 0;
        return (x);
    }
    return (x);
}

int music_checker(int c, int v)
{
    if (c == 0) {
        v = 1;
        return (v);
    }
    if (c == 1) {
        v = 0;
        return (v);
    }
    return (v);
}

int music_bt(global_s *all)
{
    sfFloatRect rm = sfSprite_getGlobalBounds(all->sprite.menu.bt_left3);
    sfFloatRect rm2 = sfSprite_getGlobalBounds(all->sprite.menu.bt_right3);
    sfVector2i m = sfMouse_getPositionRenderWindow(all->wind);
    if(all->event->type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&rm, m.x, m.y))
            //actvier la structure des musiques
            return (1);
        if (sfFloatRect_contains(&rm2, m.x, m.y))
            //desactvier la structure des musiques
            return (0);
    }
    return (3);
}

void event_close_opt(global_s *all)
{
    if (all->event->type == sfEvtClosed) {
        sfRenderWindow_close(all->wind);
        all->STATUS = FINISH;
    }
}

void more_option(global_s *all)
{
    all->event = malloc(sizeof(sfEvent));
    sfRenderWindow_clear(all->wind, sfBlack);
    char **i = fill_act(), **k = fill_act2();
    int j = 1, y = 0, x = 0, m = 0, n = 0, c = 0, v = 0;
    while (sfRenderWindow_isOpen(all->wind)) {
        while (sfRenderWindow_pollEvent(all->wind, all->event)) {
            all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
            event_close_opt(all);
            if (more_bt_close(all) == 1)
                return;
            y = verif_button(all, i);
            j = fps_checker(y, j);
            m = sound_bt(all);
            x = sound_checker(m, x);
            c = music_bt(all);
            v = music_checker(c, v);
        }
        draw_more_option(all), draw_fps(all, i[j], k[x], k[v]);
        sfRenderWindow_display(all->wind);
    }
}
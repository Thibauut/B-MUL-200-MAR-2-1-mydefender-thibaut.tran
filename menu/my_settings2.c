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
    if (all->event->type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&rm, m.x, m.y)) {
            if (all->sounds.active == sfTrue) {
                sfSound_stop(all->sounds.sound1);
                sfSound_play(all->sounds.sound1);
            }
            all->sounds.active = sfTrue;
            return (1);
        }
        if (sfFloatRect_contains(&rm2, m.x, m.y)) {
            if (all->sounds.active == sfTrue) {
                sfSound_stop(all->sounds.sound1);
                sfSound_play(all->sounds.sound1);
            }
            all->sounds.active = sfFalse;
            return (0);
        }
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
    if (all->event->type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&rm, m.x, m.y)) {
            if (all->sounds.active == sfTrue) {
                sfSound_stop(all->sounds.sound1);
                sfSound_play(all->sounds.sound1);
            }
            all->musics.active = sfTrue;
            return (1);
        }
        if (sfFloatRect_contains(&rm2, m.x, m.y)) {
            if (all->sounds.active == sfTrue) {
                sfSound_stop(all->sounds.sound1);
                sfSound_play(all->sounds.sound1);
            }
            all->musics.active = sfFalse;
            return (0);
        }
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
    int y = 0, m = 0, n = 0, c = 0;
    while (sfRenderWindow_isOpen(all->wind)) {
        while (sfRenderWindow_pollEvent(all->wind, all->event)) {
            all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
            event_close_opt(all);
            if (more_bt_close(all) == 1)
                return;
            y = verif_button(all, i);
            all->j = fps_checker(y, all->j);
            m = sound_bt(all);
            all->x = sound_checker(m, all->x);
            c = music_bt(all);
            all->v = music_checker(c, all->v);
            if (all->musics.active == sfFalse && all->i == 1) {
                sfMusic_stop(all->musics.music1);
                all->i = 0;
            }
        }
        draw_more_option(all), draw_fps(all, i[all->j], k[all->x], k[all->v]);
        sfRenderWindow_display(all->wind);
    }
}

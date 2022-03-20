/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** my_menu5.c
*/

#include "../include/func.h"
#include "../include/struct.h"

sfVector2f transform_vf(float x, float y)
{
    sfVector2f vector = {x, y};
    return (vector);
}

int pause_menu(global_s *all)
{
    all->event = malloc(sizeof(sfEvent)), all->verif_save = 0;
    sfRenderWindow_clear(all->wind, sfBlack);
    while (sfRenderWindow_isOpen(all->wind)) {
        pause_menu_draw(all);
        while (sfRenderWindow_pollEvent(all->wind, all->event)) {
            all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
            if (all->event->type == sfEvtClosed) {
                sfRenderWindow_close(all->wind);
                all->STATUS = FINISH;
            }
            if (all->event->type == sfekp && all->event->key.code == ske)
                return (0);
            if (pause_exit_menu(all) == 1) {
                sfRenderWindow_close(all->wind);
                all->STATUS = FINISH;
            }
            pause_save_menu(all);
        }
    }
    return (0);
}

void check_events_map(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        check_button_weap(all);
        check_mouse_icone(all);
        check_upgrade_base(all);
        if (all->event->type == sfekp && all->event->key.code == sfKeyEscape)
            pause_menu(all);
        if (all->event->type == sfEvtClosed) {
            sfRenderWindow_close(all->wind);
            all->STATUS = FINISH;
        }
    }
}

void my_map(global_s *all)
{
    if (all->musics.active == sfTrue && all->i == 0) {
        sfMusic_stop(all->musics.music2);
        sfMusic_play(all->musics.music2);
        all->i = 1;
    }
    choose_icons_level(all);
    my_draw_levels(all);
    check_events_map(all);
}

void print_light(global_s *all)
{
    if (all->verif.verif_1 != 0) {
        sfSprite_setOrigin(all->sprite.level.light, tsvf(382, 382));
        sfSprite_rotate(all->sprite.level.light, 1);
        sfSprite_setPosition(all->sprite.level.light, all->verif.pos_1);
        sfRenderWindow_drawSprite(all->wind, all->sprite.level.light, NULL);
    }
}

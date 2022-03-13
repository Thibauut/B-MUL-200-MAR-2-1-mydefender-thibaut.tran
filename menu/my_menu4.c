/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** my_menu4.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void is_up_base(global_s *all)
{
    // if (all->info_p->coins >= 5000 && all->info_p->pl_base == 4) {
    //     all->info_p->pl_base = 7;
    //     all->info_p->coins -= 5000;
    // }
    if (all->info_p->coins >= 1000 && all->info_p->pl_base == 2) {
        all->info_p->pl_base = 4;
        all->info_p->coins -= 1000;
    }
}

void check_upgrade_base(global_s *all)
{
    sfFloatRect r = sfSprite_getGlobalBounds(all->sprite.level.upgrade_bt);
    sfSprite_setPosition(all->sprite.level.upgrade_bt, tsvf(1575, 825));
    sfSprite_setScale(all->sprite.level.upgrade_bt, tsvf(1, 1));
    if (sfFloatRect_contains(&r, p_ms.x, p_ms.y)) {
        sfSprite_setScale(all->sprite.level.upgrade_bt, tsvf(1.02, 1.02));
        sfSprite_setPosition(all->sprite.level.upgrade_bt, tsvf(1575, 823));
        if (sfMouse_isButtonPressed(sfMouseLeft))
            is_up_base(all);
    }
}

void check_events_map(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        check_button_weap(all);
        check_mouse_icone(all);
        check_upgrade_base(all);
        if (all->event->type == sfekp && all->event->key.code == sfKeySpace)
            save_info(all);
        if (all->event->type == sfEvtClosed) {
            sfRenderWindow_close(all->wind);
            all->STATUS = FINISH;
        }
    }
}

void my_map(global_s *all)
{
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
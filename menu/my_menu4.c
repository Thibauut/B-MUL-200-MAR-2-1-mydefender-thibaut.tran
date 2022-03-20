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
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (all->sounds.active == sfTrue) {
                sfSound_stop(all->sounds.sound1);
                sfSound_play(all->sounds.sound1);
            }
            is_up_base(all);
        }
    }
}

int pause_exit_menu(global_s *all)
{
    v2f size = {1.5, 1.5}, sizeup = {1.53, 1.53}, move = {828, 797};
    v2f pos = {830, 800};
    sfFloatRect exit = sfggb(all->sprite.game.pause_menu.exit_menu);
    if (sffrc(&exit, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.game.pause_menu.exit_menu, move);
        sfSprite_setScale(all->sprite.game.pause_menu.exit_menu, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed) {
            if (all->sounds.active == sfTrue) {
                sfSound_play(all->sounds.sound1);
                sfSound_stop(all->sounds.sound1);
            }
            return (1);
        }
    } else {
        sfSprite_setScale(all->sprite.game.pause_menu.exit_menu, size);
        sfSprite_setPosition(all->sprite.game.pause_menu.exit_menu, pos);
    }
    return (0);
}

int pause_save_menu(global_s *all)
{
    v2f size = {1.5, 1.5}, sizeup = {1.53, 1.53}, move = {828, 647};
    v2f pos = {830, 650};
    sfFloatRect save = sfggb(all->sprite.game.pause_menu.save_menu);
    if (sffrc(&save, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.game.pause_menu.save_menu, move);
        sfSprite_setScale(all->sprite.game.pause_menu.save_menu, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed) {
            if (all->sounds.active == sfTrue) {
                sfSound_stop(all->sounds.sound1);
                sfSound_play(all->sounds.sound1);
            }
            all->verif_save_menu = 1;
            save_info(all);
        }
    } else {
        sfSprite_setScale(all->sprite.game.pause_menu.save_menu, size);
        sfSprite_setPosition(all->sprite.game.pause_menu.save_menu, pos);
    }
    return (0);
}

void pause_menu_draw(global_s *all)
{
    sfRenderWindow_drawSprite(all->wind, asgpmpm, NULL);
    sfrwds(all->wind, all->sprite.game.pause_menu.exit_menu, NULL);
    sfrwds(all->wind, all->sprite.game.pause_menu.save_menu, NULL);
    if (all->verif_save_menu == 1) {
            sfrwds(all->wind, all->sprite.game.pause_menu.save_icon_menu, NULL);
            all->verif_save_menu = 0;
    }
    sfRenderWindow_display(all->wind);
}

int pause_menu(global_s *all)
{
    all->event = malloc(sizeof(sfEvent));
    sfRenderWindow_clear(all->wind, sfBlack);
    all->verif_save = 0;
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

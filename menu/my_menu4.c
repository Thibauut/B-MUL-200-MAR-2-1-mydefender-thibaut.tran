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

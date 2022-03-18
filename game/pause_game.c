/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** pause_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void pause_draw(global_s *all)
{
    sfrwds(all->wind, all->sprite.game.pause_menu.pause, NULL);
    sfrwds(all->wind, all->sprite.game.pause_menu.r_pause, NULL);
    sfrwds(all->wind, all->sprite.game.pause_menu.resume, NULL);
    sfrwds(all->wind, all->sprite.game.pause_menu.save, NULL);
    sfrwds(all->wind, all->sprite.game.pause_menu.exit, NULL);
    if (all->verif_save == 1) {
        sfrwds(all->wind, all->sprite.game.pause_menu.save_icon, NULL);
        all->verif_save = 0;
    }
    sfRenderWindow_display(all->wind);
}

void init_pause_rect(global_s *all)
{
    all->rect = malloc(sizeof(rect));
    all->rect->p_resume = sfggb(all->sprite.game.pause_menu.resume);
    all->rect->p_exit = sfggb(all->sprite.game.pause_menu.exit);
    all->rect->p_save = sfggb(all->sprite.game.pause_menu.save);
}

int pause_resume(global_s *all)
{
    v2f size = {1.5, 1.5}, sizeup = {1.53, 1.53}, move = {828, 497};
    v2f pos = {830, 500};
    if (sffrc(&all->rect->p_resume, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.game.pause_menu.resume, move);
        sfSprite_setScale(all->sprite.game.pause_menu.resume, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed)
            return (1);
    } else {
        sfSprite_setScale(all->sprite.game.pause_menu.resume, size);
        sfSprite_setPosition(all->sprite.game.pause_menu.resume, pos);
    }
    return (0);
}

int pause_exit(global_s *all)
{
    v2f size = {1.5, 1.5}, sizeup = {1.53, 1.53}, move = {828, 797};
    v2f pos = {830, 800};
    if (sffrc(&all->rect->p_exit, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.game.pause_menu.exit, move);
        sfSprite_setScale(all->sprite.game.pause_menu.exit, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed)
            return (1);
    } else {
        sfSprite_setScale(all->sprite.game.pause_menu.exit, size);
        sfSprite_setPosition(all->sprite.game.pause_menu.exit, pos);
    }
    return (0);
}

int pause_save(global_s *all)
{
    v2f size = {1.5, 1.5}, sizeup = {1.53, 1.53}, move = {828, 647};
    v2f pos = {830, 650};
    if (sffrc(&all->rect->p_save, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setPosition(all->sprite.game.pause_menu.save, move);
        sfSprite_setScale(all->sprite.game.pause_menu.save, sizeup);
        if (all->event->type == sfEvtMouseButtonPressed) {
            all->verif_save = 1;
            save_info(all);
        }
    } else {
        sfSprite_setScale(all->sprite.game.pause_menu.save, size);
        sfSprite_setPosition(all->sprite.game.pause_menu.save, pos);
    }
    return (0);
}

int pause_game(global_s *all)
{
    all->event = malloc(sizeof(sfEvent));
    init_pause_rect(all);
    all->verif_save = 0;
    while (sfRenderWindow_isOpen(all->wind)) {
        pause_draw(all);
        while (sfRenderWindow_pollEvent(all->wind, all->event)) {
            all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
            if (all->event->type == sfEvtClosed) {
                sfRenderWindow_close(all->wind);
                all->STATUS = FINISH;
            }
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

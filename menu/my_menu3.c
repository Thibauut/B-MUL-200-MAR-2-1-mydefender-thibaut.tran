/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** my_menu3.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void choose_icons_level(global_s *all)
{
    choose_icon_level(all->sprite.level.ic_1, all->info_p->lvl, 1);
    choose_icon_level(all->sprite.level.ic_2, all->info_p->lvl, 2);
    choose_icon_level(all->sprite.level.ic_3, all->info_p->lvl, 3);
    choose_icon_level(all->sprite.level.ic_4, all->info_p->lvl, 4);
    choose_icon_level(all->sprite.level.ic_5, all->info_p->lvl, 5);
    choose_icon_level(all->sprite.level.ic_6, all->info_p->lvl, 6);
    choose_icon_level(all->sprite.level.ic_7, all->info_p->lvl, 7);
    choose_icon_level(all->sprite.level.ic_8, all->info_p->lvl, 8);
    choose_icon_level(all->sprite.level.ic_9, all->info_p->lvl, 9);
}

void check_button_weap(global_s *all)
{
    sfFloatRect r_weap = sfSprite_getGlobalBounds(all->sprite.level.bt_weap);
    sfSprite_setPosition(all->sprite.level.bt_weap, tsvf(1000, 875));
    sfSprite_setScale(all->sprite.level.bt_weap, tsvf(1, 1));
    if (sfFloatRect_contains(&r_weap, p_ms.x, p_ms.y)) {
        sfSprite_setScale(all->sprite.level.bt_weap, tsvf(1.03, 1.03));
        sfSprite_setPosition(all->sprite.level.bt_weap, tsvf(1000, 872));
        if (all->event->type == sfEvtMouseButtonPressed) {
            all->STATUS = WEAPONS;
            init_weapons(all);
        }
    }
}

void choose_num_enemy(global_s *all)
{
    if (all->level_played <= 3) {
        all->sprite.game.nb_car = 1;
        all->sprite.game.nb_jet = 1;
    } else {
        all->sprite.game.nb_car = 5;
        all->sprite.game.nb_jet = 5;
    }
    all->sprite.game.nb_mecha = 10;
}

void game_level(global_s *all, int lvl)
{
    if (all->event->type == sfEvtMouseButtonPressed) {
        all->STATUS = GAME, all->level_played = lvl;
        choose_num_enemy(all);
        my_init_game(all);
    }
}

void choose_icone_anim(sfSprite *sprite, global_s *all, int lvl)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    sfSprite_setScale(sprite, tsvf(1, 1));
    if (sfFloatRect_contains(&rect, all->pos_mouse.x, all->pos_mouse.y)) {
        sfSprite_setScale(sprite, tsvf(1.06, 1.06));
        if (lvl <= all->info_p->lvl) {
            all->verif.verif_1 = 1;
            all->verif.pos_1 = sfSprite_getPosition(sprite);
            all->verif.pos_1.y = all->verif.pos_1.y + 40;
            all->verif.pos_1.x = all->verif.pos_1.x + 43;
            game_level(all, lvl);
        }
    }

}

void check_mouse_icone(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    all->verif.verif_1 = 0;
    choose_icone_anim(all->sprite.level.ic_1, all, 1);
    choose_icone_anim(all->sprite.level.ic_2, all, 2);
    choose_icone_anim(all->sprite.level.ic_3, all, 3);
    choose_icone_anim(all->sprite.level.ic_4, all, 4);
    choose_icone_anim(all->sprite.level.ic_5, all, 5);
    choose_icone_anim(all->sprite.level.ic_6, all, 6);
    choose_icone_anim(all->sprite.level.ic_7, all, 7);
    choose_icone_anim(all->sprite.level.ic_8, all, 8);
    choose_icone_anim(all->sprite.level.ic_9, all, 9);
}

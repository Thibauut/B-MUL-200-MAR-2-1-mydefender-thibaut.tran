/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_menu2.c
*/

#include "../include/func.h"
#include "../include/struct.h"

sfVector2f transform_vf(float x, float y)
{
    sfVector2f vector = {x, y};
    return (vector);
}

void my_init_level(global_s *all)
{
    all->sprite.level.bg_lvl = csS("res/menu/bg_levels.png", 0, 0, tsvf(1, 1));
    all->verif.verif_1 = 0;
    all->sprite.level.ic_1 = csS("res/menu/lvl_av.png", 230, 400, tsvf(1, 1));
    all->sprite.level.ic_2 = csS("res/menu/lvl_lk.png", 230, 720, tsvf(1, 1));
    all->sprite.level.ic_3 = csS("res/menu/lvl_lk.png", 565, 720, tsvf(1, 1));
    all->sprite.level.ic_4 = csS("res/menu/lvl_lk.png", 565, 300, tsvf(1, 1));
    all->sprite.level.ic_5 = csS("res/menu/lvl_lk.png", 900, 300, tsvf(1, 1));
    all->sprite.level.ic_6 = csS("res/menu/lvl_lk.png", 900, 600, tsvf(1, 1));
    all->sprite.level.ic_7 = csS("res/menu/lvl_lk.png", 1100, 600, tsvf(1, 1));
    all->sprite.level.ic_8 = csS("res/menu/lvl_lk.png", 1100, 300, tsvf(1, 1));
    all->sprite.level.ic_9 = csS("res/menu/lvl_lk.png", 1400, 300, tsvf(1, 1));
    all->sprite.level.light = csS("res/menu/BrightLight.png", 0, 0, tsvf(0.35, 0.35));
    all->sprite.level.cb = csS("res/menu/coin_bar.png", 50, 100, tsvf(2, 2));
    all->sprite.level.right_ar = csS("res/menu/rh_arrow.png", 1800, 500, tsvf(1, 1));
    all->sprite.level.left_ar = csS("res/menu/lf_arrow.png", 30, 500, tsvf(1, 1));
    all->sprite.level.bt_weap = csS("res/menu/bt_weap.png", 1000, 875, tsvf(1, 1));
    all->pop5 = pop_up(all, 1, 0.1, all->sprite.level.bt_weap);
    all->sprite.game.load = create_spriteStocky("res/sprites/load.png", 0, 0, tsvf(1, 1));
    all->sprite.level.txt_coins = create_textStocky(my_itoa(all->info_p->coins), 47, sfWhite, 200, 115);
}

sfSprite *choose_icon_level(sfSprite *sprite, int player_lvl, int states)
{
    sfTexture *t_lock = sfTexture_createFromFile("res/menu/lvl_lk.png", NULL);
    sfTexture *t_av = sfTexture_createFromFile("res/menu/lvl_av.png", NULL);
    sfTexture *t_win = sfTexture_createFromFile("res/menu/lvl_win.png", NULL);
    if (player_lvl > states)
        sfSprite_setTexture(sprite, t_win, sfTrue);
    if (player_lvl < states)
        sfSprite_setTexture(sprite, t_lock, sfTrue);
    if (player_lvl == states)
        sfSprite_setTexture(sprite, t_av, sfTrue);
    return (sprite);
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

void my_draw_levels(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.bg_lvl, NULL);
    print_light(all);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_1, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_2, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_3, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_4, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_5, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_6, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_7, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_8, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.ic_9, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.cb, NULL);
    draw_pop_up(all->sprite.level.bt_weap, all, &all->pop5);
    sfRenderWindow_drawSprite(all->wind, all->sprite.level.bt_weap, NULL);
    sfRenderWindow_drawText(all->wind, all->sprite.level.txt_coins, NULL);
    sfText_setString(all->sprite.level.txt_coins, my_itoa(all->info_p->coins));
    sfRenderWindow_display(all->wind);
}

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
            if (all->event->type == sfEvtMouseButtonPressed) {
                all->STATUS = GAME, all->level_played = lvl;
                my_init_game(all);
            }
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

void check_events_map(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        check_button_weap(all);
        check_mouse_icone(all);
        if (all->event->type == sfEvtKeyPressed && all->event->key.code == sfKeySpace)
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
    while (all->STATUS == WEAPONS)
        my_weapons(all);
}
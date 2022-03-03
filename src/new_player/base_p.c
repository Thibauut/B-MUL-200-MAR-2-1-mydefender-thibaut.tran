/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** base_p.c
*/

#include "../../include/func.h"
#include "../../include/struct.h"

void reset_texture_base(global_s *all)
{
    sfTexture *t_of = sfTexture_createFromFile("res/others/base_atk.png", NULL);
    sfTexture *t_def = sfTexture_createFromFile("res/others/base_def.png", NULL);
    sfTexture *t_pv = sfTexture_createFromFile("res/others/base_pv.png", NULL);
    sfSprite_setTexture(all->sprite.other.base_of, t_of, sfFalse);
    sfSprite_setTexture(all->sprite.other.base_def, t_def, sfFalse);
    sfSprite_setTexture(all->sprite.other.base_pv, t_pv, sfFalse);
}

void check_wich_base(global_s *all)
{
    sfFloatRect rec_of = sfSprite_getGlobalBounds(all->sprite.other.base_of);
    sfFloatRect rec_def = sfSprite_getGlobalBounds(all->sprite.other.base_def);
    sfFloatRect rec_pv = sfSprite_getGlobalBounds(all->sprite.other.base_pv);
    sfTexture *texture;
    if (sfFloatRect_contains(&rec_of, all->pos_mouse.x, all->pos_mouse.y)) {
        reset_texture_base(all);
        texture = sfTexture_createFromFile("res/others/base_atk2.png", NULL);
        sfSprite_setTexture(all->sprite.other.base_of, texture, sfFalse);
        all->info_p->base = ATTACK;
    }
    if (sfFloatRect_contains(&rec_def, all->pos_mouse.x, all->pos_mouse.y)) {
        reset_texture_base(all);
        texture = sfTexture_createFromFile("res/others/base_def2.png", NULL);
        sfSprite_setTexture(all->sprite.other.base_def, texture, sfFalse);
        all->info_p->base = DEFENSIVE;
    }
    if (sfFloatRect_contains(&rec_pv, all->pos_mouse.x, all->pos_mouse.y)) {
        reset_texture_base(all);
        texture = sfTexture_createFromFile("res/others/base_pv2.png", NULL);
        sfSprite_setTexture(all->sprite.other.base_pv, texture, sfFalse);
        all->info_p->base = PV;
    }

}

void check_choose_base(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        if (all->event->type == sfEvtClosed) {
            sfRenderWindow_close(all->wind);
            all->STATUS = FINISH;
            all->is_ask = FINISH;
        }
        if (all->event->type == sfEvtMouseButtonPressed)
            check_wich_base(all);
        if (all->event->type == sfEvtKeyPressed && all->event->key.code == sfKeyEnter) {
            if (all->info_p->base != 0) {
                all->is_ask = FINISH;
                all->STATUS = MAP;
            }
        }
    }
}

void create_choose_base(global_s *all)
{
    all->sprite.other.base_of = create_spriteStocky("res/others/base_atk.png", 176, 250, tsvf(0.75, 0.75));
    all->sprite.other.base_def = create_spriteStocky("res/others/base_def.png", 758, 250, tsvf(0.75, 0.75));
    all->sprite.other.base_pv = create_spriteStocky("res/others/base_pv.png", 1338, 250, tsvf(0.75, 0.75));
    all->sprite.other.select = create_spriteStocky("res/others/select.png", 0, 0, tsvf(1, 1));
}

void print_choose_base(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.more_bg, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.other.select, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.other.base_def, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.other.base_of, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.other.base_pv, NULL);
    sfRenderWindow_display(all->wind);
}

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
    sfTexture *t_of = sftcff("res/others/base_atk.png", NULL);
    sfTexture *t_def = sftcff("res/others/base_def.png", NULL);
    sfTexture *t_pv = sftcff("res/others/base_pv.png", NULL);
    sfSprite_setTexture(all->sprite.other.base_of, t_of, sfFalse);
    sfSprite_setTexture(all->sprite.other.base_def, t_def, sfFalse);
    sfSprite_setTexture(all->sprite.other.base_pv, t_pv, sfFalse);
}

void base_done(global_s *all)
{
    if (all->info_p->base != 0) {
        all->is_ask = FINISH;
        all->STATUS = MAP;
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
        if (all->event->type == sfekp && all->event->key.code == sfKeyEnter)
            base_done(all);
    }
}

void create_choose_base(global_s *all)
{
    char *base_atk = "res/others/base_atk.png";
    char *base_def = "res/others/base_def.png";
    char *base_pv = "res/others/base_pv.png";
    char *select = "res/others/select.png";
    all->sprite.other.base_of = csS(base_atk, 176, 250, tsvf(0.75, 0.75));
    all->sprite.other.base_def = csS(base_def, 758, 250, tsvf(0.75, 0.75));
    all->sprite.other.base_pv = csS(base_pv, 1338, 250, tsvf(0.75, 0.75));
    all->sprite.other.select = csS(select, 0, 0, tsvf(1, 1));
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

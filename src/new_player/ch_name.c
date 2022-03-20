/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** ch_name.c
*/

#include "../../include/func.h"
#include "../../include/struct.h"

int ask_name_event(global_s *all)
{
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        if (all->is_ask == ASKING || all->is_ask == TEXT) {
            text_box("WHAT IS YOUR USERNAME ?", all);
            is_ask(all);
        }
        if (all->event->key.code == sfKeyEnter && my_strlen(all->ask) > 4) {
            all->is_ask = WEAPONS;
            all->info_p->name = ctS(all->ask, 30, sfBlack, tsvf(200, 400));
            return (1);
        }
    }
    return (0);
}

void ask_name(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    while (all->is_ask != FINISH) {
        if (ask_name_event(all) == 1)
            return;
    }
}

void is_ask(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.more_bg, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.box_dia, NULL);
    sfText *text2 = create_textStocky(all->ask_1, 80, sfBlack, tsvf(600, 100));
    sfRenderWindow_drawText(all->wind, text2, NULL);
    sfText *text = create_textStocky(all->ask, 60, sfBlack, tsvf(705, 710));
    sfRenderWindow_drawText(all->wind, text, NULL);
    sfText_destroy(text2), sfText_destroy(text);
    sfRenderWindow_display(all->wind);
}

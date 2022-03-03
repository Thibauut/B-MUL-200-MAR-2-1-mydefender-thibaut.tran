/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ch_name.c
*/

#include "../../include/func.h"
#include "../../include/struct.h"

void ask_name(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    while (all->is_ask != FINISH) {
        while (sfRenderWindow_pollEvent(all->wind, all->event)) {
            if (all->is_ask == ASKING || all->is_ask == TEXT) {
                text_box("WHAT IS YOUR USERNAME ?", all);
                is_ask(all);
            }
            if (all->event->key.code == sfKeyEnter && my_strlen(all->ask) > 4) {
                all->is_ask = WEAPONS;
                all->info_p->name = create_textStocky(all->ask, 30, sfBlack, 200, 400);
                return;
            }
        }
    }
}

void is_ask(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.more_bg, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.box_dia, NULL);
    sfText *text2 = create_textStocky(all->ask_1, 80, sfBlack, 600, 100);
    sfRenderWindow_drawText(all->wind, text2, NULL);
    sfText *text = create_textStocky(all->ask, 60, sfBlack, 705, 710);
    sfRenderWindow_drawText(all->wind, text, NULL);
    sfText_destroy(text2), sfText_destroy(text);
    sfRenderWindow_display(all->wind);
}

/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** text_box.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void alpha_key(sfEvent *event, global_s *all)
{
    if (event->key.code == sfKeySpace) {
        all->ask[all->c_ask] = ' ';
        all->c_ask = all->c_ask + 1;
    } else if (event->key.code != sfKeyBackspace
    && event->key.code != sfKeyEnter) {
        all->ask[all->c_ask] = event->key.code + 65;
        all->c_ask = all->c_ask + 1;
        all->ask[all->c_ask + 1] = '\0';
    }
}

void alpha(sfEvent *event, global_s *all)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyBackspace && all->c_ask > 0) {
            all->ask[all->c_ask] = '\b';
            all->ask[all->c_ask] = ' ';
            all->c_ask = all->c_ask - 1;
            all->ask[all->c_ask] = '\b';
            all->ask[all->c_ask + 1] = '\0';
        }
        if (my_strlen(all->ask) < 20)
            alpha_key(&*event, all);
    }
}

void text_box(char *ask, global_s *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wind);
    sfVector2f pos = {mouse.x, mouse.y};
    sfFloatRect rect = sfSprite_getGlobalBounds(all->sprite.menu.box_dia);
    all->ask_1 = my_strdup(ask);
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)
    && all->event->type == sfEvtMouseButtonPressed)
        all->is_ask = TEXT;
    if (all->is_ask == TEXT) {
        alpha(all->event, all);
    }
}

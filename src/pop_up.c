/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** pop_up.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void restart_pop(pop_up_s* pop)
{
    pop->size = 0;
    pop->is_pop = True;
}

pop_up_s pop_up(global_s *all, float size_max, float i, sfSprite *sprite)
{
    pop_up_s pop;
    pop.clock = create_one_clock();
    pop.is_pop = True;
    pop.size_max = size_max;
    pop.i = i;
    pop.size = 0;
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    rect.width = rect.width / 2;
    rect.height = rect.height / 2;
    sfSprite_setOrigin(sprite, tsvf(rect.width, rect.height));
    return (pop);
}

void draw_pop_up(sfSprite *sprite, global_s *all, pop_up_s *pop)
{
    pop->clock.time = sfClock_getElapsedTime(pop->clock.clock);
    pop->clock.seconds = pop->clock.time.microseconds / 1000000.0;
    if ((pop->size >= pop->size_max + (pop->size_max / 10)) && pop->is_pop == True)
        pop->is_pop = Down;
     if (pop->size <= pop->size_max && pop->is_pop == Down) {
        sfSprite_setScale(sprite, tsvf(pop->size_max, pop->size_max));
        pop->is_pop = False;
     }
    if (pop->clock.seconds > 0.001) {
        if (pop->is_pop == True) {
            pop->size = pop->size + pop->i;
            sfSprite_setScale(sprite, tsvf(pop->size, pop->size));
        }
        if (pop->is_pop == Down) {
            pop->size = pop->size - pop->i;
            sfSprite_setScale(sprite, tsvf(pop->size, pop->size));
        }
        sfClock_restart(pop->clock.clock);
    }
    sfRenderWindow_drawSprite(all->wind, sprite, NULL);
}
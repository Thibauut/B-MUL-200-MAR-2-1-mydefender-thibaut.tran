/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** rect_collision2.c
*/

#include "../include/func.h"
#include "../include/struct.h"

sfFloatRect rect_e4_rev(global_s *all, sfSprite *spt)
{
    sfFloatRect rect;
    rect = sfSprite_getGlobalBounds(spt);
    rect.width -= 180;
    rect.height -= 123;
    rect.left += 120;
    rect.top += 65;
    return (rect);
}

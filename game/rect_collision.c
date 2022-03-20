/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** rect_collision.c
*/

#include "../include/func.h"
#include "../include/struct.h"

sfFloatRect rect_e1(global_s *all, sfSprite *spt)
{
    sfFloatRect rect;
    rect = sfSprite_getGlobalBounds(spt);
    rect.width -= 180;
    rect.height -= 120;
    rect.left += 88;
    rect.top += 70;
    return (rect);
}

sfFloatRect rect_e1_rev(global_s *all, sfSprite *spt)
{
    sfFloatRect rect;
    rect = sfSprite_getGlobalBounds(spt);
    rect.width -= 180;
    rect.height -= 120;
    rect.left += 88;
    rect.top += 70;
    return (rect);
}

sfFloatRect rect_e3_rev(global_s *all, sfSprite *spt)
{
    sfFloatRect rect;
    rect = sfSprite_getGlobalBounds(spt);
    rect.width -= 130;
    rect.height -= 173;
    rect.left += 30;
    rect.top += 75;
    return (rect);
}

sfFloatRect rect_e3(global_s *all, sfSprite *spt)
{
    sfFloatRect rect;
    rect = sfSprite_getGlobalBounds(spt);
    rect.width -= 130;
    rect.height -= 173;
    rect.left += 95;
    rect.top += 65;
    return (rect);
}

sfFloatRect rect_e4(global_s *all, sfSprite *spt)
{
    sfFloatRect rect;
    rect = sfSprite_getGlobalBounds(spt);
    rect.width -= 180;
    rect.height -= 123;
    rect.left += 50;
    rect.top += 65;
    return (rect);
}

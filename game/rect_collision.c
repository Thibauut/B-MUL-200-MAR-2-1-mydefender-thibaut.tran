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
    sfRectangleShape *test1 = sfRectangleShape_create();
    sfVector2f v = {rect.left, rect.top};
    sfVector2f v2 = {rect.width, rect.height};
    sfRectangleShape_setSize(test1, v2);
    sfRectangleShape_setOutlineThickness(test1, 3);
    sfRectangleShape_setFillColor(test1, sfTransparent);
    sfRectangleShape_setOutlineColor(test1, sfRed);
    sfRectangleShape_setPosition(test1, v);
    sfRenderWindow_drawRectangleShape(all->wind, test1, NULL);
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
    sfRectangleShape *test1 = sfRectangleShape_create();
    sfVector2f v = {rect.left, rect.top};
    sfVector2f v2 = {rect.width, rect.height};
    sfRectangleShape_setSize(test1, v2);
    sfRectangleShape_setOutlineThickness(test1, 3);
    sfRectangleShape_setFillColor(test1, sfTransparent);
    sfRectangleShape_setOutlineColor(test1, sfRed);
    sfRectangleShape_setPosition(test1, v);
    sfRenderWindow_drawRectangleShape(all->wind, test1, NULL);
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
    sfRectangleShape *test1 = sfRectangleShape_create();
    sfVector2f v = {rect.left, rect.top};
    sfVector2f v2 = {rect.width, rect.height};
    sfRectangleShape_setSize(test1, v2);
    sfRectangleShape_setOutlineThickness(test1, 3);
    sfRectangleShape_setFillColor(test1, sfTransparent);
    sfRectangleShape_setOutlineColor(test1, sfRed);
    sfRectangleShape_setPosition(test1, v);
    sfRenderWindow_drawRectangleShape(all->wind, test1, NULL);
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
    sfRectangleShape *test1 = sfRectangleShape_create();
    sfVector2f v = {rect.left, rect.top};
    sfVector2f v2 = {rect.width, rect.height};
    sfRectangleShape_setSize(test1, v2);
    sfRectangleShape_setOutlineThickness(test1, 3);
    sfRectangleShape_setFillColor(test1, sfTransparent);
    sfRectangleShape_setOutlineColor(test1, sfRed);
    sfRectangleShape_setPosition(test1, v);
    sfRenderWindow_drawRectangleShape(all->wind, test1, NULL);
    return (rect);
}

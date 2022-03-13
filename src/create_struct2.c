/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** create_struct2.c
*/

#include "../include/func.h"
#include "../include/struct.h"

sp_menu create_sprites(void)
{
    sp_menu menu = create_spt_menu();
    return (menu);
}

sfrw *create_window(void)
{
    sfVideoMode vm = {1920, 1080, 32};
    sfrw* wind = sfRenderWindow_create(vm, "MY DEFENDER", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(wind, 60);
    return (wind);
}

sfText* create_textStocky(char *str, int size, sfColor color, float x, float y)
{
    sfText* text;
    sfFont* font;
    sfVector2f pos = {x, y}, scale = {1, 1};
    font = sfFont_createFromFile("res/font/SquadaOne-Regular.ttf");
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setScale(text, scale);
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    return (text);
}

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}
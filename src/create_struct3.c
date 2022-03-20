/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** create_struct3.c
*/

#include "../include/func.h"
#include "../include/struct.h"

one_cl create_one_clock(void)
{
    one_cl cl;
    cl.clock = sfClock_create();
    cl.seconds = 0;
    cl.time.microseconds = 0;
    cl.pos = 0;
    return (cl);
}

all_cl create_clock(void)
{
    all_cl cl;
    cl.cl_1 = create_one_clock();
    cl.cl_2 = create_one_clock();
    cl.cl_3 = create_one_clock();
    cl.cl_4 = create_one_clock();
    cl.cl_5 = create_one_clock();
    cl.cl_6 = create_one_clock();
    cl.cl_7 = create_one_clock();
    cl.cl_8 = create_one_clock();
    cl.cl_9 = create_one_clock();
    cl.cl_10 = create_one_clock();
    cl.cl_11 = create_one_clock();
    cl.cl_12 = create_one_clock();
    cl.cl_more = create_one_clock();
    cl.cl_more2 = create_one_clock();
    cl.cl_e1 = create_one_clock();
    return (cl);
}

sfSprite *create_spriteStocky(const char *filename, int x, int y, v2f size)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sftcff(filename, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfVector2f scale = {size.x, size.y};
    sfSprite_setScale(sprite, scale);
    sfVector2f pos = {x, y};
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

sp_menu create_spt_menu2(sp_menu menu)
{
    sfVector2f size_1 = {1 , 1}, size_2 = {0.55 , 0.55};
    menu.bt_option = csS("res/menu/option_bt.png", 810, 732, size_1);
    menu.bt_tutorial = csS("res/menu/tutorial_bt.png", 810, 600, size_1);
    menu.more_bg3 = csS("res/menu/more_bg_border.png", 0, 0, size_1);
    menu.more_bg4 = csS("res/menu/more_bg_border2.png", 0, 0, size_1);
    menu.bt_close = csS("res/menu/close_bt.png", 1800, 50, size_1);
    menu.bt_left = csS("res/menu/left.png", 760, 355, size_2);
    menu.bt_right = csS("res/menu/right.png", 1100, 355, size_2);
    menu.bt_left2 = csS("res/menu/left.png", 760, 455, size_2);
    menu.bt_right2 = csS("res/menu/right.png", 1100, 455, size_2);
    menu.bt_left3 = csS("res/menu/left.png", 760, 555, size_2);
    menu.bt_right3 = csS("res/menu/right.png", 1100, 555, size_2);
    menu.bg_bt = csS("res/menu/darkbluebox.png", 200, 350, size_2);
    menu.r_option = csS("res/menu/option_bar.png", 0, 0, size_1);
    menu.tutorial = csS("res/others/tutorial.png", 0, 0, size_1);
    return (menu);
}

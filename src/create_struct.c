/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** create_struct.c
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

sp_menu create_spt_menu(void)
{
    sp_menu menu;
    sfVector2f size_1 = {1 , 1}, size_2 = {1.5, 1.5};
    menu.bg_1 = csS("res/menu/1.png", 0, 0, size_1);
    menu.bg_2 = csS("res/menu/2.png", 0, -100, size_1);
    menu.bg_3 = csS("res/menu/3.png", 0, 220, size_1);
    menu.bg_4 = csS("res/menu/4.png", 0, 280, size_1);
    menu.bg_5 = csS("res/menu/5.png", 0, 435, size_1);
    menu.bg_6 = csS("res/menu/6.png", 0, 535, size_1);
    menu.bg_7 = csS("res/menu/7.png", 0, 350, size_1);
    menu.bg_8 = csS("res/menu/8.png", 0, 290, size_1);
    menu.menu = csS("res/menu/menu_img.png", 0, 0, size_1);
    menu.bt_1 = csS("res/menu/more_bt.png", 810, 732, size_1);
    menu.bt_2 = csS("res/menu/play_bt.png", 810, 600, size_1);
    menu.box_dia = csS("res/menu/ribbon.png", 575, 700, size_2);
    menu.more_bg = csS("res/menu/more_bg.png", 0, 0, size_1);
    menu.more_bg2 = csS("res/menu/more_bg2.png", 0, 100, size_1);
    return (create_spt_menu2(menu));
}

sfSound *create_sound(char *path, float i)
{
    sfSoundBuffer *music = sfSoundBuffer_createFromFile(path);
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, music);
    sfSound_setVolume(sound, i);
    return (sound);
}

void init_sound(global_s *all)
{
    all->sounds.sound1 = create_sound("res/music/bt_sound.ogg", 100);
}

void create_music(global_s *all)
{
    all->musics.music1 = init_music("res/music/music1.ogg", 100, sfTrue);
    all->musics.music2 = init_music("res/music/music2.ogg", 100, sfTrue);
    all->musics.music3 = init_music("res/music/music3.ogg", 100, sfTrue);
}

void create_all(global_s *all, char **av)
{
    all->STATUS = MENU;
    init_sound(all);
    create_music(all);
    all->sounds.active = sfTrue;
    all->musics.active = sfTrue;
    all->j = 1, all->x = 0, all->v = 0, all->i = 0;
    my_init_menu(all);
    all->ask = malloc(sizeof(char) * 21);
    all->c_ask = 0;
    all->info_p = take_info(av, all);
    all->sprite.cursor = csS("res/others/cursor.png", 0, 0, tsvf(1, 1));
    find_name(all);
    all->sprite.menu = create_sprites();
    all->cl = create_clock();
}

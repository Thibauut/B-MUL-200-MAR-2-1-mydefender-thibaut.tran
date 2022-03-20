/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** create_struct.c
*/

#include "../include/func.h"
#include "../include/struct.h"

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

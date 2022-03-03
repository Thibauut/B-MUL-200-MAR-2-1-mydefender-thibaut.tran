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
    cl.cl_more = create_one_clock();
    cl.cl_more2 = create_one_clock();
    cl.cl_e1 = create_one_clock();
    return (cl);
}

sfSprite* create_spriteStocky(const char* filename, int x, int y, sfVector2f size)
{
    sfSprite* sprite = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile(filename, NULL);
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
    menu.bt_option = create_spriteStocky("res/menu/option_bt.png", 810, 732, size_1);
    menu.bt_tutorial = create_spriteStocky("res/menu/tutorial_bt.png", 810, 600, size_1);
    menu.more_bg3 = create_spriteStocky("res/menu/more_bg_border.png", 0, 0, size_1);
    menu.more_bg4 = create_spriteStocky("res/menu/more_bg_border2.png", 0, 0, size_1);
    menu.bt_close = create_spriteStocky("res/menu/close_bt.png", 1800, 50, size_1);
    menu.bt_left = create_spriteStocky("res/menu/left.png", 760, 355, size_2);
    menu.bt_right = create_spriteStocky("res/menu/right.png", 1100, 355, size_2);
    menu.bt_left2 = create_spriteStocky("res/menu/left.png", 760, 455, size_2);
    menu.bt_right2 = create_spriteStocky("res/menu/right.png", 1100, 455, size_2);
    menu.bt_left3 = create_spriteStocky("res/menu/left.png", 760, 555, size_2);
    menu.bt_right3 = create_spriteStocky("res/menu/right.png", 1100, 555, size_2);
    menu.bg_bt = create_spriteStocky("res/menu/darkbluebox.png", 200, 350, size_2);
    menu.r_option = create_spriteStocky("res/menu/option_bar.png", 0, 0, size_1);
    return (menu);
}

sp_menu create_spt_menu(void)
{
    sp_menu menu;
    sfVector2f size_1 = {1 , 1}, size_2 = {1.5, 1.5};
    menu.bg_1 = create_spriteStocky("res/menu/1.png", 0, 0, size_1);
    menu.bg_2 = create_spriteStocky("res/menu/2.png", 0, -100, size_1);
    menu.bg_3 = create_spriteStocky("res/menu/3.png", 0, 220, size_1);
    menu.bg_4 = create_spriteStocky("res/menu/4.png", 0, 280, size_1);
    menu.bg_5 = create_spriteStocky("res/menu/5.png", 0, 435, size_1);
    menu.bg_6 = create_spriteStocky("res/menu/6.png", 0, 535, size_1);
    menu.bg_7 = create_spriteStocky("res/menu/7.png", 0, 350, size_1);
    menu.bg_8 = create_spriteStocky("res/menu/8.png", 0, 290, size_1);
    menu.menu = create_spriteStocky("res/menu/menu_img.png", 0, 0, size_1);
    menu.bt_1 = create_spriteStocky("res/menu/more_bt.png", 810, 732, size_1);
    menu.bt_2 = create_spriteStocky("res/menu/play_bt.png", 810, 600, size_1);
    menu.box_dia = create_spriteStocky("res/menu/ribbon.png", 575, 700, size_2);
    menu.more_bg = create_spriteStocky("res/menu/more_bg.png", 0, 0, size_1);
    menu.more_bg2 = create_spriteStocky("res/menu/more_bg2.png", 0, 100, size_1);
    return (create_spt_menu2(menu));
}


sp_menu create_sprites(void)
{
    sp_menu menu = create_spt_menu();
    return (menu);
}

sfRenderWindow *create_window(void)
{
    sfVideoMode vm = {1920, 1080, 32};
    sfRenderWindow* wind = sfRenderWindow_create(vm, "MY DEFENDER", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(wind, 60);
    // sfRenderWindow_setIcon(wind, 50, 50, "sheets/icone.jpg");
    return (wind);
}

void find_name(global_s *all)
{
    int i = 0;
    for (; all->info_p->tab[1][i] != '='; i++);
    if (all->info_p->tab[1][i + 1] == '\0')
        all->is_ask = ASKING;
    else {
        int j = 0;
        i++;
        char *res = malloc(sizeof(char) * my_strlen(all->info_p->tab[1]));
        for (; all->info_p->tab[1][i] != '\0'; i++, j++)
            res[j] = all->info_p->tab[1][i];
        all->info_p->name = create_textStocky(res, 30, sfBlack, 200, 400);
        all->is_ask = FINISH;
    }
}

player *take_info(char **av, global_s *all)
{
    player *info;
    info = malloc(sizeof(player));
    if (av[1]) {
        char *str = malloc(sizeof(char) * 18);
        str = my_strcat(str, "save/save_player");
        str = my_strcat(str, av[1]);
        info->save = my_strdup(str);
        info->tab = word_to_tab(str, '\n', 0);
    } else {
        info->save = my_strdup("save/save_guest");
        info->tab = word_to_tab("save/save_guest", '\n', 0);
    }
    info->lvl = my_getnbr(info->tab[2]);
    info->coins = my_getnbr(info->tab[3]);
    info->base = my_getnbr(info->tab[4]);
    info->tower = my_getnbr(info->tab[5]);
    info->pl_base = my_getnbr(info->tab[6]);
    return (info);
}

sfText* create_textStocky(char const *str, int size, sfColor color, float x, float y)
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

void create_all(global_s *all, char **av)
{
    all->STATUS = MENU;
    my_init_menu(all);
    all->ask = malloc(sizeof(char) * 21);
    all->c_ask = 0;
    all->info_p = take_info(av, all);
    find_name(all);
    all->sprite.menu = create_sprites();
    all->cl = create_clock();
}
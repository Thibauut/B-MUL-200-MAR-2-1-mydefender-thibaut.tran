/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_main.c
*/

#include "include/func.h"
#include "include/struct.h"
#include "include/my.h"

void my_init_menu(global_s *all)
{
    all->wind = create_window();
}

void my_defender(global_s *all)
{
    while (all->STATUS == MENU) {
        refresh_clock(all);
        my_menu(all);
        check_events(all);
    }
    while (all->STATUS == MAP) {
        my_map(all);
    }
    while (all->STATUS == GAME) {
        my_game(all);
    }
    while (all->STATUS == WEAPONS) {
        my_weapons(all);
    }
}

int my_h(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (av[1][0] != '-')
        return (84);
    if (av[1][1] != 'h')
        return (84);
    my_putstr("USAGE\n");
    return (0);
}

void destroy_menu(global_s *all)
{
    sfSprite_destroy(all->sprite.menu.bg_1);
    sfSprite_destroy(all->sprite.menu.bg_2);
    sfSprite_destroy(all->sprite.menu.bg_3);
    sfSprite_destroy(all->sprite.menu.bg_4);
    sfSprite_destroy(all->sprite.menu.bg_5);
    sfSprite_destroy(all->sprite.menu.bg_6);
    sfSprite_destroy(all->sprite.menu.bg_7);
    sfSprite_destroy(all->sprite.menu.bg_8);
    // sfSprite_destroy(all->sprite.menu.bg_bt);
    // sfSprite_destroy(all->sprite.menu.bg_dia);
    // sfSprite_destroy(all->sprite.menu.box_dia);
    sfSprite_destroy(all->sprite.menu.bt_1);
    sfSprite_destroy(all->sprite.menu.bt_2);
}

void destroy_menu2(global_s *all)
{
    sfSprite_destroy(all->sprite.menu.bt_left2);
    sfSprite_destroy(all->sprite.menu.bt_left3);
    sfSprite_destroy(all->sprite.menu.bt_left);
    sfSprite_destroy(all->sprite.menu.bt_option);
    sfSprite_destroy(all->sprite.menu.bt_right2);
    sfSprite_destroy(all->sprite.menu.bt_right3);
    sfSprite_destroy(all->sprite.menu.bt_right);
    sfSprite_destroy(all->sprite.menu.bt_tutorial);
    sfSprite_destroy(all->sprite.menu.menu);
    sfSprite_destroy(all->sprite.menu.more_bg2);
    sfSprite_destroy(all->sprite.menu.more_bg3);
    sfSprite_destroy(all->sprite.menu.more_bg4);
    sfSprite_destroy(all->sprite.menu.more_bg);
    sfSprite_destroy(all->sprite.menu.r_option);
    sfSprite_destroy(all->sprite.menu.tutorial);
}

int main (int ac, char **av)
{
    if (!my_h(ac, av))
        return (0);
    global_s *all = malloc(sizeof(global_s));
    create_all(all, av);
    // save_info(all);
    sfRenderWindow_setFramerateLimit(all->wind, 60);
    while (sfRenderWindow_isOpen(all->wind)) {
        my_defender(all);
    }
    free(all);
    return (0);
}
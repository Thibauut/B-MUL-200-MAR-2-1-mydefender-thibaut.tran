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

int main (int ac, char **av)
{
    if (!my_h(ac, av))
        return (0);
    global_s *all = malloc(sizeof(global_s));
    create_all(all, av);
    // save_info(all);
    while (sfRenderWindow_isOpen(all->wind)) {
        my_defender(all);
    }
    return (0);
}
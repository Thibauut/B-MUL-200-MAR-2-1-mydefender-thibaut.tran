/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** free_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void free_game(global_s *all)
{
    free(all->sprite.game.list_enemy);
    free(all->sprite.game.list_enemy2);
    free(all->sprite.game.list_enemy3);
    free(all->sprite.game.list_tow);
    free(all->rect_e);
}

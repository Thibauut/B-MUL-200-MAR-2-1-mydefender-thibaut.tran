/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** bg_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void move_clouds(global_s *all)
{
    move_bg(all->sprite.game.clouds, all->wind, &all->sprite.game.cl.cl_1, 1);
    move_bg(all->sprite.game.brume, all->wind, &all->sprite.game.cl.cl_2, 1.8);
    move_bg(all->sprite.game.tree, all->wind, &all->sprite.game.cl.cl_3, 2.5);
}

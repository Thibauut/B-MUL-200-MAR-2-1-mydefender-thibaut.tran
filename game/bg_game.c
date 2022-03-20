/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** bg_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#define m_bg move_bg

void move_clouds(global_s *all)
{
    move_bg(all->sprite.game.clouds, all->wind, &all->sprite.game.cl.cl_1, 1);
    m_bg(all->sprite.game.brume, all->wind, &all->sprite.game.cl.cl_2, 1.8);
    move_bg(all->sprite.game.tree, all->wind, &all->sprite.game.cl.cl_3, 2.5);
    move_bg(all->sprite.game.bg1, all->wind, &all->sprite.game.cl.cl_4, 1);
    move_bg(all->sprite.game.bg3, all->wind, &all->sprite.game.cl.cl_5, 5);
    move_bg(all->sprite.game.bg4, all->wind, &all->sprite.game.cl.cl_6, 4);
    move_bg(all->sprite.game.bg5, all->wind, &all->sprite.game.cl.cl_7, 3);
    move_bg(all->sprite.game.bg6, all->wind, &all->sprite.game.cl.cl_8, 2);
    move_bg(all->sprite.game.bg1_1, all->wind, &all->sprite.game.cl.cl_9, 1);
    move_bg(all->sprite.game.bg3_2, all->wind, &all->sprite.game.cl.cl_10, 3);
    move_bg(all->sprite.game.bg4_2, all->wind, &all->sprite.game.cl.cl_11, 2);
    m_bg(all->sprite.game.bg5_2, all->wind, &all->sprite.game.cl.cl_12, 1.2);
}

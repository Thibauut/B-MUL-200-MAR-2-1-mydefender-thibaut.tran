/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** clock_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

void refresh_clocks2(global_s *all)
{
    all->sprite.game.cl.cl_9.time = sfcget(all->sprite.game.cl.cl_9.clock);
    all->sprite.game.cl.cl_9.sec = all->sprite.game.cl.cl_9.tms / 1000000.0;
    all->sprite.game.cl.cl_10.time = sfcget(all->sprite.game.cl.cl_10.clock);
    all->sprite.game.cl.cl_10.sec = all->sprite.game.cl.cl_10.tms / 1000000.0;
    all->sprite.game.cl.cl_11.time = sfcget(all->sprite.game.cl.cl_11.clock);
    all->sprite.game.cl.cl_11.sec = all->sprite.game.cl.cl_11.tms / 1000000.0;
    all->sprite.game.cl.cl_12.time = sfcget(all->sprite.game.cl.cl_12.clock);
    all->sprite.game.cl.cl_12.sec = all->sprite.game.cl.cl_12.tms / 1000000.0;
}

void refresh_clocks(global_s *all)
{
    all->sprite.game.cl.cl_1.time = sfcget(all->sprite.game.cl.cl_1.clock);
    all->sprite.game.cl.cl_1.sec = all->sprite.game.cl.cl_1.tms / 1000000.0;
    all->sprite.game.cl.cl_2.time = sfcget(all->sprite.game.cl.cl_2.clock);
    all->sprite.game.cl.cl_2.sec = all->sprite.game.cl.cl_2.tms / 1000000.0;
    all->sprite.game.cl.cl_3.time = sfcget(all->sprite.game.cl.cl_3.clock);
    all->sprite.game.cl.cl_3.sec = all->sprite.game.cl.cl_3.tms / 1000000.0;
    all->sprite.game.cl.cl_4.time = sfcget(all->sprite.game.cl.cl_4.clock);
    all->sprite.game.cl.cl_4.sec = all->sprite.game.cl.cl_4.tms / 1000000.0;
    all->sprite.game.cl.cl_5.time = sfcget(all->sprite.game.cl.cl_5.clock);
    all->sprite.game.cl.cl_5.sec = all->sprite.game.cl.cl_5.tms / 1000000.0;
    all->sprite.game.cl.cl_6.time = sfcget(all->sprite.game.cl.cl_6.clock);
    all->sprite.game.cl.cl_6.sec = all->sprite.game.cl.cl_6.tms / 1000000.0;
    all->sprite.game.cl.cl_7.time = sfcget(all->sprite.game.cl.cl_7.clock);
    all->sprite.game.cl.cl_7.sec = all->sprite.game.cl.cl_7.tms / 1000000.0;
    all->sprite.game.cl.cl_8.time = sfcget(all->sprite.game.cl.cl_8.clock);
    all->sprite.game.cl.cl_8.sec = all->sprite.game.cl.cl_8.tms / 1000000.0;
    refresh_clocks2(all);
}

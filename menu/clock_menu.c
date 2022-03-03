/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** clock_menu.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void refresh_clock2(global_s *all) {
    all->cl.cl_more.time = sfClock_getElapsedTime(all->cl.cl_more.clock);
    all->cl.cl_more.seconds = all->cl.cl_more.time.microseconds / 1000000.0;
    all->cl.cl_more2.time = sfClock_getElapsedTime(all->cl.cl_more2.clock);
    all->cl.cl_more2.seconds = all->cl.cl_more2.time.microseconds / 1000000.0;
}

void refresh_clock(global_s *all)
{
    all->cl.cl_1.time = sfClock_getElapsedTime(all->cl.cl_1.clock);
    all->cl.cl_1.seconds = all->cl.cl_1.time.microseconds / 1000000.0;
    all->cl.cl_2.time = sfClock_getElapsedTime(all->cl.cl_2.clock);
    all->cl.cl_2.seconds = all->cl.cl_2.time.microseconds / 1000000.0;
    all->cl.cl_3.time = sfClock_getElapsedTime(all->cl.cl_3.clock);
    all->cl.cl_3.seconds = all->cl.cl_3.time.microseconds / 1000000.0;
    all->cl.cl_4.time = sfClock_getElapsedTime(all->cl.cl_4.clock);
    all->cl.cl_4.seconds = all->cl.cl_4.time.microseconds / 1000000.0;
    all->cl.cl_5.time = sfClock_getElapsedTime(all->cl.cl_5.clock);
    all->cl.cl_5.seconds = all->cl.cl_5.time.microseconds / 1000000.0;
    all->cl.cl_6.time = sfClock_getElapsedTime(all->cl.cl_6.clock);
    all->cl.cl_6.seconds = all->cl.cl_6.time.microseconds / 1000000.0;
    all->cl.cl_7.time = sfClock_getElapsedTime(all->cl.cl_7.clock);
    all->cl.cl_7.seconds = all->cl.cl_7.time.microseconds / 1000000.0;
    all->cl.cl_8.time = sfClock_getElapsedTime(all->cl.cl_8.clock);
    all->cl.cl_8.seconds = all->cl.cl_8.time.microseconds / 1000000.0;
    refresh_clock2(all);
}

/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** anim_background.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void move_bg(sfSprite *spt, sfRenderWindow *wind, one_cl *cl, float w)
{
    sfIntRect rect_plan = {cl->pos, 0, 1920, 1080};
    if (cl->seconds > 0.0001) {
        cl->pos = cl->pos + w;
        if (cl->pos >= 1920)
            cl->pos = 0;
        sfClock_restart(cl->clock);
    }
    sfSprite_setTextureRect(spt, rect_plan);
}

void draw_menu_parallax(global_s *all)
{
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bg_1, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bg_2, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bg_3, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bg_4, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bg_5, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bg_6, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bg_7, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bg_8, NULL);
}

void anim_parallax(global_s *all)
{
    move_bg(all->sprite.menu.bg_1, all->wind, &all->cl.cl_1, 1);
    move_bg(all->sprite.menu.bg_2, all->wind, &all->cl.cl_2, 1.75);
    move_bg(all->sprite.menu.bg_3, all->wind, &all->cl.cl_3, 2.5);
    move_bg(all->sprite.menu.bg_4, all->wind, &all->cl.cl_4, 3.25);
    move_bg(all->sprite.menu.bg_5, all->wind, &all->cl.cl_5, 4);
    move_bg(all->sprite.menu.bg_6, all->wind, &all->cl.cl_6, 4.75);
    move_bg(all->sprite.menu.bg_7, all->wind, &all->cl.cl_7, 4.75);
    move_bg(all->sprite.menu.bg_8, all->wind, &all->cl.cl_8, 4.75);
    draw_menu_parallax(all);
}

void anim_button(global_s *all)
{
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.menu, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_1, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.menu.bt_2, NULL);
}

/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** my_menu6.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void check_mouse_icone(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    all->verif.verif_1 = 0;
    choose_icone_anim(all->sprite.level.ic_1, all, 1);
    choose_icone_anim(all->sprite.level.ic_2, all, 2);
    choose_icone_anim(all->sprite.level.ic_3, all, 3);
    choose_icone_anim(all->sprite.level.ic_4, all, 4);
    choose_icone_anim(all->sprite.level.ic_5, all, 5);
    choose_icone_anim(all->sprite.level.ic_6, all, 6);
    choose_icone_anim(all->sprite.level.ic_7, all, 7);
    choose_icone_anim(all->sprite.level.ic_8, all, 8);
    choose_icone_anim(all->sprite.level.ic_9, all, 9);
}

void my_draw_levels2(global_s *all)
{
    sfrwds(all->wind, asl.ic_1, NULL);
    sfrwds(all->wind, asl.ic_2, NULL);
    sfrwds(all->wind, asl.ic_3, NULL);
    sfrwds(all->wind, asl.ic_4, NULL);
    sfrwds(all->wind, asl.ic_5, NULL);
    sfrwds(all->wind, asl.ic_6, NULL);
    sfrwds(all->wind, asl.ic_7, NULL);
    sfrwds(all->wind, asl.ic_8, NULL);
    sfrwds(all->wind, asl.ic_9, NULL);
}

void my_draw_levels(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_drawSprite(all->wind, asl.bg_lvl, NULL);
    print_light(all);
    info_update(all);
    my_draw_levels2(all);
    sfrwds(all->wind, asl.cb, NULL);
    draw_pop_up(asl.bt_weap, all, &all->pop5);
    sfRenderWindow_drawSprite(all->wind, asl.bt_weap, NULL);
    sfRenderWindow_drawText(all->wind, asl.txt_coins, NULL);
    sfText_setString(asl.txt_coins, my_itoa(all->info_p->coins));
    sfRenderWindow_drawSprite(all->wind, asl.upgrade, NULL);
    if (all->info_p->pl_base != 7)
        draw_pop_up(asl.upgrade_bt, all, &all->pop1);
    sfSprite_setScale(asg.update, tsvf(0.3, 0.3));
    sfSprite_setPosition(asg.update, tsvf(1425, 600));
    sfRenderWindow_drawSprite(all->wind, asg.update, NULL);
    draw_price_base(all);
    sfRenderWindow_display(all->wind);
}

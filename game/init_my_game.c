/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** init_my_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"
#define l_rs list_rev->enemy.sprite
#define l_r list_rev->enemy
#define l_ec list->enemy.clock
#define l_es list->enemy.sprite
#define ae1r anim_e1_rev
#define ae4r anim_e4_rev

int enemy3_anim(global_s *all, list_enemy *list)
{
    int i = 0;
    i = anim_e3(&list->enemy.clock, 251, all, &list->enemy);
    anim_fx(&list->enemy);
    return (i);
}

void enemy3(global_s *all)
{
    list_enemy *list = all->sprite.game.list_enemy3;
    int len = list_len_2(list) - 1;
    sfVector2f pos_txt;
    enemy_s enemy;
    for (int i = 0; i != len; list = list->next, i++) {
        if (enemy3_anim(all, list) == 1) {
            all->sprite.game.blood += 45;
            all->sprite.game.nb_jet -= 1;
            all->sprite.game.list_enemy3 = fet(all->sprite.game.l_e3, i);
            continue;
        }
        pos_txt = sfSprite_getPosition(list->enemy.sprite);
        pos_txt.y = pos_txt.y - 50;
        pos_txt.x = pos_txt.x + 10;
        if (list->enemy.life > 0)
            sfRenderWindow_drawSprite(all->wind, list->enemy.fx, NULL);
        sfRenderWindow_drawSprite(all->wind, list->enemy.sprite, NULL);
        sfrdt(all->wind, pv(pos_txt.x, pos_txt.y, list), NULL);
    }
}

int start_api(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_setMouseCursorVisible(all->wind, sfFalse);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.load, NULL);
    sfRenderWindow_display(all->wind);
    return (0);
}

void my_init_game(global_s *all)
{
    start_api(all);
    create_sprites_game(all);
    sfRenderWindow_setFramerateLimit(all->wind, 120);
    all->sprite.game.cl = create_clock();
}

void my_game(global_s *all)
{
    if (all->musics.active == sfTrue && all->i == 0) {
        sfSound_stop(all->sounds.sound1);
        sfSound_play(all->sounds.sound1);
        all->i = 1;
    }
    refresh_clocks(all);
    move_clouds(all);
    print_game(all);
    check_events_game(all);
}

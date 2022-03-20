/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** collision_enemy2.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void detect_car_rev(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test)
{
    sfFloatRect rect_b = sfSprite_getGlobalBounds(bullet_l->sprite);
    sfFloatRect rect_e;
    enemy_s enemy;
    int len_jet = list_len_2(all->sprite.game.l_e6);
    for (int i = 0; i != len_jet; i++) {
        enemy = get_enemy(all->sprite.game.list_enemy6, i);
        rect_e = rect_e4_rev(all, enemy.sprite);
        if (sfFloatRect_intersects(&rect_e, &rect_b, NULL)) {
            enemy.life = enemy.life - dmg(tow->type, all->info_p->base);
            *test += 1;
            all->sprite.game.list_enemy6 = fet(all->sprite.game.l_e6, i);
            all->sprite.game.l_e6 = adde(all->sprite.game.l_e6, enemy, i);
            return;
        }
    }
}

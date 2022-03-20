/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** anim_enemy.c
*/

#include "../include/func.h"
#include "../include/struct.h"

void refresh_life_base(global_s *all, int dmg)
{
    if (dmg == 10000) {
        all->sprite.game.blood -= 800;
        all->sprite.game.life_b = 5000;
    } else {
        all->sprite.game.life_b -= dmg;
    }
    all->life = (all->sprite.life_tmp / 183) + 1;
    all->life = (int) all->sprite.game.life_b / all->life;
    all->rect_life = create_rect(0, 0, all->life, 12);
    sfSprite_setTextureRect(all->sprite.game.life_bs, all->rect_life);
    if (all->sprite.game.life_b <= 0)
        loose_game(all);
}

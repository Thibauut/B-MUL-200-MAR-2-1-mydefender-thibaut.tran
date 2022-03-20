/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** place_good_base.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#define A ATTACK
#define D DEFENSIVE

void place_case_pv(global_s *all)
{
    char *pv = "res/game/health_lvl1.png", *pv2 = "res/game/health_lvl2.png";
    all->sprite.game.base = csS(pv, 590, 560, tsvf(0.75, 0.75));
    all->sprite.game.life_b = 2500;
    if (all->info_p->pl_base == 4) {
        all->sprite.game.base = csS(pv2, 590, 560, tsvf(0.75, 0.75));
        all->sprite.game.life_b = 6000;
    }
}

void place_good_base(global_s *all)
{
    char *atk = "res/game/atk_lvl1.png", *atk2 = "res/game/atk_lvl2.png";
    char *def = "res/game/def_lvl1.png", *def2 = "res/game/def_lvl2.png";
    switch (all->info_p->base) {
        case A: all->sprite.game.base = csS(atk, 590, 560, tsvf(0.75, 0.75));
                all->sprite.game.life_b = 2000;
            if (all->info_p->pl_base == 4) {
                all->sprite.game.base = csS(atk2, 590, 560, tsvf(0.75, 0.75));
                all->sprite.game.life_b = 5000;
            }
            break;
        case D: all->sprite.game.base = csS(def, 590, 560, tsvf(0.75, 0.75));
                all->sprite.game.life_b = 2000;
            if (all->info_p->pl_base == 4) {
                all->sprite.game.base = csS(def2, 590, 560, tsvf(0.75, 0.75));
                all->sprite.game.life_b = 5000;
            }
            break;
        case PV: place_case_pv(all);
            break;
    }
}

void info_base(global_s *all)
{
    char *bbs = "res/sprites/bg_bar.png";
    char *bs = "res/sprites/green_bar.png";
    place_good_base(all);
    all->sprite.life_tmp = all->sprite.game.life_b;
    all->sprite.game.life_bbs = csS(bbs, 765, 300, tsvf(1.64, 2));
    all->sprite.game.life_bs = csS(bs, 775, 306, tsvf(2, 2));
    all->rect_life = create_rect(0, 0, 183, 12);
    all->life = 0;
    sfSprite_setTextureRect(all->sprite.game.life_bs, all->rect_life);
}

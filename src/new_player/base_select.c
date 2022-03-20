/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** base_select.c
*/

#include "../../include/func.h"
#include "../../include/struct.h"

void bases(global_s *all, sffr rec_of, sffr rec_def, sffr rec_pv)
{
    sfTexture *texture;
    if (sfFloatRect_contains(&rec_of, all->pos_mouse.x, all->pos_mouse.y)) {
        if (all->sounds.active == sfTrue) {
            sfSound_stop(all->sounds.sound1);
            sfSound_play(all->sounds.sound1);
        }
        reset_texture_base(all);
        texture = sfTexture_createFromFile("res/others/base_atk2.png", NULL);
        sfSprite_setTexture(all->sprite.other.base_of, texture, sfFalse);
        all->info_p->base = ATTACK;
    }
    if (sfFloatRect_contains(&rec_def, all->pos_mouse.x, all->pos_mouse.y)) {
        if (all->sounds.active == sfTrue) {
            sfSound_stop(all->sounds.sound1);
            sfSound_play(all->sounds.sound1);
        }
        reset_texture_base(all);
        texture = sfTexture_createFromFile("res/others/base_def2.png", NULL);
        sfSprite_setTexture(all->sprite.other.base_def, texture, sfFalse);
        all->info_p->base = DEFENSIVE;
    }
    if (sfFloatRect_contains(&rec_pv, all->pos_mouse.x, all->pos_mouse.y)) {
        if (all->sounds.active == sfTrue) {
            sfSound_stop(all->sounds.sound1);
            sfSound_play(all->sounds.sound1);
        }
        reset_texture_base(all);
        texture = sfTexture_createFromFile("res/others/base_pv2.png", NULL);
        sfSprite_setTexture(all->sprite.other.base_pv, texture, sfFalse);
        all->info_p->base = PV;
    }
}

void check_wich_base(global_s *all)
{
    sfFloatRect rec_of = sfggb(all->sprite.other.base_of);
    sfFloatRect rec_def = sfggb(all->sprite.other.base_def);
    sfFloatRect rec_pv = sfggb(all->sprite.other.base_pv);
    bases(all, rec_of, rec_def, rec_pv);
}

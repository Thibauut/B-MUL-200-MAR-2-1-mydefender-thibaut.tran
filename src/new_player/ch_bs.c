/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** ch_bs.c
*/

#include "../../include/func.h"
#include "../../include/struct.h"

void choose_base(global_s *all)
{
    create_choose_base(all);
    if (all->is_ask == WEAPONS)
        all->info_p->base = 0;
    while (all->is_ask == WEAPONS) {
        check_choose_base(all);
        print_choose_base(all);
    }
}

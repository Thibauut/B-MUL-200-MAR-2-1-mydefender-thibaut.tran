/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** init_my_game.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

list_tow_g *fill_list_tow(global_s *all)
{
    list_tow_g *list = NULL;
    tow_g tow;
    tow.type = 0;
    int *bin_x = malloc(sizeof(int) * 2);
    bin_x[0] = 610;
    bin_x[1] = 1225;
    int *bin_y = malloc(sizeof(int) * 2);
    bin_y[0] = 750;
    bin_y[1] = 750;
    int place = 0;
    for (; place != all->info_p->pl_base; place += 1) {
        tow.clock = create_one_clock();
        tow.clock_b = create_one_clock();
        tow.rect.left = 0;
        tow.pos = tsvf(bin_x[place], bin_y[place]);
        tow.sprite = create_spriteStocky("res/game/add_weap.png", tow.pos.x, tow.pos.y, tsvf(1.2, 1.2));
        tow.type = 0;
        tow.bullet = NULL;
        list = add_tower(list, tow, 0);
    }
    return (list);
}

void create_sprites_game(global_s *all)
{
    all->sprite.game.e1 = 0;
    switch (all->info_p->base)
    {
        case ATTACK: all->sprite.game.base = create_spriteStocky("res/game/atk_lvl1.png", 590, 560, tsvf(0.75, 0.75));
            break;
        case DEFENSIVE: all->sprite.game.base = create_spriteStocky("res/game/def_lvl1.png", 590, 560, tsvf(0.75, 0.75));
            break;
        case PV: all->sprite.game.base = create_spriteStocky("res/game/health_lvl1.png", 590, 560, tsvf(0.75, 0.75));
            break;
    }
    all->sprite.game.bg = create_spriteStocky("res/game/bg_sky.png", 0, 0, tsvf(1, 1));
    all->sprite.game.clouds = create_spriteStocky("res/game/clouds.png", 0, 0, tsvf(1, 1));
    all->sprite.game.brume = create_spriteStocky("res/game/brume.png", 0, 0, tsvf(1, 1));
    all->sprite.game.road = create_spriteStocky("res/menu/6.png", 0, 535, tsvf(1, 1));
    all->sprite.game.tree = create_spriteStocky("res/game/cloud2.png", 0, 60, tsvf(1, 1));
    all->sprite.game.list_tow = fill_list_tow(all);
    all->sprite.weapons.tower_bar = create_spriteStocky("res/weapons/tower_bar.png", 467, 70, tsvf(1, 1));
    all->sprite.weapons.bt_wp1 = create_spriteStocky("res/weapons/bt_wp1.png", 487, 125, tsvf(0.6, 0.6));
    all->sprite.weapons.bt_wp2 = create_spriteStocky("res/weapons/bt_wp2.png", 697, 120, tsvf(0.85, 0.85));
    all->sprite.weapons.bt_wp3 = create_spriteStocky("res/weapons/bt_wp3.png", 886, 93, tsvf(0.6, 0.6));
    all->sprite.weapons.bt_wp4 = create_spriteStocky("res/weapons/bt_wp4.png", 1095, 117, tsvf(0.65, 0.65));
    all->sprite.weapons.bt_wp5 = create_spriteStocky("res/weapons/bt_wp5.png", 1305, 95, tsvf(0.65, 0.65));
    all->sprite.weapons.unlock1 = create_spriteStocky("res/weapons/wp_lock.png", 1305, 95, tsvf(0.65, 0.65));
    all->sprite.game.blood = 10000;
    all->sprite.game.blood_s = create_spriteStocky("res/weapons/elixir.png", 5, 10, tsvf(0.25, 0.25));
    all->sprite.game.blood_x = create_textStocky(my_itoa(all->sprite.game.blood), 70, sfWhite, 100, 5);
    all->sprite.game.ennemy1 = create_spriteStocky("res/sprites/e1_spt.png", 7, 743, tsvf(0.65, 0.65));
    all->sprite.game.list_enemy = fill_enemy(all);
    all->sprite.game.list_enemy2 = fill_enemy_2(all);
    sfRenderWindow_setMouseCursorVisible(all->wind, sfTrue);
}

void anim_e1(sfSprite *spt, one_cl *cl, int i, global_s *all)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect ennemy_r = sfSprite_getGlobalBounds(spt);
    sfFloatRect base_r = sfSprite_getGlobalBounds(all->sprite.game.base);
    base_r.left = base_r.left + 50;
    sfIntRect rect = {cl->pos, 347, 471, 347};
    sfBool is_rect = sfFloatRect_intersects(&ennemy_r, &base_r, NULL);
    if (is_rect == sfTrue)
        rect.top = 694;
    if (cl->seconds > 0.03) {
        if (is_rect != sfTrue) {
            sfSprite_move(spt, tsvf(3, 0));
        }
        cl->pos = cl->pos + i;
        if (cl->pos >= 8473 && is_rect != sfTrue)
            cl->pos = 0;
        if (cl->pos >= 9842 && is_rect == sfTrue)
            cl->pos = 0;
        sfClock_restart(cl->clock);
    }
    sfSprite_setTextureRect(spt, rect);
}

void anim_e1_rev(sfSprite *spt, one_cl *cl, int i, global_s *all)
{
    cl->time = sfClock_getElapsedTime(cl->clock);
    cl->seconds = cl->time.microseconds / 1000000.0;
    sfFloatRect ennemy_r = sfSprite_getGlobalBounds(spt);
    sfFloatRect base_r = sfSprite_getGlobalBounds(all->sprite.game.base);
    base_r.width = base_r.width - 50;
    sfIntRect rect = {cl->pos, 347, 471, 347};
    sfBool is_rect = sfFloatRect_intersects(&ennemy_r, &base_r, NULL);
    if (is_rect == sfTrue)
        rect.top = 694;
    if (cl->seconds > 0.03) {
        if (is_rect != sfTrue) {
            sfSprite_move(spt, tsvf(-3, 0));
        }
        cl->pos = cl->pos + i;
        if (cl->pos >= 8473 && is_rect != sfTrue)
            cl->pos = 0;
        if (cl->pos >= 9842 && is_rect == sfTrue)
            cl->pos = 0;
        sfClock_restart(cl->clock);
    }
    sfSprite_setTextureRect(spt, rect);
}

sfText *pv(float x, float y, list_enemy *list)
{
    char *txt_string;
    sfText *text;
    txt_string = my_strdup("PV: ");
    txt_string = my_strcat(txt_string, my_itoa(list->enemy.life));
    text = create_textStocky(txt_string, 30, sfWhite, x, y);
    return (text);
}

void rect_e1(global_s *all, list_enemy *list)
{
    all->rect_e->e1 = sfSprite_getGlobalBounds(list->enemy.sprite);
    all->rect_e->e1.width -= 180;
    all->rect_e->e1.height -= 120;
    all->rect_e->e1.left += 105;
    all->rect_e->e1.top += 80;
    // all->rect_e->e1_2 = sfSprite_getGlobalBounds(list->enemy.sprite);
}

void collision_e1(global_s *all, list_enemy *list, int r)
{
    all->rect_e = malloc(sizeof(rect_e));
    rect_e1(all, list);
    // sfRectangleShape *test1 = sfRectangleShape_create();
    // sfVector2f v = {all->rect_e->e1.left, all->rect_e->e1.top};
    // sfVector2f v2 = {all->rect_e->e1.width, all->rect_e->e1.height};
    // sfRectangleShape_setSize(test1, v2);
    // sfRectangleShape_setOutlineThickness(test1, 3);
    // sfRectangleShape_setFillColor(test1, sfTransparent);
    // sfRectangleShape_setOutlineColor(test1, sfRed);
    // sfRectangleShape_setPosition(test1, v);
    // sfRenderWindow_drawRectangleShape(all->wind, test1, NULL);
    int verif = 0;
    int len_tow = list_len(all->sprite.game.list_tow);
    sfFloatRect rect_en = sfSprite_getGlobalBounds(get_enemy(list, r).sprite);
    for (int i = 0; i != len_tow; i++) {
        tow_g tow = get_element4(all->sprite.game.list_tow, i);
        int len_bul = list_len_2(tow.bullet);
        if (len_bul >= 1) {
            enemy_s bull = get_enemy(tow.bullet, len_bul - 1);
            sfFloatRect rect_b = sfSprite_getGlobalBounds(bull.sprite);
            if (sfFloatRect_intersects(&all->rect_e->e1, &rect_b, NULL)) {
                verif = 1;
                enemy_s ene = get_enemy(all->sprite.game.list_enemy, r);
                ene.life = ene.life - 10;
                all->sprite.game.list_tow[i].tower.bullet = free_element_at(tow.bullet, len_bul - 1);
                all->sprite.game.list_enemy = free_element_at(all->sprite.game.list_enemy, r);
                if (ene.life > 0)
                    all->sprite.game.list_enemy = add_enemy(all->sprite.game.list_enemy, ene, r);
            }
            if (verif == 1)
                return;
        }
    }
}

void enemy(global_s *all)
{
    list_enemy *list = all->sprite.game.list_enemy;
    list_enemy *list_rev = all->sprite.game.list_enemy2;
    int len = list_len_2(list) - 1;
    int len2 = list_len_2(list_rev) - 1;
    sfVector2f pos_txt;
    char *txt_string;
    for (int i = 0; i != len; list = list->next, i++) {
        anim_e1(list->enemy.sprite, &list->enemy.clock, 471, all);
        pos_txt = sfSprite_getPosition(list->enemy.sprite);
        pos_txt.y = pos_txt.y - 30;
        pos_txt.x = pos_txt.x + 70;
        sfRenderWindow_drawSprite(all->wind, list->enemy.sprite, NULL);
        sfRenderWindow_drawText(all->wind, pv(pos_txt.x, pos_txt.y, list), NULL);
        collision_e1(all, list, i);
    }
    for (int i = 0; i != len2; list_rev = list_rev->next, i++) {
        anim_e1_rev(list_rev->enemy.sprite, &list_rev->enemy.clock, 471, all);
        pos_txt = sfSprite_getPosition(list_rev->enemy.sprite);
        pos_txt.y = pos_txt.y - 30;
        pos_txt.x = pos_txt.x - 150;
        collision_e1(all, list_rev, i);
        sfRenderWindow_drawSprite(all->wind, list_rev->enemy.sprite, NULL);
        sfRenderWindow_drawText(all->wind, pv(pos_txt.x, pos_txt.y, list_rev), NULL);
    }
}

void check_place_weap(global_s *all)
{
    list_tow_g *list_tmp = all->sprite.game.list_tow;
    sfFloatRect rect_1 = sfSprite_getGlobalBounds(all->sprite.weapons.bt_wp1);
    char *str = my_itoa(all->info_p->tower);
    if (sfFloatRect_contains(&rect_1, all->pos_mouse.x, all->pos_mouse.y)) {
        int len = all->sprite.game.wc_tower;
        tow_g tow = get_element4(all->sprite.game.list_tow, len);
        if (all->sprite.game.blood < 100 || tow.type == 1)
            return;
        tow.type = 1;
        tow.rect.left = 0;
        tow.rect.width = 283;
        all->sprite.game.is_bar = False;
        all->sprite.game.blood = all->sprite.game.blood - 100;
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, len);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, len);
    }
    sfFloatRect rect_2 = sfSprite_getGlobalBounds(all->sprite.weapons.bt_wp2);
    if (sfFloatRect_contains(&rect_2, all->pos_mouse.x, all->pos_mouse.y) && str[1] == '1') {
        int len = all->sprite.game.wc_tower;
        tow_g tow = get_element4(all->sprite.game.list_tow, len);
        if (all->sprite.game.blood < 300 || tow.type == 2)
            return;
        tow.type = 2;
        tow.rect.left = 0;
        tow.rect.width = 177;
        all->sprite.game.is_bar = False;
        all->sprite.game.blood = all->sprite.game.blood - 300;
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, len);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, len);
    }
    sfFloatRect rect_3 = sfSprite_getGlobalBounds(all->sprite.weapons.bt_wp3);
    if (sfFloatRect_contains(&rect_3, all->pos_mouse.x, all->pos_mouse.y) && str[2] == '1') {
        int len = all->sprite.game.wc_tower;
        tow_g tow = get_element4(all->sprite.game.list_tow, len);
        if (all->sprite.game.blood < 600 || tow.type == 3)
            return;
        tow.type = 3;
        tow.rect.left = 0;
        tow.rect.width = 290;
        all->sprite.game.is_bar = False;
        all->sprite.game.blood = all->sprite.game.blood - 600;
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, len);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, len);
    }
    sfFloatRect rect_4 = sfSprite_getGlobalBounds(all->sprite.weapons.bt_wp4);
    if (sfFloatRect_contains(&rect_4, all->pos_mouse.x, all->pos_mouse.y) && str[3] == '1') {
        int len = all->sprite.game.wc_tower;
        tow_g tow = get_element4(all->sprite.game.list_tow, len);
        if (all->sprite.game.blood < 900 || tow.type == 4)
            return;
        tow.type = 4;
        tow.rect.left = 0;
        tow.rect.width = 246;
        all->sprite.game.is_bar = False;
        all->sprite.game.blood = all->sprite.game.blood - 900;
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, len);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, len);
    }
    sfFloatRect rect_5 = sfSprite_getGlobalBounds(all->sprite.weapons.bt_wp5);
    if (sfFloatRect_contains(&rect_5, all->pos_mouse.x, all->pos_mouse.y) && str[4] == '1') {
        int len = all->sprite.game.wc_tower;
        tow_g tow = get_element4(all->sprite.game.list_tow, len);
        if (all->sprite.game.blood < 1200 || tow.type == 5)
            return;
        tow.type = 5;
        all->sprite.game.is_bar = False;
        all->sprite.game.blood = all->sprite.game.blood - 1200;
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, len);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, len);
    }
}

tow_g choose_texture(global_s *all, tow_g tow)
{
    sfTexture *texture;
    if (tow.type == 0) {
        texture = sfTexture_createFromFile("res/game/add_weap.png", NULL);
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        return (tow);
    }
    sfVector2f scale = {0.45, 0.45};
    int more = 0;
    if (sfSprite_getPosition(tow.sprite).x > 1000) {
        scale.x = scale.x * (-1);
        more = 115;
    }
    if (tow.type == 1) {
        texture = sfTexture_createFromFile("res/sprites/wp1_spt.png", NULL);
        sfSprite_setScale(tow.sprite, scale);
        sfSprite_setPosition(tow.sprite, tsvf(tow.pos.x - 60 + more, tow.pos.y + 100));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        anim_klassico(&tow);
    }
    if (tow.type == 2) {
        texture = sfTexture_createFromFile("res/sprites/wp2_spt.png", NULL);
        sfSprite_setScale(tow.sprite, scale);
        sfSprite_setPosition(tow.sprite, tsvf(tow.pos.x - 20 + more, tow.pos.y + 105));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        anim_avocado(&tow);
    }
    if (tow.type == 3) {
        texture = sfTexture_createFromFile("res/sprites/wp3_spt.png", NULL);
        sfIntRect rect_1;
        sfSprite_setScale(tow.sprite, scale);
        sfSprite_setPosition(tow.sprite, tsvf(tow.pos.x - 60 + more, tow.pos.y + 71));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        anim_stazz(&tow);
    }
    if (tow.type == 4) {
        texture = sfTexture_createFromFile("res/sprites/wp4_spt.png", NULL);
        sfSprite_setScale(tow.sprite, scale);
        sfSprite_setPosition(tow.sprite, tsvf(tow.pos.x - 45 + more, tow.pos.y + 95));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        anim_blaster(&tow);
    }
    if (tow.type == 5) {
        texture = sfTexture_createFromFile("res/sprites/wp5_spt.png", NULL);
        sfIntRect rect_1;
        rect_1.left = 0;
        rect_1.top = 0;
        rect_1.width = 230;
        rect_1.height = 132;
        sfSprite_setScale(tow.sprite, tsvf(0.6, 0.6));
        sfSprite_setPosition(tow.sprite, tsvf(tow.pos.x - 50, tow.pos.y + 100));
        sfSprite_setTexture(tow.sprite, texture, sfFalse);
        sfSprite_setTextureRect(tow.sprite, rect_1);
    }
    return (tow);
}

void print_weapons(global_s *all)
{
    int i = 0;
    int len = list_len(all->sprite.game.list_tow);
    sfFloatRect rect;
    for (; i != len; i += 1) {
        tow_g tow = get_element4(all->sprite.game.list_tow, i);
        rect = sfSprite_getGlobalBounds(tow.sprite);
        if (sfFloatRect_contains(&rect, all->pos_mouse.x, all->pos_mouse.y)) {
            sfSprite_setPosition(tow.sprite, tsvf(tow.pos.x - 2, tow.pos.y - 3));
            if (all->event->type == sfEvtMouseButtonPressed) {
                all->sprite.game.is_bar = True;
                all->sprite.game.wc_tower = i;
            }
        } else {
            sfSprite_setPosition(tow.sprite, tsvf(tow.pos.x, tow.pos.y));
        }
        tow = choose_texture(all, tow);
        all->sprite.game.list_tow = free_tow_at(all->sprite.game.list_tow, i);
        all->sprite.game.list_tow = add_tower(all->sprite.game.list_tow, tow, i);
        if (tow.type == 1) {
            int len_bul = list_len_2(tow.bullet);
            if (len_bul >= 1)
                for (int i = 0; i < len_bul; i++)
                    sfRenderWindow_drawSprite(all->wind, get_enemy(tow.bullet, i).sprite, NULL);
        }
        sfRenderWindow_drawSprite(all->wind, tow.sprite, NULL);
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
    all->sprite.game.cl = create_clock();
}

void is_draw_wep(sfSprite *spt, int num, global_s *all)
{
    char *str = my_itoa(all->info_p->tower);
    char c = str[num];
    if (c == '1')
        sfRenderWindow_drawSprite(all->wind, spt, NULL);
    else {
        sfVector2f vect = sfSprite_getPosition(spt);
        sfSprite_setPosition(all->sprite.weapons.unlock1, vect);
        sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.unlock1, NULL);
    }
}

void print_game(global_s *all)
{
    sfRenderWindow_clear(all->wind, sfBlack);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.bg, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.clouds, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.brume, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.tree, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.road, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.base, NULL);
    sfRenderWindow_drawSprite(all->wind, all->sprite.game.blood_s, NULL);
    sfText_setString(all->sprite.game.blood_x, my_itoa(all->sprite.game.blood));
    sfRenderWindow_drawText(all->wind, all->sprite.game.blood_x, NULL);
    if (all->sprite.game.is_bar == True) {
        sfRenderWindow_drawSprite(all->wind, all->sprite.weapons.tower_bar, NULL);
        is_draw_wep(all->sprite.weapons.bt_wp1, 0, all);
        is_draw_wep(all->sprite.weapons.bt_wp2, 1, all);
        is_draw_wep(all->sprite.weapons.bt_wp3, 2, all);
        is_draw_wep(all->sprite.weapons.bt_wp4, 3, all);
        is_draw_wep(all->sprite.weapons.bt_wp5, 4, all);
    }
    print_weapons(all);
    enemy(all);
    sfRenderWindow_display(all->wind);
}

void check_events_game(global_s *all)
{
    all->pos_mouse = sfMouse_getPositionRenderWindow(all->wind);
    while (sfRenderWindow_pollEvent(all->wind, all->event)) {
        if (all->event->type == sfEvtClosed) {
            sfRenderWindow_close(all->wind);
            all->STATUS = FINISH;
        }
        if (all->event->type == sfEvtKeyPressed && all->event->key.code == sfKeyEscape) {
            if (all->sprite.game.is_bar == False)
                all->STATUS = MAP;
            else
                all->sprite.game.is_bar = False;
        }
        if (all->event->type == sfEvtMouseButtonPressed && all->sprite.game.is_bar == True)
            check_place_weap(all);
    }
}

void move_clouds(global_s *all)
{
    move_bg(all->sprite.game.clouds, all->wind, &all->sprite.game.cl.cl_1, 1);
    move_bg(all->sprite.game.brume, all->wind, &all->sprite.game.cl.cl_2, 1.8);
    move_bg(all->sprite.game.tree, all->wind, &all->sprite.game.cl.cl_3, 2.5);
}

void refresh_clocks(global_s *all)
{
    all->sprite.game.cl.cl_1.time = sfClock_getElapsedTime(all->sprite.game.cl.cl_1.clock);
    all->sprite.game.cl.cl_1.seconds = all->sprite.game.cl.cl_1.time.microseconds / 1000000.0;
    all->sprite.game.cl.cl_2.time = sfClock_getElapsedTime(all->sprite.game.cl.cl_2.clock);
    all->sprite.game.cl.cl_2.seconds = all->sprite.game.cl.cl_2.time.microseconds / 1000000.0;
    all->sprite.game.cl.cl_3.time = sfClock_getElapsedTime(all->sprite.game.cl.cl_3.clock);
    all->sprite.game.cl.cl_3.seconds = all->sprite.game.cl.cl_3.time.microseconds / 1000000.0;
    all->sprite.game.cl.cl_4.time = sfClock_getElapsedTime(all->sprite.game.cl.cl_4.clock);
    all->sprite.game.cl.cl_4.seconds = all->sprite.game.cl.cl_4.time.microseconds / 1000000.0;
    all->sprite.game.cl.cl_5.time = sfClock_getElapsedTime(all->sprite.game.cl.cl_5.clock);
    all->sprite.game.cl.cl_5.seconds = all->sprite.game.cl.cl_5.time.microseconds / 1000000.0;
    all->sprite.game.cl.cl_6.time = sfClock_getElapsedTime(all->sprite.game.cl.cl_6.clock);
    all->sprite.game.cl.cl_6.seconds = all->sprite.game.cl.cl_6.time.microseconds / 1000000.0;
    all->sprite.game.cl.cl_7.time = sfClock_getElapsedTime(all->sprite.game.cl.cl_7.clock);
    all->sprite.game.cl.cl_7.seconds = all->sprite.game.cl.cl_7.time.microseconds / 1000000.0;
    all->sprite.game.cl.cl_8.time = sfClock_getElapsedTime(all->sprite.game.cl.cl_8.clock);
    all->sprite.game.cl.cl_8.seconds = all->sprite.game.cl.cl_8.time.microseconds / 1000000.0;
    int len = list_len_2(all->sprite.game.list_enemy);
    enemy_s enemy;
    for (int i = 0; i != len; i++) {
        enemy = get_enemy(all->sprite.game.list_enemy, i);
        enemy.clock.time = sfClock_getElapsedTime(enemy.clock.clock);
        enemy.clock.seconds = enemy.clock.time.microseconds / 1000000.0;
        all->sprite.game.list_enemy = free_element_at(all->sprite.game.list_enemy, i);
        all->sprite.game.list_enemy = add_enemy(all->sprite.game.list_enemy, enemy, i);
    }
}

list_enemy *fill_enemy(global_s *all)
{
    list_enemy *list = NULL;
    enemy_s enemy;
    enemy.life = 100;
    int count = 7;
    enemy.type = 0;
    for (int i = 0; i != 3; i++) {
        enemy.clock = create_one_clock();
        enemy.sprite = create_spriteStocky("res/sprites/e1_spt.png", count, 795, tsvf(0.5, 0.5));
        list = add_enemy(list, enemy, 0);
        count = count - 500;
    }
    return (list);
}

list_enemy *fill_enemy_2(global_s *all)
{
    list_enemy *list = NULL;
    enemy_s enemy;
    enemy.life = 100;
    int count = 1920;
    enemy.type = 0;
    for (int i = 0; i != 3; i++) {
        enemy.clock = create_one_clock();
        enemy.sprite = create_spriteStocky("res/sprites/e1_spt.png", count, 795, tsvf(-0.5, 0.5));
        list = add_enemy(list, enemy, 0);
        count = count + 500;
    }
    return (list);
}

void my_game(global_s *all)
{
    sfRenderWindow_setMouseCursorVisible(all->wind, sfTrue);
    refresh_clocks(all);
    move_clouds(all);
    print_game(all);
    check_events_game(all);
    return;
}
/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-mydefender-thibaut.tran
** File description:
** struct.h
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Network.h>
#include <time.h>
#define MENU 0
#define MAP 1
#define GAME 2
#define TEXT 3
#define ASKING 32
#define FINISH 10
#define WEAPONS 58
#define ATTACK 1011
#define DEFENSIVE 1012
#define PV 1013
#define tsvf transform_vf
#define p_ms all->pos_mouse
#define v2f sfVector2f
#define sfpt sfSprite
#define sffrc sfFloatRect_contains
#define w sfWhite
#define i_a my_itoa
#define sfrwc sfRenderWindow_create
#define csS create_spriteStocky
#define ctS create_textStocky
#define sftcff sfTexture_createFromFile
#define sffr sfFloatRect
#define sft sfTexture
#define ske sfKeyEscape
#define sfekp sfEvtKeyPressed
#define sfggb sfSprite_getGlobalBounds
#define sfrw sfRenderWindow
#define sfso sfSprite_setOrigin
#define sfssp sfSprite_setPosition
#define sfcget sfClock_getElapsedTime
#define sfsst sfSprite_setTexture
#define tms time.microseconds
#define fta free_tow_at
#define addt add_tower
#define sec seconds
#define fet free_element_at
#define adde add_enemy
#define l_e list_enemy
#define l_e2 list_enemy2
#define l_e3 list_enemy3
#define l_e4 list_enemy4
#define l_e5 list_enemy5
#define l_e6 list_enemy6
#define sfrdt sfRenderWindow_drawText
#define sfrwds sfRenderWindow_drawSprite
#define asgpmpm all->sprite.game.pause_menu.pause_menu
#define t11 tsvf(1, 1)
#define t07 tsvf(0.75, 0.75)
#define ctsss ctS(i_a(all->info_p->coins), 47, w, tsvf(200, 115))
#define asl all->sprite.level
#define sm1 all->sounds.sound1
#define asg all->sprite.game

typedef enum {
    False,
    True,
    Down
}Bool;

typedef struct clock_time {
    sfClock *clock;
    sfTime time;
    float seconds;
    int pos;
    int pos2;
}one_cl;

typedef struct enemy_in_game {
    sfSprite *sprite;
    one_cl clock;
    sfIntRect rect;
    sfSprite *fx;
    one_cl clock_fx;
    sfSprite *bullet;
    sfIntRect rect_fx;
    int type;
    int life;
    sfFloatRect col;
    sfVector2f move_b;
}enemy_s;

typedef struct list_enemy_game {
    enemy_s enemy;
    struct list_enemy_game *next;
}list_enemy;

typedef struct tower_in_game {
    sfVector2f pos;
    sfSprite *sprite;
    one_cl clock;
    sfIntRect rect;
    int type;
    one_cl clock_b;
    list_enemy *bullet;
    sfVector2f target;
    int verif_shoot;
}tow_g;

typedef struct my_list_tower_game {
    struct my_list_tower_game *prev;
    tow_g tower;
    struct my_list_tower_game *next;
}list_tow_g;

typedef struct my_menu {
    sfSprite *bg_1, *bg_2, *bg_3, *bg_4, *bg_5, *bg_6;
    sfSprite *bg_7, *bg_8, *menu;
    sfSprite *bt_1, *bt_2;
    sfSprite *bt_close, *bt_option, *bt_tutorial;
    sfSprite *more_bg, *more_bg2, *more_bg3, *more_bg4;
    sfSprite *bg_dia;
    sfSprite *box_dia;
    sfSprite *r_option;
    sfSprite *bt_left;
    sfSprite *bt_right;
    sfSprite *bt_left2;
    sfSprite *bt_right2;
    sfSprite *bt_left3;
    sfSprite *bt_right3;
    sfSprite *bg_bt;
    sfSprite *tutorial;
}sp_menu;

typedef struct my_level {
    sfSprite *bg_lvl;
    sfSprite *ic_1;
    sfSprite *ic_2;
    sfSprite *ic_3;
    sfSprite *ic_4;
    sfSprite *ic_5;
    sfSprite *ic_6;
    sfSprite *ic_7;
    sfSprite *ic_8;
    sfSprite *ic_9;
    sfSprite *light;
    sfSprite *cb;
    sfSprite *left_ar;
    sfSprite *right_ar;
    sfSprite *bt_weap;
    sfSprite *bg_weap;
    sfText *txt_coins;
    sfSprite *upgrade;
    sfSprite *upgrade_bt;
    sfSprite *coins;
}sp_level;

typedef struct all_cl {
    one_cl cl_1;
    one_cl cl_2;
    one_cl cl_3;
    one_cl cl_4;
    one_cl cl_5;
    one_cl cl_6;
    one_cl cl_7;
    one_cl cl_8;
    one_cl cl_9;
    one_cl cl_10;
    one_cl cl_11;
    one_cl cl_12;
    one_cl cl_13;
    one_cl cl_more;
    one_cl cl_more2;
    one_cl cl_e1;
}all_cl;

typedef struct weapons {
    sfSprite *unlock1;
    sfSprite *unlock2;
    sfSprite *unlock3;
    sfSprite *unlock4;
    sfSprite *unlock5;
    sfSprite *wp1;
    sfSprite *wp2;
    sfSprite *wp3;
    sfSprite *wp4;
    sfSprite *wp5;
    sfSprite *tower_bar;
    sfSprite *bt_wp1;
    sfSprite *bt_wp2;
    sfSprite *bt_wp3;
    sfSprite *bt_wp4;
    sfSprite *bt_wp5;
}sp_weap;

typedef struct pause_s {
    sfSprite *pause;
    sfSprite *r_pause;
    sfSprite *resume;
    sfSprite *save;
    sfSprite *exit;
    sfSprite *save_icon;
    sfSprite *pause_menu;
    sfSprite *save_menu;
    sfSprite *exit_menu;
    sfSprite *save_icon_menu;
}pause_t;

typedef struct my_game {
    sfSprite *bg, *clouds, *brume, *tree, *base;
    sfSprite *bg1, *bg2, *bg3, *bg4, *bg5, *bg6;
    sfSprite *bg1_1, *bg2_2, *bg3_2, *bg4_2, *bg5_2;
    sfSprite *update, *road, *tower_1, *tower_2, *tower_3;
    sfSprite *tower_4, *tower_5, *add_weap, *blood_s;
    int blood, life_b, wc_tower;
    sfText *blood_x;
    list_enemy *list_enemy, *list_enemy2, *list_enemy3, *list_enemy4;
    list_enemy *list_enemy5, *list_enemy6;
    list_tow_g *list_tow;
    Bool is_bar;
    sfSprite *life_bs, *life_bbs;
    all_cl cl;
    sfSprite *ennemy1;
    int e1, nb_enemy, nb_mecha, nb_mecha_rev, nb_jet, nb_car;
    sfSprite *logo_enemy, *load;
    sfText *nb_enemy_t;
    pause_t pause_menu;
    Bool power;
    one_cl cl_pow;
}sp_game;

typedef struct my_other {
    sfSprite *base_of;
    sfSprite *base_def;
    sfSprite *base_pv;
    sfSprite *select;
    Bool is_pop_up;
    float size;
    float size_max;
    float i;
    one_cl cl_pop;
}sp_other;

typedef struct sprites_g {
    sfSprite *cursor;
    sp_menu menu;
    sp_level level;
    sp_game game;
    sp_other other;
    sp_weap weapons;
    int life_tmp;
}sprites_s;

typedef struct info_player {
    char *save;
    char **tab;
    sfText *name;
    int base;
    int pl_base;
    int lvl;
    int tower;
    int coins;
}player;

typedef struct my_pop_up {
    float size;
    float size_max;
    float i;
    Bool is_pop;
    one_cl clock;
}pop_up_s;

typedef struct rect_menu {
    sfFloatRect play;
    sfFloatRect more;
    sfFloatRect close;
    sfFloatRect tutorial;
    sfFloatRect option;
    sfFloatRect p_resume;
    sfFloatRect p_exit;
    sfFloatRect p_save;
} rect;

typedef struct rect_col {
    sfFloatRect e1;
    sfFloatRect e1_1;
    sfFloatRect e2;
    sfFloatRect bullet1;
} rect_e;

typedef struct verif_struct {
    int verif_1;
    int verif_2;
    sfVector2f pos_1;
}verif_s;

typedef struct loose_game {
    sfSprite *bg;
    sfSprite *bg2;
    sfSprite *restart_bt;
    sfSprite *exit_bt;
    sfSprite *light;
}loose;

typedef struct win_game {
    sfSprite *bg;
    sfSprite *bg2;
    sfSprite *restart_bt;
    sfSprite *exit_bt;
    sfSprite *light;
}win;

typedef struct my_musics {
    sfMusic *music1;
    sfMusic *music2;
    sfMusic *music3;
    sfMusic *music4;
    sfMusic *music5;
    sfBool active;
}musics_s;

typedef struct my_sounds {
    sfSound *sound1;
    sfSound *sound2;
    sfSound *sound3;
    sfSound *sound4;
    sfSound *sound5;
    sfBool active;
}sounds_s;

typedef struct global_struct {
    sfRenderWindow *wind;
    int STATUS;
    musics_s musics;
    sounds_s sounds;
    all_cl cl;
    sprites_s sprite;
    sfEvent *event;
    player *info_p;
    rect *rect;
    rect_e *rect_e;
    verif_s verif;
    pop_up_s pop1, pop2, pop3;
    pop_up_s pop4, pop5, pop6, pop7, pop8, pop9, pop10;
    int level_played, c_ask, is_ask, fps_verif, j, x, v, i;
    char *ask, *ask_1;
    sfVector2i pos_mouse;
    int verif_dead, more, verif_save, verif_anim;
    int verif_l, verif_r, verif_r_bullet, verif_save_menu;
    float life;
    sfIntRect rect_life;
    loose loose;
    win win;
}global_s;

list_enemy *fill_enemy_2(global_s *all);
list_enemy *fill_enemy_3(global_s *all);
void refresh_life_base(global_s *all, int dmg);
list_tow_g *free_tow_at(list_tow_g *list, int pos);
list_enemy *modif_element2(list_enemy *list, one_cl clock, int e);
enemy_s get_enemy(list_enemy *list, int pos);
tow_g get_element4(list_tow_g *list, int pos);
char *my_strdup2(char const *str);
sfSprite *get_element(list_tow_g *list, int pos);
list_tow_g *create_cell(tow_g tower);
list_tow_g *add_tower(list_tow_g *list, tow_g tower, int pos);
list_enemy *add_enemy(list_enemy *list2, enemy_s enemy, int pos);
list_enemy *free_element_at(list_enemy *list, int pos);
void destroy_menu(global_s *all);
void destroy_menu2(global_s *all);
sfSprite *get_spt_en(list_enemy *list, int pos);
sfFloatRect rect_e1(global_s *all, sfSprite *spt);
sfFloatRect rect_e1_rev(global_s *all, sfSprite *spt);
sfFloatRect rect_e3(global_s *all, sfSprite *spt);
sfFloatRect rect_e4(global_s *all, sfSprite *spt);
list_enemy *fill_enemy_4(global_s *all);
void enemy4(global_s *all);
int anim_e1(one_cl *cl, int i, global_s *all, enemy_s *en);
int anim_e1_rev(one_cl *cl, int i, global_s *all, enemy_s *en);
int anim_e3(one_cl *cl, int i, global_s* all, enemy_s *en);
int anim_e4(one_cl *cl, int i, global_s* all, enemy_s *en);
sfRenderWindow *create_window(void);
sfText *ctS(char *str, int size, sfColor color, sfVector2f pos);
sfSprite *csS(const char *filename, int x, int y, v2f size);
tow_g choose_texture2(global_s *all, tow_g tow, sft *texture, v2f scale);
void create_all(global_s *all, char **av);
void my_init_menu(global_s *all);
void my_init_level(global_s *all);
void my_init_game(global_s *all);
void init_rect(global_s *all);
sfRenderWindow *create_window_1(int x, int y, int i);
one_cl create_one_clock(void);
all_cl create_clock(void);
void init_weapons(global_s *all);
list_enemy *create_enemy(enemy_s enemy);
list_enemy *add_enemy(list_enemy *list2, enemy_s enemy, int pos);
list_enemy *fill_enemy(global_s *all);
sp_menu create_spt_menu(void);
sp_menu create_sprites(void);
player *take_info(char **av, global_s *all);
void find_name(global_s *all);
void print_light(global_s *all);
sfSprite *choose_icon_level(sfSprite *sprite, int player_lvl, int states);
void game_level(global_s *all, int lvl);
void check_button_weap(global_s *all);
void choose_icons_level(global_s *all);
void my_draw_levels(global_s *all);
void check_mouse_icone(global_s *all);
void can_buy_weap(global_s *all, int wep);
void draw_menu_weap(global_s *all);
void enemy2(global_s *all);
sfIntRect create_rect(int top, int left, int width, int height);
int collision_e1(global_s *all, list_enemy *list, int r);
int collision_e1_rev(global_s *all, list_enemy *list, int r);
int collision_e3(global_s *all, list_enemy *list, int i);
int collision_e4(global_s *all, list_enemy *list, int i);
int dmg(int type, int base);
sfText *pv(float x, float y, list_enemy *list);
list_tow_g *modif_element(list_tow_g *list, int e, v2f pos, sfpt *spt, int t);
int list_len(list_tow_g *list);
int list_len_2(list_enemy *list);
void save_info(global_s *all);
void text_box(char *ask, global_s *all);
void restart_pop(pop_up_s *pop);
pop_up_s pop_up(global_s *all, float size_max, float i, sfSprite *sprite);
void draw_pop_up(sfSprite *sprite, global_s *all, pop_up_s *pop);
sfVector2f transform_vf(float x, float y);
void move_bg(sfSprite *spt, sfRenderWindow *wind, one_cl *cl, float w);
sfVector2f get_element3(list_tow_g *list, int pos);
void my_weapons(global_s *all);
void my_menu(global_s *all);
void bt_menu(global_s *all);
void draw_sprite_menu(global_s *all);
int more_bt(global_s *all);
void my_map(global_s *all);
void check_events(global_s *all);
void refresh_clock(global_s *all);
void more(global_s *all);
void more_bt_tutorial(global_s *all);
void more_bt_option(global_s *all);
void more_option(global_s *all);
int music_bt(global_s *all);
int sound_bt(global_s *all);
void draw_fps(global_s *all, char *i, char *k, char *l);
int verif_button(global_s *all, char **i);
void draw_more_option(global_s *all);
int more_bt_close(global_s *all);
void draw_more(global_s *all);
int play_bt(global_s *all);
void print_weap(global_s *all);
void check_wich_base(global_s *all);
void reset_texture_base(global_s *all);
int more_event(global_s *all);
void anim_klassico(tow_g *tow, global_s *all);
void anim_avocado(tow_g *tow, global_s *all);
void check_events_game(global_s *all);
void anim_stazz(tow_g *tow, global_s *all);
void anim_blaster(tow_g *tow, global_s *all);
void my_game(global_s *all);
void create_sprites_game(global_s *all);
list_tow_g *fill_list_tow(global_s *all);
void print_game(global_s *all);
void refresh_clocks(global_s *all);
void is_draw_wep(sfSprite *spt, int num, global_s *all);
void print_weapons(global_s *all);
void enemy(global_s *all);
void move_clouds(global_s *all);
list_enemy *fill_enemy_3_rev(global_s *all);
list_enemy *fill_enemy_4_rev(global_s *all);
sp_menu create_spt_menu2(sp_menu menu);
void print_weapons(global_s *all);
void check_place_weap(global_s *all);
int pause_game(global_s *all);
void detect_mecha(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test);
void detect_mecha_rev(global_s *all, enemy_s *bullet_l, tow_g *tow, int *t);
void detect_jet(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test);
void detect_car(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test);
void ask_name(global_s *all);
void create_choose_base(global_s *all);
void choose_base(global_s *all);
void check_choose_base(global_s *all);
void print_choose_base(global_s *all);
void is_ask(global_s *all);
int is_weap_unclock(global_s *all, int wp);
void create_weapons(global_s *all);
void refresh_clock_pop(global_s *all);
void check_events_map(global_s *all);
void check_events(global_s *all);
void draw_menu_parallax(global_s *all);
void anim_parallax(global_s *all);
void info_base(global_s *all);
void anim_button(global_s *all);
void enemy3(global_s *all);
void free_game(global_s *all);
sfFloatRect rect_e3_rev(global_s *all, sfSprite *spt);
void enemy3_rev(global_s *all);
int enemy3_rev_anim(global_s *all, list_enemy *list);
int anim_e3_rev(one_cl *cl, int i, global_s* all, enemy_s *en);
list_enemy *fill_enemy_3_rev(global_s *all);
void detect_jet_rev(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test);
list_enemy *fill_enemy_4_rev(global_s *all);
sfFloatRect rect_e4_rev(global_s *all, sfSprite *spt);
int anim_e4_rev(one_cl *cl, int i, global_s* all, enemy_s *en);
void enemy4_rev(global_s *all);
void detect_car_rev(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test);
sfMusic *init_music(char *str, int i, sfBool loop);
void draw_bg(global_s *all);
void draw_bg2(global_s *all);
void draw_bg3(global_s *all);
int exit_win_bt(global_s *all);
void destroy_menu(global_s *all);
void destroy_menu2(global_s *all);
void create_sprites_game3(global_s *all);
void create_sprites_game4(global_s *all);
void create_sprites_game5(global_s *all);
void create_sprites_game2(global_s *all);
sfFloatRect rect_e4_rev(global_s *all, sfSprite *spt);
void is_wep_draw(global_s *all);
void print_base_selected(global_s *all);
void print_weapons2(global_s *all, tow_g *tow);
void print_weapons3(global_s *all, tow_g *tow);
void print_weapons4(global_s *all, tow_g *tow, sfFloatRect rect, int i);
void print_weapons5(global_s *all, tow_g *tow, int i);
void choose_target(global_s *all, tow_g *tow);
void anim_fx_rev(enemy_s *enemy);
sfText *pv(float x, float y, list_enemy *list);
int dmg(int type, int base);
void anim_fx(enemy_s *enemy);
void init_list(global_s *all);
int pause_game(global_s *all);
void anim_klassico(tow_g *tow, global_s *all);
void anim_avocado(tow_g *tow, global_s *all);
void anim_stazz(tow_g *tow, global_s *all);
void anim_blaster(tow_g *tow, global_s *all);
void create_bullet_klassico(tow_g *tow, enemy_s t_bullet, global_s *all);
void create_bullet_avocado(tow_g *tow, enemy_s t_bullet, global_s *all);
void create_bullet_hunter(tow_g *tow, enemy_s t_bullet, global_s *all);
void create_bullet_blaster(tow_g *tow, enemy_s t_bullet, global_s *all);
void move_bullet(tow_g *tow, int len_bul, global_s *all);
void detect_car_rev(global_s *all, enemy_s *bullet_l, tow_g *tow, int *test);
int pause_resume(global_s *all);
void pause_draw(global_s *all);
int pause_exit(global_s *all);
int pause_save(global_s *all);
void init_pause_rect(global_s *all);
void event_close_opt(global_s *all);
void pause_menu_draw(global_s *all);
int pause_save_menu(global_s *all);
int pause_exit_menu(global_s *all);
void check_upgrade_base(global_s *all);
void loose_game(global_s *all);
sfVector2f transform_vf(float x, float y);
void check_mouse_icone(global_s *all);
void my_draw_levels2(global_s *all);
void my_draw_levels(global_s *all);
void choose_icone_anim(sfSprite *sprite, global_s *all, int lvl);
void info_update(global_s *all);
void draw_price_base(global_s *all);
void anim_move_e33(global_s *all, one_cl *cl, sfIntRect *rect, enemy_s *en);
void anim_move_e3_rev(global_s *all, one_cl *cl, sfBool is_rect, enemy_s *en);
void anim_move_e3(global_s *all, one_cl *cl, sfBool is_rect, enemy_s *en);
void anim_clock_e33(global_s *all, one_cl *cl, sfBool is_rect, enemy_s *en);
void check_death_e3(enemy_s *en, sfIntRect *rect, sfBool *is_rect);
int anim_e3(one_cl *cl, int i, global_s* all, enemy_s *en);
int anim_e3_rev(one_cl *cl, int i, global_s* all, enemy_s *en);
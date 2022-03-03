/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
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
#define csS create_spriteStocky

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
    int type;
    int life;
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
}tow_g;

typedef struct my_list_tower_game {
    struct my_list_tower_game *prev;
    tow_g tower;
    struct my_list_tower_game *next;
}list_tow_g;


typedef struct my_menu {
    sfSprite *bg_1;
    sfSprite *bg_2;
    sfSprite *bg_3;
    sfSprite *bg_4;
    sfSprite *bg_5;
    sfSprite *bg_6;
    sfSprite *bg_7;
    sfSprite *bg_8;
    sfSprite *menu;
    sfSprite *bt_1;
    sfSprite *bt_2;
    sfSprite *bt_close;
    sfSprite *bt_option;
    sfSprite *bt_tutorial;
    sfSprite *more_bg;
    sfSprite *more_bg2;
    sfSprite *more_bg3;
    sfSprite *more_bg4;
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

typedef struct my_game {
    sfSprite *bg;
    sfSprite *clouds;
    sfSprite *brume;
    sfSprite *tree;
    sfSprite *base;
    sfSprite *road;
    sfSprite *tower_1;
    sfSprite *tower_2;
    sfSprite *tower_3;
    sfSprite *tower_4;
    sfSprite *tower_5;
    sfSprite *add_weap;
    int blood;
    sfSprite *blood_s;
    sfText *blood_x;
    list_enemy *list_enemy;
    list_enemy *list_enemy2;
    list_tow_g *list_tow;
    Bool is_bar;
    int wc_tower;
    all_cl cl;
    sfSprite *ennemy1;
    int e1;
    sfSprite *load;
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
    sp_menu menu;
    sp_level level;
    sp_game game;
    sp_other other;
    sp_weap weapons;
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
} rect;

typedef struct rect_col {
    sfFloatRect e1;
    sfFloatRect e1_1;
    sfFloatRect bullet1;
} rect_e;

typedef struct verif_struct {
    int verif_1;
    int verif_2;
    sfVector2f pos_1;
}verif_s;

typedef struct global_struct {
    sfRenderWindow *wind;
    int STATUS;
    all_cl cl;
    sprites_s sprite;
    sfEvent *event;
    player *info_p;
    rect *rect;
    rect_e *rect_e;
    verif_s verif;
    pop_up_s pop1;
    pop_up_s pop2;
    pop_up_s pop3;
    pop_up_s pop4;
    pop_up_s pop5;
    pop_up_s pop6;
    pop_up_s pop7;
    pop_up_s pop8;
    int level_played;
    char *ask;
    char *ask_1;
    int c_ask;
    int is_ask;
    int fps_verif;
    sfVector2i pos_mouse;
}global_s;

//FUNC LIST
list_enemy *fill_enemy_2(global_s *all);
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

// INITIALISATION
sfRenderWindow *create_window(void);
sfText* create_textStocky(char const *str, int size, sfColor color, float x, float y);
sfSprite* create_spriteStocky(const char* filename, int x, int y, sfVector2f size);
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

// UTILITAIRES
list_tow_g *modif_element(list_tow_g *list, int e, sfVector2f pos, sfSprite *spt, int type);
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

// MENU
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

// GAME
void anim_klassico(tow_g *tow);
void anim_avocado(tow_g *tow);
void anim_stazz(tow_g *tow);
void anim_blaster(tow_g *tow);
void my_game(global_s *all);

// NEW USER
void ask_name(global_s *all);
void create_choose_base(global_s *all);
void choose_base(global_s *all);
void check_choose_base(global_s *all);
void print_choose_base(global_s *all);
void is_ask(global_s *all);

// OTHERS
int is_weap_unclock(global_s *all, int wp);
void create_weapons(global_s *all);
void refresh_clock_pop(global_s *all);
void check_events_map(global_s *all);
void check_events(global_s *all);
void draw_menu_parallax(global_s *all);
void anim_parallax(global_s *all);
void anim_button(global_s *all);

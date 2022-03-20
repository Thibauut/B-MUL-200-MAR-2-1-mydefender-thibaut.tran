##
## EPITECH PROJECT, 2021
## B-MUL-200-MAR-2-1-mydefender-thibaut.tran
## File description:
## Makefile
##

SRC 	= 	src/create_struct.c				\
			src/create_struct2.c			\
			src/create_struct3.c			\
			src/func_lib.c					\
			src/func_lib2.c					\
			src/func_lib3.c					\
			src/load_save.c					\
			src/text_box.c					\
			src/pop_up.c					\
			src/my_func_link_list.c			\
			src/my_func_link_list2.c		\
			src/my_func_link_list3.c		\
			src/my_func_link_list4.c		\
			src/save_info.c					\
			src/new_player/base_select.c	\
			src/new_player/base_p.c			\
			src/new_player/ch_bs.c			\
			src/find_info.c					\
			src/new_player/ch_name.c		\
			menu/anim_background.c			\
			menu/my_menu1.c					\
			menu/my_menu2.c					\
			menu/my_menu3.c					\
			menu/my_menu4.c					\
			menu/my_menu5.c					\
			menu/my_menu6.c					\
			menu/bt_menu.c					\
			menu/can_buy_weap.c				\
			menu/init_weap.c				\
			menu/my_settings1.c				\
			menu/my_settings2.c				\
			menu/destroy_menu.c				\
			menu/my_settings3.c				\
			menu/my_settings4.c				\
			menu/menu_weap.c				\
			menu/clock_menu.c				\
			game/init_my_game.c				\
			game/init_my_game2.c			\
			game/init_my_game3.c			\
			game/init_my_game4.c			\
			game/add_weapons.c				\
			game/anim_weapons.c				\
			game/anim_weapons2.c			\
			game/fill_list_game.c			\
			game/fill_list_game2.c			\
			game/create_spt_game.c			\
			game/check_place_weap.c			\
			game/print_game.c				\
			game/print_game2.c				\
			game/print_game3.c				\
			game/clock_game.c				\
			game/bg_game.c					\
			src/free_game.c					\
			game/print_weapons.c			\
			game/place_good_base.c			\
			game/print_weapons2.c			\
			game/print_weapons3.c			\
			game/check_event_game.c 		\
			game/rect_collision.c			\
			game/rect_collision2.c			\
			game/anim_enemy.c				\
			game/anim_enemy2.c				\
			game/collision_enemy.c			\
			game/collision_enemy2.c			\
			game/pause_game.c				\
			game/pause_game2.c				\
			game/loose_game.c				\
			my_defender.c

CFLAGS = -Wno-deprecated-declarations

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

all	:	$(NAME)	$(SRC)

$(NAME)	:	$(OBJ)
	gcc $(CFLAGS)	$(SRC)	-o	$(NAME)	-I/usr/local/include/	-L/usr/local/	-lcsfml-graphics	-lcsfml-window	-lcsfml-audio	-lcsfml-system

clean :
	rm	-f	$(OBJ)

fclean :
	rm	-f	$(NAME)

re :	fclean	all	clean
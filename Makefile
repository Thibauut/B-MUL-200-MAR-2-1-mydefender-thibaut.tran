##
## EPITECH PROJECT, 2021
## Visual Studio Live Share (Workspace)
## File description:
## Makefile
##

SRC 	= 	src/create_struct.c		\
			src/func_lib.c			\
			src/func_lib2.c			\
			src/load_save.c			\
			src/text_box.c			\
			src/pop_up.c			\
			src/my_func_link_list.c	\
			src/save_info.c			\
			src/new_player/base_p.c	\
			src/new_player/ch_bs.c	\
			src/new_player/ch_name.c\
			menu/anim_background.c	\
			menu/my_menu1.c			\
			menu/my_menu2.c			\
			menu/bt_menu.c			\
			menu/my_settings1.c		\
			menu/my_settings2.c		\
			menu/my_settings3.c		\
			menu/menu_weap.c		\
			menu/clock_menu.c		\
			game/init_my_game.c		\
			game/add_weapons.c		\
			game/anim_weapons.c		\
			my_defender.c

CFLAGS = -Wno-deprecated-declarations

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

all	:	$(NAME)	$(SRC)

$(NAME)	:	$(OBJ)
	gcc $(CFLAGS)	$(SRC)	-o	$(NAME)	-I/usr/local/include/	-L/usr/local/	-lcsfml-graphics	-lcsfml-window	-lcsfml-audio	-lcsfml-system

clean :
	rm	-f	*.o
	rm	-f	*~
	rm	-f	src/*.o
	rm	-f	menu/*.o
	rm	-f	game/*.o
	rm	-f	src/new_player/*.o

fclean :
	rm	-f	$(NAME)

re :	fclean	all	clean
/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_settings1.c
*/

#include "../include/func.h"
#include "../include/struct.h"
#include "../include/my.h"

char **fill_act(void)
{
    char **tab = malloc(sizeof(char *) * 4);
    tab[0] = my_itoa(30);
    tab[1] = my_itoa(60);
    tab[2] = my_itoa(120);
    tab[3] = 0;
    return (tab);
}

char **fill_act2(void)
{
    char **tab = malloc(sizeof(char *) * 3);
    tab[0] = "ON";
    tab[1] = "OFF";
    tab[2] = 0;
    return (tab);
}

int verif_button(global_s *all, char **i)
{
    sfFloatRect rm = sfSprite_getGlobalBounds(all->sprite.menu.bt_left);
    sfFloatRect rm2 = sfSprite_getGlobalBounds(all->sprite.menu.bt_right);
    sfVector2i m = sfMouse_getPositionRenderWindow(all->wind);
    if(all->event->type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&rm, m.x, m.y))
            return (1);
        if (sfFloatRect_contains(&rm2, m.x, m.y)) {
            all->fps_verif += 1;
            if (all->fps_verif > 1)
                return (3);
            return (2);
        }
    }
    return (0);
}

void draw_fps(global_s *all, char *i, char *k, char *l)
{
    char *cfps = i, *sound = k, *musicc = l;
    sfVector2f move = {900, 325}, move2 = {900, 430}, move3 = {900, 530};
    sfText *fps = create_textStocky(cfps, 100, sfBlack, 910, 325);
    if (my_strlen(cfps) > 2)
        sfText_setPosition(fps, move);
    sfText *audio = create_textStocky(sound, 100, sfBlack, 910, 430);
    if (my_strlen(sound) > 2)
        sfText_setPosition(audio, move2);
    sfText *music = create_textStocky(musicc, 100, sfBlack, 910, 530);
    if (my_strlen(musicc) > 2)
        sfText_setPosition(music, move3);
    sfText *opt = create_textStocky("FPS :", 100, sfBlack, 300, 330);
    sfText *opt2 = create_textStocky("SOUND :", 100, sfBlack, 300, 430);
    sfText *opt3 = create_textStocky("MUSIC :", 100, sfBlack, 300, 530);
    sfRenderWindow_drawText(all->wind, fps, NULL);
    sfRenderWindow_drawText(all->wind, audio, NULL);
    sfRenderWindow_drawText(all->wind, music, NULL);
    sfRenderWindow_drawText(all->wind, opt, NULL);
    sfRenderWindow_drawText(all->wind, opt2, NULL);
    sfRenderWindow_drawText(all->wind, opt3, NULL);
}

int fps_checker(int y, int j)
{
    if (y == 1) {
        if (j != 0)
            j -= 1;
        return (j);
    }
    if (y == 2) {
        if (j != 1)
            j += 1;
        return (j);
    }
    if (y == 3) {
        if (j != 2)
            j += 1;
        return (j);
    }
    return (j);
}
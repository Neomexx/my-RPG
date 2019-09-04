/*
** EPITECH PROJECT, 2017
** display_window
** File description:
** Desc
*/

#include "struct_rpg.h"

void	display_window(t_window *window)
{
	sfRenderWindow_display(window->window);
	sfRenderWindow_clear(window->window, sfBlack);
}

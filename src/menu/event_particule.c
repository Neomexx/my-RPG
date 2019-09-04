/*
** EPITECH PROJECT, 2017
** event_particule
** File description:
** Desc
*/

#include "menu.h"

void	event_blow(t_window *window)
{
	sfEvent click;

	while (sfRenderWindow_pollEvent(window->window, &click)) {
		if (click.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
	}
}

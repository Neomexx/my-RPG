/*
** EPITECH PROJECT, 2017
** credit
** File description:
** Desc
*/

#include "credit.h"
#include <stdlib.h>

#include <stdio.h>

void	set_next(t_credit *credit, int *i, int *y, int *count)
{
	sfVector2f	pos;

	pos = sfSprite_getPosition(credit[*i].sprite);
	if (*count == 1) {
		sfSprite_move(credit[*y].sprite, credit[*y].move);
		sfSprite_move(credit[*i].sprite, credit[*i].move);
	}
	if (pos.x >= credit[*i].pos.x && *count == 1) {
		*count = 0;
		(*i)++;
		(*y)++;
	}
}

void	moving_credit(t_credit *credit, int *i, int *y)
{
	sfVector2f	pos;
	static int	count = 0;

	pos = sfSprite_getPosition(credit[*i].sprite);
	if (pos.x >= credit[*i].pause.x && count == 0) {
		sfSprite_move(credit[*i].sprite, credit[*i].move);
		sfSprite_move(credit[*y].sprite, credit[*y].move);
	} else {
		credit[*i].move.x = 3;
		credit[*y].move.x = -3;
		count = 1;
	}
	set_next(credit, i, y, &count);
}

void	credit(t_window *window)
{
	t_credit	credit[12];
	sfEvent	event;
	int		i = 1;
	int		y = 7;

	set_credit(credit);
	while (sfRenderWindow_isOpen(window->window) && i < 6) {
		sfRenderWindow_drawSprite(window->window,
					credit[0].sprite, NULL);
		sfRenderWindow_drawSprite(window->window,
						credit[i].sprite, NULL);
		sfRenderWindow_drawSprite(window->window,
					credit[y].sprite, NULL);
		moving_credit(credit, &i, &y);
		while (sfRenderWindow_pollEvent(window->window, &event))
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window->window);
		display_window(window);
	}
}

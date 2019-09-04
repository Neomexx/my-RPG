/*
** EPITECH PROJECT, 2017
** print_inventory
** File description:
** Desc
*/

#include "struct_rpg.h"

void	check_inventory(t_window *window, sfEvent *event)
{
	if (event->type == sfEvtKeyReleased && event->key.code == sfKeyI
		&& window->inv[0].visible == 0) {
		window->inv[0].visible = 1;
	} else if (event->type == sfEvtKeyReleased && event->key.code == sfKeyI
		&& window->inv[0].visible == 1) {
		window->inv[0].visible = 0;
	}
}

void	print_inventory(t_window *window)
{
	if (window->inv[0].visible == 1) {
		for (int i = 0; i < 4; i++) {
			if (window->inv[i].visible == 1) {
				sfRenderWindow_drawSprite(window->window,
						window->inv[i].sprite, NULL);
			}
		}
	}
}

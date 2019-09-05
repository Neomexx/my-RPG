/*
** EPITECH PROJECT, 2017
** print_inventory
** File description:
** Desc
*/

#include "inventory.h"

void	check_inventory(inventory_t *inv)
{
	if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue
		&& inv[0].visible = 0) {
		inv[0].visible == 1;
	} else if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue
		&& inv[0].visible = 1) {
		inv[0].visible == 0;
	}
}

void	print_inventory(t_window *window, inventory_t *inv)
{
	if (inv[0].visible == 1) {
		for (int i = 0; i < 4; i++) {
			if (inv[i].visible == 1) {
				sfRenderwindow_drawSprite(window->window,
						inv[i].sprite);
			}
		}
	}
}

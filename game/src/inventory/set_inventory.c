/*
** EPITECH PROJECT, 2017
** set_inventory
** File description:
** Desc
*/

#include "my.h"
#include "struct_rpg.h"

void	set_inventory(t_window *window)
{
	char	*str = "image/inventory.png";

	for (int i = 0; i < 4; i++)
		window->inv[i].texture = sfTexture_createFromFile(str, NULL);
	for (int i = 0; i < 4; i++) {
		window->inv[i].sprite = sfSprite_create();
		sfSprite_setTexture(window->inv[i].sprite,
					window->inv[i].texture, sfTrue);
		window->inv[i].pos = pos_inv[i];
		window->inv[i].rect = rect_inv[i];
		sfSprite_setTextureRect(window->inv[i].sprite,
					window->inv[i].rect);
		sfSprite_setPosition(window->inv[i].sprite, window->inv[i].pos);
		window->inv[i].visible = 0;
	}
}

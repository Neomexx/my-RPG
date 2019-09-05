/*
** EPITECH PROJECT, 2017
** set_buffer_particule
** File description:
** Desc
*/

#include <string.h>
#include <stdlib.h>
#include "particule.h"

void	newPartBuffer(int size, t_particule *this)
{
	const	size_t	size_m = (sizeof(t_particule)
			+ sizeof(sfVertex) * size * 4
			+ sizeof(t_info) * size);
	void	*pnt = malloc(size_m);

	if (pnt == NULL) {
		this->texCoords.x = -1;
		return;
	}
	memset(pnt, 0, size_m);
	this->size = size;
	this->vertex = (sfVertex*)(pnt + sizeof(t_particule));
	this->info = (t_info*)(this->vertex + (size * 4));
}

void	setPart(t_particule *this, uint id, sfVector2f pos, sfColor color)
{
	if (id >= this->size)
		return;
	this->vertex[(id * 4) + 0].position =
		(sfVector2f){pos.x - 0, pos.y - 0};
	this->vertex[(id * 4) + 1].position =
		(sfVector2f){pos.x - 4, pos.y - 0};
	this->vertex[(id * 4) + 2].position =
		(sfVector2f){pos.x - 4, pos.y - 4};
	this->vertex[(id * 4) + 3].position =
		(sfVector2f){pos.x - 0, pos.y - 4};
	this->vertex[(id * 4) + 0].color = color;
	this->vertex[(id * 4) + 1].color = color;
	this->vertex[(id * 4) + 2].color = color;
	this->vertex[(id * 4) + 3].color = color;
	this->info[id].life = 1.0;
}

void	drawPartBufer(t_particule *this, t_window *window,
		menu_t *menu, menu_text_t *text)
{
	if (menu[1].visible == 1)
		sfRenderWindow_drawSprite(window->window, menu[1].sprite, NULL);
	if (menu[2].visible == 1)
		sfRenderWindow_drawSprite(window->window, menu[2].sprite, NULL);
	if (menu[0].visible == 1)
		sfRenderWindow_drawSprite(window->window, menu[0].sprite, NULL);
	else {
		for (int i = 0; i < 4; i++)
			sfRenderWindow_drawText(window->window,
					text[i].text, NULL);
	}
	sfRenderWindow_drawPrimitives(window->window,
			this->vertex, this->size * 4, sfQuads, NULL);
}

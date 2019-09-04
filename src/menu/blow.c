/*
** EPITECH PROJECT, 2017
** blow
** File description:
** Desc
*/

#include "particule.h"
#include <string.h>
#include <stdlib.h>

static int	init(t_window *window, t_particule *buffer)
{
	sfRenderWindow_setFramerateLimit(window->window, 120);
	for (int i = 0; i < 7; i++) {
		buffer[i].texCoords.x = 0;
		newPartBuffer(200000, &buffer[i]);
		if (buffer[i].texCoords.x == -1)
			return (0);
	}
	for (uint i = 0; i <= 1500; i++) {
		for (int y = 0; y < 7; y++)
		setPart(&buffer[y], i,
			(sfVector2f){rand() % 4000, rand() % 2400},
			(sfColor){255, 211, 155, 80});
	}
	return (1);
}

static void	speed_particule(t_particule *this, uint id)
{
	this->info[id].speed.x = (rand() % 255) / 10;
	this->info[id].speed.y = (rand() % 255) / 20;
	this->vertex[(id * 4) + 0].position.x -= this->info[id].speed.x;
	this->vertex[(id * 4) + 0].position.y -= this->info[id].speed.y;
	this->vertex[(id * 4) + 1].position.x += this->info[id].speed.x;
	this->vertex[(id * 4) + 1].position.y -= this->info[id].speed.y;
	this->vertex[(id * 4) + 2].position.x -= this->info[id].speed.x;
	this->vertex[(id * 4) + 2].position.y -= this->info[id].speed.y;
	this->vertex[(id * 4) + 3].position.x -= this->info[id].speed.x;
	this->vertex[(id * 4) + 3].position.y -= this->info[id].speed.y;
}

static void	set_alpha_particule(t_particule *this, uint id)
{
	if (this->vertex[(id * 4) + 0].color.a > 0) {
		if (rand() % 50 <= 15)
			this->vertex[(id * 4) + 0].color.a -= 2;
	}
	if (this->vertex[(id * 4) + 1].color.a > 0) {
		if (rand() % 50 <= 15)
			this->vertex[(id * 4) + 1].color.a -= 2;
	}
	if (this->vertex[(id * 4) + 2].color.a > 0) {
		if (rand() % 50 <= 15)
			this->vertex[(id * 4) + 2].color.a -= 2;
	}
	if (this->vertex[(id * 4) + 3].color.a > 0) {
		if (rand() % 50 <= 15)
			this->vertex[(id * 4) + 3].color.a -= 2;
	}
}

static void	update(t_window *window, menu_t *menu, menu_text_t *text,
		t_particule *buffer)
{
	sfRenderWindow_clear(window->window, sfBlack);
	for (int i = 0; i < 7; i++) {
		for (uint id = 0; id < buffer[i].size; id++) {
			if (buffer[i].info[id].life <= 0)
				continue;
			buffer[i].info[id].life -= 1.0/140.0;
			if (buffer[i].info[id].life <= 0) {
				memset(buffer[i].vertex + (id * 4), 0,
					sizeof(sfVertex) * 4);
				continue;
			}
			speed_particule(&buffer[i], id);
			set_alpha_particule(&buffer[i], id);
		}
		drawPartBufer(&buffer[i], window, menu, text);
	}
	sfRenderWindow_display(window->window);
}

void	blow(t_window *window, menu_t *menu)
{
	t_particule	buffer[7];

	if (init(window, buffer) == 0)
		return;
	while (buffer[0].info[0].life >= 0
		&& sfRenderWindow_isOpen(window->window)) {
		event_blow(window);
		update(window, menu, menu->text, buffer);
		for (int i = 0; i < 4; i++) {
			if (menu->text[0].alpha < 255) {
				menu->text[i].alpha += 3;
				menu->text[i].color = sfColor_fromRGBA(255, 255,
							0, menu->text[i].alpha);
				sfText_setColor(menu->text[i].text,
						menu->text[i].color);
			}
		}
	}
}

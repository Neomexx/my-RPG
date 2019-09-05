/*
** EPITECH PROJECT, 2017
** dust
** File description:
** Desc
*/

#include "particule.h"
#include <string.h>
#include <stdlib.h>

static int	init(t_window *window, t_particule *buffer)
{
	buffer[0].texCoords.x = 0;
	buffer[1].texCoords.x = 0;
	sfRenderWindow_setFramerateLimit(window->window, 120);
	for (int i = 0; i < 2; i++)
		newPartBuffer(90000, &buffer[i]);
	for (int i = 2; i < 5; i++)
		newPartBuffer(150000, &buffer[i]);
	if (buffer[0].texCoords.x == -1 || buffer[1].texCoords.x == -1)
		return (0);
	for (uint i = 0; i <= 1500; i++) {
		for (int y = 0; y < 2; y++)
			setPart(&buffer[y], i,
			(sfVector2f){rand() % 20 + 500, rand() % 700 + 150},
			(sfColor){200, 200, 200, rand() % 60});
		for (int y = 2; y < 5; y++)
			setPart(&buffer[y], i,
			(sfVector2f){rand() % 500, rand() % 1000},
			(sfColor){200, 200, 200, rand() % 100});
	}
	return (1);
}

static void	speed_particule(t_particule *this, uint id)
{
	this->info[id].speed.x = (rand() % 255) / 150;
	this->info[id].speed.y = (rand() % 255) / 200;
	this->vertex[(id * 4) + 0].position.x -= this->info[id].speed.x;
	this->vertex[(id * 4) + 0].position.y -= this->info[id].speed.y;
	this->vertex[(id * 4) + 1].position.x -= this->info[id].speed.x;
	this->vertex[(id * 4) + 1].position.y -= this->info[id].speed.y;
	this->vertex[(id * 4) + 2].position.x -= this->info[id].speed.x;
	this->vertex[(id * 4) + 2].position.y -= this->info[id].speed.y;
	this->vertex[(id * 4) + 3].position.x -= this->info[id].speed.x;
	this->vertex[(id * 4) + 3].position.y -= this->info[id].speed.y;
}

static void	set_alpha_particule(t_particule *this, uint id)
{
	if (this->vertex[(id * 4) + 0].color.a > 0) {
		if (rand() % 50 <= 10)
			this->vertex[(id * 4) + 0].color.a -= 1;
	}
	if (this->vertex[(id * 4) + 1].color.a > 0) {
		if (rand() % 50 <= 10)
			this->vertex[(id * 4) + 1].color.a -= 1;
	}
	if (this->vertex[(id * 4) + 2].color.a > 0) {
		if(rand() % 50 <= 10)
			this->vertex[(id * 4) + 2].color.a -= 1;
	}
	if (this->vertex[(id * 4) + 3].color.a > 0) {
		if (rand() % 50 <= 10)
			this->vertex[(id * 4) + 3].color.a -= 1;
	}
}

void	update_dust(t_window *window, menu_t *menu, menu_text_t *text,
		t_particule *buffer)
{
	sfRenderWindow_clear(window->window, sfBlack);
	for (int i = 0; i < 5; i++) {
		for (uint id = 0; id < buffer[i].size; id++) {
			if (buffer[i].info[id].life <= 0)
				continue;
			buffer[i].info[id].life -= 1.0/170.0;
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
	if (buffer[0].info[0].life <= 0)
		menu[1].particule = 0;
}

t_particule	*open_book(t_window *window, t_particule *buffer)
{
	if (init(window, buffer) == 0)
		return (NULL);
	return (buffer);
}

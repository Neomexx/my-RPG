/*
** EPITECH PROJECT, 2017
** particule
** File description:
** Desc
*/

#ifndef	PARTICULE_H
#define	PARTICULE_H

#include "my.h"
#include "struct_rpg.h"
#include "menu.h"

typedef	unsigned int uint;

typedef	struct	s_info
{
	sfVector2f	speed;
	float		life;
}		t_info;

typedef	struct	s_particule
{
	sfVertex	*vertex;
	t_info		*info;
	uint		size;
	sfVector2f	texCoords;
}		t_particule;

void	newPartBuffer(int size, t_particule *this);
void		setPart(t_particule *buffer, uint id, sfVector2f pos,
		sfColor color);
void		drawPartBufer(t_particule *buffer, t_window *window,
		menu_t *menu, menu_text_t *text);
void		update_dust(t_window *window, menu_t *menu, menu_text_t *text,
		t_particule *buffer);
t_particule	*open_book(t_window *window, t_particule *buffer);
void event_menu(t_window *window, menu_t *menu, t_particule *buffer);
void event_text(t_window *window, menu_t *menu, menu_text_t *text);

#endif

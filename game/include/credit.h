/*
** EPITECH PROJECT, 2017
** credit
** File description:
** Desc
*/

#ifndef CREDIT_H
#define CREDIT_H

#include "struct_rpg.h"

extern	const	char		*texture_credit[6];
extern	const	sfVector2f	pos_credit[12];
extern	const	sfVector2f	pos_pause[6];
extern	const	sfIntRect	rect_credit[6];

typedef	struct	s_credit
{
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVector2f	pos;
	sfVector2f	pause;
	sfVector2f	move;
	sfIntRect	rect;
}		t_credit;

void	set_credit(t_credit *credit);
void credit(t_window *window);

#endif

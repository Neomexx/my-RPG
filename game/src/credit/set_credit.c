/*
** EPITECH PROJECT, 2017
** set_credit
** File description:
** Desc
*/

#include "credit.h"

void	set_photo(t_credit *credit, int i)
{
	for (int y = 1; i < 12; i++, y++) {
		credit[i].texture = sfTexture_createFromFile(texture_credit[y],
								NULL);
		credit[i].sprite = sfSprite_create();
		sfSprite_setTexture(credit[i].sprite,
					credit[i].texture, sfTrue);
		credit[i].pos = pos_credit[i];
		sfSprite_setPosition(credit[i].sprite, credit[i].pos);
		credit[i].move = (sfVector2f){0.6, 0};
	}
}

void	set_credit(t_credit *credit)
{
	int i = 0;

	for (i = 0; i < 7; i++) {
		credit[i].texture = sfTexture_createFromFile(texture_credit[0],
								NULL);
		credit[i].sprite = sfSprite_create();
		sfSprite_setTexture(credit[i].sprite,
					credit[i].texture, sfTrue);
		credit[i].pause = pos_pause[i];
		credit[i].pos = pos_credit[i];
		sfSprite_setPosition(credit[i].sprite, credit[i].pos);
		credit[i].move = (sfVector2f){-0.5, 0};
		sfSprite_setTextureRect(credit[i].sprite, rect_credit[i]);
	}
	set_photo(credit, i);
}

/*
** EPITECH PROJECT, 2017
** defence
** File description:
** Desc
*/

#include "fight.h"

void	defence(t_fight *fight, t_select *select, t_window *window)
{
	if (select[0].specifics == 1)
		fight[10].bonus = (5 + window->defence);
	if (select[0].specifics == 2)
		fight[10].bonus = (12 + window->defence);
	if (select[0].specifics == 3)
		fight[10].bonus = (20 + window->defence);
	waiting(fight, window, select);
	moving_ennemy(fight, window);
	sfSprite_setPosition(fight[5].sprite, fight[5].pos_def);
	damage(fight, window);
	fight[7].rect_fight.width -= (window->attack_ennemy - fight[10].bonus);
	sfSprite_setTextureRect(fight[7].sprite, fight[7].rect_fight);
	waiting(fight, window, select);
	fight[10].bonus = 0;
	select[0].visible = 0;
	select[0].specifics = 1;
	select[0].select = 1;
	sfSprite_setPosition(fight[3].sprite, fight[3].pos_attack);
	sfSprite_setPosition(fight[4].sprite, fight[4].pos_attack);
}

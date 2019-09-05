/*
** EPITECH PROJECT, 2017
** select_attack_def_bonus
** File description:
** Desc
*/

#include "fight.h"

void	select_upper(t_fight *fight, t_select *select)
{
	sfVector2f	pos = sfSprite_getPosition(fight[3].sprite);

	if (pos.y == fight[3].pos_def.y) {
		sfSprite_setPosition(fight[3].sprite, fight[3].pos_attack);
		sfSprite_setPosition(fight[4].sprite, fight[4].pos_attack);
		sfSprite_setPosition(select[0].sprite, select[0].attack_bot);
		select[0].select = 1;
	}
	if (pos.y == fight[3].pos_bonus.y) {
		sfSprite_setPosition(fight[3].sprite, fight[3].pos_def);
		sfSprite_setPosition(fight[4].sprite, fight[4].pos_def);
		sfSprite_setPosition(select[0].sprite, select[0].def_bot);
		select[0].select = 2;
	}
}

void	select_bottom(t_fight *fight, t_select *select)
{
	sfVector2f	pos = sfSprite_getPosition(fight[3].sprite);

	if (pos.y == fight[3].pos_attack.y) {
		sfSprite_setPosition(fight[3].sprite, fight[3].pos_def);
		sfSprite_setPosition(fight[4].sprite, fight[4].pos_def);
		sfSprite_setPosition(select[0].sprite, select[0].def_bot);
		select[0].select = 2;
	}
	if (pos.y == fight[3].pos_def.y) {
		sfSprite_setPosition(fight[3].sprite, fight[3].pos_bonus);
		sfSprite_setPosition(fight[4].sprite, fight[4].pos_bonus);
		sfSprite_setPosition(select[0].sprite, select[0].bonus_bot);
		select[0].select = 3;
	}
}

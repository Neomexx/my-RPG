/*
** EPITECH PROJECT, 2017
** select_specific
** File description:
** Desc
*/

#include "fight.h"

void	select_specific_upper(t_fight *fight, t_select *select)
{
	sfVector2f	pos_select = sfSprite_getPosition(select[0].sprite);
	sfVector2f	pos_fight = sfSprite_getPosition(fight[4].sprite);
	sfVector2f	new_pos = sfSprite_getPosition(select[0].sprite);

	new_pos.y -= 20;
	select[0].specifics += 1;
	if (pos_select.y > select[0].attack_top.y
		&& pos_fight.y == fight[4].pos_attack.y)
		sfSprite_setPosition(select[0].sprite, new_pos);
	if (pos_select.y > select[0].def_top.y
		&& pos_fight.y == fight[4].pos_def.y)
		sfSprite_setPosition(select[0].sprite, new_pos);
	if (pos_select.y > select[0].bonus_top.y
		&& pos_fight.y == fight[4].pos_bonus.y)
		sfSprite_setPosition(select[0].sprite, new_pos);
}

void	select_specific_bottom(t_fight *fight, t_select *select)
{
	sfVector2f	pos_select = sfSprite_getPosition(select[0].sprite);
	sfVector2f	pos_fight = sfSprite_getPosition(fight[4].sprite);
	sfVector2f	new_pos = sfSprite_getPosition(select[0].sprite);

	new_pos.y += 20;
	select[0].specifics -= 1;
	if (pos_select.y < select[0].attack_bot.y
		&& pos_fight.y == fight[4].pos_attack.y)
		sfSprite_setPosition(select[0].sprite, new_pos);
	if (pos_select.y < select[0].def_bot.y
		&& pos_fight.y == fight[4].pos_def.y)
		sfSprite_setPosition(select[0].sprite, new_pos);
	if (pos_select.y < select[0].bonus_bot.y
		&& pos_fight.y == fight[4].pos_bonus.y)
		sfSprite_setPosition(select[0].sprite, new_pos);
}

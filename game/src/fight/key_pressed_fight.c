/*
** EPITECH PROJECT, 2017
** key_pressed
** File description:
** Desc
*/

#include "fight.h"

void	key_down(t_fight *fight, t_select *select)
{
	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue
		&& select[0].i == 0)
		select_bottom(fight, select);
	else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue
		&& select[0].i != 0)
		select_specific_bottom(fight, select);
}

void	key_up(t_fight *fight, t_select *select)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue
		&& select[0].i == 0)
		select_upper(fight, select);
	else if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue
		&& select[0].i != 0)
		select_specific_upper(fight, select);
}

void	key_ok(t_fight *fight, t_select *select, t_window *window, wait_t *wait)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue
		&& select[0].i != 0 && select[0].select == 1) {
		check_attack(fight, select, window, wait);
	}
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue
		&& select[0].i != 0 && select[0].select == 2) {
		check_defence(fight, select, window, wait);
	}
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue
		&& select[0].i != 0 && select[0].select == 3) {
		check_help(fight, select, wait);
		sfSprite_setPosition(fight[3].sprite, fight[3].pos_bonus);
		sfSprite_setPosition(fight[4].sprite, fight[4].pos_bonus);
	}
}

void	select_right_left(t_select *select)
{
	if (select[0].select == 1)
		sfSprite_setPosition(select[0].sprite,
				select[0].attack_bot);
	if (select[0].select == 2)
		sfSprite_setPosition(select[0].sprite,
				select[0].def_bot);
	if (select[0].select == 3)
		sfSprite_setPosition(select[0].sprite,
				select[0].bonus_bot);
}

void	key_right_left(t_fight *fight, t_select *select, sfEvent event)
{
	if (event.type == sfEvtKeyReleased
		&& (event.key.code == sfKeyReturn
		|| event.key.code == sfKeyRight)
		&& select[0].i == 0) {
		select[0].i = 1;
		select[0].visible = 1;
	}
	if (event.type == sfEvtKeyReleased
		&& (event.key.code == sfKeyBack
		|| event.key.code == sfKeyLeft)
		&& select[0].i != 0) {
		select[0].i = 0;
		select[0].visible = 0;
		select[0].specifics = 1;
		sfSprite_setPosition(fight[2].sprite, fight[2].pos_def);
		select_right_left(select);
	}
}

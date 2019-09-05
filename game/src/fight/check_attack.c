/*
** EPITECH PROJECT, 2017
** check_attack
** File description:
** Desc
*/

#include "fight.h"

void	check_last_attack(t_fight *fight, t_select *select, t_window *window,
		wait_t *wait)
{
	if (select[0].specifics == 3 && wait[0].laps == 0) {
		set_laps(wait, select);
		moving_fighter(fight, window, select);
		sfSprite_setPosition(fight[2].sprite, fight[2].pos_def);
		sfSprite_setPosition(select[0].sprite, select[0].attack_bot);
		fight[11].bonus = 0;
	}
}

void	check_attack(t_fight *fight, t_select *select, t_window *window,
		wait_t *wait)
{
	if (select[0].specifics == 1 && wait[2].laps == 0) {
		set_laps(wait, select);
		moving_fighter(fight, window, select);
		sfSprite_setPosition(fight[2].sprite, fight[2].pos_def);
		sfSprite_setPosition(select[0].sprite, select[0].attack_bot);
		fight[11].bonus = 0;
	}
	if (select[0].specifics == 2 && wait[1].laps == 0) {
		set_laps(wait, select);
		moving_fighter(fight, window, select);
		sfSprite_setPosition(fight[2].sprite, fight[2].pos_def);
		sfSprite_setPosition(select[0].sprite, select[0].attack_bot);
		fight[11].bonus = 0;
	}
	check_last_attack(fight, select, window, wait);
}

void	check_defence(t_fight *fight, t_select *select, t_window *window,
		wait_t *wait)
{
	if (select[0].specifics == 1 && wait[5].laps == 0) {
		set_laps(wait, select);
		defence(fight, select, window);
		sfSprite_setPosition(fight[2].sprite, fight[2].pos_def);
		sfSprite_setPosition(select[0].sprite, select[0].attack_bot);
	}
	if (select[0].specifics == 2 && wait[4].laps == 0) {
		set_laps(wait, select);
		defence(fight, select, window);
		sfSprite_setPosition(fight[2].sprite, fight[2].pos_def);
		sfSprite_setPosition(select[0].sprite, select[0].attack_bot);
	}
	if (select[0].specifics == 3 && wait[3].laps == 0) {
		set_laps(wait, select);
		defence(fight, select, window);
		sfSprite_setPosition(fight[2].sprite, fight[2].pos_def);
		sfSprite_setPosition(select[0].sprite, select[0].attack_bot);
	}
}

void	check_help(t_fight *fight, t_select *select, wait_t *wait)
{
	if (select[0].specifics == 1 && wait[8].laps == 0) {
		set_laps(wait, select);
		fight[11].bonus += 3;
	}
	if (select[0].specifics == 2 && wait[7].laps == 0) {
		set_laps(wait, select);
		fight[11].bonus += 5;
	}
	if (select[0].specifics == 3 && wait[6].laps == 0) {
		set_laps(wait, select);
		fight[11].bonus += 8;
	}
}

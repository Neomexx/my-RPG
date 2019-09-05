/*
** EPITECH PROJECT, 2017
** set_laps
** File description:
** Desc
*/

#include "fight.h"

static void	set_def(t_select *select, wait_t *wait)
{
	if (select[0].specifics == 3)
		wait[3].laps = 5;
	if (select[0].specifics == 2)
		wait[4].laps = 3;
	if (select[0].specifics == 1)
		wait[5].laps = 1;
}

static void	set_attack(t_select *select, wait_t *wait)
{
	if (select[0].specifics == 3)
		wait[0].laps = 5;
	if (select[0].specifics == 2)
		wait[1].laps = 3;
	if (select[0].specifics == 1)
		wait[2].laps = 1;
}

static void	set_help(t_select *select, wait_t *wait)
{
	if (select[0].specifics == 3)
		wait[6].laps = 5;
	if (select[0].specifics == 2)
		wait[7].laps = 3;
	if (select[0].specifics == 1)
		wait[8].laps = 1;
}

void	set_laps(wait_t *wait, t_select *select)
{
	if (select[0].select == 1)
		set_attack(select, wait);
	else if (select[0].select == 2)
		set_def(select, wait);
	else
		set_help(select, wait);
	for (int i = 0; i < 9; i++) {
		if (wait[i].laps != 0 && select[0].select != 3)
			wait[i].laps -= 1;
		sfText_setString(wait[i].text, my_itoa(wait[i].laps));
	}
}

/*
** EPITECH PROJECT, 2017
** set_wait
** File description:
** Desc
*/

#include "fight.h"

void	set_wait(wait_t wait[9])
{
	for (int i = 0; i < 9; i++) {
		wait[i].string = string_fight[i];
		wait[i].laps = 0;
	}
}

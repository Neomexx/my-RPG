/*
** EPITECH PROJECT, 2017
** set_text
** File description:
** Desc
*/

#include "fight.h"

void	select_text(t_select *select)
{
	sfVector2f	scale = {1, 0.6};
	int y = 0;

	for (int i = 1; i < 10; i++, y++) {
		select[i].font = sfFont_createFromFile("font.ttf");
		select[i].text = sfText_create();
		sfText_setFont(select[i].text, select[i].font);
		sfText_setPosition(select[i].text, fight_select[y]);
		sfText_setString(select[i].text, string_fight[y]);
		sfText_setScale(select[i].text, scale);
	}
}

void	fight_text(t_fight *fight)
{
	int y = 9;

	for (int i = 1; i < 4; i++, y++) {
		fight[i].font = sfFont_createFromFile("font.ttf");
		fight[i].text = sfText_create();
		sfText_setFont(fight[i].text, fight[i].font);
		sfText_setPosition(fight[i].text, fight_select[y]);
		sfText_setString(fight[i].text, string_fight[y]);
	}
}

void	wait_text(wait_t *wait)
{
	for (int i = 0; i < 9; i++) {
		wait[i].font = sfFont_createFromFile("font.ttf");
		wait[i].text = sfText_create();
		sfText_setFont(wait[i].text, wait[i].font);
		sfText_setPosition(wait[i].text, wait_pos[i]);
		sfText_setString(wait[i].text, my_itoa(wait[i].laps));
	}
}

void	set_text_fight(t_fight *fight, t_select *select, wait_t *wait)
{
	select_text(select);
	fight_text(fight);
	wait_text(wait);
}

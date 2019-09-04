/*
** EPITECH PROJECT, 2017
** attack
** File description:
** Desc
*/

#include "fight.h"

void	damage_step(t_fight *fight, t_window *window, t_select *select,
			float atk)
{
	sfSprite_setPosition(fight[5].sprite, fight[5].pos_attack);
	damage(fight, window);
	if (select[0].specifics == 1)
		fight[9].rect_fight.width -= (15 + fight[11].bonus + atk);
	if (select[0].specifics == 2)
		fight[9].rect_fight.width -= (10 + (fight[11].bonus * 2)
						+ atk);
	if (select[0].specifics == 3)
		fight[9].rect_fight.width -= (8 + (fight[11].bonus * 3)
						+ atk);
	sfSprite_setTextureRect(fight[9].sprite, fight[9].rect_fight);
	waiting(fight, window, select);
	if (fight[9].rect_fight.width <= 0)
		return;
	moving_ennemy(fight, window);
	sfSprite_setPosition(fight[5].sprite, fight[5].pos_def);
	damage(fight, window);
	fight[7].rect_fight.width -= window->attack_ennemy;
	sfSprite_setTextureRect(fight[7].sprite, fight[7].rect_fight);
	waiting(fight, window, select);
}

void	draw_fighting(t_fight *fight, t_window *window)
{
	for (int i = 0; i < 4; i++)
		sfRenderWindow_drawSprite(window->window,
					fight[i].sprite, NULL);
	for (int i = 6; i < 10; i++)
		sfRenderWindow_drawSprite(window->window,
					fight[i].sprite, NULL);
	for (int i = 1; i < 4; i++)
		sfRenderWindow_drawText(window->window, fight[i].text, NULL);
	if (fight[10].bonus != 0)
		sfRenderWindow_drawSprite(window->window,
					fight[10].sprite, NULL);
	if (fight[11].bonus != 0)
		sfRenderWindow_drawSprite(window->window,
					fight[11].sprite, NULL);
}

static int	time_elapse(int what_pos, sfTime *time_move,
		sfClock *clock_move, t_fight *fight)
{
	*time_move = sfClock_restart(clock_move);
	if (what_pos == 0) {
		sfSprite_setPosition(fight[1].sprite, fight[1].pos_attack);
		return (1);
	}
	sfSprite_setPosition(fight[1].sprite, fight[1].pos_def);
	return (0);
}

void	moving_fighter(t_fight *fight, t_window *window, t_select *select)
{
	sfClock *clock = sfClock_create();
	sfTime	time;
	int	what_pos = 0;
	float	time_sec;

	for (int count = 0; count <= 100
		&& sfRenderWindow_isOpen(window->window); count++) {
		time = sfClock_getElapsedTime(clock);
		time_sec = sfTime_asSeconds(time);
		if (what_pos == 0 && time_sec > 0.05)
			what_pos = time_elapse(what_pos, &time, clock, fight);
		else if (time_sec > 0.05)
			what_pos = time_elapse(what_pos, &time, clock, fight);
		draw_fighting(fight, window);
		event_window(window->window);
		display_window(window);
	}
	sfClock_destroy(clock);
	damage_step(fight, window, select, window->attack);
}

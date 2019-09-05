/*
** EPITECH PROJECT, 2017
** damaging
** File description:
** Desc
*/

#include <stdio.h>
#include "fight.h"

void	waiting(t_fight *fight, t_window *window, t_select *select)
{
	for (int count = 0; count <= 200
		&& sfRenderWindow_isOpen(window->window); count++) {
		draw_fighting(fight, window);
		event_window(window->window);
		display_window(window);
	}
	select[0].visible = 0;
	select[0].i = 0;
	select[0].specifics = 1;
}

int	draw_damage(t_window *window, t_fight *fight, sfTime *time_move,
		sfClock *clock_move)
{
	sfRenderWindow_drawSprite(window->window, fight[5].sprite, NULL);
	*time_move = sfClock_restart(clock_move);
	return (1);
}

int	undraw_damage(sfTime *time_move, sfClock *clock_move)
{
	*time_move = sfClock_restart(clock_move);
	return (0);
}

void	damage(t_fight *fight, t_window *window)
{
	sfClock *clock = sfClock_create();
	sfTime	time;
	int	what_pos = 0;
	float	time_sec;

	play_sound(window, "songs/sound_hit.ogg");
	sfSprite_setPosition(fight[2].sprite, fight[2].pos_def);
	for (int count = 0; count <= 100
		&& sfRenderWindow_isOpen(window->window); count++) {
		time = sfClock_getElapsedTime(clock);
		time_sec = sfTime_asSeconds(time);
		draw_fighting(fight, window);
		if (what_pos == 0 && time_sec > 0.05)
			what_pos = draw_damage(window, fight, &time, clock);
		else if (time_sec > 0.05)
			what_pos = undraw_damage(&time, clock);
		event_window(window->window);
		display_window(window);
	}
	sfClock_destroy(clock);
}

/*
** EPITECH PROJECT, 2017
** attack_ennemy
** File description:
** Desc
*/

#include "fight.h"

static int	time_elapse(int what_pos, sfTime *time_move,
		sfClock *clock_move, t_fight *fight)
{
	*time_move = sfClock_restart(clock_move);
	if (what_pos == 0) {
		sfSprite_setPosition(fight[2].sprite, fight[2].pos_attack);
		return (1);
	}
	sfSprite_setPosition(fight[2].sprite, fight[2].pos_def);
	return (0);
}

void	moving_ennemy(t_fight *fight, t_window *window)
{
	sfClock *clock = sfClock_create();
	sfTime	time;
	int	what_pos = 0;
	float	time_sec;

	play_sound(window, "songs/sound_attack.ogg");
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
}

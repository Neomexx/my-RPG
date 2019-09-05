/*
** EPITECH PROJECT, 2018
** event_game.c
** File description:
** manage event in game
*/

#include <stdlib.h>
#include <stdio.h>
#include "struct_rpg.h"
#include "menu.h"

int check_event(sfEvent *event, t_window *window, t_map *map,
		t_obstacles *obst)
{
	if (event->type == sfEvtClosed)
		sfRenderWindow_close(window->window);
	else if ((event->type == sfEvtKeyReleased)
	&& (event->key.code == sfKeyReturn || event->key.code == sfKeyE))
		return (check_interactions(window, map, obst));
	check_inventory(window, event);
	sfClock_restart(window->clock);
	return (0);
}

int check_other_keys(t_window *window, t_map *map,
			t_obstacles *obst)
{
	int input[2];

	if ((sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
		|| (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)) {
		input[0] = -1;
		input[1] = 0;
		move_character(input, map, window, obst);
	}
	else if ((sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
			|| (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)) {
			input[0] = 0;
			input[1] = 1;
			move_character(input, map, window, obst);
	}
	return (0);
}

int check_key(t_window *window, t_map *map, t_obstacles *obst)
{
	int input[2];

	if ((sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
		|| (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)) {
		input[0] = 0;
		input[1] = -1;
		move_character(input, map, window, obst);
	}
	if ((sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
		|| (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)) {
		input[0] = 1;
		input[1] = 0;
		move_character(input, map, window, obst);
	}
	else
		return (check_other_keys(window, map, obst));
	return (0);
}

static void pause(t_window *window, menu_t *menu)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
		game_pause(window, menu);
	}
}

int event_game(t_window *window, t_map *map, t_obstacles *obst, menu_t *menu)
{
	sfEvent event;
	int return_value_check_event = 0;

	while (sfRenderWindow_pollEvent(window->window, &event))
		if (sfTime_asMicroseconds(sfClock_getElapsedTime(window->clock))
			> 100) {
			pause(window, menu);
			return_value_check_event = check_event(&event,
							window, map, obst);
		}
	return (return_value_check_event);
}

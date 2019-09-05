/*
** EPITECH PROJECT, 2017
** game
** File description:
** Desc
*/

#include <stdio.h>
#include <stdlib.h>
#include "credit.h"
#include "menu.h"

void check_return_fight(int fight, t_window *window, menu_t *menu)
{
	if ((fight > 0 && fight < 4) || fight == 5) {
		if (fight > 0 && fight < 4) {
			window->attack += 10;
			window->defence += 10;
			window->inv[fight].visible = 1;
		}
		set_music_game(window, "songs/game.ogg");
	}
	else if (fight == 4 || fight == -1) {
		if (fight == -1)
			set_music_game(window, "songs/game_over.ogg");
		credit(window);
		sfMusic_stop(window->sounds.music);
		set_menu(menu);
		menu_loop(window, menu);
	}
}

static void main_game(t_window *window, t_map *map, t_obstacles *obst,
			menu_t *menu)
{
	int return_fight = 0;

	sfRenderWindow_clear(window->window, sfBlack);
	print_map(map, window->window, obst, 0);
	check_key(window, map, obst);
	return_fight = event_game(window, map, obst, menu);
	check_return_fight(return_fight, window, menu);
	set_special_obst(obst, map);
	print_inventory(window);
}

void	game(t_window *window, menu_t *menu)
{
	char *image_char = "01234TCPDcdFHhOoAGagsVvYyBbp";
	t_obstacles *obst = malloc(sizeof(t_obstacles) * my_strlen(image_char));
	t_map map;

	obst[0].nb_sprites = my_strlen(image_char);
	if (!obst || create_obstacles_map(obst, image_char) == -1)
		return;
	set_game(window, &map, obst);
	window->attack = 10;
	while (sfRenderWindow_isOpen(window->window)) {
		main_game(window, &map, obst, menu);
		sfRenderWindow_display(window->window);
	}
}

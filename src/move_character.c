/*
** EPITECH PROJECT, 2018
** move_character.c
** File description:
** move the character
*/

#include "struct_rpg.h"
#include <stdlib.h>

void move_character(int *inputs, t_map *map, t_window *window,
			t_obstacles *obst);

int get_coordinates_p(int *tab, char **map)
{
	tab[0] = -1;
	tab[1] = -1;
	for (int i = 1; map[i]; i++) {
		for (int j = 0; map[i][j] != '\0'; j++) {
			if (map[i][j] == 'P') {
				tab[1] = i;
				tab[0] = j;
			}
		}
	}
	if (tab[0] == -1 || tab[1] == -1)
		return (-1);
	return (0);
}

void move_player(t_map *map, int *inputs, t_window *window, t_obstacles *obst)
{
	char temp;
	int *tab = malloc(sizeof(int) * 2);

	if (!tab || get_coordinates_p(tab, map->map) == -1) {
		sfRenderWindow_close(window->window);
		return;
	}
	animate_characters(map, window, obst, inputs);
	temp = map->map[tab[1] + inputs[1]][tab[0] + inputs[0]];
	map->map[tab[1] + inputs[1]][tab[0] + inputs[0]] =
		map->map[tab[1]][tab[0]];
	if (map->temp_char)
		map->map[tab[1]][tab[0]] = map->temp_char;
	else
		map->map[tab[1]][tab[0]] = '.';
	map->temp_char = temp;
	free(tab);
}

int change_map(t_map *map, int i, t_window *window, int *tab)
{
	map->current_map += i;
	if (map->all_maps[map->current_map]) {
		map->map = malloc(sizeof(char *) * (find_buffer_size
					(map->all_maps[map->current_map]) + 1));
		if (!map->map) {
			sfRenderWindow_close(window->window);
			return (0);
		}
		map->map = stock_map(map->map, map->all_maps[map->current_map]);
		map->temp_char = '\0';
		set_pos_player(tab, map, i);
		return (0);
	}
	else {
		sfRenderWindow_close(window->window);
		return (-1);
	}
}

int check_portal(t_map *map, int *tab, t_window *window, int inputs[2])
{
	int i = 0;

	switch (map->map[tab[1] + inputs[1]][tab[0] + inputs[0]]) {
	case 'N' : i += 10;
		break;
	case 'S' : i -= 10;
		break;
	case 'E' : i += 1;
		break;
	case 'W' : i -= 1;
		break;
	case 'C' : i += 10;
		break;
	case 'D' : change_map_after_ape_fight(window, map, 17);
		return (0);
	default : return -1;
	}
	if (change_map(map, i, window, tab) == -1)
		return (-1);
	return (0);
}

void move_character(int *inputs, t_map *map, t_window *window,
			t_obstacles *obst)
{
	int *tab = malloc(sizeof(int) * 2);
	int count = 0;

	if (!tab || get_coordinates_p(tab, map->map) == -1) {
		sfRenderWindow_close(window->window);
		return;
	}
	for (int i = 0; map->boss_chars[i] != '\0'; i++) {
		if (map->map[tab[1] + inputs[1]]
			[tab[0] + inputs[0]] == map->boss_chars[i])
			count++;
	}
	if (check_portal(map, tab, window, inputs) == 0)
		return;
	if (count == 0)
		move_player(map, inputs, window, obst);
	free(tab);
}

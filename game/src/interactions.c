/*
** EPITECH PROJECT, 2018
** interactions.c
** File description:
** check_interactions
*/

#include <stdio.h>
#include "struct_rpg.h"
#include "map.h"
#include "menu.h"

void find_player(t_map *map, int pos_player[2])
{
	for (int i = 2; map->map[i]; i++)
		for (int j = 0; map->map[i][j] != '\0'; j++)
			if (map->map[i][j] == 'P') {
				pos_player[0] = i;
				pos_player[1] = j;
			}
}

void choose_dialogue(t_window *window, t_obstacles *obst, t_map *map,
			char ennemy)
{
	switch (ennemy) {
	case 'y' : display_dialogue(window, "txt/first_quest/rescue.txt",
					obst, map);
		break;
	case 'V' : display_dialogue(window, "txt/axel_quest/begin_quest.txt",
					obst, map);
		break;
	case 'Y' : display_dialogue(window, "txt/maxime.txt", obst, map);
		break;
	case 'B' : display_dialogue(window, "txt/pnj_warning/second.txt",
					obst, map);
		break;
	case 'b' : display_dialogue(window, "txt/pnj_warning/first.txt",
					obst, map);
		break;
	case 'v' : display_dialogue(window, "txt/romain_dialogue.txt",
					obst, map);
		break;
	default : display_dialogue(window, "txt/error.txt", obst, map);
	}
}

int interact(t_window *window, t_map *map, char ennemy, t_obstacles *obst)
{
	int i = 0;

	for (i = 0; map->boss_chars[i] != 'V'
			&& map->boss_chars[i] != '\0'; i++)
		if (ennemy == map->boss_chars[i])
			return (prepare_fight(window, map, ennemy, obst));
	choose_dialogue(window, obst, map, ennemy);
	return (0);
}

int check_interactions(t_window *window, t_map *map, t_obstacles *obst)
{
	int pos[2];
	char ennemy;

	find_player(map, pos);
	for (int i = 0; map->boss_chars[i] != '#'
			&& map->boss_chars[i] != '\0'; i++) {
		ennemy = map->boss_chars[i];
		if ((map->map[pos[0] - 1][pos[1]] == ennemy)
			|| (map->map[pos[0] - 1][pos[1]] == ennemy)
			|| (map->map[pos[0] + 1][pos[1]] == ennemy)
			|| (map->map[pos[0]][pos[1] - 1] == ennemy)
			|| (map->map[pos[0]][pos[1] + 1] == ennemy))
			return (interact(window, map, ennemy, obst));
	}
	return (0);
}

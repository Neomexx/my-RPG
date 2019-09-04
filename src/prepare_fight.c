/*
** EPITECH PROJECT, 2018
** prepare_fight.c
** File description:
** check the fighter you will fight
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "menu.h"
#include "struct_rpg.h"

void change_map_after_ape_fight(t_window *window, t_map *map, int nb)
{
	map->current_map = nb;
	map->map = malloc(sizeof(char *) * (find_buffer_size
					(map->all_maps[map->current_map]) + 1));
	map->map = stock_map(map->map, map->all_maps[map->current_map]);
	if (!map->map)
		sfRenderWindow_close(window->window);
}

int fight_other(t_window *window, t_map *map, char ennemy,
			t_obstacles *obst)
{
	switch (ennemy) {
	case 's' : display_dialogue(window, "txt/minion/minion3.txt",
					obst, map);
		window->attack_ennemy = 55;
		if (fight(window, "image/fight/skeleton.png") == 2) {
			map->map[9][4] = '.';
			return (5);
		}
		return (-1);
	case 'o' : display_dialogue(window, "txt/after_ff_ava/meet_astek.txt",
					obst, map);
		window->attack_ennemy = 22;
		if (fight(window, "image/fight/fo.png") == 2) {
			map->map[6][13] = '.';
			map->map[6][14] = '.';
			return (5);
		}
		return (-1);
	default : return (0);
	}
}

int other_boss(t_window *window, t_map *map, char ennemy,
		t_obstacles *obst)
{
	switch (ennemy) {
	case 'A' : display_dialogue(window, "txt/ape/second_ape.txt",
					obst, map);
		window->attack_ennemy = 48;
		if (fight(window, "image/fight/moa.png") == 2) {
			change_map_after_ape_fight(window, map, 13);
			return (2);
		}
		return (-1);
	default : return (fight_other(window, map, ennemy, obst));
	}
}

int other_fighters(t_window *window, t_map *map, char ennemy,
			t_obstacles *obst)
{
	switch (ennemy) {
	case 'G' : display_dialogue(window, "txt/ava/final_fight.txt",
					obst, map);
		window->attack_ennemy = 65;
		if (fight(window, "image/fight/moga.png") == 2) {
			display_dialogue(window, "txt/ava/end.txt", obst, map);
			return (4);
		}
		return (-1);
	case 'g' : display_dialogue(window, "txt/ape/third_ape.txt",
					obst, map);
		window->attack_ennemy = 60;
		if (fight(window, "image/fight/foga.png") == 2) {
			change_map_after_ape_fight(window, map, 13);
			map->map[4][10] = 'D';
			return (3);
		}
		return (-1);
	default : return (other_boss(window, map, ennemy, obst));
	}
}

int prepare_fight(t_window *window, t_map *map, char ennemy,
				t_obstacles *obst)
{
	switch (ennemy) {
	case 'a' : display_dialogue(window, "txt/minion/minion2.txt",
					obst, map);
		window->attack_ennemy = 45;
		if (fight(window, "image/fight/foa.png") == 2) {
			map->map[6][6] = '.';
			return (5);
		}
		return (-1);
	case 'O' : display_dialogue(window, "txt/ape/first_ape.txt",
					obst, map);
		window->attack_ennemy = 25;
		if (fight(window, "image/fight/mo.png") == 2) {
			change_map_after_ape_fight(window, map, 13);
			return (1);
		}
		return (-1);
	default : return (other_fighters(window, map, ennemy, obst));
	}
}

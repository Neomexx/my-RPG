/*
** EPITECH PROJECT, 2018
** print_map.c
** File description:
** print the map
*/

#include "map.h"

void print_stage_set(t_obstacles *obst, sfRenderWindow *window, t_map *map)
{
	for (int i = 0; i < obst[0].nb_sprites; i++) {
		if (map->temp_char == obst[i].img_char) {
			sfSprite_setPosition(obst[i].sprite, obst[0].pos);
			sfRenderWindow_drawSprite(window, obst[i].sprite,
							NULL);
		}
	}
}

void print_obstacle(char letter, t_obstacles *obst,
			sfRenderWindow *window)
{
	for (int i = 0; i < obst[0].nb_sprites; i++) {
		if (letter == obst[i].img_char) {
			sfSprite_setPosition(obst[i].sprite, obst[0].pos);
			sfRenderWindow_drawSprite(window, obst[i].sprite,
							NULL);
		}
	}
}

void print_background(t_obstacles *obst, sfRenderWindow *window, t_map *map)
{
	sfVector2f pos = {0, 0};

	for (int i = 0; i < 11; i++) {
		pos.x = 0;
		while (pos.x < 2000) {
			sfSprite_setPosition(
				obst[my_getnbr(map->map[0])].sprite, pos);
			sfRenderWindow_drawSprite(
				window, obst[my_getnbr
				(map->map[0])].sprite, NULL);
			pos.x += 100;
		}
		pos.y += 100;
	}
}

void check_letter(char letter, t_obstacles *obst, sfRenderWindow *window,
			int nb)
{
	if (letter != 'P')
		print_obstacle(letter, obst, window);
	else if (letter == 'P' && nb == 0)
		print_obstacle(letter, obst, window);
}

void print_map(t_map *map, sfRenderWindow *window, t_obstacles *obst, int nb)
{
	sfVector2f pos = {12, 35};

	print_background(obst, window, map);
	for (int i = 2; map->map[i]; i++) {
		for (int j = 1; map->map[i][j]; j++) {
			obst[0].pos = pos;
			if (map->map[i][j] == 'P')
				print_stage_set(obst, window, map);
			check_letter(map->map[i][j], obst, window, nb);
			pos.x += 100;
		}
		pos.x = 12;
		pos.y += 100;
	}
}

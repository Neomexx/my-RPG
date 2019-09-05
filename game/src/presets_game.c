/*
** EPITECH PROJECT, 2018
** presets_game.c
** File description:
** preset game
*/

#include <stdlib.h>
#include "struct_rpg.h"
#include "menu.h"

void set_sprites(t_obstacles *obst, t_window *window)
{
	sfVector2f scale = {2, 2};
	sfIntRect rect = {0, 710, 55, 55};
	sfIntRect face = {0, 650, 55, 55};

	for (int i = 14; i < obst[0].nb_sprites; i++) {
		sfSprite_setTextureRect(obst[i].sprite, face);
		sfSprite_setScale(obst[i].sprite, scale);
	}
	window->fight_p = my_strdup("image/fight/m.png");
	sfSprite_setScale(obst[7].sprite, scale);
	sfSprite_setTextureRect(obst[7].sprite, rect);
}

void set_map(t_map *map, t_window *window)
{
	map->current_map = 0;
	map->all_maps = malloc(sizeof(char *) * (find_buffer_size
						("maps/links") + 1));
	map->all_maps = stock_map(map->all_maps, "maps/links");
	map->map = malloc(sizeof(char *) * (find_buffer_size
					(map->all_maps[map->current_map]) + 1));
	map->map = stock_map(map->map, map->all_maps[map->current_map]);
	if (!map->map || !map->all_maps) {
		sfRenderWindow_close(window->window);
		return;
	}
	map->temp_char = 'd';
	map->boss_chars = my_strdup("OoAaGgsVvYyBbp#TCPFcHh");
}

void set_special_obst(t_obstacles *obst, t_map *map)
{
	sfIntRect rect_special = {0, 0, 100, 100};
	sfIntRect bigrect_special = {0, 0, 200, 200};
	sfIntRect castlerect_special = {0, 0, 300, 300};

	rect_special.left = 0 + 100 * my_getnbr(map->map[0]);
	castlerect_special.left = 0 + 300 * my_getnbr(map->map[0]);
	bigrect_special.left = 0 + 200 * my_getnbr(map->map[0]);
	sfSprite_setTextureRect(obst[5].sprite, rect_special);
	sfSprite_setTextureRect(obst[10].sprite, rect_special);
	sfSprite_setTextureRect(obst[13].sprite, bigrect_special);
	sfSprite_setTextureRect(obst[6].sprite, castlerect_special);
}

void set_game(t_window *window, t_map *map, t_obstacles *obst)
{
	set_inventory(window);
	window->clock = sfClock_create();
	set_map(map, window);
	set_sprites(obst, window);
	set_special_obst(obst, map);
	display_dialogue(window, "txt/introduce_story/new_world.txt",
			obst, map);
	window->attack_ennemy = 80;
	set_music_game(window, "songs/game.ogg");
	if (map)
		map->map[6][3] = 'd';
}

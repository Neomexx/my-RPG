/*
** EPITECH PROJECT, 2018
** set_pos_palyer.c
** File description:
** change the pos of the player
*/

#include "map.h"

void set_pos_player(int *tab, t_map *map, int nb)
{
	for (int i = 1; map->map[i]; i++) {
		for (int j = 0; map->map[i][j] != '\0'; j++) {
			if (map->map[i][j] == 'P')
				map->map[i][j] = '.';
		}
	}
	switch (nb) {
	case -1 : map->map[tab[1]][my_strlen(map->map[1]) - 2] = 'P';
		break;
	case 1 : map->map[tab[1]][1] = 'P';
		break;
	case -10 : map->map[2][tab[0]] = 'P';
		break;
	case 10 : map->map[10][tab[0]] = 'P';
		break;
	}
}

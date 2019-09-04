/*
** EPITECH PROJECT, 2018
** animate_characters.c
** File description:
** animate characters
*/

#include "struct_rpg.h"

static sfVector2f get_pos_player(t_map *map)
{
	sfVector2f pos = {12, 35};

	for (int i = 2; map->map[i]; i++) {
		for (int j = 1; map->map[i][j]; j++) {
			if (map->map[i][j] == 'P')
				return (pos);
			pos.x += 100;
		}
		pos.x = 12;
		pos.y += 100;
	}
	return (pos);
}

static void set_pos_text_player(sfVector2f *pos, int *tab, sfIntRect *rect)
{
	if (tab[0] == 1 && tab[1] == 0) {
		pos->x += 12.5;
		rect->top = 710;
	}
	else if (tab[0] == -1 && tab[1] == 0) {
		pos->x -= 9.5;
		rect->top = 585;
	}
	else {
		if (tab[0] == 0 && tab[1] == -1) {
			pos->y -= 10;
			pos->x += 2;
			rect->top = 525;
		}
		else if (tab[0] == 0 && tab[1] == 1) {
			pos->y += 11;
			pos->x += 2;
			rect->top = 650;
		}
	}
}

static void animation(t_window *window, sfIntRect *rect, sfVector2f *pos,
			t_obstacles *obst)
{
	sfSprite_setPosition(obst[7].sprite, *pos);
	sfSprite_setTextureRect(obst[7].sprite, *rect);
	sfRenderWindow_drawSprite(window->window,
					obst[7].sprite, NULL);
	rect->left += 65;
	print_inventory(window);
	sfRenderWindow_display(window->window);
	sfClock_restart(window->clock);
}

void animate_characters(t_map *map, t_window *window, t_obstacles *obst,
			int *tab)
{
	sfIntRect rect = sfSprite_getTextureRect(obst[7].sprite);
	sfVector2f pos = get_pos_player(map);

	while (rect.left < 550) {
		if (sfTime_asSeconds(sfClock_getElapsedTime
					(window->clock)) > 0.02) {
			set_pos_text_player(&pos, tab, &rect);
			sfRenderWindow_clear(window->window, sfBlack);
			print_map(map, window->window, obst, 1);
			animation(window, &rect, &pos, obst);
		}
	}
	rect.left = 0;
	sfSprite_setTextureRect(obst[7].sprite, rect);
}

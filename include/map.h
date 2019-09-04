/*
** EPITECH PROJECT, 2018
** map.h
** File description:
** map.h
*/

#ifndef	MAP_H_
#define	MAP_H_

#include "my.h"

typedef	struct	s_obstacles {
	int		nb_sprites;
	sfSprite	*sprite;
	sfTexture	*text;
	char		*img;
	char		img_char;
	sfVector2f	pos;
}		t_obstacles;

typedef	struct	s_map {
	char	**all_maps;
	int	current_map;
	char	**map;
	char	temp_char;
	char	*boss_chars;
}		t_map;

void	print_map(t_map *map, sfRenderWindow *window, t_obstacles *obst,
		int nb);
int	find_buffer_size(char *path);
char	**stock_map(char **map, char *path);
int	create_obstacles_map(t_obstacles *obst, char *image_char);
char	*my_strdup(char const *src);
void	set_pos_player(int *tab, t_map *map, int nb);
void	print_obstacle(char letter, t_obstacles *obst,
			sfRenderWindow *window);
void	print_background(t_obstacles *obst, sfRenderWindow *window,
		t_map *map);

#endif

/*
** EPITECH PROJECT, 2017
** struct_rpg
** File description:
** Desc
*/

#ifndef	STRUCT_RPG_H
#define	STRUCT_RPG_H

#include "my.h"
#include "map.h"

extern const sfVector2f pos_inv[4];
extern const sfIntRect rect_inv[4];

typedef struct s_inventory
{
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVector2f	pos;
	sfIntRect	rect;
	int	visible;
}t_inventory;

typedef struct s_sounds
{
	sfSound *sound;
	sfSoundBuffer *buffer;
	sfMusic *music;
}t_sounds;

typedef	struct	window
{
	sfRenderWindow	*window;
	sfClock	*clock;
	float		attack;
	float		defence;
	float		help;
	int		attack_ennemy;
	char		*fight_p;
	t_sounds	sounds;
	t_inventory	inv[5];
}		t_window;

typedef	struct	menu
{
	sfTexture	*t_background;
	sfSprite	*s_background;
	sfVector2f	v_background;
	sfIntRect	r_background;
	sfTexture	*t_button;
	sfSprite	*s_button;
	sfVector2f	v_button;
	sfVector2f	scale;
	sfIntRect	r_button;
}		t_menu;

typedef	struct	option
{
	sfTexture	*t_background;
	sfSprite	*s_background;
	sfTexture	*t_button;
	sfSprite	*s_button;
	sfVector2f	v_button;
	sfVector2f	scale;
	sfIntRect	r_button;
}		t_option;

void	option(t_window *window);
int	fight(t_window *window, char *ennemy);
void	move_character(int *inputs, t_map *map, t_window *window,
			t_obstacles *obst);
void	animate_characters(t_map *map, t_window *window, t_obstacles *obst,
			int *tab);
int	check_key(t_window *window, t_map *map, t_obstacles *obst);
void	display_window(t_window *window);
int	check_interactions(t_window *window, t_map *map,
				t_obstacles *obsatcles);
int prepare_fight(t_window *window, t_map *map, char ennemy,
			t_obstacles *obst);
void set_inventory(t_window *window);
void print_inventory(t_window *window);
void check_inventory(t_window *window, sfEvent *event);
void change_map_after_ape_fight(t_window *window, t_map *map, int nb);
void set_music_game(t_window *window, char *path);
void play_sound(t_window *window, char *path);
void set_game(t_window *window, t_map *map, t_obstacles *obst);
void set_special_obst(t_obstacles *obst, t_map *map);

#endif

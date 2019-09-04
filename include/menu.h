/*
** EPITECH PROJECT, 2017
** menu
** File description:
** Desc
*/

#ifndef MENU_T
#define MENU_T

#include "my.h"
#include "struct_rpg.h"

extern	const	sfVector2f	pos_menu[4];
extern	const	sfVector2f	scale_menu[4];
extern	const	char		*name_menu[4];
extern	const	int		visible_menu[4];

extern	const	sfVector2f	pos_text[4];
extern	const	sfVector2f	scale_text[4];
extern	const	char		*text_menu[4];

typedef	struct	text_menu_s
{
	sfText	*text;
	sfFont	*font;
	sfColor	color;
	int	alpha;
}		menu_text_t;

typedef	struct	menu_s
{
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVector2f	pos;
	sfVector2f	scale;
	sfIntRect	rect;
	int		visible;
	int		particule;
	menu_text_t	*text;
}		menu_t;

void	game(t_window *window, menu_t *menu);
void	display_help(t_window *window, menu_t *menu, menu_text_t *text);
void	display_dialogue(t_window *window, char *,
			t_obstacles *obst, t_map *map);
void	menu_loop(t_window *window, menu_t *menu);
void	options(t_window *window, menu_t *menu,
			menu_text_t *text, sfMusic *music);
void	set_menu(menu_t *menu);
void	set_text_menu(menu_text_t *text);
void	blow(t_window *window, menu_t *menu);
int	event_dust(t_window *window, menu_t *menu, menu_text_t *text);
void	event_blow(t_window *window);
int game_pause(t_window *window, menu_t *menu);
int event_game(t_window *window, t_map *map, t_obstacles *obst, menu_t *menu);

#endif

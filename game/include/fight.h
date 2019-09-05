/*
** EPITECH PROJECT, 2017
** fight
** File description:
** Desc
*/

#ifndef FIGHT_H
 #define FIGHT_H

#include "my.h"
#include "struct_rpg.h"

extern	const sfVector2f	attack_fight[5];
extern	const sfVector2f	def_fight[11];
extern	const sfVector2f	wait_pos[9];
extern	const sfVector2f	scale[3];
extern	const sfVector2f	fight_select[12];
extern	const sfIntRect		rect[4];
extern	const char		*image_fight[12];
extern	const char		*string_fight[12];

typedef	struct	s_fight
{
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVector2f	scale;
	sfVector2f	pos_attack;
	sfVector2f	pos_def;
	sfVector2f	pos_bonus;
	sfIntRect	rect_fight;
	sfText		*text;
	sfFont		*font;
	float		bonus;
}		t_fight;

typedef	struct	s_select
{
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVector2f	attack_top;
	sfVector2f	attack_bot;
	sfVector2f	def_top;
	sfVector2f	def_bot;
	sfVector2f	bonus_top;
	sfVector2f	bonus_bot;
	sfIntRect	rect_select;
	sfText		*text;
	sfFont		*font;
	int		i;
	int		select;
	int		specifics;
	int		visible;
}		t_select;

typedef	struct	s_wait
{
	sfText		*text;
	sfFont		*font;
	const char	*string;
	int		laps;
}		wait_t;

void	set_text_fight(t_fight *fight, t_select *select, wait_t *wait);
void	set_fight(t_fight *sfight, char *ennemy, t_window *window);
void	set_select(t_select *select);
void	set_wait(wait_t wait[9]);
void	set_laps(wait_t *wait, t_select *select);
void	select_upper(t_fight *fight, t_select *select);
void	select_bottom(t_fight *fight, t_select *select);
void	select_specific_bottom(t_fight *fight, t_select *select);
void	select_specific_upper(t_fight *fight, t_select *select);
void	key_down(t_fight *fight, t_select *select);
void	key_up(t_fight *fight, t_select *select);
void	key_right_left(t_fight *fight, t_select *select, sfEvent event);
void	key_ok(t_fight *fight, t_select *select, t_window *window,
		wait_t *wait);
void	defence(t_fight *fight, t_select *select, t_window *window);
void	check_attack(t_fight *fight, t_select *select, t_window *window,
		wait_t *wait);
void	check_defence(t_fight *fight, t_select *select, t_window *window,
		wait_t *wait);
void	check_help(t_fight *fight, t_select *select, wait_t *wait);
void	moving_fighter(t_fight *fight, t_window *window, t_select *select);
void	moving_ennemy(t_fight *fight, t_window *window);
void	damage(t_fight *fight, t_window *window);
void	waiting(t_fight *fight, t_window *window, t_select *select);
void	draw_fighting(t_fight *fight, t_window *window);

#endif

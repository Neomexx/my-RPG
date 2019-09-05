/*
** EPITECH PROJECT, 2018
** menu_manage.h
** File description:
** header for managing menu
*/

#ifndef MENU_MANAGE_H_
#define MENU_MANAGE_H_

#include "my.h"
#include "struct_rpg.h"

#define b_credits "image/inferno_squad.png"
#define f_credits "src/dialogues/ressources_dialogues/dialogue_perso1.png"
#define f_help "image/how_to_play.png"

typedef void (*do_button)(t_window *);

typedef	struct	button
{
	do_button	function;
	sfVector2f	position;
}		t_button;

image	*stock_credit(void);
void 	event_menu(t_window *window, t_menu *menu, sfMusic *button_sound);

#endif /* MENU_MANAGE_H_ */

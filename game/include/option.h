/*
** EPITECH PROJECT, 2018
** option.h
** File description:
** header of option file
*/

#ifndef OPTION_H_
#define OPTION_H_

#include "menu.h"
#include "my.h"
#include "struct_rpg.h"
#include "menu_manage.h"

#define f_sound "image/sound.png"
#define f_full_bar "image/life_point.png"
#define f_empty_bar "image/life_point_empty.png"

void	event_sound(sfVector2i mouse, sfVector2f pos_sound, sfMusic *music);
void	event_perso(t_window *window, menu_t *menu, menu_text_t *text,
		t_menu *option, sfMusic *music);
int	event_option(t_window *window, menu_t *menu, t_menu *option,
		sfMusic *music);
int evt_click(sfVector2i mouse, sfVector2f pos_return);

#endif /* OPTION_H_ */

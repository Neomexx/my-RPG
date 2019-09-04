/*
** EPITECH PROJECT, 2018
** option_event.c
** File description:
** function that handle the events of option
*/

#include "option.h"
#include "menu.h"

void event_sound(sfVector2i mouse, sfVector2f pos_sound, sfMusic *music)
{
	int volume;

	if ((mouse.x <= pos_sound.x + 400
		&& mouse.x >= pos_sound.x)
		&& (mouse.y <= pos_sound.y + 250
		&& mouse.y >= pos_sound.y)) {
		volume = (mouse.x - 600) / 4;
		sfMusic_setVolume(music, volume);
	}
}

int evt_click(sfVector2i mouse, sfVector2f pos_return)
{
	if ((mouse.x <= pos_return.x + 48
		&& mouse.x >= pos_return.x + 3)
		&& (mouse.y <= pos_return.y + 52
		&& mouse.y >= pos_return.y))
		return (1);
	return (0);
}

int event_option(t_window *window, menu_t *menu,
		t_menu *option, sfMusic *music)
{
	sfEvent click;
	sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
	sfVector2f pos_return = sfSprite_getPosition(menu[3].sprite);
	sfVector2f pos_sound = sfSprite_getPosition(option[0].s_button);

	while (sfRenderWindow_pollEvent(window->window, &click)) {
		if (click.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			return (1);
		if (click.type == sfEvtMouseButtonPressed) {
			event_sound(mouse, pos_sound, music);
			if (evt_click(mouse, pos_return) == 1)
				return (1);
		}
	}
	return (0);
}

/*
** EPITECH PROJECT, 2018
** event_window.c
** File description:
** all events of the window
*/

#include "my.h"

void event_window(sfRenderWindow *window)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed
			|| sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			sfRenderWindow_close(window);
	}
}

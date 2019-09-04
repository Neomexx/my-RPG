/*
** EPITECH PROJECT, 2018
** help.c
** File description:
** function for help function of main menu
*/

#include "menu_manage.h"
#include "menu.h"
#include <stdlib.h>
#include <stdio.h>

int help_events(t_window *window, menu_t *menu)
{
	sfEvent click;
	sfVector2f pos_return = sfSprite_getPosition(menu[3].sprite);
	sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);

	while (sfRenderWindow_pollEvent(window->window, &click)) {
		if (click.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			return (1);
		if (click.type == sfEvtMouseButtonPressed) {
			if ((mouse.x <= pos_return.x + 48
				&& mouse.x >= pos_return.x + 3)
				&& (mouse.y <= pos_return.y + 52
				&& mouse.y >= pos_return.y))
				return (1);
		}
	}
	return (0);
}

static void set_text_help(sfText *help_text[6], menu_text_t *text)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	sfVector2f pos_text = (sfVector2f){600, 200};

	file = fopen("txt/help.txt", "r");
	for (int i = 0; i < 6; i++) {
		getline(&line, &len, file);
		help_text[i] = sfText_create();
		sfText_setString(help_text[i], line);
		sfText_setFont(help_text[i], text->font);
		sfText_setColor(help_text[i], text->color);
		sfText_setPosition(help_text[i], pos_text);
		pos_text.y = pos_text.y + 50;
	}
}

void display_help(t_window *window, menu_t *menu, menu_text_t *text)
{
	sfText *help_text[6];

	play_sound(window, "songs/click.ogg");
	set_text_help(help_text, text);
	while (sfRenderWindow_isOpen(window->window)) {
		sfRenderWindow_clear(window->window, sfBlack);
		sfRenderWindow_drawSprite(window->window, menu[1].sprite, NULL);
		sfRenderWindow_drawSprite(window->window, menu[3].sprite, NULL);
		for (int i = 0; i < 6; i++)
			sfRenderWindow_drawText(window->window,
						help_text[i], NULL);
		if (help_events(window, menu) == 1)
			return;
		sfRenderWindow_display(window->window);
	}
}

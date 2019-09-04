/*
** EPITECH PROJECT, 2018
** dialogue_displaying.c
** File description:
** all function that help the displaying function to work
*/

#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "struct_rpg.h"
#include "dialogue.h"
#include "my.h"
#include "menu_manage.h"

static void dialogue_background(image *dial)
{
	sfVector2f position = {40, 600};

	dial->texture = sfTexture_createFromFile("image/empty_dialogue.png",
							NULL);
	dial->sprite = sfSprite_create();
	sfSprite_setTexture(dial->sprite, dial->texture, sfTrue);
	sfSprite_setPosition(dial->sprite, position);
}

static int count_lines_file(char *path)
{
	char **tab = malloc(sizeof(char *) * (find_buffer_size(path) + 1));
	int count = 0;

	tab = stock_map(tab, path);
	if (!tab)
		return (0);
	for (int i = 0; tab[i]; i++) {
		count++;
	}
	return (count - 1);
}

static void set_var_dialogue(t_dialogue text[3], char *path, image *dialogue)
{
	text[0].current_line = 0;
	text[0].nb_lines = count_lines_file(path);
	dialogue_background(dialogue);
	create_dialogue(700, &text[0]);
	create_dialogue(760, &text[1]);
	create_dialogue(820, &text[2]);
	for (int j = 0; j < 3; j++)
		set_dialogue(path, text[0].current_line + j, &text[j]);
}

static void event_dialogue(t_window *window, sfEvent *click, t_dialogue text[3],
				char *path)
{
	if (click->type == sfEvtClosed) {
		sfRenderWindow_close(window->window);
		return;
	}
	if (click->type == sfEvtKeyReleased) {
		text[0].current_line += 3;
		for (int j = 0; j < 3 && text[0].current_line
				< text[0].nb_lines; j++)
			set_dialogue(path, text[0].current_line + j, &text[j]);
	}
}

void display_dialogue(t_window *window, char *path, t_obstacles *obst,
			t_map *map)
{
	t_dialogue text[3];
	image dial;
	sfEvent click;

	set_var_dialogue(text, path, &dial);
	while (text[0].current_line < text[0].nb_lines
		&& sfRenderWindow_isOpen(window->window)) {
		sfRenderWindow_clear(window->window, sfBlack);
		print_map(map, window->window, obst, 0);
		sfRenderWindow_drawSprite(window->window, dial.sprite, NULL);
		for (int i = 0; i < 3; i++)
			sfRenderWindow_drawText(window->window,
						text[i].text, NULL);
		while (sfRenderWindow_pollEvent(window->window, &click))
			event_dialogue(window, &click, text, path);
		sfRenderWindow_display(window->window);
	}
	sfSprite_destroy(dial.sprite);
	for (int k = 0; k < 3; k++)
		sfText_destroy(text[k].text);
}

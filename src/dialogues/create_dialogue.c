/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** create_dialogue.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "dialogue.h"
#include "my.h"

void	create_dialogue(float nb, t_dialogue *dialogue)
{
	sfVector2f	scale = {275, nb};
	sfColor color = sfBlack;

	dialogue->font = sfFont_createFromFile("font.ttf");
	dialogue->text = sfText_create();
	sfText_setFont(dialogue->text, dialogue->font);
	sfText_setCharacterSize(dialogue->text, 50);
	sfText_setColor(dialogue->text, color);
	sfText_setPosition(dialogue->text, scale);
}

void set_dialogue(char *path, int i, t_dialogue *dialogue)
{
	char **tab = malloc(sizeof(char *) * (find_buffer_size(path) + 1));

	tab = stock_map(tab, path);
	if (!tab)
		return;
	if (tab[i] && my_strcmp(tab[i], "\0") != 0)
		sfText_setString(dialogue->text, tab[i]);
}

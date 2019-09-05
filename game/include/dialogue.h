/*
1;4803;0c** EPITECH PROJECT, 2018
** dialogue.h
** File description:
** header of dialogues directory
*/

#ifndef _DIALOGUE_H
#define _DIALOGUE_H

#include "my.h"
#include "struct_rpg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_dialogue
{
	sfFont *font;
	sfText *text;
	int nb_lines;
	int current_line;
} t_dialogue;

//create_dialogue.c
void create_dialogue(float nb, t_dialogue *dialogue);
void set_dialogue(char *path, int i, t_dialogue *dialogue);

//read_file.c
int get_number_line(char *path);
char **fill_tab_scene(char *path);

#endif

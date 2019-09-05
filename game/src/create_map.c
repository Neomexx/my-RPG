/*
** EPITECH PROJECT, 2017
**t
** File description:
**t
*/

#include "map.h"
#include <stdio.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
	int i = 0;
	char *new;

	new = malloc(sizeof(char) * my_strlen(src) + 1);
	if (!new)
		return (NULL);
	while (src[i] != '\0') {
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
char **stock_map(char **map, char *path)
{
	FILE *file2 = NULL;
	char *line2 = NULL;
	size_t length2 = 0;
	ssize_t read2;
	int i = 0;

	file2 = fopen(path, "r");
	if (file2 == NULL)
		return (NULL);
	while ((read2 = getline(&line2, &length2, file2)) != -1) {
		if (!(map[i] = my_strdup(line2)))
			return (NULL);
		map[i][my_strlen(line2) - 1] = '\0';
		i += 1;
	}
	map[i] = NULL;
	fclose(file2);
	if (i == 0)
		return (NULL);
	return (map);
}

int find_buffer_size(char *path)
{
	int i = 0;
	FILE *file = NULL;
	char *line = NULL;
	size_t length = 0;
	ssize_t read;

	if (!path)
		return (0);
	file = fopen(path, "r");
	if (file == NULL)
		return (0);
	while ((read = getline(&line, &length, file)) != -1)
		i++;
	fclose(file);
	return (i);
}

void assign_values(int size, t_obstacles *obst, char *image_char,
		char **images)
{
	for (int i = 0; i < size; i++) {
		obst[i].img = images[i];
		if (image_char)
			obst[i].img_char = image_char[i];
		obst[i].text = sfTexture_createFromFile(obst[i].img, NULL);
		obst[i].sprite = sfSprite_create();
		sfSprite_setTexture(obst[i].sprite, obst[i].text, sfTrue);
	}
}

int create_obstacles_map(t_obstacles *obst, char *image_char)
{
	char **images = malloc(sizeof(char *) * (find_buffer_size
						("img_map/links") + 1));

	if (!images)
		return (-1);
	images = stock_map(images, "img_map/links");
	assign_values(obst[0].nb_sprites, obst, image_char, images);
	return (0);
}

/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** task2
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	char *str = malloc(sizeof(char) * (my_strlen(dest)
						+ my_strlen(src) + 1));

	if (!str)
		exit(84);
	for (i = 0; dest[i] != '\0'; i++)
		str[i] = dest[i];
	for (int j = 0; src[j] != '\0'; i++, j++)
		str[i] = src[j];
	str[i] = '\0';
	return (str);
}

/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** task03
*/

#include <unistd.h>

int my_strlen(char const *str)
{
	int d = 0;

	if (!str)
		return (-1);
	while (str[d] != '\0')
		d++;
	return (d);
}

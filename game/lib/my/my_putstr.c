/*
** EPITECH PROJECT, 2017
** my_pustr
** File description:
** task02
*/

#include <unistd.h>
#include "../../include/my.h"

int my_putstr(char const *str)
{
	int a = 0;

	if (!str[a])
		return (0);
	while (str[a] != '\0') {
		my_putchar(str[a]);
		a++;
	}
	return (0);
}

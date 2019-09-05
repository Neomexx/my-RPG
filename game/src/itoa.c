/*
** EPITECH PROJECT, 2017
** itoa
** File description:
** Desc
*/

#include "my.h"
#include <stdlib.h>

char	*my_itoa(int num)
{
	char	*str = malloc(sizeof(char) * 20);
	int	i = 0;

	if (num == 0)
		return ("0");
	while (num != 0) {
		str[i] = (num % 10) + '0';
		num = num / 10;
		i += 1;
	}
	str[i] = '\0';
	my_revstr(str);
	return (str);
}

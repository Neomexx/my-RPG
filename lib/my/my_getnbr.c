/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** return a number when the function sent it as a string
*/

#include <stdlib.h>

int get_nbr(char const *str, int a)
{
	long nbr = 0;

	while (str[a] >= '0' && str[a] <= '9') {
		nbr = nbr * 10;
		nbr = nbr + (str[a] - '0');
		if (nbr > 2147483647) {
			return (0);
		}
		a++;
	}
	return (nbr);
}
int my_getnbr(char const *str)
{
	int a = 0;
	int neg = 0;
	long nbr = 0;

	while(str[a] == '-' || str[a] == '+') {
		if (str[a] == '-') {
			neg ++;
		}
		a++;
	}
	nbr = get_nbr(str, a);
	(int)nbr;
	if ((neg % 2) == 1) {
		return (-nbr);
	}
	else {
		return (nbr);
	}
}

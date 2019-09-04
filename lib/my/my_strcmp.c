/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** reproduce the behavior of the strcmp function
*/
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	j = (s1[i] -48) - (s2[i] -48);
	return (j);
}

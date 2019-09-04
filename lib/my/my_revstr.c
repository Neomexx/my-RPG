/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** task3
*/

char hahaha(char *str)
{
	char v;

	v = 0;
	while (str[v] != '\0')
		v++;
	return (v);
}
char *my_revstr(char *str)
{
	int a;
	int b = 0;
	char c = 0;

	a = hahaha(str) - 1;
	while (a != b) {
		c = str[a];
		str[a] = str[b];
		str[b] = c;
		b++;
		a--;
	}
	return (str);
}

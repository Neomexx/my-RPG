/*
** EPITECH PROJECT, 2017
** main
** File description:
** create a cook game
*/

#include "my.h"
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av, char **env)
{
	int fd;
	char buf[315];
	int size;

	if (env[0] == NULL)
		return (84);
	if (ac > 2)
		return (84);
	if (ac == 2) {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			fd = open("README", O_RDONLY);
			size = read(fd, buf, 314);
			buf[size] = '\0';
			close(fd);
			my_putstr(buf);
			return (0);
		}
	}
	my_rpg();
	return (0);
}

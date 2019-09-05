/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** sfds
*/
#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
	if (nb == -2147483648) {
		my_putchar('-');
		my_putchar('2');
		nb = 147483648;
	}
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	else if (nb > 9) {
		my_put_nbr(nb / 10);
	}
	my_putchar(nb % 10 + 48);
	return (0);
}

/*
** EPITECH PROJECT, 2017
** main
** File description:
** main for test my_printf
*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

void print_adress(va_list *ad)
{
	long int adr;
	char *hexa;
	char res[12];
	int i;

	adr = va_arg(*ad, long int);
	hexa = "0123456789abcdef";
	i = 11;
	while ((adr / 16) > 0)
	{
		res[i] = hexa[(adr % 16)];
		adr = adr / 16;
		i--;
	}
	res[i] = hexa[(adr % 16)];
	my_putstr("0x");
	while (i < 12) {
		write(1, &res[i], 1);
		i++;
	}
}
void print_modulo(va_list ad, char *str, int i)
{
	switch(str[i+1]) {
	case 'i' : my_put_nbr(va_arg(ad, int));
		break;
	case 'd' : my_put_nbr(va_arg(ad, int));
		break;
	case 's' : my_putstr(va_arg(ad, char *));
		break;
	case 'c' : my_putchar(va_arg(ad, int));
		break;
	default :
		break;
	}
}
int check_modulo(va_list *ad, char *str, int i)
{
	if (str[i+1] == 'p')
		print_adress(&*ad);
	else
		print_modulo(*ad, str, i);
	return (i);
}
int my_printf(char *str, ...)
{
	int i = 0;
	va_list ad;

	va_start (ad, str);
	while (str[i] != '\0') {
		if (str[i] == '%' && str[i+1] != '%' ) {
			i = check_modulo(&ad, str, i);
			i++;
		}
		else {
			if (str[i] == '%' && str[i+1] == '%') {
				my_putchar('%');
				i++;
			}
			else
				my_putchar(str[i]);
		}
		i++;
	}
	return (0);
}

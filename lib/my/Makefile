##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## short file description
##

SRC	=	*.c

OBJ	=	*.o

NAME	=	libmy.a

all:
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re :	fclean all

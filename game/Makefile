##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

NAME	=	my_rpg

CC	=	gcc

INCLUDE	=	-I include -L./lib/my -lmy -lc_graph_prog

CFLAGS	+=	-Wall -Wextra  $(INCLUDE)

SRC	=	src/animate_characters.c		\
		src/option.c				\
		src/create_map.c			\
		src/display_window.c			\
		src/event_game.c			\
		src/event_window.c			\
		src/game.c				\
		src/help.c				\
		src/itoa.c				\
		src/main.c				\
		src/move_character.c			\
		src/option_event.c			\
		src/pause.c				\
		src/print_map.c			\
		src/set_pos_player.c			\
		include/fight_iteratif.c		\
		include/menu_iteratif.c			\
		include/inventory_iteratif.c		\
		include/credit_iteratif.c		\
		src/menu/menu.c				\
		src/menu/set_menu.c			\
		src/menu/open_book.c			\
		src/menu/blow.c				\
		src/menu/set_buffer_particule.c		\
		src/menu/event_particule.c		\
		src/fight/fight.c			\
		src/fight/key_pressed_fight.c		\
		src/fight/defence.c			\
		src/fight/check_attack.c		\
		src/fight/set_text.c			\
		src/fight/set_fight.c			\
		src/fight/set_select.c			\
		src/fight/set_wait.c			\
		src/fight/set_laps.c			\
		src/fight/select_attack_def_bonus.c	\
		src/fight/select_specific.c		\
		src/fight/damaging.c			\
		src/fight/attack.c			\
		src/fight/attack_ennemy.c		\
		src/inventory/set_inventory.c		\
		src/inventory/print_inventory.c		\
		src/dialogues/create_dialogue.c		\
		src/dialogues/dialogue_displaying.c	\
		src/credit/set_credit.c			\
		src/credit/credit.c			\
		src/interactions.c			\
		src/prepare_fight.c			\
		src/change_music.c			\
		src/presets_game.c			\
		src/menu/event_menu.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/ all
	$(CC) -o $(NAME) $(SRC) $(INCLUDE)

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my/ fclean
	rm -f libmy.a
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean re all

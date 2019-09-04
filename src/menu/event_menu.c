/*
** EPITECH PROJECT, 2018
** event_menu.c
** File description:
** event_menu.c
*/

#include "particule.h"

static void check_pos_open_book(t_window *window, menu_t *menu,
				t_particule *buffer, sfVector2i *pos_mouse)
{
	sfVector2f pos_book = sfSprite_getPosition(menu[0].sprite);

	if ((pos_mouse->x <= pos_book.x + 480
		&& pos_mouse->x >= pos_book.x)
		&& (pos_mouse->y <= pos_book.y + 737
			&& pos_mouse->y >= pos_book.y)) {
		if (menu[0].visible == 1) {
			menu[0].visible = 0;
			menu[1].visible = 1;
			menu[2].visible = 0;
			open_book(window, buffer);
			menu[1].particule = 1;
		}
	}
}

static void check_pos_close_book(menu_t *menu, sfVector2i *pos_mouse)
{
	sfVector2f close_book = sfSprite_getPosition(menu[1].sprite);

	if ((pos_mouse->x <= close_book.x + 90
		&& pos_mouse->x >= close_book.x)
		&& (pos_mouse->y <= close_book.y + 375
			&& pos_mouse->y >= close_book.y + 300)) {
		if (menu[0].visible == 0) {
			menu[0].visible = 1;
			menu[1].visible = 0;
			menu[2].visible = 1;
		}
	}
}
void event_menu (t_window *window, menu_t *menu, t_particule *buffer)
{
	sfEvent click;
	sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window->window);

	while (sfRenderWindow_pollEvent(window->window, &click)) {
		if (click.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (click.type == sfEvtMouseButtonPressed) {
			event_text(window, menu, menu->text);
			play_sound(window, "songs/click.ogg");
			check_pos_open_book(window, menu, buffer, &pos_mouse);
			check_pos_close_book(menu, &pos_mouse);
		}
		if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue
			&& menu->text[0].alpha < 255 && menu[0].visible == 0
			&& menu[1].particule == 0)
			blow(window, menu);
	}
}

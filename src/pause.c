/*
** EPITECH PROJECT, 2018
** pause.c
** File description:
** pause the game
*/

#include <stdlib.h>
#include "particule.h"

void set_pause_button(t_menu pause[2])
{
	pause[0].t_button = sfTexture_createFromFile(f_pause, NULL);
	pause[0].s_button = sfSprite_create();
	sfSprite_setTexture(pause[0].s_button, pause[0].t_button, sfTrue);
	pause[0].r_button = (sfIntRect){ 0, 0, 277, 175};
	sfSprite_setTextureRect(pause[0].s_button, pause[0].r_button);
	pause[0].v_button = (sfVector2f){ 850, 300};
	sfSprite_setPosition(pause[0].s_button, pause[0].v_button);
	pause[1].t_button = sfTexture_createFromFile(f_pause, NULL);
	pause[1].s_button = sfSprite_create();
	sfSprite_setTexture(pause[1].s_button, pause[1].t_button, sfTrue);
	pause[1].r_button = (sfIntRect){ 279, 0, 277, 175};
	sfSprite_setTextureRect(pause[1].s_button, pause[1].r_button);
	pause[1].v_button = (sfVector2f){ 850, 500};
	sfSprite_setPosition(pause[1].s_button, pause[1].v_button);
}

void handle_pause_button(t_window *window, t_menu *pause, menu_t *menu)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
	sfVector2f pos_menu = sfSprite_getPosition(pause[0].s_button);
	sfVector2f pos_exit = sfSprite_getPosition(pause[1].s_button);

	if ((mouse.x <= pos_menu.x + 277
		&& mouse.x >= pos_menu.x)
		&& (mouse.y <= pos_menu.y + 175
		&& mouse.y >= pos_menu.y)) {
		play_sound(window, "songs/click.ogg");
		sfMusic_stop(window->sounds.music);
		set_menu(menu);
		menu_loop(window, menu);
	}
	if ((mouse.x <= pos_exit.x + 277
		&& mouse.x >= pos_exit.x)
		&& (mouse.y <= pos_exit.y + 175
		&& mouse.y >= pos_exit.y)) {
		play_sound(window, "songs/click.ogg");
		sfRenderWindow_close(window->window);
	}
}

int pause_event(t_window *window, t_menu *pause, int bool, menu_t *menu)
{
	sfEvent click;

	while (sfRenderWindow_pollEvent(window->window, &click)) {
		if (click.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			bool = 1;
		if (click.type == sfEvtMouseButtonPressed) {
			bool = 1;
			handle_pause_button(window, pause, menu);
		}
	}
	return (bool);
}

static void print_pause_menu(t_menu pause[2], t_window *window, menu_t *menu)
{
	int bool = 0;

	while (bool != 1 && sfRenderWindow_isOpen(window->window)) {
		sfRenderWindow_drawSprite(window->window,
						pause[0].s_background, NULL);
		sfRenderWindow_drawSprite(window->window,
						pause[0].s_button, NULL);
		sfRenderWindow_drawSprite(window->window,
						pause[1].s_button, NULL);
		sfRenderWindow_display(window->window);
		bool = pause_event(window, pause, bool, menu);
	}
}

int game_pause(t_window *window, menu_t *menu)
{
	t_menu pause[2];

	while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue);
	pause[0].t_background = sfTexture_createFromFile(f_pause, NULL);
	pause[0].s_background = sfSprite_create();
	sfSprite_setTexture(pause[0].s_background,
				pause[0].t_background, sfTrue);
	pause[0].r_background = (sfIntRect){0, 175, 360, 160};
	sfSprite_setTextureRect(pause[0].s_background, pause[0].r_background);
	pause[0].v_background = (sfVector2f){800, 100};
	sfSprite_setPosition(pause[0].s_background, pause[0].v_background);
	set_pause_button(pause);
	print_pause_menu(pause, window, menu);
	return (0);
}

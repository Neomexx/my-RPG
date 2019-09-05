/*
** EPITECH PROJECT, 2017
** menu
** File description:
** Desc
*/

#include <stdio.h>
#include <stdlib.h>
#include "particule.h"

void check_other_pos_mouse(t_window *window, menu_t *menu, menu_text_t *text,
				sfVector2i *pos_mouse)
{
	sfVector2f	option = sfText_getPosition(text[1].text);
	sfVector2f	help = sfText_getPosition(text[2].text);
	sfVector2f	exit = sfText_getPosition(text[3].text);

	if ((pos_mouse->x <= option.x + 214
		&& pos_mouse->x >= option.x)
		&& (pos_mouse->y <= option.y + 73
		&& pos_mouse->y >= option.y))
		options(window, menu, text, window->sounds.music);
	if (pos_mouse->x <= help.x + 150 && pos_mouse->x >= help.x
		&& pos_mouse->y <= help.y + 62
		&& pos_mouse->y >= help.y)
		display_help(window, menu, text);
	if (pos_mouse->x <= exit.x + 137
		&& pos_mouse->x >= exit.x
		&& pos_mouse->y <= exit.y + 62
		&& pos_mouse->y >= exit.y)
		sfRenderWindow_close(window->window);
}

void	event_text(t_window *window, menu_t *menu, menu_text_t *text)
{
	sfVector2i	pos_mouse =
			sfMouse_getPositionRenderWindow(window->window);
	sfVector2f	play = sfText_getPosition(text[0].text);

	if (text[0].alpha == 255 && menu[0].visible == 0) {
		if ((pos_mouse.x <= play.x + 151
			&& pos_mouse.x >= play.x)
			&& (pos_mouse.y <= play.y + 72
			&& pos_mouse.y >= play.y)) {
			play_sound(window, "songs/click.ogg");
			game(window, menu);
		}
		check_other_pos_mouse(window, menu, text, &pos_mouse);
	}
}

void draw_menu(t_window *window, menu_t *menu, t_particule buffer[5])
{
	if (menu[2].visible == 1) {
		sfRenderWindow_drawSprite(window->window,
						menu[2].sprite, NULL);
		sfRenderWindow_drawSprite(window->window,
						menu[0].sprite, NULL);
		if (menu[1].particule == 1)
			update_dust(window, menu, menu->text, buffer);
	}
	else {
		for (int i = 0; i < 4; i++)
			sfRenderWindow_drawText(window->window,
						menu->text[i].text, NULL);
	}
}

void	menu_loop (t_window *window, menu_t *menu)
{
	t_particule buffer[5];

	window->sounds.music = sfMusic_createFromFile("songs/intro.ogg");
	sfMusic_play(window->sounds.music);
	while (sfRenderWindow_isOpen(window->window)) {
		sfRenderWindow_clear(window->window, sfBlack);
		if (menu[1].visible == 1) {
			sfRenderWindow_drawSprite(window->window,
					menu[1].sprite, NULL);
			update_dust(window, menu, menu->text, buffer);
		}
		draw_menu(window, menu, buffer);
		sfRenderWindow_display(window->window);
		event_menu(window, menu, buffer);
	}
}

void	my_rpg (void)
{
	t_window	window;
	sfVideoMode	video_mode;
	menu_t		menu[4];

	menu->text = malloc(sizeof(menu_text_t) * 4);
	if (!menu->text)
		return;
	set_text_menu(menu->text);
	set_menu(menu);
	video_mode = (sfVideoMode){1920, 1080, 32};
	window.window = sfRenderWindow_create(video_mode, "my_rpg",
			sfDefaultStyle, NULL);
	if (!window.window)
		return;
	window.attack = 3;
	window.defence = 0;
	window.help = 0;
	window.sounds.sound = sfSound_create();
	menu_loop(&window, menu);
}

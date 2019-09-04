/*
** EPITECH PROJECT, 2017
** chose_perso
** File description:
** Desc
*/

#include "menu.h"
#include "option.h"
#include <stdlib.h>

void draw_sound_bar(t_window *window, t_menu *option, sfMusic *music)
{
	int volume = sfMusic_getVolume(music);

	option[0].r_button = (sfIntRect){0, 85, (2.5 * volume), 40};
	sfSprite_setTextureRect(option[0].s_button, option[0].r_button);
	sfSprite_setScale(option[0].s_button, option[0].scale);
	sfSprite_setScale(option[1].s_button, option[1].scale);
	sfRenderWindow_drawSprite(window->window, option[1].s_button, NULL);
	sfRenderWindow_drawSprite(window->window, option[0].s_button, NULL);
}

t_menu *set_option(t_menu *option)
{
	option[0].t_background = sfTexture_createFromFile(f_sound, NULL);
	option[0].s_background = sfSprite_create();
	sfSprite_setTexture(option[0].s_background,
				option[0].t_background, sfTrue);
	option[0].v_background = (sfVector2f){700, 300};
	sfSprite_setPosition(option[0].s_background, option[0].v_background);
	option[0].scale = (sfVector2f){1.6, 2};
	option[1].scale = (sfVector2f){1.6, 2};
	option[0].t_button = sfTexture_createFromFile(f_full_bar, NULL);
	option[0].s_button = sfSprite_create();
	option[1].t_button = sfTexture_createFromFile(f_empty_bar, NULL);
	option[1].s_button = sfSprite_create();
	option[1].r_button = (sfIntRect){0, 85, 250, 40};
	sfSprite_setTexture(option[0].s_button, option[0].t_button, sfTrue);
	sfSprite_setTexture(option[1].s_button, option[1].t_button, sfTrue);
	option[0].v_button = (sfVector2f){600, 500};
	sfSprite_setTextureRect(option[1].s_button, option[1].r_button);
	sfSprite_setPosition(option[0].s_button, option[0].v_button);
	sfSprite_setPosition(option[1].s_button, option[0].v_button);
	return (option);
}

void	options(t_window *window, menu_t *menu,
			menu_text_t *text, sfMusic *music)
{
	t_menu *option = malloc(sizeof(t_option) * 3);
	(void) text;

	play_sound(window, "songs/click.ogg");
	option = set_option(option);
	while (sfRenderWindow_isOpen(window->window)) {
		sfRenderWindow_clear(window->window, sfBlack);
		sfRenderWindow_drawSprite(window->window, menu[1].sprite, NULL);
		sfRenderWindow_drawSprite(window->window, menu[3].sprite, NULL);
		sfRenderWindow_drawSprite(window->window,
						option[0].s_background, NULL);
		draw_sound_bar(window, option, music);
		if (event_option(window, menu, option, music) == 1)
			return;
		sfRenderWindow_display(window->window);
	}
}

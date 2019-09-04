/*
** EPITECH PROJECT, 2017
** fight
** File description:
** Desc
*/

#include "fight.h"
#include <stdlib.h>

void	event_fight(t_window *window, t_fight *fight, t_select *select,
		wait_t *wait)
{
	sfEvent		event;

	while (sfRenderWindow_pollEvent(window->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		key_down(fight, select);
		key_up(fight, select);
		key_right_left(fight, select, event);
		key_ok(fight, select, window, wait);
	}
}

void	last_visible(t_select *select, t_window *window,
		wait_t *wait)
{
	if (select[0].select == 2) {
		for (int i = 4; i < 7; i++)
			sfRenderWindow_drawText(window->window,
						select[i].text, NULL);
		for (int i = 3; i < 6; i++)
			sfRenderWindow_drawText(window->window,
						wait[i].text, NULL);
	}
	if (select[0].select == 3) {
		for (int i = 7; i < 10; i++)
			sfRenderWindow_drawText(window->window,
						select[i].text, NULL);
		for (int i = 6; i < 9; i++)
			sfRenderWindow_drawText(window->window,
						wait[i].text, NULL);
	}
}

void	visible(t_select *select, t_fight *fight, t_window *window,
		wait_t *wait)
{
	sfRenderWindow_drawSprite(window->window, fight[4].sprite, NULL);
	sfRenderWindow_drawSprite(window->window, select[0].sprite, NULL);
	if (select[0].select == 1) {
		for (int i = 1; i < 4; i++)
			sfRenderWindow_drawText(window->window,
						select[i].text, NULL);
		for (int i = 0; i < 3; i++)
			sfRenderWindow_drawText(window->window,
						wait[i].text, NULL);
	}
	last_visible(select, window, wait);
}

static	void	set(t_fight *fight, t_select *select, char *ennemy,
			t_window *window)
{
	set_fight(fight, ennemy, window);
	set_select(select);
	set_music_game(window, "songs/fight.ogg");
}

int	fight(t_window *window, char *ennemy)
{
	t_fight	fight[12];
	t_select	select[10];
	wait_t		wait[9];

	set_wait(wait);
	set_text_fight(fight, select, wait);
	set(fight, select, ennemy, window);
	while (sfRenderWindow_isOpen(window->window) &&
		(fight[7].rect_fight.width > 0
		&& fight[9].rect_fight.width > 0)) {
		draw_fighting(fight, window);
		if (select[0].visible == 1)
			visible(select, fight, window, wait);
		display_window(window);
		event_fight(window, fight, select, wait);
	}
	if (fight[7].rect_fight.width <= 0)
		return (1);
	return (2);
}

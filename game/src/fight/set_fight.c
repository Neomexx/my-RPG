/*
1;4803;0c** EPITECH PROJECT, 2017
** set_fight
** File description:
** Desc
*/

#include "fight.h"

static void	set_rect_fight(t_fight *fight)
{
	int y = 0;

	for (int i = 3; i < 6; i++, y++)
		fight[i].scale = scale[y];
	fight[0].scale = (sfVector2f){3, 2.5};
	fight[3].pos_bonus = (sfVector2f) {295, 899};
	fight[4].pos_bonus = (sfVector2f) {450, 825};
	fight[4].rect_fight = (sfIntRect) {0, 0, 50, 7};
	for (int i = 6, y = 0; i < 10; i++, y++)
		fight[i].rect_fight = rect[y];
	for (int i = 1, y = 0; i < 6; i++, y++) {
		fight[i].pos_def = def_fight[y];
		fight[i].pos_attack = attack_fight[y];
	}
	for (int i = 6, y = 5; i < 12; i++, y++)
		fight[i].pos_def = def_fight[y];
	sfSprite_setTextureRect(fight[4].sprite, fight[4].rect_fight);
	sfSprite_setScale(fight[0].sprite, fight[0].scale);
	fight[0].pos_attack = (sfVector2f) {0, 0};
	sfSprite_setPosition(fight[0].sprite, fight[0].pos_attack);
}

static	void	set_position_fight(t_fight *fight)
{
	for (int i = 6; i < 10; i++) {
		sfSprite_setTextureRect(fight[i].sprite,
					fight[i].rect_fight);
		sfSprite_setPosition(fight[i].sprite, fight[i].pos_def);
	}
	for (int i = 3; i < 6; i++) {
		sfSprite_setScale(fight[i].sprite, fight[i].scale);
		sfSprite_setPosition(fight[i].sprite,
				fight[i].pos_attack);
	}
	for (int i = 1; i < 3; i++)
		sfSprite_setPosition(fight[i].sprite, fight[i].pos_def);
	sfSprite_setPosition(fight[10].sprite, fight[10].pos_def);
	sfSprite_setPosition(fight[11].sprite, fight[11].pos_def);
	fight[10].bonus = 0;
	fight[11].bonus = 0;
}

void	set_fight(t_fight *fight, char *ennemy, t_window *window)
{
	for (int i = 0; i < 12; i++)
		fight[i].texture = sfTexture_createFromFile(image_fight[i],
							NULL);
	fight[2].texture = sfTexture_createFromFile(ennemy, NULL);
	fight[1].texture = sfTexture_createFromFile(window->fight_p, NULL);
	for (int i = 0; i < 12; i++) {
		fight[i].sprite = sfSprite_create();
		sfSprite_setTexture(fight[i].sprite, fight[i].texture,
				sfTrue);
	}
	set_rect_fight(fight);
	set_position_fight(fight);
}

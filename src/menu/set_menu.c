/*
** EPITECH PROJECT, 2017
** set_menu
** File description:
** Desc
*/

#include "menu.h"

void	set_menu(menu_t *menu)
{
	for (int i = 0; i < 4; i++) {
		menu[i].texture = sfTexture_createFromFile(name_menu[i],
							NULL);
		menu[i].sprite = sfSprite_create();
		menu[i].pos = pos_menu[i];
		menu[i].scale = scale_menu[i];
		sfSprite_setTexture(menu[i].sprite,
				menu[i].texture, sfTrue);
		sfSprite_setPosition(menu[i].sprite, menu[i].pos);
		sfSprite_setScale(menu[i].sprite, menu[i].scale);
		menu[i].visible = visible_menu[i];
		menu[i].particule = visible_menu[i];
	}
}

void	set_text_menu(menu_text_t *text)
{
	for (int i = 0; i < 4; i++) {
		text[i].font = sfFont_createFromFile("font.ttf");
		text[i].text = sfText_create();
		sfText_setFont(text[i].text, text[i].font);
		sfText_setPosition(text[i].text, pos_text[i]);
		sfText_setString(text[i].text, text_menu[i]);
		sfText_setScale(text[i].text, scale_text[i]);
		text[i].alpha = 0;
		text[i].color = sfColor_fromRGBA(255, 255, 0,
						text[i].alpha);
		sfText_setColor(text[i].text, text[i].color);
	}
}

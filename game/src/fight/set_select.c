/*
** EPITECH PROJECT, 2017
** set_select
** File description:
** Desc
*/

#include "fight.h"

void	set_select(t_select *select)
{
	select[0].texture = sfTexture_createFromFile(image_fight[0], NULL);
	select[0].sprite = sfSprite_create();
	sfSprite_setTexture(select[0].sprite, select[0].texture, sfTrue);
	select[0].attack_top = (sfVector2f){455, 730};
	select[0].attack_bot = (sfVector2f){455, 770};
	select[0].def_top = (sfVector2f){455, 780};
	select[0].def_bot = (sfVector2f){455, 820};
	select[0].bonus_top = (sfVector2f){455, 830};
	select[0].bonus_bot = (sfVector2f){455, 870};
	select[0].rect_select = (sfIntRect){0, 307, 239, 21};
	sfSprite_setTextureRect(select[0].sprite, select[0].rect_select);
	sfSprite_setPosition(select[0].sprite, select[0].attack_bot);
	select[0].i = 0;
	select[0].visible = 0;
	select[0].select = 1;
	select[0].specifics = 1;
}

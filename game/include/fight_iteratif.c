/*
** EPITECH PROJECT, 2018
** fight iteratif
** File description:
** iteratif
*/

#include "fight.h"

const sfVector2f	def_fight[11] = { {100, 400}, {1400, 100}, {295, 847},
				{450, 776}, {200, 430}, {200, 700},
				{200, 700}, {1450, 400}, {1450, 400},
				{600, 400}, {250, 100} };

const sfVector2f	attack_fight[5] = { {125, 400}, {1375, 100},
				{295, 796}, {450, 725}, {1470, 160} };

const sfVector2f	scale[3] = { {3, 4}, {5, 10}, {2, 2} };

const sfVector2f	fight_select[12] = { {460, 726}, {460, 747},
				{460, 767}, {460, 777}, {460, 795}, {460, 817},
				{460, 826}, {460, 847}, {460, 867},
				{300, 790}, {300, 840}, {300, 890} };

const sfVector2f	wait_pos[9] = { {670, 719}, {670, 739}, {670, 759},
				{670, 769}, {670, 789}, {670, 809},
				{670, 819}, {670, 839}, {670, 859} };

const sfIntRect		rect[4] = { {2, 89, 242, 30}, {2, 89, 242, 30},
				{2, 6, 242, 30}, {2, 6, 242, 30} };

const char		*image_fight[12] = {"image/background_fight.png",
			"image/fight/m.png", "image/fight/mo.png",
			"image/select_fight.png", "image/select_fight.png",
			"image/star_damage.png", "image/life_point_empty.png",
			"image/life_point.png", "image/life_point_empty.png",
			"image/life_point.png", "image/shield.png",
			"image/bonus.png"};

const char		*string_fight[12] = {"Printf", "lemin", "bistro",
				"Avast", "GDB", "Valgrind",
				"APE", "Astek", "P-A",
				"Attack", "Defence", "Help"};

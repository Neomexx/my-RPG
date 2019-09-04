/*
** EPITECH PROJECT, 2018
** change_music.c
** File description:
** change the music
*/

#include "struct_rpg.h"

void set_music_game(t_window *window, char *path)
{
	sfMusic_stop(window->sounds.music);
	window->sounds.music = sfMusic_createFromFile(path);
	sfMusic_setLoop(window->sounds.music, sfTrue);
	sfMusic_play(window->sounds.music);
}

void play_sound(t_window *window, char *path)
{
	window->sounds.buffer = sfSoundBuffer_createFromFile(path);
	sfSound_setBuffer(window->sounds.sound, window->sounds.buffer);
	sfSound_play(window->sounds.sound);
}

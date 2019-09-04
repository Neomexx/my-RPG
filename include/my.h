/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Desc
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#define f_pause "image/pause_button.png"

typedef	struct	s_texture
{
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVector2f	position;
	sfVector2f	speed;
	sfClock		*clock;
}		image;

char	*my_itoa(int nb);

//manage_window.c
void	my_rpg(void);

//event_window.c
void	event_window(sfRenderWindow *window);
void	my_putchar(char c);
int	my_strcmp(char *str, char *string);
int	my_strlen(char const *str);
int	my_putstr(char const *str);
int	my_put_nbr(int nb);
int	my_printf(char *s, ...);
int	my_getnbr(char const *str);
char	*my_revstr(char *str);
char	*my_strcpy(char *des, char const *src);
char	**my_str_to_word_array(char *str, int j, char c);

#endif /* MY_H_ */

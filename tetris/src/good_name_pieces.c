/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "tetris.h"
#include "my.h"

int	good_name_pieces(char *name)
{
	if (my_strstr(name, ".tetrimino") != NULL) {
		if (my_strstr(name, ".tetriminos") == NULL)
			return (1);
	}
	return (0);
}

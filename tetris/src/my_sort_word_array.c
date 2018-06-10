/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

int	count_line(char **tab)
{
	int     i = 0;

	while (tab[i])
		i++;
	return (i);
}

int	right_place(char **tab)
{
	int     y = 0;
	int     nb_line = count_line(tab);

	while ((my_strcmp(tab[y], tab[y + 1]) <= 0) && y < nb_line - 2)
		y++;
	return (y);
}

char	**my_sort_array(char **tab)
{
	int     y = 0;

	while (y < count_line(tab) - 1) {
		y = right_place(tab);
		if (my_strcmp(tab[y], tab[y + 1]) > 0 && tab[y] && tab[y + 1]) {
			my_swap(&tab[y], &tab[y + 1]);
			y = 0;
		}
		y++;
	}
	return (tab);
}

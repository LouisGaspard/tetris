/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

int	check_first_line(char *str)
{
	char	**tab = my_str_to_word_array(str, " ");

	if (count_line(tab) != 3)
		return (1);
	for (int a = 0; tab[a]; a++) {
		if (my_str_isnum(tab[a]) == 0)
			return (1);
	}
	return (0);
}

int	check_stars(char **tab)
{
	int	error = 0;

	for (int a = 1; tab[a]; a++) {
		for (int b = 0; tab[a][b]; b++)
			error = (tab[a][b] != '*' && tab[a][b] != ' ') ? 1 : 0;
	}
	if (error != 0)
		return (1);
	return (0);
}

int	check_content(char **tab)
{
	char	**tab2 = my_str_to_word_array(tab[0], " ");
	int	line = my_getnbr(tab2[1]);
	int	col = my_getnbr(tab2[0]);
	int	save_max = 0;

	if (count_line(tab) != line + 1)
		return (1);
	for (int a = 1; tab[a]; a++) {
		if (my_strlen2(tab[a]) > save_max)
			save_max = my_strlen2(tab[a]);
	}
	if (save_max != col)
		return (1);
	return (0);
}

int	check_tab(char **tab)
{
	if ((check_first_line(tab[0])) == 1)
		return (1);
	if ((check_stars(tab)) == 1)
		return (1);
	if ((check_content(tab)) == 1)
		return (1);
	return (0);
}

int	is_error(char *name)
{
	int	fd = open(name, O_RDONLY);
	char	*str;
	char	*final = my_strdup("");
	char	**tab;

	while ((str = get_next_line(fd))) {
		final = my_strcat(final, str);
		final = my_strcat(final, "\n");
	}
	if (final[0] == '\0')
		return (1);
	tab = my_str_to_word_array(final, "\n");
	if ((check_tab(tab)) == 1)
		return (1);
	return (0);
}

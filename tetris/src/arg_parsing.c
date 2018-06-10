/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

char	*my_add_dup(char *str)
{
	if (my_strlen(str) == 1 && str[0] == ' ')
		return (my_strdup("(space)"));
	return (my_strdup(str));
}

int	is_g_arg(char *str)
{
	if (str == NULL || str[0] == '\0')
		return (0);
	return (1);
}

int	check_arg(char **av, t_tetris *tetris, int a)
{
	int     r_value = 0;

	if ((r_value = check_key_b1(av, tetris, a)) == -1)
		return (-1);
	if (r_value > 0) {
		return (r_value);
	}
	return (-1);
}

int	parse_arg(int ac, char **av, t_tetris *tetris)
{
	int     a = 1;
	int	ret = 0;

	while (a != ac) {
		if ((ret = check_arg(av, tetris, a)) == -1)
			return (-1);
		a += ret;
	}
	return (1);
}

/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

int	main(int ac, char **av, char **env)
{
	t_tetris	tetris;

	if (env == NULL || env[0] == NULL)
		return (84);
	tetris.env = env;
	if ((init_struct(&tetris)) == 84)
		return (84);
	if ((ac == 2) && (my_strcmp(av[1], "--help") == 0))
		return (my_help(av[0]));
	if ((parse_arg(ac, av, &tetris)) == -1) {
		my_help(av[0]);
		return (1);
	}
	if (!(my_strcmp(tetris.debug, "true")))
		return (debug_mode(&tetris));
	free_struct(&tetris);
	return (1);
}

/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

int	check_key_s3(char **av, t_tetris *tetris, int a)
{
	if (!(my_strcmp(av[a], "-d"))) {
		if (is_g_arg(av[a + 1])) {
			tetris->kd = my_add_dup(av[a + 1]);
			return (2);
		} else
			return (-1);
	}
	if (!(my_strcmp(av[a], "-l"))) {
		if (is_g_arg(av[a + 1])) {
			tetris->kl = my_add_dup(av[a + 1]);
			return (2);
		} else
			return (-1);
	}
	return (check_bool(av, tetris, a));
}

int	check_key_s2(char **av, t_tetris *tetris, int a)
{
	if (!(my_strcmp(av[a], "-q"))) {
		if (is_g_arg(av[a + 1])) {
			tetris->kq = my_add_dup(av[a + 1]);
			return (2);
		} else
			return (-1);
	}
	if (!(my_strcmp(av[a], "-p"))) {
		if (is_g_arg(av[a + 1])) {
			tetris->kp = my_add_dup(av[a + 1]);
			return (2);
		} else
			return (-1);
	}
	return (check_key_s3(av, tetris, a));
}

int	check_key_s1(char **av, t_tetris *tetris, int a)
{
	if (!(my_strcmp(av[a], "-r"))) {
		if (is_g_arg(av[a + 1])) {
			tetris->kr = my_add_dup(av[a + 1]);
			return (2);
		} else
			return (-1);
	}
	if (!(my_strcmp(av[a], "-t"))) {
		if (is_g_arg(av[a + 1])) {
			tetris->kt = my_add_dup(av[a + 1]);
			return (2);
		} else
			return (-1);
	}
	return (check_key_s2(av, tetris, a));
}

int     check_bool(char **av, t_tetris *tetris, int a)
{
	if (!(my_strcmp(av[a], "-w")) ||\
!(my_strcmp(av[a], "--without-next"))) {
		tetris->next = "No";
		return (1);
	}
	if (my_strcmp(av[a], "-D") == 0 || my_strcmp(av[a], "--debug") == 0) {
		tetris->debug = "true";
		return (1);
	}
	return (check_lvl(av, tetris, a));
}

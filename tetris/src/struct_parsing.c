/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

int	check_key_b3(char **av, t_tetris *tetris, int a)
{
	if (!(my_strncmp(av[a], "--key-drop=", 11))) {
		if (is_g_arg(av[a] + 11)) {
			tetris->kd = my_add_dup(av[a] + 11);
			return (1);
		} else
			return (-1);
	}
	if (!(my_strncmp(av[a], "--key-left=", 11))) {
		if (is_g_arg(av[a] + 11)) {
			tetris->kl = my_add_dup(av[a] + 11);
			return (1);
		} else
			return (-1);
	}
	return (check_key_s1(av, tetris, a));
}

int	check_key_b2(char **av, t_tetris *tetris, int a)
{
	if (!(my_strncmp(av[a], "--key-quit=", 11))) {
		if (is_g_arg(av[a] + 11)) {
			tetris->kq = my_add_dup(av[a] + 11);
			return (1);
		} else
			return (-1);
	}
	if (!(my_strncmp(av[a], "--key-pause=", 12))) {
		if (is_g_arg(av[a] + 12)) {
			tetris->kp = my_add_dup(av[a] + 12);
			return (1);
		} else
			return (-1);
	}
	return (check_key_b3(av, tetris, a));
}

int	check_key_b1(char **av, t_tetris *tetris, int a)
{
	if (!(my_strncmp(av[a], "--key-right=", 12))) {
		if (is_g_arg(av[a] + 12)) {
			tetris->kr = my_add_dup(av[a] + 12);
			return (1);
		} else
			return (-1);
	}
	if (!(my_strncmp(av[a], "--key-turn=", 11))) {
		if (is_g_arg(av[a] + 11)) {
			tetris->kt = my_add_dup(av[a] + 11);
			return (1);
		} else
			return (-1);
	}
	return (check_key_b2(av, tetris, a));
}

int	check_lvl(char **av, t_tetris *tetris, int a)
{
	if (!my_strcmp(av[a], "-L") && is_g_arg(av[a + 1])) {
		if (my_str_isnum(av[a + 1]) == 1) {
			tetris->lvl = my_getnbr(av[a + 1]);
			return (2);
		}
	}
	if (!(my_strncmp(av[a], "--level=", 8))) {
		if (my_str_isnum(av[a] + 8) == 1)
			tetris->lvl = my_getnbr(av[a] + 8);
		return (1);
	}
	return (check_size(av, tetris, a));
}

int	check_size(char **av, t_tetris *tetris, int a)
{
	if (!my_strncmp(av[a], "--map-size=", 11)) {
		tetris->m_size = my_getnbr_comma(tetris->m_size, av[a] + 11);
		return (1);
	}
	return (-1);
}

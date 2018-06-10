/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

char	*check_env(char **env, int a)
{
	if (env[a][5] != '\0')
		return (env[a] + 5);
	return (NULL);
}

char	*get_term_in_env(char **env)
{
	int     a = 0;

	while (env[a]) {
		if ((my_strncmp(env[a], "TERM=", 5) == 0))
			return (check_env(env, a));
		a++;
	}
	return (NULL);
}

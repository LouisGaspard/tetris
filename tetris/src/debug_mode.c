/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"
#include <ncurses.h>
#include <term.h>

void	print_info_tetriminos(char *name)
{
	char	**mab = my_str_to_word_array(name, "\n");

	mab = my_sort_array(mab);
	print_pieces(mab);
	my_free_tab(mab);
}

int	my_print_tetriminos(void)
{
	DIR		*repo;
	struct dirent	*d;
	char		*str = my_strdup("");

	if ((repo = opendir("./tetriminos")) == NULL)
		return (1);
	if ((print_nb_tetriminos()) == 1)
		return (1);
	while ((d = readdir(repo))) {
		if (good_name_pieces(d->d_name) == 1) {
			str = my_strcat(str, "./tetriminos/");
			str = my_strcat(str, d->d_name);
			str = my_strcat(str, "\n");
		}
	}
	str[my_strlen(str) - 1] = '\0';
	print_info_tetriminos(str);
	free(str);
	closedir(repo);
	return (0);
}

char	*my_addend(char *dest, char c)
{
	int	a = 0;
	char	*str = malloc(sizeof(char) * my_strlen(dest) + 2);

	while (dest[a]) {
		str[a] = dest[a];
		a++;
	}
	str[a] = c;
	str[a + 1] = '\0';
	free(dest);
	return (str);
}

char	*my_tigetstr(char *cap, t_tetris *tetris)
{
	int	a = 0;
	int	ret;
	char	*term = get_term_in_env(tetris->env);
	char	*str;
	char	*dest = my_strdup("");

	if (term == NULL)
		return (NULL);
	setupterm(term, 1, &ret);
	if ((str = tigetstr(cap)) == (char *) -1)
		return (NULL);
	while (str[a]) {
		if (str[a] == 27) {
			dest = my_addend(dest, '^');
			dest = my_addend(dest, 'E');
		} else
			dest = my_addend(dest, str[a]);
		a++;
	}
	return (dest);
}

int	debug_mode(t_tetris *tetris)
{
	DIR		*repo;

	if ((repo = opendir("./tetriminos")) == NULL)
		return (1);
	my_printf("*** DEBUG MODE ***\n");
	my_print_struct(tetris);
	if ((my_print_tetriminos()) == 1)
		return (1);
	free_struct(tetris);
	return (1);
}

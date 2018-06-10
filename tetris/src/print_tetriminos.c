/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

int	print_nb_tetriminos(void)
{
	DIR		*repo = opendir("./tetriminos");
	struct dirent	*d;
	int	nb = 0;

	while ((d = readdir(repo))) {
		if (good_name_pieces(d->d_name) == 1)
			nb++;
	}
	if (nb == 0)
		return (1);
	closedir(repo);
	my_printf("Tetriminos : %d\n", nb);
	return (0);
}

void	print_name(char *name)
{
	int	a = 13;

	my_printf("Tetriminos : Name ");
	while (name[a]) {
		if (name[a] == '.' && a != 13 && name[a + 10] == '\0')
			break;
		my_printf("%c", name[a]);
		a++;
	}
}

void	my_prints(char *str)
{
	int	a = my_strlen(str);

	while (str[a] != '*' && a > 0)
		a--;
	str[a + 1] = '\0';
	my_printf("%s\n", str);
}

void	print_size_color(char *name)
{
	int	fd = open(name, O_RDONLY);
	char	*str = get_next_line(fd);
	char	**tab;

	if ((is_error(name)) == 1 || str == NULL) {
		my_printf(" : Error\n");
		return;
	}
	tab = my_str_to_word_array(str, " ");
	free(str);
	if (count_line(tab) < 2 || str == NULL) {
		my_printf(" : Error\n");
		close(fd);
		return;
	}
	my_printf(" : Size %s*%s : Color %s :\n", tab[0], tab[1], tab[2]);
	while ((str = get_next_line(fd))) {
		my_prints(str);
		free(str);
	}
}

void	print_pieces(char **tab)
{
	int	a = 0;

	while (tab[a]) {
		print_name(tab[a]);
		print_size_color(tab[a]);
		a++;
	}
}

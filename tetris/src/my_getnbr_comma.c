/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

int	*my_getnbr_comma(int *nb, char *str)
{
	int     a = 0;
	char    *str1= "";

	while (str[a] && str[a] != ',')
		a++;
	str1 = my_strncpy(str1, str, a);
	if (my_str_isnum(str1) == 1)
		nb[0] = my_getnbr(str1);
	if (my_str_isnum(str + a + 1) == 1)
		nb[1] = my_getnbr(str + a + 1);
	return (nb);
}

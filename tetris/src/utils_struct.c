/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

int	init_struct(t_tetris *tetris)
{
	tetris->lvl = 1;
	if ((tetris->kl = my_strdup(my_tigetstr("kcub1", tetris))) == NULL)
		return (84);
	if ((tetris->kr = my_strdup(my_tigetstr("kcuf1", tetris))) == NULL)
		return (84);
	if ((tetris->kt = my_strdup(my_tigetstr("kcuu1", tetris))) == NULL)
		return (84);
	if ((tetris->kd = my_strdup(my_tigetstr("kcud1", tetris))) == NULL)
		return (84);
	tetris->kq = my_strdup("q");
	tetris->kp = my_strdup("(space)");
	tetris->m_size = malloc(sizeof(int) * 3);
	tetris->m_size[0] = 20;
	tetris->m_size[1] = 10;
	tetris->m_size[2] = 0;
	tetris->next = "Yes";
	tetris->debug = "false";
	return (0);
}

void	free_struct(t_tetris *tetris)
{
	free(tetris->kl);
	free(tetris->kr);
	free(tetris->kt);
	free(tetris->kd);
	free(tetris->kq);
	free(tetris->kp);
	free(tetris->m_size);
}

void	my_print_struct(t_tetris *tetris)
{
	my_printf("Key Left : %s\n", tetris->kl);
	my_printf("Key Right : %s\n", tetris->kr);
	my_printf("Key Turn : %s\n", tetris->kt);
	my_printf("Key Drop : %s\n", tetris->kd);
	my_printf("Key Quit : %s\n", tetris->kq);
	my_printf("Key Pause : %s\n", tetris->kp);
	my_printf("Next : %s\n", tetris->next);
	my_printf("Level : %d\n", tetris->lvl);
	my_printf("Size : %d*%d\n", tetris->m_size[0], tetris->m_size[1]);
}

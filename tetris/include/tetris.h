/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#ifndef __TETRIS_H_
#define __TETRIS_H_

typedef struct
{
	int	lvl;
	char	*kl;
	char	*kr;
	char	*kt;
	char	*kd;
	char	*kq;
	char	*kp;
	int	*m_size;
	char	*next;
	char	*debug;
	char	**env;
} t_tetris;

int	my_help(char *name);
int	my_help_next(void);
int	check_key_s1(char **av, t_tetris *tetris, int a);
int	check_key_b1(char **av, t_tetris *tetris, int a);
int	check_bool(char **av, t_tetris *tetris, int a);
int	check_lvl(char **av, t_tetris *tetris, int a);
int	check_size(char **av, t_tetris *tetris, int a);
int	debug_mode(t_tetris *tetris);
int	is_g_arg(char *str);
int	*my_getnbr_comma(int *nb, char *str);
int	good_name_pieces(char *name);
int	init_struct(t_tetris *tetris);
int	parse_arg(int ac, char **av, t_tetris *tetris);
int	count_line(char **tab);
int	print_nb_tetriminos(void);
int	is_error(char *str);
int	my_strlen2(char *str);
void	free_struct(t_tetris *tetris);
void	print_pieces(char **tab);
void	my_print_struct(t_tetris *tetris);
char	*get_next_line(int fd);
char	*my_tigetstr(char *cap, t_tetris *tetris);
char	*my_add_dup(char *str);
char	*get_term_in_env(char **env);
char	**my_sort_array(char **tab);

#endif

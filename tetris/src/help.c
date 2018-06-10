/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "my.h"
#include "tetris.h"

int	my_help(char *name)
{
	my_printf("Usage: %s [options]\n", name);
	my_printf("Options:\n");
	my_printf("  --help\t\tDisplay this help\n");
	my_printf("  -L --level={num}\tStart Tetris at level num ");
	my_printf("(def: 1)\n");
	my_printf("  -l --key-left={K}\tMove the tetrimino LEFT using the K ");
	my_printf("key (def: left arrow)\n");
	my_printf("  -r --key-right={K}\tMove the tetrimino RIGHT using the K");
	my_printf(" key (def: right arrow)\n");
	my_printf("  -t --key-turn={K}\tTURN the tetrimino clockwise 90d ");
	my_printf("using the K key (def: up arrow)\n");
	my_printf("  -d --key-drop={K}\tDROP the tetrimino using the K key ");
	my_printf("(def: down arrow)\n");
	return (my_help_next());
}

int	my_help_next(void)
{
	my_printf("  -q --key-quit={K}\tQUIT the game using the K key (def: ");
	my_printf("'q' key)\n");
	my_printf("  -p --key-pause={K}\tPAUSE/RESTART the game using the K ");
	my_printf("key (def: space bar)\n");
	my_printf("  --map-size={row,col}\tSet the numbers of rows and ");
	my_printf("columns of the map ");
	my_printf("(def: 20,10)\n");
	my_printf("  -w --without-next\tHide next tetrimino ");
	my_printf("(def: false)\n");
	my_printf("  -D --debug\t\tDebug mode (def: false)\n");
	return (0);
}

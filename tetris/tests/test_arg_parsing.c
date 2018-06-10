/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include "tetris.h"
#include "my.h"
#include <criterion/criterion.h>

Test(my_add_dup, check_my_add_dup)
{
	cr_assert(my_strcmp(my_add_dup(" "), "(space)") == 0);
	cr_assert(my_strcmp(my_add_dup("toto"), "toto") == 0);
}

Test(is_g_arg, check_is_g_arg)
{
	cr_assert(is_g_arg(NULL) == 0);
	cr_assert(is_g_arg("toto") == 1);
}

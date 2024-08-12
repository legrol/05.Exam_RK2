/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:05:45 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/04 11:40:03 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : rostring
 * Expected files   : rostring.c
 * Allowed functions: write, malloc, free
 * -----------------------------------------------------------------
 * 
 * Write a program that takes a string and displays this string after 
 * rotating it one word to the left.
 * 
 * Thus, the first word becomes the last, and others stay in the same order.
 * 
 * A "word" is defined as a part of a string delimited either by spaces/tabs, 
 * or by the start/end of the string.
 * 
 * Words will be separated by only one space in the output.
 * 
 * If there's less than one argument, the program displays \n.
 * 
 * Example:
 * 
 * $>./rostring "abc   " | cat -e
 * abc$
 * $>
 * $>./rostring "Que la      lumiere soit et la lumiere fut"
 * la lumiere soit et la lumiere fut Que
 * $>
 * $>./rostring "     AkjhZ zLKIJz , 23y"
 * zLKIJz , 23y AkjhZ
 * $>
 * $>./rostring "first" "2" "11000000"
 * first
 * $>
 * $>./rostring | cat -e
 * $
 * $> 
 * 
 */

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		k;

	if (argc > 1)
	{
		i = 0;
		j = 0;
		while (argv[1][i] == 32 || argv[1][i] == 9)
			i += 1;
		k = i;
		while (argv[1][i] && argv[1][i] != 32 && argv[1][i] != 9)
			i += 1;
		while (argv[1][i++])
		{
			if (argv[1][i] && (argv[1][i] != 32 && argv[1][i] != 9) \
				&& (argv[1][i - 1] == 32 || argv[1][i - 1] == 9))
			{
				while (argv[1][i] && (argv[1][i] != 32 && argv[1][i] != 9))
					write(1, &argv[1][i++], 1);
				write(1, " ", 1);
			}
		}
		while (argv[1][k] && (argv[1][k] != 32 && argv[1][k] != 9))
			write(1, &argv[1][k++], 1);
	}
	write(1, "\n", 1);
	return (0);
}

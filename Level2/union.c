/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:25:44 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/09 19:13:13 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : union
 * Expected files   : union.c
 * Allowed functions: write
 * ---------------------------------------------------------------
 * 
 * Write a program that takes two strings and displays, without doubles, the
 * characters that appear in either one of the strings.
 * 
 * The display will be in the order characters appear in the command line, 
 * and will be followed by a \n.
 * 
 * If the number of arguments is not 2, the program displays \n.
 * 
 * Example:
 * 
 * $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
 * zpadintoqefwjy$
 * $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
 * df6vewg4thras$
 * $>./union "rien" "cette phrase ne cache rien" | cat -e
 * rienct phas$
 * $>./union | cat -e
 * $
 * $>
 * $>./union "rien" | cat -e
 * $
 * $>
 * 
 */

/**
 * 
 * Alternativa para int lookup[256] = {0};
 * 
 * int lookup[256];        // Declaración del array
 * memset(lookup, 0, sizeof(lookup)); // Inicialización del array a cero
 * 
 */

int main(int argc, char *argv[])
{
	int	i;
	int lookup[256] = {0};

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (!lookup[(int)argv[1][i]])
			{
				lookup[(int)argv[1][i]] = 1;
				write (1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (!lookup[(int)argv[2][i]])
			{
				lookup[(int)argv[2][i]] = 1;
				write (1, &argv[2][i], 1);
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	int				i;
	int lookup[256] = {0};

	i = 0;
	if (argc == 3)
	{
		
		
		while (argv[1][i])
		{
			if (!lookup[(int)argv[1][i]])
			{
				lookup[(int)argv[1][i]] = 1;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (!lookup[(int)argv[2][i]])
			{
				lookup[(int)argv[2][i]] = 1;
				write(1, &argv[2][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}


*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:05:24 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/13 18:06:15 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : repeat_alpha
 * Expected files   : repeat_alpha.c
 * Allowed functions: write
 * -------------------------------------------------------------------
 * 
 * Write a program called repeat_alpha that takes a string and display it
 * repeating each alphabetical character as many times as its alphabetical 
 * index, followed by a newline.
 * 
 * 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
 * 
 * Case remains unchanged.
 * 
 * If the number of arguments is not 1, just display a newline.
 * 
 * Examples:
 * 
 * $>./repeat_alpha "abc"
 * abbccc
 * $>./repeat_alpha "Alex." | cat -e
 * Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
 * $>./repeat_alpha 'abacadaba 42!' | cat -e
 * abbacccaddddabba 42!$
 * $>./repeat_alpha | cat -e
 * $
 * $>
 * $>./repeat_alpha "" | cat -e
 * $
 * $>
 * 
 */

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			j = 0;
			if (argv[1][i] >= 97 && argv[1][i] <= 122)
			{
				while (j++ <= argv[1][i] - 97)
					write (1, &argv[1][i], 1);
			}
			else if (argv[1][i] >= 65 && argv[1][i] <= 90)
			{
				while (j++ <= argv[1][i] - 65)
					write (1, &argv[1][i], 1);
			}
			else
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

/*
int main(int argc, char *argv[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{	
			if (argv[1][i] >= 65 && argv[1][i] <= 90)
				j = argv[1][i] - 65 + 1;
			if (argv[1][i] >= 97 && argv[1][i] <= 122)
				j = argv[1][i] - 97 + 1;
			if (j > 0)
			{
				while (j > 0)
				{
					write (1, &argv[1][i], 1);
					j--;
				}
			}
			else
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
*/

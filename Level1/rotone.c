/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-03 12:24:51 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-06-03 12:24:51 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/***
 * 
 * Assignment name  : rotone
 * Expected files   : rotone.c
 * Allowed functions: write
 * ---------------------------------------------------------------
 * 
 * Write a program that takes a string and displays it, replacing each of its
 * letters by the next one in alphabetical order.
 * 
 * 'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
 * 
 * The output will be followed by a \n.
 * 
 * If the number of arguments is not 1, the program displays \n.
 * 
 * Example:
 * 
 * $>./rotone "abc"
 * bcd
 * $>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
 * Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
 * $>./rotone "AkjhZ zLKIJz , 23y " | cat -e
 * BlkiA aMLJKa , 23z $
 * $>./rotone | cat -e
 * $
 * $>
 * $>./rotone "" | cat -e
 * $
 * $>
 * 
 */

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 65 && argv[1][i] <= 89)
				argv[1][i] += 1;
			else if (argv[1][i] == 90)
				argv[1][i] -= 25;
			else if (argv[1][i] >= 97 && argv[1][i] <= 121)
				argv[1][i] += 1;
			else if (argv[1][i] == 122)
				argv[1][i] -= 25;
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:02:22 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/06/30 18:33:49 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : paramsum
 * Expected files   : paramsum.c
 * Allowed functions: write
 * ------------------------------------------------------------------
 * 
 * Write a program that displays the number of arguments passed to it, 
 * followed by a newline.
 * 
 * If there are no arguments, just display a 0 followed by a newline.
 * 
 * Example:
 * 
 * $>./paramsum 1 2 3 5 7 24
 * 6
 * $>./paramsum 6 12 24 | cat -e
 * 3$
 * $>./paramsum | cat -e
 * 0$
 * $>
 *  
 */

void	ft_putnbr(int nbr)
{
	int	digit;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	digit = (nbr % 10) + '0';
	write (1, &digit, 1);
}

int	main(int argc, char *argv[])
{
	(void) argv;
	int	param;

	if (argc == 1)
	{
		write (1, "0\n", 2);
		return (0);
	}
	param = argc - 1;
	ft_putnbr(param);
	write (1, "\n", 1);
	return (0);
}
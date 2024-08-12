/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:33:37 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/06/30 23:33:37 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : print_hex
 * Expected files   : print_hex.c
 * Allowed functions: write
 * ------------------------------------------------------------------
 * 
 * Write a program that takes a positive (or zero) number expressed in base 10,
 * and displays it in base 16 (lowercase letters) followed by a newline.
 * 
 * If the number of parameters is not 1, the program displays a newline.
 * 
 * Examples:
 * 
 * $> ./print_hex "10" | cat -e
 * a$
 * $> ./print_hex "255" | cat -e
 * ff$
 * $> ./print_hex "5156454" | cat -e
 * 4eae66$
 * $> ./print_hex | cat -e
 * $ 
 * 
 */

int	ft_atoi(char*str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	while (str[i] == 32 || str[i] == 9)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr *= 10;
		nbr += (str[i] - 48);
		i++;
	}
	nbr *= sign;
	return (nbr);
}

void	ft_puthex(int nbr)
{
	if (nbr >= 16)
		ft_puthex(nbr / 16);
	nbr = "0123456789abcdef"[nbr % 16];
	write (1, &nbr, 1);
}

int	main(int argc, char *argv[])
{

	if (argc == 2)
		ft_puthex(ft_atoi(argv[1]));
	write (1, "\n", 1);
	return (0);
}
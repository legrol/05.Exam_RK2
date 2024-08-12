/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:17:45 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/09 16:35:54 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : print_bits
 * Expected files   : print_bits.c
 * Allowed functions: write
 * -------------------------------------------------------------
 * 
 * Write a function that takes a byte, and prints it in binary WITHOUT A 
 * NEWLINE AT THE END.
 * 
 * Your function must be declared as follows:
 * 
 * void	print_bits(unsigned char octet);
 * 
 * Example, if you pass 2 to print_bits, it will print "00000010"
 * 
 */

void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + 48;
		write (1, &bit, 1);
		i--;
	}
}

/***********************************************************************/

int	main(void)
{
	unsigned char	number;

	number = 'A';
	print_bits(number);
	printf("\n");
	return (0);
}
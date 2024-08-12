/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:20:21 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/10 01:30:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/***
 *  * 
 * Assignment name  : reverse_bits
 * Expected files   : reverse_bits.c
 * Allowed functions:
 * -------------------------------------------------------------------
 * 
 * Write a function that takes a byte, reverses it, bit by bit (like the
 * example) and returns the result.
 * 
 * Your function must be declared as follows:
 * 
 * unsigned char	reverse_bits(unsigned char octet);
 * 
 * Example:
 * 
 *   1 byte
 * _____________
 *  0010  0110
 *      ||
 *      \/
 *  0110  0100
 * 
 */

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 7;
	res = 0;
	while (i >= 0)
	{
		res = (res << 1 | octet & 1);
		octet = octet >> 1;
		i--;
	}
	return (res);
}

/***********************************************************************/

int	main(void)
{
	unsigned char	mybit;
	unsigned char	res1;

	mybit = 0;
	res1 = reverse_bits((unsigned char)38);

	int i = 8;
	while (i--)
	{
		mybit = (res1 >> i & 1) + 48;
		printf("%c", mybit);
	}
	return (0);
}

/*
int main(void)
{
	unsigned char bit;

	bit = 38;
	printf("%i\n", reverse_bits(bit));
	return (0);
}
*/

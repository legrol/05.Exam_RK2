/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:29:54 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/04 18:39:24 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : swap_bits
 * Expected files   : swap_bits.c
 * Allowed functions:
 * --------------------------------------------------------------
 * 
 * Write a function that takes a byte, swaps its halves (like the example) and
 * returns the result.
 * 
 * Your function must be declared as follows:
 * 
 * unsigned char	swap_bits(unsigned char octet);
 * 
 * Example:
 *   1 byte
 * _____________
 *  0100 | 0001
 *      \ /
 *      / \
 *  0001 | 0100
 * 
 */

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}

/***********************************************************************/


int	main(void)
{
	unsigned char	letter;

	letter = 65;
	printf("%i\n", swap_bits(letter));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:59:59 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/03 19:30:27 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : lcm
 * Expected files   : lcm.c
 * Allowed functions:
 * ------------------------------------------------------------------
 * 
 * Write a function who takes two unsigned int as parameters and returns the
 * computed LCM of those parameters.
 * 
 * LCM (Lowest Common Multiple) of two non-zero integers is the smallest 
 * positive integer divisible by the both integers.
 * 
 * A LCM can be calculated in two ways:
 * 
 * - You can calculate every multiples of each integers until you have a 
 * common multiple other than 0
 * 
 * - You can use the HCF (Highest Common Factor) of these two integers 
 * and calculate as follows:
 * 
 * 	  LCM(x, y) = | x * y | / HCF(x, y)
 * 
 *   | x * y | means "Absolute value of the product of x by y"
 * 
 * If at least one integer is null, LCM is equal to 0.
 * 
 * Your function must be prototyped as follows:
 * 
 *   unsigned int    lcm(unsigned int a, unsigned int b); 
 * 
*/

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	g;

	if (a > b)
		g = a;
	else
		g = b;
	if (a == 0 || b == 0)
		return (0);
	while (1)
	{
		if ((g % a == 0) && (g % b == 0))
			return (g);
		g++;
	}
}

/******************************************************************************/

int	main(int argc, char *argv[])
{
	unsigned int	m;

	if (argc == 3)
	{
		m = lcm(atoi(argv[1]), atoi(argv[2]));
		printf("LCM: %u\n", m);
	}
}
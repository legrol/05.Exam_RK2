/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:12:02 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/04 17:11:50 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : is_power_of_2
 * Expected files   : is_power_of_2.c
 * Allowed functions: None
 * ---------------------------------------------------------------------
 * 
 * Write a function that determines if a given number is a power of 2.
 * This function returns 1 if the given number is a power of 2, otherwise it 
 * returns 0.
 * 
 * Your function must be declared as follows:
 * 
 * int	    is_power_of_2(unsigned int n);
 * 
 */

int	is_power_of_2(unsigned int n)
{
	unsigned int	test = 1;

	while (test <= n)
	{
		if (test == n)
			return (1);
		test = test * 2;
	}
	return (0);
}

/***********************************************************************/

int	main(void)
{
	unsigned int	number;

	number = 2048;
	printf("%i\n", is_power_of_2(number));
	return (0);
}


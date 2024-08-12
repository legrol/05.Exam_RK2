/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:15:20 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/07 19:05:49 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : max
 * Expected files   : max.c
 * Allowed functions:
 * ----------------------------------------------------------------------
 * 
 * Write the following function:
 * 
 * int		max(int* tab, unsigned int len);
 * 
 * The first parameter is an array of int, the second is the number of 
 * elements in the array.
 * 
 * The function returns the largest number found in the array.
 * 
 * If the array is empty, the function returns 0.
 * 
 */

int	max(int *tab, unsigned int len)
{
	int	i;
	int	my_max;

	i = 0;
	my_max = tab[0];
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > my_max)
			my_max = tab[i];
		i++;
	}
	return (my_max);
}

/********************************************************************/

int	main(void)
{
	int my_array[5] = {2, 56, 3, 15, 8};
	printf("%i\n", max(my_array, 5));
	return (0);
}
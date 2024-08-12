/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:25:16 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/03 19:42:31 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : ft_rrange
 * Expected files   : ft_rrange.c
 * Allowed functions: malloc
 * -------------------------------------------------------------------
 * 
 * Write the following function:
 * 
 * int     *ft_rrange(int start, int end);
 * 
 * It must allocate (with malloc()) an array of integers, fill it with 
 * consecutive values that begin at end and end at start (Including start 
 * and end !), then return a pointer to the first value of the array.
 * 
 * Examples:
 * 
 * - With (1, 3) you will return an array containing 3, 2 and 1
 * - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
 * - With (0, 0) you will return an array containing 0.
 * - With (0, -3) you will return an array containing -3, -2, -1 and 0. * 
 * 
 */

int	*ft_rrange(int start, int end)
{
	int	i;
	int	len;
	int	*range;

	i = 0;
	len = abs(end - start) + 1;
	range = (int *) malloc(len * sizeof(int));
	while (i < len)
	{
		if (start < end)
			range[i] = end--;
		else
			range[i] = end++;
		i++;
	}
	return (range);
}

/******************************************************************************/

int	main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	i;
	int	size;

	i = 0;
	min = 0;
	max = -3;
	size = abs(max - min) + 1;
	tab = ft_rrange(min, max);
	while (i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}

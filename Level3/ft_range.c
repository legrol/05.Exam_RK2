/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:59:31 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/03 19:23:35 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * Assignment name  : ft_range
 * Expected files   : ft_range.c
 * Allowed functions: malloc
 * ----------------------------------------------------------------
 * 
 * Write the following function:
 * 
 * int     *ft_range(int start, int end);
 * 
 * It must allocate (with malloc()) an array of integers, fill it with 
 * consecutive values that begin at start and end at end (Including start 
 * and end !), then return a pointer to the first value of the array.
 * 
 * Examples:
 * 
 * - With (1, 3) you will return an array containing 1, 2 and 3.
 * - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
 * - With (0, 0) you will return an array containing 0.
 * - With (0, -3) you will return an array containing 0, -1, -2 and -3.
 * 
 */

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*range;

	i = 0;
	len = abs(end - start) + 1;
	/**
	 * if (len < 0)
	 * 		len = ((end - start) * -1) + 1;
	 * 	else
	 * 		len = (end - start) + 1;
	 */
	range = (int *) malloc(len * sizeof(int));
	while (i < len)
	{
		if (start < end)
			range[i] = start++;
		else
			range[i] = start--;
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
	tab = ft_range(min, max);
	while (i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}

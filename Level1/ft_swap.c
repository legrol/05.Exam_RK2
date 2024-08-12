/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:26:13 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/07 22:09:47 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
 * 
 * Assignment name  : ft_swap
 * Expected files   : ft_swap.c
 * Allowed functions:
 * 
 * --------------------------------------------------------------------
 * 
 * Write a function that swaps the contents of two integers the adresses 
 * of which are passed as parameters.
 * 
 * Your function must be declared as follows:
 * 
 * void	ft_swap(int *a, int *b);
 * 
 */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/****************************************************************************/

int	main(void)
{
	int	i;
	int	j;

	i = 4;
	j = 7;
	printf("El primer número antes del swap es: %i\n", i);
	printf("El segundo número antes del swap es: %i\n\n", j);
	ft_swap(&i, &j);
	printf("El primer número después del swap es: %i\n", i);
	printf("El segundo número después del swap es: %i\n", j);
	return (0);
}

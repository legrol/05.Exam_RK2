/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:05:38 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/04 16:12:44 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
 * 
 * Assignment name  : ft_strlen
 * Expected files   : ft_strlen.c
 * Allowed functions:
 * ---------------------------------------------------------------
 * 
 * Write a function that returns the length of a string.
 * 
 * Your function must be declared as follows:
 * 
 * int	ft_strlen(char *str);
 * 
 */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/****************************************************************************/

int	main(void)
{
	char	*s;

	s = "Hola que tal andas?";
	printf("%d\n", ft_strlen(s));
	return (0);
}

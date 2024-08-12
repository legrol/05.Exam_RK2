/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:05:19 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/04 16:11:07 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : ft_putstr
 * Expected files   : ft_putstr.c
 * Allowed functions: write
 * ------------------------------------------------------------------
 * 
 * Write a function that displays a string on the standard output.
 * 
 * The pointer passed to the function contains the address of the string's 
 * first character.
 * 
 * Your function must be declared as follows:
 * 
 * void	ft_putstr(char *str);
 * 
 */

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/****************************************************************************/

int	main(void)
{
	char	*s;

	s = "Hola Malaga";
	ft_putstr(s);
	return (0);
}

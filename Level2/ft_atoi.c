/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:39:50 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/04 17:00:18 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : ft_atoi
 * Expected files   : ft_atoi.c
 * Allowed functions: None
 * ------------------------------------------------------------------
 * 
 * Write a function that converts the string argument str to an integer 
 * (type int) and returns it.
 * 
 * It works much like the standard atoi(const char *str) function, see the man.
 * 
 * Your function must be declared as follows:
 * 
 * int	ft_atoi(const char *str);
 * 
 */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/**************************************************************************/

int	main(void)
{
	char	*s1;

	s1 = "    -+-+-12569";
	printf("%i", ft_atoi(s1));
	return (0);
}

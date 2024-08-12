/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:15:21 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/08 23:12:09 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/**
 * 
 * Assignment name  : ft_strrev
 * Expected files   : ft_strrev.c
 * Allowed functions:
 * ---------------------------------------------------------------
 * 
 * Write a function that reverses (in-place) a string.
 * 
 * It must return its parameter.
 * 
 * Your function must be declared as follows:
 * 
 * char    *ft_strrev(char *str);
 * 
 */

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < len - 1)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	return (str);
}

/*************************************************************/

int	main(void)
{
	char	s1[6] = "Hello";

	printf("%s\n", ft_strrev(s1));
	return (0);
}

/*int	main(void)
{
	char s[] = "Hello World";
	ft_strrev(s);
	printf("%s\n", s);
	return (0);
}*/
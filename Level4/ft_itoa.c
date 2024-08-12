/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:21:59 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/18 17:58:19 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : ft_itoa
 * Expected files   : ft_itoa.c
 * Allowed functions: malloc
 * ------------------------------------------------------------------
 * 
 * Write a function that takes an int and converts it to a null-terminated 
 * string.
 * The function returns the result in a char array that you must allocate.
 * 
 * Your function must be declared as follows:
 * 
 * char	*ft_itoa(int nbr); 
 * 
 */

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strrev(char *str)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (j > i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);

}

char	*ft_itoa(int nbr)
{
	int		i;
	int		neg;
	char	*tmp;

	i = 0;
	neg = 0;
	tmp = (char *) malloc(12 * sizeof(char));
	if (tmp == 0 || tmp == NULL)
		return (NULL);
	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	while (nbr)
	{
		tmp[i] = (nbr % 10) + '0';
		nbr /= 10;
		i++;
	}
	if (neg)
		tmp[i] = '-';
	return (ft_strrev(tmp));
}

/*
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);

}

char	*ft_itoa(int nbr)
{
	int		i;
	int		sign;
	char	*tmp;

	i = 0;
	sign = 1;
	tmp = (char *) malloc(12 * sizeof(char));
	if (tmp == 0 || tmp == NULL || !tmp)
		return (NULL);
	if (nbr == -2147483648)
		return ("-2147483648");
    if (nbr == 2147483647)
		return ("2147483647");
    if (nbr == 0)
		return ("0");
	if (nbr < 0)
	{
		sign *= 1;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		tmp[i] = (nbr % 10) + '0';
		nbr /= 10;
		i++;
	}
	if (sign == -1)
		tmp[i] = '-';
	return (ft_strrev(tmp));
}
*/

//**************************************************************************

/*int	main(void)
{
	int	i;
	int	tab[5] = {-2147483648, -42, 0, 2147483647};

	while (i < 5)
		printf("%s\n", ft_itoa(tab[i++]));
	return (0);
}*/

int	main(void)
{
	printf("%s\n", ft_itoa(33));
	printf("%s\n", ft_itoa(-33));
	printf("%s\n", ft_itoa(12345));
	printf("%s\n", ft_itoa(-12345));
	printf("%s\n", ft_itoa(98765));
	printf("%s\n", ft_itoa(-98765));
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	return (0);
}
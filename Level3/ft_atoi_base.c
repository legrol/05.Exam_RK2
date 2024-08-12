/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:52:31 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/05 12:45:26 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : ft_atoi_base
 * Expected files   : ft_atoi_base.c
 * Allowed functions: None
 * ---------------------------------------------------------------
 * 
 * Write a function that converts the string argument str (base N <= 16)
 * to an integer (base 10) and returns it.
 * 
 * The characters recognized in the input are: 0123456789abcdef
 * Those are, of course, to be trimmed according to the requested base. For
 * example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
 * 
 * Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
 * 
 * Minus signs ('-') are interpreted only if they are the first character of 
 * the string.
 * 
 * Your function must be declared as follows:
 * 
 * int	ft_atoi_base(const char *str, int str_base);
 * 
 */


int	isvalid(int chr, int baselen)
{
	char	*lcbase;
	char	*ucbase;
	int		i;

	lcbase = "0123456789abcdef";
	ucbase = "0123456789ABCDEF";
	i = 0;
	while (i < baselen)
	{
		if (chr == lcbase[i] || chr == ucbase[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && isvalid(str[i], str_base))
	{
		res *= str_base;
		if (str[i] >= 48 && str[i] <= 57)
			res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		i++;
	}
	return (res * sign);
}

/****************************************************************************/

int	main(void)
{
	printf("%d\n", ft_atoi_base("AF", 16));
	printf("%d\n", ft_atoi_base("A", 16));
	printf("%d\n", ft_atoi_base("B", 16));
	printf("%d\n", ft_atoi_base("C", 16));
	printf("%d\n", ft_atoi_base("D", 16));
	printf("%d\n", ft_atoi_base("e", 16));
	printf("%d\n", ft_atoi_base("E", 16));
	printf("%d\n", ft_atoi_base("4", 16));
	printf("%d\n", ft_atoi_base("42", 16));
	printf("%d\n", ft_atoi_base("ab", 16));
	printf("%d\n", ft_atoi_base("abc", 16));
	printf("%d\n", ft_atoi_base("Eaca16", 16));
	return (0);
}

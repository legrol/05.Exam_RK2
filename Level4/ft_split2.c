/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:05:59 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/11 20:22:21 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * 
 * Assignment name  : ft_split
 * Expected files   : ft_split.c
 * Allowed functions: malloc
 * ------------------------------------------------------------
 * 
 * Write a function that takes a string, splits it into words, and returns 
 * them as a NULL-terminated array of strings.
 * 
 * A "word" is defined as a part of a string delimited either by 
 * spaces/tabs/new lines, or by the start/end of the string.
 * 
 * Your function must be declared as follows:
 * 
 * char    **ft_split(char *str); 
 * 
 */

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i = 0;

	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	wordcount = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == 9 || str[i] == 10))
			i++;
		if (str[i])
			wordcount++;
		while (str[i] && (str[i] != 32 && str[i] != 9 && str[i] != 10))
			i++;
	}
	char **res = (char **)malloc(sizeof(char *) * (wordcount + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == 9 || str[i] == 10))
			i++;
		j = i;
		while (str[i] && (str[i] != 32 && str[i] != 9 && str[i] != 10))
			i++;
		if (i > j)
		{
			res[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(res[k], &str[j], i - j);
			k++;
		}
	}
	res[k] = NULL;
	return (res);
}

//***********************************************************************************/

int	main(void)
{
	int		idx;
	char	**tab;

	idx = 0;
	tab = ft_split("  The prophecy is true");
	while (idx < 4)
	{
		printf("String %d : %s\n", idx, tab[idx]);
		idx++;
	}
	return (0);
}
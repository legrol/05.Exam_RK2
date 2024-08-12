/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:53:22 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/04 17:50:16 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * Assignment name  : ft_strdup
 * Expected files   : ft_strdup.c
 * Allowed functions: malloc
 * -------------------------------------------------------------------
 * 
 * Reproduce the behavior of the function strdup (man strdup).
 * 
 * Your function must be declared as follows:
 * 
 * char    *ft_strdup(char *src);
 * 
 */

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(src);
	tmp = (void *) malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

/*****************************************************************/

int	main(void)
{
	char	*s1;

	s1 = "Duplicado";
	printf("%s\n", ft_strdup(s1));
	return (0);
}

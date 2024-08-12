/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:05:55 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/09 20:35:53 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/***
 * 
 * Assignment name  : ft_strcpy
 * Expected files   : ft_strcpy.c
 * Allowed functions:
 * ---------------------------------------------------------------------
 * 
 * Reproduce the behavior of the function strcpy (man strcpy).
 * 
 * Your function must be declared as follows:
 * 
 * char    *ft_strcpy(char *s1, char *s2);
 * 
 */

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

/****************************************************************************/

int	main(void)
{
	char src[] = "Hola mundo";
	char dest[] = "";

	printf("%s\n", ft_strcpy(dest, "Hola mundo"));
	return (0);
}

/*int	main(void)
{
	int i;
	char	dest[5];
	char	src[5];

	i = 0;
	dest[0] = '1';
	dest[1] = '2';
	dest[2] = '3';
	dest[3] = '\n';
	dest[4] = '\0';
	src[0] = 'y';
	src[1] = 'e';
	src[2] = 's';
	src[3] = '\n';
	src[4] = '\0';
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	ft_strcpy(dest, src);
	i = 0;
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return (0);
}*/

/*int	main(void)
{
	char str1[7] = "";
	char str2[5] = "Hala";
	printf("%s\n", ft_strcpy(str1, str2));
	return (0);
}*/

/*int main(void)
{
	char	dest[20];
	char	*src;	
	printf("%s", ft_strcpy(dest, "Hola mundo"));}*/
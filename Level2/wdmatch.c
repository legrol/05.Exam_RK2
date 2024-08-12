/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:02:14 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/10 14:48:38 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : wdmatch
 * Expected files   : wdmatch.c
 * Allowed functions: write
 * -----------------------------------------------------------
 * 
 * Write a program that takes two strings and checks whether it's possible to
 * write the first string with characters from the second string, while 
 * respecting the order in which these characters appear in the second string.
 * 
 * If it's possible, the program displays the string, followed by a \n, 
 * otherwise it simply displays a \n.
 * 
 * If the number of arguments is not 2, the program displays a \n.
 * 
 * Examples:
 * 
 * $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
 * faya$
 * $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
 * $
 * $>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " 
 * | cat -e
 * quarante deux$
 * $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
 * $
 * $>./wdmatch | cat -e
 * $
 *  
 */

int	main(int argc, char *argv[])
{
	int			i;
	int			len;
	const char	*s1;
	const char	*s2;

	s1 = argv[1];
	s2 = argv[2];
	i = 0;
	len = 0;
	if (argc == 3)
	{
		while (s1[len])
			len++;		
		while (i < len && *s2)
		{
			if (s1[i] == *s2)
				i++;
			s2++;
		}
		if (i == len)
			write (1, s1, len);
	}
	write (1, "\n", 1);
	return (0);
}

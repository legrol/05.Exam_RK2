/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-27 10:27:38 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-06-27 10:27:38 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : expand_str
 * Expected files   : expand_str.c
 * Allowed functions: write
 * --------------------------------------------------------------
 * 
 * Write a program that takes a string and displays it with exactly three 
 * spaces between each word, with no spaces or tabs either at the beginning 
 * or the end, followed by a newline.
 * 
 * A word is a section of string delimited either by spaces/tabs, or by the
 * start/end of the string.
 * 
 * If the number of parameters is not 1, or if there are no words, simply 
 * display a newline.
 * 
 * Examples:
 * 
 * $> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   
 * meme   chose" | cat -e
 * vous   voyez   c'est   facile   d'afficher   la   meme   chose$
 * $> ./expand_str " seulement          la c'est      plus dur " | cat -e
 * seulement   la   c'est   plus   dur$
 * $> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" 
 * | cat -e
 * $
 * $> ./expand_str "" | cat -e
 * $
 * $>
 * 
 */

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while ((argv[1][i] == 32 || argv[1][i] == 9) && argv[1][i])
			i++;
		while (argv[1][i])
		{
			while (argv[1][i] >= 97 && argv[1][i] <= 122)
			{
				write (1, &argv[1][i], 1);
				i++;
			}
			while (argv[1][i] == 32 && argv[1][i + 1] == 32 && argv[1][i])
				i++;
			if (argv[1][i] == '\0' || (argv[1][i] == 32 \
				&& argv[1][i + 1] == '\0'))
				break ;
			if (argv[1][i] == ' ')
				write (1, "   ", 3);
			else
				write(1, &argv[1][i], 1);
			i++;
		}

	}
	write (1, "\n", 1);
	return (0);
}

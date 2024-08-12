/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:09:25 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/09 14:20:34 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * 
 * Assignment name  : last_word
 * Expected files   : last_word.c
 * Allowed functions: write
 * ------------------------------------------------------------------
 * 
 * Write a program that takes a string and displays its last word followed 
 * by a \n.
 * 
 * A word is a section of string delimited by spaces/tabs or by the start/end 
 * of the string.
 * 
 * If the number of parameters is not 1, or there are no words, display a 
 * newline.
 * 
 * Example:
 * 
 * $> ./last_word "FOR PONY" | cat -e
 * PONY$
 * $> ./last_word "this        ...       is sparta, then again, maybe    not"
 *  | cat -e
 * not$
 * $> ./last_word "   " | cat -e
 * $
 * $> ./last_word "a" "b" | cat -e
 * $
 * $> ./last_word "  lorem,ipsum  " | cat -e
 * lorem,ipsum$
 * $>
 * 
 */

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 32 && argv[1][i + 1] >= 33 && argv[1][i + 1] <= 126)
				j = i + 1;
			i++;
		}
		while (argv[1][j] >= 33 && argv[1][j] <= 126)
		{
			write (1, &argv[1][j], 1);
			j++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

/*
int main(int argc, char *argv[])
{
    int start;
    int end;

    start = 0;
    end = 0;
    if (argc == 2)
    {
        while (argv[1][end])
            end++;
        end--;
        while (argv[1][end] == 32 || argv[1][end] == 9)
            end--;        
        start = end;
        while (argv[1][start] >= 33 && argv[1][start] <= 126)
            start--;
        start++;
        while (start <= end)
        {
            write (1, &argv[1][start], 1);
            start++;
        }
    }
    write (1, "\n", 1);
    return (0);
}
*/
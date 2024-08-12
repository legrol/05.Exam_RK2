/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:13:50 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/13 23:59:06 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
 * 
 * Assignment name	: ft_strspn
 * Expected files	: ft_strspn.c
 * Allowed functions: None
 * ---------------------------------------------------------------
 * 
 * Reproduce exactly the behavior of the strspn function 
 * (man strspn).
 * 
 * The function should be prototyped as follows:
 * 
 * size_t	ft_strspn(const char *s, const char *accept);
 * 
 */

/**
 * 
 * STRSPN(3) (simplified)
 * 
 * NAME
 *     strspn -- span a string
 * LIBRARY
 *     Standard C Library (libc, -lc)SYNOPSIS
 *     #include <string.h>
 *     size_t strspn(const char *s, const char *charset);
 * DESCRIPTION
 *     The strspn() function spans the initial part of the null-terminated * 
 * string s as long as the characters from s occur in the null-terminated 
 * string charset. In other words, it computes the string array index of the
 * first character of s which is not in charset, else the index of the first
 * null character
 * RETURN VALUES
 *     The strspn() functions return the number of characters spanned.
 * 
 */

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t  i;
    size_t  j;
    size_t  check;

    i = 0;
    while (s[i])
    {
        j = 0;
        check = 0;
        while (accept[j])
        {
            if (s[i] == accept[j])
                check = 1;
            j++;
        }
        if (check == 0)
            return (i);
        i++;
    }
    return (i);
}

/****************************************************************************/

int main(void)
{
	char	*str1;
	char	*str2;

	str1 = "algmrdf";
	str2 = "malaga";
	printf("%zu\n", ft_strspn(str1, str2));
	return (0);
}
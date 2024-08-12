/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:05:59 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/04 01:00:18 by rdel-olm         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (size < 1)
		return (count);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	str = (char *) malloc((j + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && (s[i] != c))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	count_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
	{
		i++;
	}
	return (i);
}

static void	free_str(size_t i, char **str)
{
	while (i > 0)
	{
		i--;
		free (*(str + i));
	}
	free(str);
}

static char	**create_word(char const *s, char c, char **str, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(str + i) = ft_substr(s, j, count_word_len(&*(s + j), c));
		if (!*(str + i))
		{
			free_str(i, str);
			return (0);
		}
		while (*(s + j) && (*(s + j) != c))
			j++;
		i++;
	}
	*(str + i) = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	totalwords;

	if (!s)
		return (NULL);
	totalwords = count_words(s, c);
	str = (char **) malloc((totalwords + 1) * (sizeof(char *)));
	if (!str)
		return (NULL);
	str = create_word(s, c, str, totalwords);
	return (str);
}

//***********************************************************************************/

int	main(void)
{
	char	*str1;
	char	id;
	char	**result;
	int		numberwords;
	int		i;

	str1 = "Hello World Malaga    ";
	id = 32;
	i = 0;
	numberwords = count_words(str1, id);
	result = ft_split(str1, id);
	printf("%s\n", str1);
	while (i < numberwords)
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}
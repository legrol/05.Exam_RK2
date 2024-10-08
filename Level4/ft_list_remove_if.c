/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-02 10:06:22 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-07-02 10:06:22 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

/**
 * 
 * Assignment name  : ft_list_remove_if
 * Expected files   : ft_list_remove_if.c
 * Allowed functions: free
 * ---------------------------------------------------------------
 * 
 * Write a function called ft_list_remove_if that removes from the
 * passed list any element the data of which is "equal" to the reference data.
 * 
 * It will be declared as follows :
 * 
 * void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
 * 
 * cmp takes two void* and returns 0 when both parameters are equal.
 * 
 * You have to use the ft_list.h file, which will contain:
 * 
 * $>cat ft_list.h
 * typedef struct      s_list
 * {
 *     struct s_list   *next;
 *     void            *data;
 * }                   t_list;
 * $> 
 * 
 */

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*i;

	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	i = *begin_list;
	while (i && i->next)
	{
		if (!cmp(i->next->data, data_ref))
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp);
		}
		if (i->next)
			i = i->next;
	}
}

/******************************************************************************/

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while ((s1[idx] == s2[idx]) && (s1[idx] != '\0' && s2[idx] != '\0'))
		idx++;
	return (s1[idx] - s2[idx]);
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		if (begin_list->data)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

t_list	*ft_new_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (node = NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*test_list;
	t_list	**begin_list;

	begin_list = &test_list;
	test_list = ft_new_elem("Follow the ");
	test_list->next = ft_new_elem("White rabbit...");
	test_list->next->next = ft_new_elem("!");
	test_list->next->next->next = ft_new_elem("!");
	ft_list_foreach(test_list, (void *)ft_putstr);
	ft_putstr("\n");
	ft_list_remove_if(begin_list, "!", ft_strcmp);
	ft_putstr("Removing the dot -> (!)\n");
	ft_list_foreach(test_list, (void *)ft_putstr);
	ft_putstr("\n");
}

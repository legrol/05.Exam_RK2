/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:48:56 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/06/27 22:58:38 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

/**
 * 
 * Assignment name  : ft_list_size
 * Expected files   : ft_list_size.c, ft_list.h
 * Allowed functions:
 * -----------------------------------------------------------
 * 
 * Write a function that returns the number of elements in the linked 
 * list that's passed to it.
 * 
 * It must be declared as follows:
 * 
 * int	ft_list_size(t_list *begin_list);
 * 
 * You must use the following structure, and turn it in as a file called
 * ft_list.h:
 * 
 * typedef struct    s_list
 * {
 *     struct s_list *next;
 *     void          *data;
 * }                 t_list;
 *  
 */

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

/******************************************************************************/

t_list	*ft_new_node(void *data)
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
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*fourth;
	t_list	*solo;

	first = ft_new_node("One");
	second = ft_new_node("Two");
	third = ft_new_node((void *)3);
	fourth = ft_new_node("Four");
	solo = ft_new_node("Solo");
	first->next = second;
	second->next = third;
	third->next = fourth;
	printf("%d\n", ft_list_size(first));
	printf("%d\n", ft_list_size(second));
	printf("%d\n", ft_list_size(third));
	printf("%d\n", ft_list_size(solo));
	printf("%d\n", ft_list_size(NULL));
	printf("%d\n", ft_list_size(fourth));
	return (0);
}
/*		Small not for later

first->next = ft_new_elem("One");
first->next->next = ft_new_elem("Two");
again && again
or a fct loop
with this fct for exemple ft_list_push_front(t_list **begin_list, void *data)

*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:04:48 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/07/04 12:48:06 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

/**
 * 
 * Assignment name  : sort_list
 * Expected files   : sort_list.c
 * Allowed functions:
 * ---------------------------------------------------------------
 * 
 * Write the following functions:
 * 
 * t_list	*sort_list(t_list* lst, int (*cmp)(int, int));
 * 
 * This function must sort the list given as a parameter, using the function
 * pointer cmp to select the order to apply, and returns a pointer to the
 * first element of the sorted list.
 * 
 * Duplications must remain.
 * 
 * Inputs will always be consistent.
 * 
 * You must use the type t_list described in the file list.h
 * that is provided to you. You must include that file
 * (#include "list.h"), but you must not turn it in. We will use our own
 * to compile your assignment.
 * 
 * Functions passed as cmp will always return a value different from
 * 0 if a and b are in the right order, 0 otherwise.
 * 
 * For example, the following function used as cmp will sort the list
 * in ascending order:
 * 
 * int ascending(int a, int b)
 * {
 * 	return (a <= b);
 * } 
 * 
 */

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		swap;
	t_list	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

/*******************************************************************************/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

int	ascending(int a, int b)
{
	return (a <= b);
}

t_list	*ft_new_elem(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (node = NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_list_foreach_space(t_list *begin_list, void (*f)(int))
{
	while (begin_list != NULL)
	{
		if (begin_list->data)
			(*f)(begin_list->data);
		ft_putchar(' ');
		begin_list = begin_list->next;
	}
}

int	main(void)
{
	t_list	*test_list;

	test_list = ft_new_elem(42);
	test_list->next = ft_new_elem(666);
	test_list->next->next = ft_new_elem(69);
	test_list->next->next->next = ft_new_elem(420);
	test_list->next->next->next->next = ft_new_elem(669);
	test_list->next->next->next->next->next = ft_new_elem(42);
	test_list->next->next->next->next->next->next = ft_new_elem(0);
	ft_list_foreach_space(test_list, (void *)ft_putnbr);
	sort_list(test_list, ascending);
	ft_putchar('\n');
	ft_list_foreach_space(test_list, (void *)ft_putnbr);
	ft_putchar('\n');
	return (0);
}

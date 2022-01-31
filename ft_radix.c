/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:35:37 by wmonacho          #+#    #+#             */
/*   Updated: 2022/01/31 17:01:01 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_returnrotate(t_list **tab_a, int count, int size)
{
	int	i;

	i = size - count;
	while (i > 0)
		ft_rotate_a(tab_a);
	return (0);
}

static int	ft_return_reverserotate(t_list **tab_a, int count)
{
	int	i;

	i = count - 1;
	while (i > 0)
	{
		ft_reverserotate_a(tab_a);
		i--;
	}
	return (0);
}

static int	ft_severalrotate(t_list **tab_a, int count, int size)
{
	int	i;

	i = count - 1;
	if (count == 1)
	{
		ft_swap_a(tab_a);
		return (0);
	}
	while (i > 0)
	{
		ft_rotate_a(tab_a);
		i--;
	}
	ft_swap_a(tab_a);
	if (count > size / 2)
		ft_returnrotate(tab_a, count, size);
	else
		ft_return_reverserotate(tab_a, count);
	return (1);
}

static int	ft_triradix(t_list **tab_a, t_list **tab_b, int j, int size)
{
	t_list	*temp;
	int		number;
	int		count;

	temp = *tab_a;
	count = 0;
	while ((temp) != NULL && (temp)->next != NULL)
	{
		count++;
		number = *((int*)((temp)->content));
		// printf("%d: %d\n", number, (1 & (number >> j)));

		if ((1 & (number >> j)) == 0)
		{
			count--;
			if (count > 0)
				ft_severalrotate(&temp, count, size);
			ft_push_a(&temp, tab_b);
		}
		temp = (temp)->next;
		print_stack(tab_a);
	}
	
	printf("END\n");
	while ((*tab_b)->next != NULL)
		ft_push_b(tab_a, tab_b);
	return (0);
}

int	ft_setradix(t_list **tab_a, t_list **tab_b, int argc)
{
	int		size;
	int		i;
	int		j;

	size = argc - 1;
	i = 0;
	while ((size >> i) != 0)
		i++;
	j = i;
	while (i > 0)
	{
		ft_triradix(tab_a, tab_b, j - i, size);
		i--;
	}
	return (0);
}

/*
le souci maintenant c'est tab_a.
il avance a chaque appel de triradix
*/
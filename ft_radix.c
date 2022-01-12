/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:35:37 by wmonacho          #+#    #+#             */
/*   Updated: 2022/01/11 14:23:52 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	returnrotate(int **tab_a, int count, int size)
{
	int	i;

	i = size - count;
	while (i > 0)
		ft_rotate_a(tab_a);
	return (0);
}

static int	return_reverserotate(int **tab_a, int count)
{
	int	i;

	i = count - 1;
	while (i > 0)
	{
		ft_reverse_rotate_a(tab_a);
		i--;
	}
	return (0);
}

static int	ft_severalrotate(int **tab_a, int count, int size)
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
}

static int	ft_triradix(t_list **tab_a, t_list **tab_b, int j, int size)
{
	int		count;

	count = 0;
	while ((*tab_a)->next != NULL)
	{
		count++;
		if ((1 & ((int)(*tab_a)->content) >> j) == 0)
		{
			count--;
			if (count > 0)
				ft_severalrotate(tab_a, count, size);
			ft_push_a(&tab_a, tab_b);
		}
		*tab_a = (*tab_a)->next;
	}
	while ((*tab_b)->next != NULL)
		ft_push_b(tab_a, tab_b);
	return (0);
}

int	ft_setradix(t_list **tab_a, t_list **tab_b, int argc)
{
	t_list	*tmp;
	int		size;
	int		i;

	size = argc - 1;
	i = 0;
	while ((size >> i) != 0)
		i++;
	while (i > 0)
	{
		tmp = *tab_a;
		tab_a = ft_triradix(&tmp, tab_b, size - i, size);
		i--;
	}
	return (0);
}

/*

 */
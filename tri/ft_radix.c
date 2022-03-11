/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:35:37 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/11 19:05:03 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

/*
il faut que je fasse un compteur dans triradix
la condition du while doit dependre de ce compteur
*/
static int	ft_triradix(t_list **tab_a, t_list *tab_b, int j, int size)
{
	int		number;
	int		i;

	i = 0;
	while (i < size)
	{
		number = *((int *)((*tab_a)->content));
		if ((1 & (number >> j)) == 0)
		{
			ft_push_b(tab_a, &tab_b);
			i++;
		}
		if ((1 & (number >> j)) != 0)
		{
			ft_rotate_a(tab_a);
			i++;
		}
	}
	while (tab_b != NULL)
		ft_push_a(tab_a, &tab_b);
	return (0);
}

int	ft_setradix(t_list *tab_a, t_list *tab_b, int size)
{
	int		i;
	int		j;

	i = 0;
	while ((size >> i) != 0)
		i++;
	j = i;
	while (i > 0)
	{
		ft_triradix(&tab_a, tab_b, j - i, size);
		i--;
	}
	return (0);
}

/*
*/
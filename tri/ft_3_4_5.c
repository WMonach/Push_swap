/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:53:10 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/11 13:11:10 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_push_me(t_list **tab_a, t_list **tab_b, int location, int mod)
{
	if (mod == 1)
	{
		if (location > 2)
			while (location++ <= 4)
				ft_reverserotate_a(tab_a);
		if (location <= 2)
			while (location-- != 0)
				ft_rotate_a(tab_a);
		ft_push_b(tab_a, tab_b);
	}
	if (mod == 2)
	{
		if (location > 2)
		{
			while (location <= 3)
			{
				ft_reverserotate_a(tab_a);
				location++;
			}
		}
		if (location <= 2)
			while (location-- != 0)
				ft_rotate_a(tab_a);
		ft_push_b(tab_a, tab_b);
	}
}

void	ft_tri_2(t_list **tab_a)
{
	int	numberone;
	int	numbertwo;

	numberone = *(int *)((*tab_a)->content);
	numbertwo = *(int *)((*tab_a)->next->content);
	if (numberone > numbertwo)
		ft_swap_a(tab_a);
}

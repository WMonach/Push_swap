/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:15:09 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/08 18:42:38 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_swap_a(t_list **tab_a)
{
	void	*tmp;

	tmp = (*tab_a)->content;
	(*tab_a)->content = (*tab_a)->next->content;
	(*tab_a)->next->content = tmp;
	write(1, "sa\n", 4);
	return (0);
}

int	ft_swap_b(t_list **tab_b)
{
	void	*tmp;

	tmp = (*tab_b)->content;
	(*tab_b)->content = (*tab_b)->next->content;
	(*tab_b)->next->content = tmp;
	write(1, "sb\n", 4);
	return (0);
}

/**/
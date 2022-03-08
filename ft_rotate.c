/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:14:35 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/08 20:14:59 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_rotate_a(t_list **tab_a)
{
	t_list	*savelist;
	t_list	*tmp;

	savelist = (*tab_a)->next;
	tmp = *tab_a;
	while (tmp->next && tmp->next->content != NULL)
		tmp = tmp->next;
	tmp->next = *tab_a;
	(*tab_a)->next = NULL;
	*tab_a = savelist;
	write(1, "ra\n", 3);
	return (0);
}

int	ft_rotate_b(t_list **tab_b)
{
	t_list	*savelist;
	t_list	*tmp;

	savelist = (*tab_b)->next;
	tmp = *tab_b;
	while (tmp->next && tmp->next->content != NULL)
		tmp = tmp->next;
	tmp->next = *tab_b;
	(*tab_b)->next = NULL;
	*tab_b = savelist;
	write(1, "rb\n", 3);
	return (0);
}

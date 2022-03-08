/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:32:09 by wmonacho          #+#    #+#             */
/*   Updated: 2022/03/08 19:13:38 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_reverserotate_a(t_list **tab_a)
{
	t_list	*tmp;

	
	tmp = *tab_a;
	while (tmp->next->next && tmp->next->next->content != NULL)
	{ 
		tmp = tmp->next;
	}
	tmp->next->next = *tab_a;
	*tab_a = tmp->next;
	tmp->next = NULL;
	write(1, "rra\n", 4);
	return (0);
}

int	ft_reverserotate_b(t_list **tab_b)
{
	t_list	*tmp;

	tmp = *tab_b;
	while (tmp->next->next && tmp->next->next->content != NULL)
	{ 
		tmp = tmp->next;
	}
	tmp->next->next = *tab_b;
	*tab_b = tmp->next;
	tmp->next = NULL;
	write(1, "rra\n", 4);
	return (0);
}

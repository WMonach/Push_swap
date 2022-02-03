/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:32:09 by wmonacho          #+#    #+#             */
/*   Updated: 2022/02/03 09:51:33 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_reverserotate_a(t_list **tab_a)
{
	t_list	*tmp;
	t_list	*tempi;

	tmp = *tab_a;
	while (tmp->next->content != NULL)
		tmp = tmp->next;
	tempi = ft_lstnew(tmp->content);
	if (tempi == NULL)
		return (-1);
	ft_lstadd_front(tab_a, tempi);
	write(1, "rra\n", 4);
	free(tmp);
	return (0);
}

int	ft_reverserotate_b(t_list **tab_b)
{
	t_list	*tmp;
	t_list	*tempi;

	tmp = *tab_b;
	while (tmp->next->content != NULL)
		tmp = tmp->next;
	tempi = ft_lstnew(tmp->content);
	if (tempi == NULL)
		return (-1);
	ft_lstadd_front(tab_b, tempi);
	write(1, "rrb\n", 4);
	free(tmp);
	return (0);
}
